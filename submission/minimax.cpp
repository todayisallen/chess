#include <cstdlib>
#include "../state/state.hpp"
#include"minimax.hpp"
#include<climits>
using namespace std;


Move MiniMax::get_move(State *state, int depth){
    if(!state->legal_actions.size())
        state->get_legal_actions();
    
    Move best;
    int max = INT_MIN;
    auto actions = state->legal_actions;
    for(auto it : actions){
        State* next_state = state->next_state(it);
        next_state->get_legal_actions();
        int val = minn(next_state, depth - 1);
        if(val > max){
            max = val;
            best = it;
        }

    }
    return best;
}


//https://www.chessprogramming.org/Minimax
int MiniMax::maxx(State *state, int depth){
    if(depth == 0) return state->evaluate();
    int val = INT_MIN;
    state->get_legal_actions();
    
    auto actions = state->legal_actions;
    for(auto it: actions){
        State* next_state = state->next_state(it);
        val = std::max(val, minn(next_state, depth - 1));
    }
    return val;
}

int MiniMax::minn(State *state, int depth){
    if (depth == 0) return state->evaluate()*(-1);
    int val = INT_MAX;
    state->get_legal_actions();

    auto actions = state->legal_actions;
    for(auto it: actions){
        State* next_state = state->next_state(it);
        val = std::min(val, maxx(next_state, depth - 1));
    }
    return val;
}
