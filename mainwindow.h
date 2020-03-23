#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <game.h>
#include <logger.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void checkButton(int buttonId);

  void reset();

  void on_firstPushButton_clicked();

  void on_secondPushButton_clicked();

  void on_thirdPushButton_clicked();

  void on_fourthPushButton_clicked();

  void on_startPushButton_clicked();

  void on_plainTextEdit_textChanged();

private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
