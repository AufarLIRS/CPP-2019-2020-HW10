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
  Logger(){};
  ~Logger(){};

  Logger(Logger const&) = delete;
  Logger& operator=(Logger const&) = delete;

public:
  static Logger& Instance()
  {
    static Logger l;
    return l;
  }

  QFile file_;

  static void log(QByteArray data);
};

#endif  // LOGGER_H
