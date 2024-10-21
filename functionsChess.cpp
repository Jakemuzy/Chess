#include "Chess.h"
#include <iostream>

//Base class
piece::piece() {
	this->state = 0;
	this->position = "";
	this->color = WHITE;
}
piece::piece(std::string pos, colors col) {
	this->state = 0;
	this->position = pos;
	this->color = col;
}

std::string piece::getPosition() {
	return this->position;
}
bool piece::getColor() {
	return this->color;
}
pieces piece::getType() {
	return this->type;
}
void piece::setPosition(std::string pos) {
	this->position = pos;
}
std::ostream& operator<<(std::ostream& os, const piece* obj) {
	piece object = *obj;
	std::string pieceName = "";
	
	bool color = object.color;
	std::unordered_map<pieces, std::string> conversion = { {KING, "K"}, {QUEEN, "Q"}, {ROOK, "R"}, {BISHOP, "B"}, {KNIGHT, "N"}, {PAWN, "P"}, {NONE, "_"} };
	
	if (color == 1)
		pieceName += "w";
	else
		pieceName += "b";

	pieceName += conversion[object.type];

	const char* pieceNamePtr = pieceName.c_str();

	os.write(pieceNamePtr, sizeof(pieceNamePtr));
	
	return os;
}



//Other pieces
pawn::pawn(std::string pos, colors col) {
	this->state = 1;
	this->type = PAWN;
	this->position = pos;
	this->color = col;
}
knight::knight(std::string pos, colors col) {
	this->state = 1;
	this->type = KNIGHT;
	this->position = pos;
	this->color = col;
}
bishop::bishop(std::string pos, colors col) {
	this->state = 1;
	this->type = BISHOP;
	this->position = pos;
	this->color = col;
}
rook::rook(std::string pos, colors col) {
	this->state = 1;
	this->type = ROOK;
	this->position = pos;
	this->color = col;
}
queen::queen(std::string pos, colors col) {
	this->state = 1;
	this->type = QUEEN;
	this->position = pos;
	this->color = col;
}
king::king(std::string pos, colors col) {
	this->state = 1;
	this->type = KING;
	this->position = pos;
	this->color = col;
}
