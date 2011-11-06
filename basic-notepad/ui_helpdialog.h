/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created: Wed Jan 19 13:11:04 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_contentsDialog
{
public:
    QPushButton *okButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *contentsDialog)
    {
        if (contentsDialog->objectName().isEmpty())
            contentsDialog->setObjectName(QString::fromUtf8("contentsDialog"));
        contentsDialog->resize(346, 232);
        okButton = new QPushButton(contentsDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(140, 160, 86, 27));
        textBrowser = new QTextBrowser(contentsDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(100, 30, 161, 111));

        retranslateUi(contentsDialog);
        QObject::connect(okButton, SIGNAL(clicked()), contentsDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(contentsDialog);
    } // setupUi

    void retranslateUi(QDialog *contentsDialog)
    {
        contentsDialog->setWindowTitle(QApplication::translate("contentsDialog", "Help", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("contentsDialog", "OK", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("contentsDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Liberation Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n<img src='images/icon.png'>"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Control + C -	Copy</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Control + V -  Paste</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-rig"
                        "ht:0px; -qt-block-indent:0; text-indent:0px;\">Control + A -	 Select All</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class contentsDialog: public Ui_contentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
