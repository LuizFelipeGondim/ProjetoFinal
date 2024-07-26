#include "Game.hpp"
#include "Reversi.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Reversi::Reversi(int rows, int cols) : Game(rows, cols){}

bool Reversi::thereIsNearby(int rows, int cols) {
    int maxRows = _defaultRows;
    int maxCols = _defaultCols;

    bool top = (rows - 1 >= 0);
    bool bottom = (rows + 1 < maxRows);
    bool left = (2 * cols - 2 >= 0);
    bool right = (2 * cols + 2 < maxCols);

    if ((bottom && _board[rows + 1][2 * cols] == _watching) ||
        (top && _board[rows - 1][2 * cols] == _watching) ||
        (right && _board[rows][2 * cols + 2] == _watching) ||
        (left && _board[rows][2 * cols - 2] == _watching) ||
        (bottom && right && _board[rows + 1][2 * cols + 2] == _watching) ||
        (bottom && left && _board[rows + 1][2 * cols - 2] == _watching) ||
        (top && right && _board[rows - 1][2 * cols + 2] == _watching) ||
        (top && left && _board[rows - 1][2 * cols - 2] == _watching)) {
        return true;
    }

    return false;
}

bool Reversi::thereIsConnection(int rows,int cols){
    bool playable = false;
    if(!(rows == _defaultRows - 1)){
        if(_board[rows+1][2*cols] == _watching){            //Embaixo
            for(int i = rows+1; i < _defaultRows; i++){
                if(_board[i][2*cols] == _watching){
                    continue;
                }
                else if(_board[i][2*cols] == " "){
                    break;
                } 
                else if(_board[i][2*cols] == _turn){
                    playable = true;
                    break;
                }
            }
        }
        if(_board[rows+1][2*cols+2] == _watching){     //Embaixo-Direita
            int i = rows+1;
            int j = 2*cols+2;               
            for(;i < _defaultRows && j < _defaultCols ; i += 1,j += 2){
                if(_board[i][j] == _watching){
                    continue;
                }
                else if(_board[i][j] == " "){
                    break;
                } 
                else if(_board[i][j] == _turn){
                    playable = true;
                    break;
                }
            }
        }
        if(_board[rows+1][2*cols-2] == _watching){     //Embaixo-Esquerda
            int i = rows+1;
            int j = 2*cols-2;               
            for(;i < _defaultRows && j >= 0 ; i+=1, j-=2){
                if(_board[i][j] == _watching){
                    continue;
                }
                else if(_board[i][j] == " "){
                    break;
                } 
                else if(_board[i][j] == _turn){
                    playable = true;
                    break;
                }
            }
        }
    }
    if(!(rows == 1)){
        if(_board[rows-1][2*cols] == _watching){       //Em cima
            for(int i = rows-1; i >= 0; i--){
                if(_board[i][2*cols] == _watching){
                    continue;
                }
                else if(_board[i][2*cols] == " "){
                    break;
                } 
                else if(_board[i][2*cols] == _turn){
                    playable = true;
                    break;
                }
            }
        }

        if(_board[rows-1][2*cols+2] == _watching){     //Em cima-Direita
            int i = rows-1;
            int j = 2*cols+2;               
            for(;i >= 0 && j < _defaultCols ; i-=1, j+=2){
                if(_board[i][j] == _watching){
                    continue;
                }
                else if(_board[i][j] == " "){
                    break;
                } 
                else if(_board[i][j] == _turn){
                    playable = true;
                    break;
                }
            }   
        }
        if(_board[rows-1][2*cols-2] == _watching){     //Em cima-Esquerda
            int i = rows-1;
            int j = 2*cols-2;               
            for(;i >= 0 && j >= 0 ; i-=1, j-=2){
                if(_board[i][j] == _watching){
                    continue;
                }
                else if(_board[i][j] == " "){
                    break;
                } 
                else if(_board[i][j] == _turn){
                    playable = true;
                    break;
                }
            }
        }
    }
    if(!(cols == _defaultCols - 2)){
        if(_board[rows][2*cols+2] == _watching){       //Direita
            for(int i = 2*cols+2;i < _defaultCols; i+=2){
                if(_board[rows][i] == _watching){
                    continue;
                }
                else if(_board[rows][i] == " "){
                    break;
                } 
                else if(_board[rows][i] == _turn){
                    playable = true;
                    break;
                }
            }
        }
    }
    if(!(cols == 2)){
        if(_board[rows][2*cols-2] == _watching){       //Esquerda
            for(int i = 2*cols-2;i >= 0; i-=2){
                if(_board[rows][i] == _watching){
                    continue;
                }
                else if(_board[rows][i] == " "){
                    break;
                } 
                else if(_board[rows][i] == _turn){
                    playable = true;
                    break;
                }
            }
        }
    }
    return playable;
}

void Reversi::isPlaying(int rows,int cols){
    _board[rows][2*cols] = _turn;
    if(!(rows == _defaultRows - 1)){
        if(_board[rows+1][2*cols] == _watching){            //Embaixo
            for(int i = rows+1;i < _defaultRows; i++){
                if(_board[i][2*cols] == _watching){
                    continue;
                }
                else if(_board[i][2*cols] == " "){
                    break;
                } 
                else if(_board[i][2*cols] == _turn){
                    for(int k = rows+1;k <= i; k++){
                        _board[k][2*cols] = _turn;
                    }
                    break;
                }
            }
        }

        if(_board[rows+1][2*cols+2] == _watching){     //Embaixo-Direita
            int i = rows+1;
            int j = 2*cols+2;               
            for(;i < _defaultRows && j < _defaultCols ; i+=1, j+=2){
                if(_board[i][j] == _watching){
                    continue;
                }
                else if(_board[i][j] == " "){
                    break;
                } 
                else if(_board[i][j] == _turn){
                    for(int k = rows+1,m = 2*cols+2;k <= i; k++, m+=2){
                        _board[k][m] = _turn;
                    }
                    break;
                }
            }
        }

        if(_board[rows+1][2*cols-2] == _watching){     //Embaixo-Esquerda
            int i = rows+1;
            int j = 2*cols-2;               
            for(;i < _defaultRows && j >= 0 ; i+=1, j-=2){
                if(_board[i][j] == _watching){
                    continue;
                }
                else if(_board[i][j] == " "){
                    break;
                }    
                else if(_board[i][j] == _turn){
                    for(int k = rows+1,m = 2*cols-2;k <= i; k++, m-=2){
                        _board[k][m] = _turn;
                    }
                    break;
                }
            }
        }
    }
    if(!(rows == 1)){
        if(_board[rows-1][2*cols] == _watching){       //Em cima
            for(int i = rows-1;i >= 0; i--){
                if(_board[i][2*cols] == _watching){
                    continue;
                }
                else if(_board[i][2*cols] == " "){
                    break;
                } 
                else if(_board[i][2*cols] == _turn){
                    for(int k = rows-1;k >= i; k--){
                        _board[k][2*cols] = _turn;
                    }
                    break;
                }
            }
        }

        if(_board[rows-1][2*cols+2] == _watching){     //Em cima-Direita
            int i = rows-1;
            int j = 2*cols+2;               
            for(;i >= 0 && j < _defaultCols ; i-=1, j+=2){
                if(_board[i][j] == _watching){
                    continue;
                }
                else if(_board[i][j] == " "){

                    break;
                } 
                else if(_board[i][j] == _turn){
                    for(int k = rows-1,m = 2*cols+2; k >= i; k--, m+=2){
                        _board[k][m] = _turn;
                    }
                    break;
                }
            }
        }

        if(_board[rows-1][2*cols-2] == _watching){     //Em cima-Esquerda
            int i = rows-1;
            int j = 2*cols-2;               
            for(;i >= 0 && j >= 0 ; i-=1, j-=2){
                if(_board[i][j] == _watching){
                    continue;
                }
                else if(_board[i][j] == " "){

                    break;
                } 
                else if(_board[i][j] == _turn){
                    for(int k = rows-1,m = 2*cols-2; k >= i; k--, m-=2){
                        _board[k][m] = _turn;
                    }
                    break;
                }
            }
        }
    }
    if(!(cols == _defaultCols - 2)){
        if(_board[rows][2*cols+2] == _watching){                //Direita
            for(int i = 2*cols+2;i < _defaultCols; i+=2){
                if(_board[rows][i] == _watching){
                    continue;
                }
                else if(_board[rows][i] == " "){
                    break;
                } 
                else if(_board[rows][i] == _turn){
                    for(int k = 2*cols+2;k <= i; k+=2){
                        _board[rows][k] = _turn;
                    }
                    break;
                }
            }
        }
    }
    if(!(cols == 2)){
        if(_board[rows][2*cols-2] == _watching){       //Esquerda
            for(int i = 2*cols-2;i >= 0; i-=2){
                if(_board[rows][i] == _watching){
                    continue;
                }
                else if(_board[rows][i] == " "){
                    break;
                } 
                else if(_board[rows][i] == _turn){
                    for(int k = 2*cols-2;k >= i; k-=2){
                        _board[rows][k] = _turn;
                    }
                    break;
                }
            }
        }
    }
}

void Reversi::counter(){
    int auxXCounter = 0;
    int auxOCounter = 0;
    for(int i = 1;i < _defaultRows; i++){
        for(int j = 2;j < _defaultCols; j+=2){
            if(_board[i][j] == "X"){
                auxXCounter++;
            }
            else if(_board[i][j] == "O"){
                auxOCounter++;
            }
        }
    }
    _xCounter = auxXCounter;
    _oCounter = auxOCounter;
    cout << endl;
    cout << "-------------------------------------" << endl;
    cout << "|      X = " << _xCounter;         //|  X = 12  |  O = 23  |
    cout << "      |      O = " << _oCounter << "      |" << endl;
    cout << "-------------------------------------" << endl;
}

bool Reversi::piecesLeft(){
    int piece;
    if(_turn == "X"){
       piece = _xCounter;
    } 
    else if(_turn == "O"){
       piece = _oCounter;
    }

    if(piece == 0){
        return false;
    }

    return true; 
}

bool Reversi::isAnyPossiblePlay(){
    for(int i = 1;i < _defaultRows; i++){
        for(int j = 2;j < _defaultCols; j+=2){
            if(_board[i][j] == " "){
               if(!thereIsNearby(i,(j/2))){
                    continue;
               }
               if(!thereIsConnection(i,(j/2))){
                    continue;
               }
               return true;
            }
        }
    }
    return false;
}

bool Reversi::gameOver(){
    int x = 0;
    int o = 0;
    for(int i = 1;i < _defaultRows; i++){
        for(int j = 2;j < _defaultCols; j+=2){
            if(_board[i][j] == "X"){
                x += 1;
            }
            else if(_board[i][j] == "O"){
                o += 1;
            }
            else if(_board[i][j] == " "){
                return false;
            }
        }
    }
    if(x > o){
        cout << "FIM DO JOGO" << endl << "X GANHOU!!" << endl;
    }
    else if(x < 0){
        cout << "FIM DO JOGO" << endl << "O GANHOU!!" << endl;
    }
    else{
        cout << "FIM DO JOGO" << endl << "EMPATE!!" << endl;
    }
    return true;
}

void Reversi::match(){
    int rows;
    int cols;
    while(1){
        cout << "Vez do " << _turn << " jogar:" << endl << endl;
        cin >> rows;
        if(rows == -1){
            cout << _turn << " Desistiu, vitória do " << _watching << "." << endl; 
            break;
        }
        cin >> cols;
        if(_board[rows][2*cols] != " "){
            cout << "ERRO: jogada inválida" << endl;   //jogar em lugar ocupado
            continue;
        }
        
        if(!thereIsNearby(rows,cols)){
            cout << "ERRO: jogada inválida" << endl;   //nao tem peça oposta perto
            continue;
        }
        
        if(!thereIsConnection(rows, cols)){
            cout << "ERRO: jogada inválida" << endl;   //nao tem conexão com outro da mesma peça
            continue;
        }
        
        isPlaying(rows, cols);
        
        printBoard();
        counter();
        string _aux = _turn;
        _turn = _watching;
        _watching = _aux;

        if(!piecesLeft()){
            cout << endl << "Jogador " << _watching << " GANHOU !!" << endl;
            break;
        }
        
        if(gameOver()){       
            break;
        }
        
        if(!isAnyPossiblePlay()){
            cout << endl << "Nao tem jogada possível para o jogador " << _turn << endl;
            string _aux = _turn;
            _turn = _watching;
            _watching = _aux;
        }

    }
}