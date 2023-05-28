#include "connect4.hpp"
#include <iostream>
#include <sstream>

using namespace std;

connect4::connect4()
{
  for (int i = 0; i < WIDTH; ++i)
    height[i] = H1 * i;
}

string connect4::player_to_string(int player) const
{
  return player == CROSS ? "X" : (player == CIRCLE ? "O" : " ");
}

string connect4::bitboard_to_string(uint64_t bitboard)
{
  stringbuf buffer;
  ostream os(&buffer);
  for (int y = HEIGHT - 1; y >= 0; --y)
    {
      for (int k = 0; k < WIDTH; ++k) os << "+-";
      os << "+" << endl;
      for (int x = 0; x < WIDTH; ++x)
        {
          os << "|" << (bitboard & (1ULL << (x * H1 + y)) ? "#" : " ");
        }
      os << "|" << endl;
    }
  for (int k = 0; k < WIDTH; ++k) os << "+-";
  os << "+" << endl;
  for (int k = 0; k < WIDTH; ++k) os << " " << k;
  os << endl;
  return buffer.str();
}

string connect4::to_string() const
{
  stringbuf buffer;
  ostream os(&buffer);
  for (int y = HEIGHT - 1; y >= 0; --y)
    {
      for (int k = 0; k < WIDTH; ++k) os << "+-";
      os << "+" << endl;
      for (int x = 0; x < WIDTH; ++x)
        {
          os << "|" << (get(CROSS, x, y) ? player_to_string(CROSS) :
                        get(CIRCLE, x, y) ? player_to_string(CIRCLE) : " ");
        }
      os << "|" << endl;
    }
  for (int k = 0; k < WIDTH; ++k) os << "+-";
  os << "+" << endl;
  for (int k = 0; k < WIDTH; ++k) os << " " << k;
  os << endl;
  return buffer.str();
}

ostream& operator<<(ostream& os, const connect4& c4)
{
  os << c4.to_string();
  return os;
}
