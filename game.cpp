#include "game.h"

QVector<int> Game::numbers_ = QVector<int>();
int Game::current_;

void Game::generateNumbers()
{
  current_ = 0;
  std::random_device device;
  std::mt19937 algo(device());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1, 4);

  while (numbers_.length() < 4)
  {
    int x = dist(algo);
    if (!numbers_.contains(x))
    {
      numbers_.push_back(x);
    }
  }

  QByteArray nums = "";
  for (auto n : numbers_)
  {
    nums += n;
  }
  qDebug() << numbers_[0] << numbers_[1] << numbers_[2] << numbers_[3];
  Logger::log(nums);
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
