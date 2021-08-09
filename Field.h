#pragma once
#include "windows.h"
#include <vector>
#include "Figure.h"

class Field
{
public:
	Field();
	Figure current_element(Field*);

	// эти переменные должны находится внутри секции private:
	int COLS; // с большой буквы пишут обычно только макросы. Здесь просто переменные и их нужно писать с маленькой
	int ROWS;
	std::vector<std::vector<char>> coords;

	void createRandomFigure();
	bool canInsertElement();
	void insertElement();
	void deleteElement();
	void clearField();
	void drawField();
};

