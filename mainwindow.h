#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

enum class Color
{
  Red = 0,
  Blue,
  Yellow,
  Green
};

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void on_RedPushButton_clicked();

  void on_BluePushButton_clicked();

  void on_YellowPushButton_clicked();

  void on_GreenPushButton_clicked();

  void on_pushButton_clicked();

  void ChangeFrameColor(Color color);

  void CorrectOrderCheck(Color color);

private:
  std::vector<Color> order{ Color::Red, Color::Blue, Color::Yellow, Color::Green };
  size_t checkIndex;
  bool isStarted = false;
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
