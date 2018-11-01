#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "protocol.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void CallButton();
    void LoginButton();
    void RegisterButton();
    void AddContactButton();
    void RemoveContactButton();
    void EndCallButton();
    void LogoutButton();
    void SelectContact();
    void askNetworkInfo();

private:
    Ui::MainWindow *ui;
    protocol	*ptc;
};

#endif // MAINWINDOW_H
