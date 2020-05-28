#ifndef GAMEGEN_H
#define GAMEGEN_H

#include <QDebug>
#include <QApplication>
#include <QProcess>

#include <cstdlib>
#include <random>
#include <algorithm>
#include <time.h>
#include <log.h>
#include <vector>

class GameGen
{
  static std::vector<int> numbers_;
  static int current_;

public:
  static void NumbersGen();
  static bool Check(int button);
  static bool IfWin();
  static void Restart();
};

#endif  // GAMEGEN_H
