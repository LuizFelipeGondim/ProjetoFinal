#include "Game.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Game::Game(int rows, int cols) : _defaultRows(rows+1), _defaultCols(2*cols+2){
    _board.resize(_defaultRows, vector<string>(_defaultCols));

    for(int i = 0; i < _defaultCols; i++){
        if(i == 0 || i % 2 == 1){
            _board[0][i] = " ";  
        }else{
            _board[0][i] = to_string(i/2);
        }
    }

    for(int i = 1; i < _defaultRows; i++){
        for(int j = 0; j < _defaultCols; j++){
            if(j == 0){
                _board[i][j] = to_string(i);
            }else if(j % 2 == 1){
                _board[i][j] = "|";    
            }else{
                _board[i][j] = " ";
            }  
        }  
    }
    _board[(_defaultRows-1)/2][(_defaultCols-2)/2] = "X";
    _board[(_defaultRows-1)/2 + 1][(_defaultCols-2)/2] = "O";
    _board[(_defaultRows-1)/2][(_defaultCols + 2)/2] = "O";
    _board[(_defaultRows-1)/2 + 1][(_defaultCols + 2)/2] = "X";
}

void Game::printBoard(){
    #if (defined(_WIN32) || defined(_WIN64))
         system("cls");
    #else
        system("clear");
    #endif

    for(int i = 0; i < _defaultRows; ++i) {
        for(int j = 0; j < _defaultCols; ++j) {
            cout << _board[i][j] << " ";
        }
        cout << endl;
    }
}

