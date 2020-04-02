#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  int combination[4] = { 1, 2, 3, 4 };
  int counter = 0;
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void on_radioButton_clicked();
  void on_radioButton_2_clicked();
  void on_radioButton_3_clicked();
  void on_radioButton_4_clicked();

private:
  void dropRadioButtons();
  void update(int i);
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
