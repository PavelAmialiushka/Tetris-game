#include "Field.h"
#pragma once
enum  Rotations
{
	none = 0,
	ninetyP,
	down,
	ninetyN
};
enum Symbols
{
	right_L = 0,
	left_L,
	t_shaped,
	cube,
	right_z,
	left_z,
	line
};

class Figure
{
public:

	Figure(const Field&);
	int current_row;
	int current_col;
	Rotations current_rotation;

	std::vector<std::vector<char>> symbol;

private:
	Symbols current_symbol;

	void CreateForm(Symbols);
};
