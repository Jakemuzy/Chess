#pragma once
#include <string>
#include <vector>
#include <unordered_map>

enum pieces {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, NONE
};
enum gameStates {
    blackMate, whiteMate, stalemate, blackWithdraw, whiteWithdraw
};
enum colors {
    BLACK, WHITE
};


class piece {
public:
    piece();
    piece(std::string pos, colors col);

    std::string getPosition();
    bool getColor();
    pieces getType();

    void setPosition(std::string pos);
    friend std::ostream& operator<<(std::ostream& os, const piece* obj);
protected:
    std::string position;
    pieces type = NONE;
    bool color;
    bool state;     //Alive or dead
};

class pawn : public piece {
public:
    pawn(std::string pos, colors col);
private:
    bool firstMove = 1;
};
class knight : public piece {
public:
    knight(std::string pos, colors col);
};
class bishop : public piece {
public:
    bishop(std::string pos, colors col);
};
class rook : public piece {
public:
    rook(std::string pos, colors col);
};
class queen : public piece {
public:
    queen(std::string pos, colors col);
};
class king : public piece {
public:
    king(std::string pos, colors col);
};

//Board





