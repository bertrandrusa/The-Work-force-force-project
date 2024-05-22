```cpp

#ifndef UI_H
#define UI_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "database.h"

    class MainWindow : public QMainWindow,
                       private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddButtonClicked()
