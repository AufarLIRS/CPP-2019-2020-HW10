#include "logger.h"

void Logger::appendLog(QByteArray string)
{
  file.setFileName("output.txt");
  if (file.open(QIODevice::WriteOnly))
  {
    file.write(string + "\n");
    file.close();
  }
}
