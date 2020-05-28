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
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void Reset();

  void CheckButtons(int buttonId);

  void on_OnePushButton_clicked();

  void on_TwoPushButton_clicked();

  void on_ThreePushButton_clicked();

  void on_FourPushButton_clicked();

  void on_StartResetPushButton_clicked();

private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
