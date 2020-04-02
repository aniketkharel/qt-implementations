#include "dialog.h"
#include "ui_dialog.h"

#include <QInputDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    model = new QDirModel(this);

    //read only mode
    model->setReadOnly(false);

    //sort first by directory , ignore case and sort by Name
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

    //sets model to our tree view
    ui->treeView->setModel(model);

    QModelIndex index = model->index("D:/");

    ui->treeView->expand(index);
      ui->treeView->scrollTo(index);
        ui->treeView->setCurrentIndex(index);
          ui->treeView->resizeColumnToContents(0);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    //make directroy
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()){
        return;
    }else{
        QString name = QInputDialog::getText(this,"Name","Enter Name");
        if(name.isEmpty()){
            return;
        }else{
            model->mkdir(index,name);
        }
    }

}

void Dialog::on_pushButton_2_clicked()
{
    //delete directory
    //make directroy
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()){
        return;
    }else if(model->fileInfo(index).isDir()){
        //directory
        model->rmdir(index);
    }else{
        model->remove(index);
    }

}
