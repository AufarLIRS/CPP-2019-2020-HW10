#include "log.h"

Log::Log()
{
  file.setFileName("GameLog.txt");
  file.open(QIODevice::WriteOnly);
}

Log::~Log()
{
  file.close();
}

Log& Log::GetInstance()
{
  static Log log;
  return log;
}

void Log::AppendLog(QByteArray string)
{
  file.write(string + "\n");
}
