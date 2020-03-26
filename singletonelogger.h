#ifndef SINGLETONELOGGER_H
#define SINGLETONELOGGER_H

#include <memory>
#include "QFileInfo"
#include <QDebug>

class SingletoneLogger
{
  QFile file;
  std::unique_ptr<QTextStream> stream;

  SingletoneLogger();

  ~SingletoneLogger();

public:
  static SingletoneLogger& GetInstance();

  void AppendLog(QString string);

  SingletoneLogger(const SingletoneLogger&) = delete;
  SingletoneLogger& operator=(const SingletoneLogger&) = delete;

  SingletoneLogger(SingletoneLogger&&) = delete;
  SingletoneLogger& operator=(SingletoneLogger&&) = delete;
};

#endif  // SINGLETONELOGGER_H
