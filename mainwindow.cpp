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
  ui->firstPushButton->setEnabled(false);
  ui->secondPushButton->setEnabled(false);
  ui->thirdPushButton->setEnabled(false);
  ui->fourthPushButton->setEnabled(false);
}

void MainWindow::generate()
{
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

  if (button == nums_[temp_])
  {
    switch (button)
    {
      case 1:
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
      reset();
    }
  }
  else
  {
    Logger::getInstance().appendLog("Defeat");
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
  nums_.clear();
  generate();
  ui->firstPushButton->setEnabled(true);
  ui->secondPushButton->setEnabled(true);
  ui->thirdPushButton->setEnabled(true);
  ui->fourthPushButton->setEnabled(true);
  ui->startPushButton->setEnabled(false);
  Logger::getInstance().appendLog("New game started");
}
