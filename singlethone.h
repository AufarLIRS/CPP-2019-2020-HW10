#ifndef SINGLETHONE_H
#define SINGLETHONE_H
#include <stdio.h>
#include <QString>
#include <QDebug>
#include <iostream>

using namespace std;
class GameLogger
{
  GameLogger()
  {
    freopen("log.txt", "w", stdout);
  }
  ~GameLogger()
  {
    fclose(stdout);
  }

public:
  static GameLogger& getInstance()
  {
    static GameLogger a;
    return a;
  }
  void static update(int i, int flag)
  {
    QString toWrite = "Player pressed button " + QString::number(i) + ".";
    if (flag == -1)
      toWrite += " Player have failed";
    else if (flag == 1)
      toWrite += " Player have won";
    cout << toWrite.toStdString() << endl;
  }

  GameLogger(const GameLogger&) = delete;
  GameLogger& operator=(const GameLogger&) = delete;
  GameLogger(GameLogger&&) = delete;
  GameLogger& operator=(GameLogger&&) = delete;
};

#endif  // SINGLETHONE_H
