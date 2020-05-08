#include "logger.h"

void Logger::AppendLog(QByteArray string)
{
  file.write(string + "\n");
}
