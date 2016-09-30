#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
//#include

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_connectButton_clicked();

private:
    Ui::Dialog *ui;
    ClientNetwork *client;
};

#endif // DIALOG_H
