#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_addBtn_clicked();

    void on_insertBtn_clicked();

    void on_deleteBtn_clicked();

private:
    Ui::Dialog *ui;
    QStringListModel *model;
};
#endif // DIALOG_H
