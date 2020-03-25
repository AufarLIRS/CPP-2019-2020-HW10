#ifndef GAME_H
#define GAME_H

#include <QDebug>
#include <QApplication>
#include <QProcess>

#include <cstdlib>
#include <random>
#include <time.h>
#include <logger.h>

class Game
{
  static QVector<int> numbers_;
  static int current_;

public:
  static void generateNumbers();
  static bool checkNumber(int button);
  static bool checkWin();
  static void start();
};

#endif  // GAME_H
