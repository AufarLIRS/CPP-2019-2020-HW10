#include "singletonelogger.h"

SingletoneLogger::SingletoneLogger() : file("D:/Projects/QT/CPP-2019-2020-HW10/log.txt")
{
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  stream = std::make_unique<QTextStream>(&file);
}

SingletoneLogger::~SingletoneLogger()
{
  file.close();
}

SingletoneLogger& SingletoneLogger::GetInstance()
{
  static SingletoneLogger logger;
  return logger;
}

void SingletoneLogger::AppendLog(QString string)
{
  *stream << string << endl;
}
