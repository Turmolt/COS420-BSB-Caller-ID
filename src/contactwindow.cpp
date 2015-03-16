#include "contactwindow.h"

ContactWindow::ContactWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ContactWindow)
{
    ui->setupUi(this);
}

ContactWindow::~ContactWindow()
{
    delete ui;
}
