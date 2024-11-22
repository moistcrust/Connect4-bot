#include "bot.h"

int bot::getBestMove(std::vector<std::vector<Player>>& board, int depth) {
    int bestMove = -1;
    int maxEval = INT_MIN;

    for (int c = 0; c < COLS; c++) {
        if (board[0][c] == Player::None) {
            int cur;
            for (cur = ROWS - 1; cur >= 0 && board[cur][c] != Player::None; cur--) {}

            board[cur][c] = Player::Yellow;
            int eval = min_max(board, depth - 1, INT_MIN, INT_MAX, false);
            board[cur][c] = Player::None;

            if (eval > maxEval) {
                maxEval = eval;
                bestMove = c;
            }
        }
    }
    return bestMove;
}

int bot::min_max(std::vector<std::vector<Player>>& board, int depth, int alpha, int beta, bool forPlayer) {
    if (checkWin(board, Player::Yellow)) {
        return 1000 - depth;
    }
    if (checkWin(board, Player::Red)) {
        return -1000 + depth;
    }
    if (depth == 0) {
        return 0;
    }

    if (forPlayer) {
        int maxEval = INT_MIN;

        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == Player::None) {
                int cur;
                for (cur = ROWS - 1; cur >= 0 && board[cur][c] != Player::None; cur--) {}

                board[cur][c] = Player::Yellow;
                int eval = min_max(board, depth - 1, alpha, beta, false);
                board[cur][c] = Player::None;

                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);

                if (beta <= alpha) {
                    break;
                }
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;

        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == Player::None) {
                int cur;
                for (cur = ROWS - 1; cur >= 0 && board[cur][c] != Player::None; cur--) {}

                board[cur][c] = Player::Red;
                int eval = min_max(board, depth - 1, alpha, beta, true);
                board[cur][c] = Player::None;

                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);

                if (beta <= alpha) {
                    break;
                }
            }
        }
        return minEval;
    }
}
