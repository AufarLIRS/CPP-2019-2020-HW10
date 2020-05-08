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
<<<<<<< HEAD
  ui->radioButton->setChecked(true);
=======
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
  ui->firstPushButton->setEnabled(false);
  ui->secondPushButton->setEnabled(false);
  ui->thirdPushButton->setEnabled(false);
  ui->fourthPushButton->setEnabled(false);
}

void MainWindow::generate()
{
<<<<<<< HEAD
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
=======
  temp_ = 0;
  nums_ = std::vector{ 1, 2, 3, 4 };

  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(nums_), std::end(nums_), rng);

  QByteArray nums = "";
  for (auto n : nums_)
  {
    nums += n;
  }
  qDebug() << nums_[0] << nums_[1] << nums_[2] << nums_[3];
  Logger::getInstance().appendLog(nums);
}

void MainWindow::checkButton(int Id)
{
  int button;
  switch (Id)
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
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

<<<<<<< HEAD
  if (checkNumber(button))
=======
  if (button == nums_[temp_])
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
  {
    switch (button)
    {
      case 1:
<<<<<<< HEAD
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
=======
        Logger::getInstance().appendLog("First button pressed");
        break;
      case 2:
        Logger::getInstance().appendLog("Second button pressed");
        break;
      case 3:
        Logger::getInstance().appendLog("Third button pressed");
        break;
      case 4:
        Logger::getInstance().appendLog("Fourth button pressed");
        break;
    }
    if (temp_ == 3)
    {
      Logger::getInstance().appendLog("Flawless Victory");
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
      reset();
    }
  }
  else
  {
<<<<<<< HEAD
    ui->plainTextEdit->appendPlainText("Lost");
    Logger::GetInstance().AppendLog("user is a loser");
=======
    Logger::getInstance().appendLog("Defeat");
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
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
<<<<<<< HEAD
  start();
=======
  nums_.clear();
  generate();
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
  ui->firstPushButton->setEnabled(true);
  ui->secondPushButton->setEnabled(true);
  ui->thirdPushButton->setEnabled(true);
  ui->fourthPushButton->setEnabled(true);
  ui->startPushButton->setEnabled(false);
<<<<<<< HEAD

  ui->plainTextEdit->appendPlainText("New game");
  Logger::GetInstance().AppendLog("user started new game");
=======
  Logger::getInstance().appendLog("New game started");
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
}
