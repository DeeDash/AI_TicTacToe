#include "tictactoe.h"
#include "ui_tictactoe.h"

using std::cin;
using std::cout;
using std::endl;

#define WIN 1000
#define DRAW 0
#define LOSS -1000

#define AI_MARKER 'O'
#define PLAYER_MARKER 'X'
#define EMPTY_SPACE '-'

#define START_DEPTH 0

std::vector<std::vector<std::pair<int, int>>> winning_states{
    // Every row
    {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)},
    {std::make_pair(1, 0), std::make_pair(1, 1), std::make_pair(1, 2)},
    {std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2)},

    // Every column
    {std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0)},
    {std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(2, 1)},
    {std::make_pair(0, 2), std::make_pair(1, 2), std::make_pair(2, 2)},

    // Every diagonal
    {std::make_pair(0, 0), std::make_pair(1, 1), std::make_pair(2, 2)},
    {std::make_pair(2, 0), std::make_pair(1, 1), std::make_pair(0, 2)}

};

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::print_game_state(int state) {
    if (WIN == state) {
        ui->Display->setText("WIN");
    } else if (DRAW == state) {
        ui->Display->setText("DRAW");
    } else if (LOSS == state) {
        ui->Display->setText("LOSS");
    }
}

void TicTacToe::print_board(char board[3][3]) {
    QPushButton *Buttons[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QString butName = "Button" + QString::number(i) + QString::number(j);
            Buttons[i][j] = TicTacToe::findChild<QPushButton *>(butName);
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Buttons[i][j]->setText(QChar(board[i][j]));
        }
    }
}

std::vector<std::pair<int, int>> TicTacToe::get_legal_moves(char board[3][3]) {
    std::vector<std::pair<int, int>> legal_moves;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != AI_MARKER && board[i][j] != PLAYER_MARKER) {
                legal_moves.push_back(std::make_pair(i, j));
            }
        }
    }
    return legal_moves;
}

bool TicTacToe::position_occupied(char board[3][3], std::pair<int, int> pos) {
    std::vector<std::pair<int, int>> legal_moves = get_legal_moves(board);

    for (int i = 0; i < legal_moves.size(); i++) {
        if (pos.first == legal_moves[i].first &&
            pos.second == legal_moves[i].second) {
            return false;
        }
    }

    return true;
}

std::vector<std::pair<int, int>> TicTacToe::get_occupied_positions(char board[3][3], char marker) {
    std::vector<std::pair<int, int>> occupied_positions;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (marker == board[i][j]) {
                occupied_positions.push_back(std::make_pair(i, j));
            }
        }
    }

    return occupied_positions;
}

bool TicTacToe::board_is_full(char board[3][3]){
    std::vector<std::pair<int, int>> legal_moves = get_legal_moves(board);

    if (0 == legal_moves.size()) {
        return true;
    } else {
        return false;
    }
}

bool TicTacToe::game_is_won(std::vector<std::pair<int, int>> occupied_positions){
    bool game_won;

    for (int i = 0; i < winning_states.size(); i++) {
        game_won = true;
        std::vector<std::pair<int, int>> curr_win_state = winning_states[i];
        for (int j = 0; j < 3; j++) {
            if (!(std::find(std::begin(occupied_positions),
                            std::end(occupied_positions), curr_win_state[j]) !=
                  std::end(occupied_positions))) {
                game_won = false;
                break;
            }
        }

        if (game_won) {
            break;
        }
    }
    return game_won;
}

char TicTacToe::get_opponent_marker(char marker){
    char opponent_marker;
    if (marker == PLAYER_MARKER) {
        opponent_marker = AI_MARKER;
    } else {
        opponent_marker = PLAYER_MARKER;
    }

    return opponent_marker;
}

int TicTacToe::get_board_state(char board[3][3], char marker){
    char opponent_marker = get_opponent_marker(marker);

    std::vector<std::pair<int, int>> occupied_positions =
        get_occupied_positions(board, marker);

    bool is_won = game_is_won(occupied_positions);

    if (is_won) {
        return WIN;
    }

    occupied_positions = get_occupied_positions(board, opponent_marker);
    bool is_lost = game_is_won(occupied_positions);

    if (is_lost) {
        return LOSS;
    }

    bool is_full = board_is_full(board);
    if (is_full) {
        return DRAW;
    }

    return DRAW;
}

std::pair<int, std::pair<int, int>> TicTacToe::minimax_optimization(char board[3][3], char marker, int depth,  int alpha, int beta){

}

bool TicTacToe::game_is_done(char board[3][3]){

}

void TicTacToe::game(){

}
