#ifndef HELPDIALOG_H
#define HELPDIALOG_H
#include "ui_helpdialog.h"
#include<QDialog>

class helpdialog:public QDialog,public Ui::contentsDialog
{
public:
    helpdialog()
    {
        setupUi(this);
        connect(okButton,SIGNAL(clicked()),this,SLOT(accept()));
    }
};

#endif // HELPDIALOG_H
