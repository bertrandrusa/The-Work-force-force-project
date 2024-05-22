#include "ui.h"
#include "database.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    db.openDatabase("employees.db");

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    // Other UI connections...
}

void MainWindow::onAddButtonClicked()
{
    QString name = nameLineEdit->text();
    QString position = positionLineEdit->text();
    QString department = departmentLineEdit->text();
    QString contact = contactLineEdit->text();

    if (db.addEmployee(name.toStdString(), position.toStdString(), department.toStdString(), contact.toStdString()))
    {
        QMessageBox::information(this, "Success", "Employee added successfully!");
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to add employee.");
    }
}
// Other UI functions...

MainWindow::~MainWindow()
{
    db.closeDatabase();
}
