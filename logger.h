#ifndef LOGGER_H
#define LOGGER_H

<<<<<<< HEAD
#include <QDebug>

#include <iostream>
#include <fstream>
#include <string>
=======
#include <memory>
#include <iostream>
#include <QDebug>
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
#include <QFile>

class Logger
{
<<<<<<< HEAD
  Logger(Logger const&) = delete;
  Logger& operator=(Logger const&) = delete;

public:
  QFile file;

  Logger()
  {
    file.setFileName("output.txt");
    file.open(QIODevice::WriteOnly);
    qDebug() << "logger was created";
  };

  ~Logger()
  {
    file.close();
    qDebug() << "logger was destroyed";
  };

=======
public:
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
  static Logger& getInstance()
  {
    static Logger l;
    return l;
  }

<<<<<<< HEAD
  void AppendLog(QByteArray data);
};

#endif  // LOGGER_H
=======
  QFile file;

  void appendLog(QByteArray data);

private:
  Logger();
  ~Logger();

  Logger(Logger const&) = delete;
  Logger& operator=(Logger const&) = delete;
};

#endif
>>>>>>> b69f2f7c3969cf53edd52ca79dca7984b05b1871
