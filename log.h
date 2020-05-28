#ifndef LOG_H
#define LOG_H

#include "QFileInfo"
#include <QDebug>

class Log
{
  QFile file;

  Log();
  ~Log();

public:
  static Log& GetInstance();
  void AppendLog(QByteArray string);

  Log(const Log&) = delete;
  Log& operator=(const Log&) = delete;

  Log(Log&&) = delete;
  Log& operator=(Log&&) = delete;
};

#endif  // LOG_H
