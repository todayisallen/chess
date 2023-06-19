#include <cstdlib>
#include "../state/state.hpp"
#include"ab.hpp"
#include<climits>
using namespace std;

//https://www.chessprogramming.org/Alpha-Beta
int AB::minn(State* state, int depth, int a, int b){
    if(depth == 0) return state->evaluate();
    state->get_legal_actions();
    for(auto it : state->legal_actions){
        State* next_state = state->next_state(it);
        int val = maxx(next_state, depth - 1, a, b);
        if(val <= a) return a;
        if(val < b) b = val;
    }
    return b;
    
}
int AB::maxx(State* state, int depth, int a, int b){
    if(depth == 0) return state->evaluate();
    
    state->get_legal_actions();
    for(auto it : state->legal_actions){
        State* next_state = state->next_state(it);
        int val = minn(next_state, depth - 1, a, b);
        if(val >= b) return b;
        if(val > a) a = val;
    }
    return a;
}
Move AB::get_move(State *state, int depth){
    if(!state->legal_actions.size())
        state->get_legal_actions();
    
    Move best;
    int max = INT_MIN;
    auto actions = state->legal_actions;
    for(auto it : actions){
        State* n_state = state->next_state(it);
        n_state->get_legal_actions();
        int val = minn(n_state, depth - 1, INT_MIN, INT_MAX);
        if(val > max){
            max = val;
            best = it;
        }

    }
    return best;
}