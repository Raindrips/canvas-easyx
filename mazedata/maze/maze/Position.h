#pragma once

class Position {

private:
  int x, y;

public:
  Position(int x, int y) {
	this->x = x;
	this->y = y;
  }

  int getX() { return x; }
  int getY() { return y; }
};
