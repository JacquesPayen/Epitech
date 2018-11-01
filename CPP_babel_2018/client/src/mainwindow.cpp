#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->callButton, SIGNAL(released()), this, SLOT(CallButton()));
    connect(ui->loginButton, SIGNAL(released()), this, SLOT(LoginButton()));
    connect(ui->registerButton, SIGNAL(released()), this, SLOT(RegisterButton()));
    connect(ui->addcontactButton, SIGNAL(released()), this, SLOT(AddContactButton()));
    connect(ui->removeButton, SIGNAL(released()), this, SLOT(RemoveContactButton()));
    connect(ui->endcallButton, SIGNAL(released()), this, SLOT(EndCallButton()));
    connect(ui->logoutButton, SIGNAL(released()), this, SLOT(LogoutButton()));
    connect(ui->contactList, SIGNAL(itemSelectionChanged()), this, SLOT(SelectContact()));

    askNetworkInfo();
    std::cout << "Passed2" << std::endl;
    ui->stackedWidget->setCurrentIndex(1);
    std::cout << "Passed3" << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void        MainWindow::askNetworkInfo()
{
	bool ok;
	std::string ip;
	int port;

	QString text = QInputDialog::getText(this, tr("Server info"),
        	tr("IP Address:"), QLineEdit::Normal, "127.0.0.1", &ok);
	if (ok && !text.isEmpty())
		ip = text.toStdString();
	bool ok2;
	QString text2 = QInputDialog::getText(this, tr("Server info"),
                tr("Port:"), QLineEdit::Normal, "1400", &ok2);
	if (ok && !text2.isEmpty())
        	port = text2.toInt();
	ptc = new protocol(ip, port);
	std::cout << "Passed" << std::endl;
}

void MainWindow::LoginButton()
{
    if (ui->loginnameLine->text() == "" || ui->loginpassLine->text() == "")
        QMessageBox::warning(
            this,
            tr("Login Error"),
            tr("Password or Username empty.") );
    else {
	    if (ptc->loginUser(ui->loginnameLine->text().toStdString(), ui->loginpassLine->text().toStdString()) == 1) {
		    ui->stackedWidget->setCurrentIndex(0);
		    ui->Username->setText(ui->loginnameLine->text());
	    }
	    else {
		        QMessageBox::warning(
            this,
            tr("Login Error"),
            tr("Password or Username empty.") );    
	    }
    }
}

void MainWindow::RegisterButton()
{
	std::cout << "Here" << std::endl;
    if (ui->registernameLine->text() == "" || ui->registerpass1Line->text() == ""
            || ui->registerpass2Line->text() == "")
        QMessageBox::warning(
            this,
            tr("Register Error"),
            tr("Password or Username empty.") );
    else if (ui->registerpass1Line->text() != ui->registerpass2Line->text()) {
        QMessageBox::warning(
            this,
            tr("Register Error"),
            tr("Password must match") );
    }
    else {
	    if (ptc->registerUser(ui->registernameLine->text().toStdString(), ui->registerpass1Line->text().toStdString()) == 1) {
            QMessageBox::information(
                        this,
                        tr("Register"),
                        tr("Succesfully registered") );
        }
        else {
                QMessageBox::warning(
            this,
            tr("Login Error"),
            tr("Password or Username empty.") );
        }
    }
}
void MainWindow::AddContactButton()
{
    if (ui->addcontactLine->text() == "")
        QMessageBox::warning(
            this,
            tr("Contact Errorr"),
            tr("Contact name is empty.") );
    else {
        if (ptc->addFriend(ui->addcontactLine->text().toStdString()) == 1) {
            ui->contactList->addItem(ui->addcontactLine->text());
            ui->addcontactLine->clear();
	}
    }
}

void MainWindow::RemoveContactButton()
{
    if (ui->contactList->count() > 0 && ui->contactList->currentItem())
    {
        ptc->removeFriend(ui->contactList->currentItem()->text().toStdString());
	delete ui->contactList->currentItem();
    }
}

void MainWindow::CallButton()
{
    ui->callStatus->setText("Appel en cours...");
    ui->callButton->setDisabled(true);
    ui->endcallButton->setDisabled(false);
    ui->contactList->setDisabled(true);
    ui->removeButton->setDisabled(true);
    ptc->startCall(ui->contactList->currentItem()->text().toStdString());
}

void MainWindow::EndCallButton()
{
    ui->callStatus->setText("statut contact");
    ui->endcallButton->setDisabled(true);
    ui->callButton->setDisabled(false);
    ui->removeButton->setDisabled(false);
    ui->contactList->setDisabled(false);
    ptc->endCall();
}

void MainWindow::LogoutButton()
{
    ptc->logout();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::SelectContact()
{
    if (ui->contactList->count() > 0 && ui->contactList->currentItem()) {
        ui->contactName->setText(ui->contactList->currentItem()->text());
        ui->removeButton->setDisabled(false);
        ui->callButton->setDisabled(false);
    }
}
