#include "logger.h"

Logger& instance = Logger::Instance();

void Logger::log(QByteArray data)
{
  instance.file_.setFileName("logger.txt");
  if (instance.file_.open(QIODevice::WriteOnly))
  {
    instance.file_.write(data + "\n");
    instance.file_.close();
  }
}
