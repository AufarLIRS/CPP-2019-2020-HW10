#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <iostream>
#include <QDebug>
#include <QFile>

class Logger
{
public:
  static Logger& getInstance()
  {
    static Logger l;
    return l;
  }

  QFile file;

  void appendLog(QByteArray data);

private:
  Logger();
  ~Logger();

  Logger(Logger const&) = delete;
  Logger& operator=(Logger const&) = delete;
};

#endif
