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

<<<<<<< HEAD
  std::vector<int> numbers_;
  int current_;
=======
  std::vector<int> nums_;
  int temp_;
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871

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
<<<<<<< HEAD

  bool checkNumber(int button);

  bool checkWin();

  void start();
=======
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871

private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
