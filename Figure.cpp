#include "Figure.h"

Figure::Figure(const Field &f)
{
	current_col = (f.COLS / 2) - 2;
	current_symbol = static_cast<Symbols>(rand() % 7);
	current_rotation = Rotations::none;
	symbol.resize(3);
	for (int i = 0; i < symbol.size(); ++i) symbol.resize(3);
	CreateForm(current_symbol);
}

void Figure::CreateForm(Symbols s) 
{
	switch (s)
	{
	case right_L:
		symbol =
		{
		 {1,0,0},
		 {1,0,0},
		 {1,1,0}
		};
		break;

	case left_L: 
		symbol =
		{
		 {0,1,0},
		 {0,1,0},
		 {1,1,0}
		};
		break;

	case right_z:
		symbol =
		{
		 {0,0,0},
		 {1,1,0},
		 {0,1,1}
		};
		break;

	case left_z:
		symbol =
		{
		 {0,0,0},
		 {0,1,1},
		 {1,1,0}
		};
		break;

	case cube:
		symbol =
		{
		 {0,0,0},
		 {1,1,0},
		 {1,1,0}
		};
		break;

	case line:
		symbol =
		{
		 {0,1,0},
		 {0,1,0},
		 {0,1,0}
		};
		break;
	case t_shaped:
		symbol =
		{
		 {0,0,0},
		 {0,1,0},
		 {1,1,1}
		};
		break;

	default:
		break;
	}
}
