#include "logger.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <random>
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

void MainWindow::generate()
{
  current_ = 0;
  numbers_ = std::vector{ 1, 2, 3, 4 };

  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(numbers_), std::end(numbers_), rng);

  QByteArray nums = "";
  for (auto n : numbers_)
  {
    nums += n;
  }
  qDebug() << numbers_[0] << numbers_[1] << numbers_[2] << numbers_[3];
  Logger::GetInstance().AppendLog(nums);
}

bool MainWindow::checkNumber(int button)
{
  return (button == numbers_[current_]);
}

bool MainWindow::checkWin()
{
  if (current_ == 3)
  {
    return true;
  }
  else
  {
    current_++;
    return false;
  }
}

void MainWindow::start()
{
  numbers_.clear();
  generate();
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

  if (checkNumber(button))
  {
    switch (button)
    {
      case 1:
        ui->plainTextEdit->appendPlainText("First button was pushed");
        Logger::GetInstance().AppendLog("user pushed the first button");
        break;
      case 2:
        ui->plainTextEdit->appendPlainText("Second button was pushed");
        Logger::GetInstance().AppendLog("user pushed the second button");
        break;
      case 3:
        ui->plainTextEdit->appendPlainText("Third button was pushed");
        Logger::GetInstance().AppendLog("user pushed the third button");
        break;
      case 4:
        ui->plainTextEdit->appendPlainText("Fourth button was pushed");
        Logger::GetInstance().AppendLog("user pushed the fourth button");
        break;
    }
    if (checkWin())
    {
      ui->plainTextEdit->appendPlainText("Win!");
      Logger::GetInstance().AppendLog("user won!");
      reset();
    }
  }
  else
  {
    ui->plainTextEdit->appendPlainText("Lost");
    Logger::GetInstance().AppendLog("user is a loser");
    reset();
  }
}

void MainWindow::on_FirstButton_clicked()
{
  ui->firstRadioButton->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_SecondButton_clicked()
{
  ui->secondRadioButton->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_ThirdButton_clicked()
{
  ui->thirdRadioButton->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_FourthButton_clicked()
{
  ui->fourthRadioButton->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_pushButton_clicked()
{
  start();
  ui->firstPushButton->setEnabled(true);
  ui->secondPushButton->setEnabled(true);
  ui->thirdPushButton->setEnabled(true);
  ui->fourthPushButton->setEnabled(true);
  ui->startPushButton->setEnabled(false);

  ui->plainTextEdit->appendPlainText("New game");
  Logger::GetInstance().AppendLog("user started new game");
}
