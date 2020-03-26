#include "logger.h"

Logger& instance = Logger::Instance();
QFile Logger::file_;

void Logger::log(QByteArray data)
{
  file_.setFileName("logger.txt");
  if (file_.open(QIODevice::WriteOnly))
  {
    file_.write(data + "\n");
    file_.close();
  }
}
