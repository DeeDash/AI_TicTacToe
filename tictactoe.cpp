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

std::vector<std::pair<int, int>> TicTacToe::get_legal_moves(char board[3][3]) {

}

bool TicTacToe::position_occupied(char board[3][3], std::pair<int, int> pos) {

}

std::vector<std::pair<int, int>> TicTacToe::get_occupied_positions(char board[3][3], char marker) {

}

bool TicTacToe::board_is_full(char board[3][3]){

}

bool TicTacToe::game_is_won(std::vector<std::pair<int, int>> occupied_positions){

}

char TicTacToe::get_opponent_marker(char marker){

}

int TicTacToe::get_board_state(char board[3][3], char marker){

}

std::pair<int, std::pair<int, int>> TicTacToe::minimax_optimization(char board[3][3], char marker, int depth,  int alpha, int beta){

}

bool TicTacToe::game_is_done(char board[3][3]){

}

void TicTacToe::game(){

}
