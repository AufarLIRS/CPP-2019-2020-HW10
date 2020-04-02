#include "mainwindow.h"

#include <QApplication>
#include <singlethone.h>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  // GameLogger::getInstance().update(1, 1);
  w.show();
  return a.exec();
}
