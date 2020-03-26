#include "game.h"

std::vector<int> Game::numbers_;
int Game::current_;

void Game::generateNumbers()
{
  current_ = 0;

  numbers_ = std::vector{ 1, 2, 3, 4 };

  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(numbers_), std::end(numbers_), rng);

  QByteArray nums = "";
  for (auto n : numbers_)
  {
    nums += n;
  }
  qDebug() << numbers_[0] << numbers_[1] << numbers_[2] << numbers_[3];
  Logger::getInstance().log(nums);
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
