#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>
#include"man.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0 );
    void setMen( std::vector<Man*> windowMen );
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<Man*> windowMen;
};

#endif // MAINWINDOW_H
