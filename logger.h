#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

#include <iostream>
#include <fstream>
#include <string>
#include <QFile>

class Logger
{
  Logger(Logger const&) = delete;
  Logger& operator=(Logger const&) = delete;

public:
  QFile file;

  Logger()
  {
    file.setFileName("output.txt");
    file.open(QIODevice::WriteOnly);
    qDebug() << "logger was created";
  };

  ~Logger()
  {
    file.close();
    qDebug() << "logger was destroyed";
  };

  static Logger& getInstance()
  {
    static Logger l;
    return l;
  }

  void AppendLog(QByteArray data);
};

#endif  // LOGGER_H
