#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

#include <iostream>
#include <fstream>
#include <string>

class Logger
{
private:
  static Logger* l_instance;
  Logger(){};
  Logger(const Logger&);
  Logger& operator=(Logger&);

public:
  static Logger* getInstance()
  {
    if (!l_instance)
      l_instance = new Logger();
    return l_instance;
  }

  static std::ofstream file_;

  static void write(std::string data);
  static void close();
};

#endif  // LOGGER_H
