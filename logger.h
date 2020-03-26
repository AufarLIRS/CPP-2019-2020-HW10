#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

#include <iostream>
#include <fstream>
#include <string>
#include <QFile>

class Logger
{
private:
  Logger()
  {
    qDebug() << "logger was created";
  };
  ~Logger()
  {
    qDebug() << "logger was destroyed";
  };

  Logger(Logger const&) = delete;
  Logger& operator=(Logger const&) = delete;

public:
  static Logger& getInstance()
  {
    static Logger l;
    return l;
  }

  QFile file_;

  void log(QByteArray data);
};

#endif  // LOGGER_H
