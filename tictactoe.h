#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private:
    Ui::TicTacToe *ui;

private slots:
    void print_game_state(int state);
    std::vector<std::pair<int, int>> get_legal_moves(char board[3][3]);
    bool position_occupied(char board[3][3], std::pair<int, int> pos);
    std::vector<std::pair<int, int>> get_occupied_positions(char board[3][3], char marker);
    bool board_is_full(char board[3][3]);
    bool game_is_won(std::vector<std::pair<int, int>> occupied_positions);
    char get_opponent_marker(char marker);
    int get_board_state(char board[3][3], char marker);
    std::pair<int, std::pair<int, int>> minimax_optimization(char board[3][3], char marker, int depth,  int alpha, int beta);
    bool game_is_done(char board[3][3]);
    void game();
};
#endif // TICTACTOE_H
