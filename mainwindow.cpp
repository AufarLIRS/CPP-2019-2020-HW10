#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <singlethone.h>

void MainWindow::update(int i)
{
  if (i == this->combination[counter])
  {
    if (counter != 3)
    {
      GameLogger::getInstance().update(i, 0);
      counter++;
      return;
    }
    GameLogger::getInstance().update(i, 1);
    ui->label_5->setText("VICTORY");
    dropRadioButtons();
    return;
  }

  GameLogger::getInstance().update(i, -1);
  ui->label_5->setText("NOPE");
  dropRadioButtons();
}

void MainWindow::dropRadioButtons()
{
  ui->radioButton->setChecked(false);
  ui->radioButton_2->setChecked(false);
  ui->radioButton_3->setChecked(false);
  ui->radioButton_3->setChecked(false);
  ui->radioButton_4->setChecked(false);
  counter = 0;
}

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_radioButton_clicked()
{
  update(1);
}

void MainWindow::on_radioButton_2_clicked()
{
  update(2);
}

void MainWindow::on_radioButton_3_clicked()
{
  update(3);
}
void MainWindow::on_radioButton_4_clicked()
{
  update(4);
}
