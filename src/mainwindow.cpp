#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlhelper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_notes->setVisible(false);

    qDebug() << "Connecting to database...";
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

void MainWindow::on_ButtonContact1_clicked()
{
    if (ui->ButtonContact1->isChecked())
    {
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact9->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact2->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact9->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact9->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact2->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact9->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}

void MainWindow::on_ButtonContact2_clicked()
{
    if (ui->ButtonContact2->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact9->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact9->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact9->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact9->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}
void MainWindow::on_ButtonContact3_clicked()
{
    if (ui->ButtonContact3->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact9->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact2->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact9->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact9->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact2->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact9->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}

void MainWindow::on_ButtonContact4_clicked()
{
    if (ui->ButtonContact4->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact9->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact2->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact9->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact9->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact2->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact9->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}

void MainWindow::on_ButtonContact5_clicked()
{
    if (ui->ButtonContact5->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact9->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact2->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact9->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact9->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact2->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact9->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}

void MainWindow::on_ButtonContact6_clicked()
{
    if (ui->ButtonContact6->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact9->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact2->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact9->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact9->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact2->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact9->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}
void MainWindow::on_ButtonContact7_clicked()
{
    if (ui->ButtonContact7->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact9->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact2->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact9->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact9->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact2->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact9->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}
void MainWindow::on_ButtonContact8_clicked()
{
    if (ui->ButtonContact8->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact9->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact2->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact9->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact9->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact2->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact9->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}
void MainWindow::on_ButtonContact9_clicked()
{
    if (ui->ButtonContact9->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact10->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact2->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact10->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact10->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact2->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact10->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}

void MainWindow::on_ButtonContact10_clicked()
{
    if (ui->ButtonContact10->isChecked())
    {
        ui->ButtonContact1->setVisible(false);
        ui->ButtonContact2->setVisible(false);
        ui->ButtonContact3->setVisible(false);
        ui->ButtonContact4->setVisible(false);
        ui->ButtonContact5->setVisible(false);
        ui->ButtonContact6->setVisible(false);
        ui->ButtonContact7->setVisible(false);
        ui->ButtonContact8->setVisible(false);
        ui->ButtonContact9->setVisible(false);

        ui->label_Contact1->setVisible(false);
        ui->label_Contact2->setVisible(false);
        ui->label_Contact3->setVisible(false);
        ui->label_Contact4->setVisible(false);
        ui->label_Contact5->setVisible(false);
        ui->label_Contact6->setVisible(false);
        ui->label_Contact7->setVisible(false);
        ui->label_Contact8->setVisible(false);
        ui->label_Contact9->setVisible(false);

        ui->widget_notes->setVisible(true);
    }
    else
    {
        ui->ButtonContact1->setVisible(true);
        ui->ButtonContact2->setVisible(true);
        ui->ButtonContact3->setVisible(true);
        ui->ButtonContact4->setVisible(true);
        ui->ButtonContact5->setVisible(true);
        ui->ButtonContact6->setVisible(true);
        ui->ButtonContact7->setVisible(true);
        ui->ButtonContact8->setVisible(true);
        ui->ButtonContact9->setVisible(true);

        ui->label_Contact1->setVisible(true);
        ui->label_Contact2->setVisible(true);
        ui->label_Contact3->setVisible(true);
        ui->label_Contact4->setVisible(true);
        ui->label_Contact5->setVisible(true);
        ui->label_Contact6->setVisible(true);
        ui->label_Contact7->setVisible(true);
        ui->label_Contact8->setVisible(true);
        ui->label_Contact9->setVisible(true);

        ui->widget_notes->setVisible(false);
    }
}
