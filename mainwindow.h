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
    explicit MainWindow( QWidget *parent , std::vector<Man*> men );
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<Man*> windowMen;
};

#endif // MAINWINDOW_H
