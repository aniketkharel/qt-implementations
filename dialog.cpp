#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);

    QStringList list ;
    list << "mark" << "tony" << "birds" << "avenger";

    model->setStringList(list);

    ui->listView->setModel(model);
    ui->comboBox->setModel(model);
    ui->listView->
            setEditTriggers(QAbstractItemView::AnyKeyPressed
                            | QAbstractItemView::DoubleClicked);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_addBtn_clicked()
{
    //add
    //counts row in that model
    int row = model->rowCount();
    //add how many ?
    model->insertRows(row,1);
    //current index in a model
    QModelIndex index = model->index(row);
    //set current index in list view
    ui->listView->setCurrentIndex(index);
    //edit mode on that index
    ui->listView->edit(index);
}

void Dialog::on_insertBtn_clicked()
{
    //insert
    //add
    int row = ui->listView->currentIndex().row();
    model->insertRows(row,1);
    QModelIndex index = model->index(row);
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void Dialog::on_deleteBtn_clicked()
{
    //delete
    model->removeRows(ui->listView->currentIndex().row(),1);
}
