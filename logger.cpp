#include "logger.h"

<<<<<<< HEAD
void Logger::AppendLog(QByteArray string)
{
  file.write(string + "\n");
=======
void Logger::appendLog(QByteArray string)
{
  file.setFileName("output.txt");
  if (file.open(QIODevice::WriteOnly))
  {
    file.write(string + "\n");
    file.close();
  }
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
}
