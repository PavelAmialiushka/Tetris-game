#pragma once
#include "Field.h"
#include <map>
#include <functional>
class Game
{
public:
	Field field;
	Game();

	bool gameOver = false;
	bool inserted = 0; // опускается ли в данный момент фигура

	void Start();
	void StepRight();
	void StepLeft();
	void StepDown();
	void Rotate();

	void MatrixRotate();

	std::map<int, std::function<void()>> Keys
	{
		  {32, [&]() {Rotate();	  }}
		, {75, [&]() {StepLeft(); }}
		, {80, [&]() {StepDown(); }}
		, {77, [&]() {StepRight(); }}
	};
};
