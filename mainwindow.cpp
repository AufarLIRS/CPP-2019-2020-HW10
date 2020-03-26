#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singletonelogger.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_RedPushButton_clicked()
{
  SingletoneLogger::GetInstance().AppendLog("RedPushButton is clicked");
  CorrectOrderCheck(Color::Red);
}

void MainWindow::on_BluePushButton_clicked()
{
  SingletoneLogger::GetInstance().AppendLog("BluePushButton is clicked");
  CorrectOrderCheck(Color::Blue);
}

void MainWindow::on_YellowPushButton_clicked()
{
  SingletoneLogger::GetInstance().AppendLog("YellowPushButton is clicked");
  CorrectOrderCheck(Color::Yellow);
}

void MainWindow::on_GreenPushButton_clicked()
{
  SingletoneLogger::GetInstance().AppendLog("GreenPushButton is clicked");
  CorrectOrderCheck(Color::Green);
}

void MainWindow::on_pushButton_clicked()
{
  ui->pushButton->setEnabled(false);
  checkIndex = 0;
  isStarted = true;
  ui->LogLabel->setText("Click color buttons in the right order!");

  std::random_shuffle(order.begin(), order.end());
  size_t sec = 1000;
  for (auto const& e : order)
  {
    QTimer::singleShot(sec, this, [=] { ChangeFrameColor(e); });
    sec += 1000;
  }
  QTimer::singleShot(5000, this, [=] {
    ui->ColorFrame->setStyleSheet("background-color: transparent");
    ui->pushButton->setEnabled(true);
  });
}

void MainWindow::ChangeFrameColor(Color color)
{
  switch (color)
  {
    case Color::Red:
      ui->ColorFrame->setStyleSheet("background-color:red; border: 3px solid gray");
      break;
    case Color::Blue:
      ui->ColorFrame->setStyleSheet("background-color:blue; border: 3px solid gray");
      break;
    case Color::Yellow:
      ui->ColorFrame->setStyleSheet("background-color:yellow; border: 3px solid gray");
      break;
    case Color::Green:
      ui->ColorFrame->setStyleSheet("background-color:green; border: 3px solid gray");
      break;
  }
}

void MainWindow::CorrectOrderCheck(Color color)
{
  if (isStarted)
  {
    if (order.at(checkIndex) != color)
    {
      SingletoneLogger::GetInstance().AppendLog("You lose!");
      ui->LogLabel->setText("You lose!");
      isStarted = false;
    }
    else if (checkIndex == 3)
    {
      SingletoneLogger::GetInstance().AppendLog("You win!");
      ui->LogLabel->setText("You win!");
      isStarted = false;
    }
    checkIndex++;
  }
  else
    ui->LogLabel->setText("Click the Start button!");
}
