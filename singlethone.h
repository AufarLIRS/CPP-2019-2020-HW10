#ifndef SINGLETHONE_H
#define SINGLETHONE_H
#include <QFileInfo>
#include <QString>
#include <memory>
#include <QDebug>

using namespace std;
class GameLogger
{
  QFile* log_;
  QTextStream* textStr_;

  GameLogger()
  {
    log_ = new QFile("/home/limberjack/Desktop/cpp_homework/CPP-2019-2020-HW10/log.txt");
    qDebug() << log_->exists();
    log_->open(QIODevice::WriteOnly | QIODevice::Text);
  }

public:
  static GameLogger& getInstance()
  {
    static GameLogger a;
    return a;
  }
  void update(int i, int flag)
  {
    QString toWrite = "Player pressed button " + QString::number(i) + ".";
    if (flag == -1)
      toWrite += " Player have failed";
    else if (flag == 1)
      toWrite += " Player have won";
    *textStr_ << toWrite << endl;
  }

  GameLogger(const GameLogger&) = delete;
  GameLogger& operator=(const GameLogger&) = delete;
  GameLogger(GameLogger&&) = delete;
  GameLogger& operator=(GameLogger&&) = delete;
};

#endif  // SINGLETHONE_H
