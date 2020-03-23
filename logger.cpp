#include "logger.h"

Logger* getInstance();
std::ofstream Logger::file_;

void Logger::write(std::string data)
{
  file_.open("logger.txt", std::ios::app);
  if (file_)
  {
    qDebug() << "file was opened";
    file_ << data;
  }
  else
  {
    qDebug() << "ERROR";
  }
  close();
}

void Logger::close()
{
  file_.close();
  qDebug() << "file was closed";
}
