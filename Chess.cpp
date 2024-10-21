
#include <iostream>
#include <string>
#include "Chess.h"
#include <unordered_map>

//Gets user input for moves
pieces userInput(char& col, int& row) {
    std::string userMove;
    pieces pieceType;
    std::vector<char> letters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

    std::cout << "Please enter a move: ";
    std::getline(std::cin, userMove);

    //Determines which piece is moving
    switch (userMove[0]) {
    case ('K'):
        pieceType = KING;
        break;
    case ('Q'):
        pieceType = QUEEN;
        break;
    case ('R'):
        pieceType = ROOK;
        break;
    case ('B'):
        pieceType = BISHOP;
        break;
    default:
        //If not a piece
        if (find(letters.begin(), letters.end(), userMove[0]) != letters.end())
            break;
        //Else its a pawn
        pieceType = PAWN;
        break;
    }

    //Determine where it's going 
    char letter = userMove[1];
    int number = stoi(userMove.substr(2, 2));    //Error check this first

    if (number < 0 || number > 7)
        return NONE;


    col = letter;
    row = number;
    return pieceType;
}


void determinePossibleMovement(std::vector<std::pair<int, int>> possiblePieces, pieces pieceType, const std::vector<std::vector<piece*>>& board) {
    std::vector<std::pair<int, int>> possibleMoves;

    bool color;
    for (auto& pair : possiblePieces) {
        color = board[pair.first][pair.second]->getColor();

        switch (pieceType) {
        case(PAWN):
            if (color) {
                possibleMoves.push_back({ pair.first - 1, pair.second });
            }
            else {
                possibleMoves.push_back({ pair.first - 1, pair.second });
            }
            break;
        case(KNIGHT):
            break;
        case(BISHOP):
            break;
        case(ROOK):
            break;
        case(QUEEN):
            break;
        case(KING):
            break;
        default:
            break;
        }
        for (auto& move : possibleMoves) {
            std::cout << "Possible moves for " << pair.first << ", " << pair.second << " is the move: " << move.first << ", " << move.second << "\n";
        }
        possibleMoves.clear();
    }
    

    

}

//Handles the movement calculations
void movement(std::vector<std::vector<piece*>>& board) {
    //Variables
    std::vector<std::string> possibleMoves;
    std::unordered_map<char, int> moveConversion = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7} };

    //Get user input for movement
    char row = ' '; int col = 0;
    pieces pieceType = userInput(row, col);
    std::cout << "Your move was: " << pieceType << " to " << row << col << "\n";

    //Print out position
    std::cout << board[7-moveConversion[row]][col-1]->getPosition() << "\n";    //Minus 7 cuz it does backwards order

    //Determine if piece is on board 
    
    
    //Push possible pieces into vector
    std::vector<std::pair<int, int>> possiblePieces;    //This is their position in board space not chess notation
    int rowNum = 0, colNum = 0;

    for (auto& row : board) {
        for (auto& piece: row) {
            if (piece->getType() == pieceType) {
                std::pair<int, int> pos(rowNum, colNum);  
                possiblePieces.push_back(pos);
            }
            colNum++;
        } 
        colNum = 0;
        rowNum++;
    }
    //Print out possiblePieces
    for (auto& pos : possiblePieces) {
        std::cout << pos.first << " " << pos.second << "\n";
    }

    determinePossibleMovement(possiblePieces, pieceType, board);

}

void printBoard(std::vector<std::vector<piece*>>& board) {
    for (auto& row : board) {
        for (auto& piece : row) {
            std::cout << piece << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    static int moveNum = 0;
    std::vector<std::vector<piece*>> board = {
        {new rook("h1", BLACK), new knight("h2", BLACK), new bishop("h3", BLACK), new queen("h4", BLACK), new king("h5", BLACK), new bishop("h6", BLACK), new knight("h7", BLACK), new rook("h8", BLACK)},
        {new pawn("g1", BLACK), new pawn("g2", BLACK), new pawn("g3", BLACK), new pawn("g4", BLACK), new pawn("g5", BLACK), new pawn("g6", BLACK), new pawn("g7", BLACK), new pawn("g8", BLACK)},
        {new piece("f1", WHITE), new piece("f2", WHITE), new piece("f3", WHITE), new piece("f4", WHITE), new piece("f5", WHITE), new piece("f6", WHITE), new piece("f7", WHITE), new piece("f8", WHITE)},
        {new piece("e1", WHITE), new piece("e2", WHITE), new piece("e3", WHITE), new piece("e4", WHITE), new piece("e5", WHITE), new piece("e6", WHITE), new piece("e7", WHITE), new piece("e8", WHITE)},
        {new piece("d1", WHITE), new piece("d2", WHITE), new piece("d3", WHITE), new piece("d4", WHITE), new piece("d5", WHITE), new piece("d6", WHITE), new piece("d7", WHITE), new piece("d8", WHITE)},
        {new piece("c1", WHITE), new piece("c2", WHITE), new piece("c3", WHITE), new piece("c4", WHITE), new piece("c5", WHITE), new piece("c6", WHITE), new piece("c7", WHITE), new piece("c8", WHITE)},
        {new pawn("b1", WHITE), new pawn("b2", WHITE), new pawn("b3", WHITE), new pawn("b4", WHITE), new pawn("b5", WHITE), new pawn("b6", WHITE), new pawn("b7", WHITE), new pawn("b8", WHITE)},
        {new rook("a1", WHITE), new knight("a2", WHITE), new bishop("a3", WHITE), new queen("a4", WHITE), new king("a5", WHITE), new bishop("a6", WHITE), new knight("a7", WHITE), new rook("a8", WHITE)}
    };

    movement(board);
    printBoard(board);
}

