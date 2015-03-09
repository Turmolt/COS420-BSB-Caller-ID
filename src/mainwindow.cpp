#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlhelper.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->ButtonContact1, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact2, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact3, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact4, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact5, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact6, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact7, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact8, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact9, SIGNAL(click()),this, SLOT(openContactWindow()));
    connect (ui->ButtonContact10, SIGNAL(click()),this, SLOT(openContactWindow()));

    sqlHelper sqlconn;
    bool connResult = sqlconn.createConnection();
    QSqlDatabase db = sqlconn.getInstance();
    if (!connResult) {
        qDebug() << "SQL Error" << db.lastError();
    }
    sqlconn.closeConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openContactWindow()
{
    myContactWindow = new ContactWindow();
    myContactWindow->show();
}

void MainWindow::on_ButtonContact1_clicked()
{
    openContactWindow();
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact9->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact2_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact9->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact3_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact9->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact4_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact9->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact5_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact9->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact6_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact9->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact7_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact9->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact8_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact9->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact9_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact10->setVisible(false);
}

void MainWindow::on_ButtonContact10_clicked()
{
    openContactWindow();
    ui->ButtonContact1->setVisible(false);
    ui->ButtonContact2->setVisible(false);
    ui->ButtonContact3->setVisible(false);
    ui->ButtonContact4->setVisible(false);
    ui->ButtonContact5->setVisible(false);
    ui->ButtonContact6->setVisible(false);
    ui->ButtonContact7->setVisible(false);
    ui->ButtonContact8->setVisible(false);
    ui->ButtonContact9->setVisible(false);
}
