#include "gamegen.h"

std::vector<int> GameGen::numbers_;
int GameGen::current_;

void GameGen::NumbersGen()
{
  current_ = 0;
  numbers_ = std::vector<int>{ 1, 2, 3, 4 };
  std::random_shuffle(std::begin(numbers_), std::end(numbers_));

  QByteArray nums = "";
  for (auto n : numbers_)
  {
    nums += n;
  }

  qDebug() << "Победная комбинация:" << numbers_[0] << numbers_[1] << numbers_[2] << numbers_[3];
  Log::GetInstance().AppendLog("Победная комбинация:" + nums);
}

bool GameGen::Check(int button)
{
  return (button == numbers_[current_]);
}

bool GameGen::IfWin()
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

void GameGen::Restart()
{
  numbers_.clear();
  NumbersGen();
}
