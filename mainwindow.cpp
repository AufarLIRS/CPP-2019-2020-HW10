#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::reset()
{
  ui->startPushButton->setEnabled(true);
  ui->radioButton->setChecked(true);

  ui->firstPushButton->setEnabled(false);
  ui->secondPushButton->setEnabled(false);
  ui->thirdPushButton->setEnabled(false);
  ui->fourthPushButton->setEnabled(false);
}

void MainWindow::checkButton(int buttonId)
{
  int button;
  switch (buttonId)
  {
    case -3:
      button = 1;
      break;
    case -4:
      button = 2;
      break;
    case -5:
      button = 3;
      break;
    case -6:
      button = 4;
      break;
  }

  if (Game::checkNumber(button))
  {
    switch (button)
    {
      case 1:
        ui->plainTextEdit->appendPlainText("First button was pushed");
        Logger::getInstance().log("user pushed the first button");
        break;
      case 2:
        ui->plainTextEdit->appendPlainText("Second button was pushed");
        Logger::getInstance().log("user pushed the second button");
        break;
      case 3:
        ui->plainTextEdit->appendPlainText("Third button was pushed");
        Logger::getInstance().log("user pushed the third button");
        break;
      case 4:
        ui->plainTextEdit->appendPlainText("Fourth button was pushed");
        Logger::getInstance().log("user pushed the fourth button");
        break;
    }
    if (Game::checkWin())
    {
      ui->plainTextEdit->appendPlainText("Win!");
      Logger::getInstance().log("user won!");
      reset();
    }
  }
  else
  {
    ui->plainTextEdit->appendPlainText("Loose :(");
    Logger::getInstance().log("user is a loser +_+");
    reset();
  }
}

void MainWindow::on_firstPushButton_clicked()
{
  ui->firstRadioButton->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_secondPushButton_clicked()
{
  ui->secondRadioButton->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_thirdPushButton_clicked()
{
  ui->thirdRadioButton->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_fourthPushButton_clicked()
{
  ui->fourthRadioButton->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_startPushButton_clicked()
{
  Game::start();
  ui->firstPushButton->setEnabled(true);
  ui->secondPushButton->setEnabled(true);
  ui->thirdPushButton->setEnabled(true);
  ui->fourthPushButton->setEnabled(true);
  ui->startPushButton->setEnabled(false);

  ui->plainTextEdit->appendPlainText("New game");
  Logger::getInstance().log("user started new game");
}
