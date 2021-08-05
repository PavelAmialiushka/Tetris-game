#pragma once
#include "windows.h"
#include <vector>
#include "Figure.h"

class Field
{
public:
	Field();
	Figure current_element(Field*);

	int COLS;
	int ROWS;
	std::vector<std::vector<char>> coords;

	void createRandomFigure();
	bool canInsertElement();
	void insertElement();
	void deleteElement();
	void clearField();
	void drawField();
};

