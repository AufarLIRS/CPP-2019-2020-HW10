#include "logger.h"

void Logger::log(QByteArray data)
{
  Logger& logger = Logger::getInstance();
  logger.file_.setFileName("logger.txt");
  if (logger.file_.open(QIODevice::WriteOnly))
  {
    logger.file_.write(data + "\n");
    logger.file_.close();
  }
}
