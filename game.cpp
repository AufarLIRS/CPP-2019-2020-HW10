#include "game.h"

QVector<int> Game::numbers_ = QVector<int>();
int Game::current_;

void Game::generateNumbers()
{
  current_ = 0;
  QVector<int> vec;
  for (int i = 0; i < 4; i++)
  {
    srand(time(nullptr));
    while (vec.length() < 4)
    {
      int x = rand() % 4 + 1;
      if (vec.contains(x))
      {
        continue;
      }
      else
      {
        vec.push_back(x);
      }
    }
  }
  numbers_ = vec;
  std::string nums = "";
  for (auto n : numbers_)
  {
    nums += n;
  }
  qDebug() << numbers_[0] << numbers_[1] << numbers_[2] << numbers_[3];
  Logger::write(nums);
}

bool Game::checkNumber(int button)
{
  return (button == numbers_[current_]);
}

bool Game::checkWin()
{
  if (current_ == 3)
  {
    return true;
  }
  else
  {
    current_++;
    return false;
  }
}

void Game::start()
{
  numbers_.clear();
  generateNumbers();
}
