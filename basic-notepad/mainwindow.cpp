#include<QtGui>
#include "mainwindow.h"
#include "helpdialog.h"

MainWindow::MainWindow()
{
    MagicNumber = 0x7F51C883;
    help=new helpdialog;
    setupUi(this);
    createActions();
    createContextMenus();
    createToolbars();
    setWindowIcon(QIcon(":/images/icon.png"));
    setCentralWidget(textEdit);
    setCurrentFile("");
}

void MainWindow::createActions()
{
    connect(actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(actionNew,SIGNAL(triggered()),this,SLOT(newFile()));
    connect(actionCopy,SIGNAL(triggered()),this,SLOT(copy()));
    connect(actionPaste,SIGNAL(triggered()),this,SLOT(paste()));
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(aboutdialog()));
    connect(actionSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(actionSave_As,SIGNAL(triggered()),this,SLOT(saveAs()));
    connect(actionOpen,SIGNAL(triggered()),this,SLOT(open()));
    connect(actionContents,SIGNAL(triggered()),this,SLOT(contents()));
    connect(textEdit,SIGNAL(textChanged()),this,SLOT(modified()));
    setCurrentFile("");
}

void MainWindow::aboutdialog()
{
    QMessageBox::about(this,tr("About Notepad"),"<h1>Notepad v1.0b  <img src='images/icon.png'> </h1>Notepad is a small fast text editor based on Qt<br><br>Developed by:<br> Saurabh Sood<br>Nitesh Narayan Lal");
}

void MainWindow::newFile()
{
    if(this->isWindowModified())
    {
        int val=QMessageBox::information(this,tr("Notepad"),tr("Do you want to save the Document?"),QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
        if(val==QMessageBox::Yes)
            save();
        else if(val==QMessageBox::No)
        {
            textEdit->clear();
            setCurrentFile("");
            setWindowModified(false);
        }
    }
}

void MainWindow::copy()
{
    textEdit->copy();
}

void MainWindow::setCurrentFile(const QString & filename)
{
    currentFile=filename;
    setWindowModified(false);
    setWindowTitle(tr("%1[*] - %2").arg(filename).arg("Notepad"));
}

bool MainWindow::save()
{
if(currentFile.isEmpty())
    return saveAs();
else return saveFile(currentFile);
}

bool MainWindow::saveFile(const QString &filename)
{
    if(!writeFile(filename))
    {
        statusBar()->showMessage(tr("Saving Cancelled"),2000);
        return false;
    }
    setCurrentFile(filename);
    statusBar()->showMessage(tr("File Saved"),2000);
    return true;
}

bool MainWindow::saveAs()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save File"),".",tr("Notepad Files (*.tf)"));
    if(fileName.isEmpty())
        return false;
    else return saveFile(fileName);
}


bool MainWindow::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,tr("Notepad"),tr("Cannot Write File %1:\n%2").arg(file.fileName()).arg(file.errorString()));
        return false;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_3);
    out<<(quint32)MagicNumber;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out<<textEdit->toPlainText();
    QApplication::restoreOverrideCursor();
    return true;
}

void MainWindow::open()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open Notepad File"),".");
    if(!fileName.isEmpty())
        if(!loadFile(fileName))
            QMessageBox::warning(this,tr("Notepad"),tr("Could not Open File"));
        return;
}

bool MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,tr("Notepad"),tr("Could not Open File %1:\n%2").arg(file.fileName()).arg(file.errorString()));
        return false;
    }

QDataStream in(&file);
in.setVersion(QDataStream::Qt_4_3);
quint32 magic;
in>>magic;

if(magic!=MagicNumber)
{
    QMessageBox::warning(this,tr("Notepad"),tr("This is not a Notepad File"));
    return false;
}
QString str;
in>>str;
textEdit->setPlainText(str);
setCurrentFile(fileName);
return true;
}

void MainWindow::createContextMenus()
{
    textEdit->addAction(actionCopy);
    textEdit->addAction(actionPaste);
    textEdit->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::paste()
{
    textEdit->paste();
}

void MainWindow::createToolbars()
{
    fileToolbar->addAction(actionNew);
    fileToolbar->addAction(actionOpen);
    fileToolbar->addAction(actionSave);

    editToolbar->addAction(actionCopy);
    editToolbar->addAction(actionPaste);

    helpToolbar->addAction(actionAbout);
}

void MainWindow::contents()
{
    help->show();
}

void MainWindow::modified()
{
    setWindowModified(true);
}
