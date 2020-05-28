#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "log.h"
#include "gamegen.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::Reset()
{
  ui->StartResetPushButton->setEnabled(true);
  ui->OneRadioButton->setEnabled(false);
  ui->TwoRadioButton->setEnabled(false);
  ui->ThreeRadioButton->setEnabled(false);
  ui->FourRadioButton->setEnabled(false);
}

void MainWindow::CheckButtons(int buttonId)
{
  int button = 0;
  switch (buttonId)
  {
    case -3:
      button = 1;
      break;
    case -4:
      button = 2;
      break;
    case -2:
      button = 3;
      break;
    case -5:
      button = 4;
      break;
  }

  if (GameGen::Check(button))
  {
    switch (button)
    {
      case 1:
        ui->PlainTextEdit->appendPlainText("'1' is correct");
        Log::GetInstance().AppendLog("Player pressed '1'");
        break;
      case 2:
        ui->PlainTextEdit->appendPlainText("'2' is correct");
        Log::GetInstance().AppendLog("Player pressed '2'");
        break;
      case 3:
        ui->PlainTextEdit->appendPlainText("'3' is correct");
        Log::GetInstance().AppendLog("Player pressed '3'");
        break;
      case 4:
        ui->PlainTextEdit->appendPlainText("'4' is correct");
        Log::GetInstance().AppendLog("Player pressed '4'");
        break;
    }

    if (GameGen::IfWin())
    {
      ui->PlainTextEdit->appendPlainText("Win!");
      Log::GetInstance().AppendLog("Player wins the game");
      Reset();
    }
  }
  else
  {
    ui->PlainTextEdit->appendPlainText("Try again!");
    Log::GetInstance().AppendLog("Player looses the game");
    Reset();
  }
}

void MainWindow::on_OnePushButton_clicked()
{
  ui->OneRadioButton->setChecked(true);
  CheckButtons(ui->buttonGroup->checkedId());
}

void MainWindow::on_TwoPushButton_clicked()
{
  ui->TwoRadioButton->setChecked(true);
  CheckButtons(ui->buttonGroup->checkedId());
}

void MainWindow::on_ThreePushButton_clicked()
{
  ui->ThreeRadioButton->setChecked(true);
  CheckButtons(ui->buttonGroup->checkedId());
}

void MainWindow::on_FourPushButton_clicked()
{
  ui->FourRadioButton->setChecked(true);
  CheckButtons(ui->buttonGroup->checkedId());
}

void MainWindow::on_StartResetPushButton_clicked()
{
  GameGen::Restart();
  ui->OnePushButton->setEnabled(true);
  ui->TwoPushButton->setEnabled(true);
  ui->ThreePushButton->setEnabled(true);
  ui->FourPushButton->setEnabled(true);
  ui->StartResetPushButton->setEnabled(false);

  ui->PlainTextEdit->appendPlainText("New game");
  Log::GetInstance().AppendLog("New game");
}
