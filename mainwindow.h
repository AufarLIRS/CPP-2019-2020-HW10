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

class MainWindow : public QMainWindow
{
  Q_OBJECT

  std::vector<int> numbers_;
  int current_;

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:

  void checkButton(int buttonId);

  void on_FirstButton_clicked();

  void on_SecondButton_clicked();

  void on_ThirdButton_clicked();

  void on_FourthButton_clicked();

  void on_pushButton_clicked();

  void reset();

  void generate();

  bool checkNumber(int button);

  bool checkWin();

  void start();

private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
