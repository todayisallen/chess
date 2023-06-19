#pragma once
#include "../state/state.hpp"


/*
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class MiniMax{
public:
  static Move get_move(State *state, int depth);
  static int maxx(State* state, int depth);
  static int minn(State* state, int depth);
};