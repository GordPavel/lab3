#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent ) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setFixedSize( 400 , 250 );
    ui->setupUi(this);
    QStringList colums;
    ui->tableWidget->setColumnCount( 3 );
    colums << "Last name" << "Telephone number" << "Birthday";
    ui->tableWidget->setHorizontalHeaderLabels( colums );
    foreach ( Man* man, this -> windowMen ) {
        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
        ui->tableWidget->setItem( ui->tableWidget->rowCount() - 1 , 0 , new QTableWidgetItem( man->getLastName().c_str() ) );
        ui->tableWidget->setItem( ui->tableWidget->rowCount() - 1 , 1 , new QTableWidgetItem( man->getTelephoneNumber().c_str() ) );
        ui->tableWidget->setItem( ui->tableWidget->rowCount() - 1 , 2 , new QTableWidgetItem( man->getBirthDate().c_str() ) );
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setMen(std::vector<Man *> men){
    this->windowMen = men;
}
