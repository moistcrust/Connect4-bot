#ifndef BOT_H
#define BOT_H
#include <utility>
#include <vector>
#include "game.h"


class bot {
public:
    int getBestMove(std::vector<std::vector<Player>>& board, int depth);
    int min_max(std::vector<std::vector<Player>> &board, int depth, int alpha, int beta,bool forPlayer);
};



#endif //BOT_H
