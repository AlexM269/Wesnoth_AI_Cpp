#pragma once

#include <string>
#include <array>
#include <vector>
#include <random>
#include <iostream>

const int WON = 1;
const int LOST = -WON;

class wesnoth
{
public:

  using Move = int;

  static const int WIDTH = 7;
  static const int HEIGHT = 6;
  static const int H1 = HEIGHT + 1;
  static const int H2 = HEIGHT + 2;
  static const int SIZE = HEIGHT * WIDTH;
  static const int SIZE1 = H1 * WIDTH;
  static const uint64_t ALL1 = (1L << SIZE1) - 1L; // assumes SIZE1 < 63
  static const uint64_t COL1 = (1L << H1) - 1;
  static const uint64_t COL2 = COL1 << H1;
  static const uint64_t COL3 = COL1 << (H1 * 2);
  static const uint64_t COL4 = COL1 << (H1 * 3);
  static const uint64_t COL5 = COL1 << (H1 * 4);
  static const uint64_t COL6 = COL1 << (H1 * 5);
  static const uint64_t COL7 = COL1 << (H1 * 6);
  static const uint64_t BOTTOM = ALL1 / COL1; // has bits i*H1 set
  static const uint64_t ROW1 = BOTTOM;
  static const uint64_t ROW2 = BOTTOM << 1;
  static const uint64_t ROW3 = BOTTOM << 2;
  static const uint64_t ROW4 = BOTTOM << 3;
  static const uint64_t ROW5 = BOTTOM << 4;
  static const uint64_t ROW6 = BOTTOM << 5;

  static const uint64_t TOP = BOTTOM << HEIGHT;

  static const int CROSS = 0;
  static const int CIRCLE = 1;

private:

  std::array<uint64_t, 2> bitboards{};
// bitboard corresponds to board as follows in 7x6 case:
//  .  .  .  .  .  .  .  TOP
//  5 12 19 26 33 40 47
//  4 11 18 25 32 39 46
//  3 10 17 24 31 38 45
//  2  9 16 23 30 37 44
//  1  8 15 22 29 36 43
//  0  7 14 21 28 35 42  BOTTOM

  int nplies = 0;
  std::array<uint8_t, WIDTH> height{}; // holds bit index of lowest free square

public:

  connect4();

  inline void set(int player, int col, int row)
  {
    bitboards[player] |= 1ULL << (col * H1 + row);
    ++nplies;
  }

  inline bool get(int player, int col, int row) const
  {
    return bitboards[player] & (1ULL << (col * H1 + row));
  }

  inline int current_player() const
  {
    return nplies & 1 ? CIRCLE : CROSS;
  }

  inline int value(int player) const
  {
    if (won_by() == player) return WON;
    if (nplies == SIZE) return 0;
    return LOST;
  }

  inline int value_for_current_player() const
  {
    return value(current_player());
  }

  inline bool won(int player) const
  {
    return won_by() == player;
  }

  inline int won_by() const
  {
    if (has_won(bitboards[CROSS])) return CROSS;
    if (has_won(bitboards[CIRCLE])) return CIRCLE;
    return -1;
  }

  inline bool end_of_game() const
  {
    return nplies == SIZE || won_by() != -1;
  }

  // return whether columns col has room
  inline bool is_playable(int col) const
  {
    return (TOP & 1ULL << height[col]) == 0;
  }

  // return whether newboard includes a win
  inline bool has_won(uint64_t newboard) const
  {
    uint64_t y = newboard & (newboard >> HEIGHT);
    if ((y & (y >> 2*HEIGHT)) != 0) return true;
    y = newboard & (newboard >> H1);
    if ((y & (y >> 2*H1)) != 0) return true;
    y = newboard & (newboard >> H2);
    if ((y & (y >> 2*H2)) != 0) return true;
    y = newboard & (newboard >> 1);
    return (y & (y >> 2)) != 0;
  }

  inline void make_move(const Move& col)
  {
    bitboards[nplies & 1] |= 1ULL << height[col]++;
    ++nplies;
  }

  inline std::vector<Move> get_moves() const
  {
    std::vector<Move> res;
    for (int col = 0; col < WIDTH; ++col)
      {
        if (is_playable(col)) res.push_back(col);
      }
    return res;
  }

  void playout(std::mt19937& engine)
  {
    while (!end_of_game())
      {
        std::vector<Move> moves = get_moves();
        std::uniform_int_distribution<int> distribution(0, moves.size() - 1);
        Move move = moves[distribution(engine)];
        make_move(move);
      }
  }

  std::string player_to_string(int player) const;
  static std::string bitboard_to_string(uint64_t bitboard);
  std::string to_string() const;
};

std::ostream& operator<<(std::ostream& os, const connect4& c4);
