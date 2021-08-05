#include "Field.h"
Field::Field()
{
	COLS = 12;
	ROWS = 25;
	coords.resize(25);
	for (size_t i = 0; i < coords.size(); ++i)
	{
		coords[i].resize(12);
	}
}

void Field::createRandomFigure()
{
	const Field &ref = *this;
	current_element = *new Figure(ref);
}

bool Field::canInsertElement()
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			int rr = r + current_element.current_row;
			int cc = c + current_element.current_col;

			if (current_element.symbol[r][c] == 0)
				continue;

			// ���������, ��� ���������� � �������� ������
			if (rr < 0 || rr >= ROWS)
				return false;
			if (cc < 0 || cc >= COLS)
				return false;

			// ���������, ��� ������ �� ������
			if (coords[rr][cc])
				return false;
		}
	}
	return true;
}
void Field::insertElement()
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			int rr = r + current_element.current_row;
			int cc = c + current_element.current_col;

			if (current_element.symbol[r][c])
				coords[rr][cc] = 1;
		}
	}
}
void Field::deleteElement()
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			int rr = r + current_element.current_row;
			int cc = c + current_element.current_col;

			if (current_element.symbol[r][c])
				coords[rr][cc] = 0;
		}
	}
}
void Field::clearField()
{
	for (int r = 0; r < ROWS; ++r)
		for (int c = 0; c < COLS; ++c)
			coords[r][c] = 0;
}
void Field::drawField()
{
	// �������� ����� �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���������� ����������
	COORD crds{ 35, 0 };

	for (int r = 0; r < ROWS; ++r)
	{
		crds.Y = r;
		// ������������� ������ � ������ �������
		SetConsoleCursorPosition(hConsole, crds);


		printf("\xB3"); // ����� ������� �������
		for (int c = 0; c < COLS; ++c)
		{
			if (coords[r][c] == 0)
				// ������� ������ ���������
				printf("  ");
			else
				// ������� ����������� ���������
				printf("\xDB\xDB");
		}
		printf("\xB3"); // ������ ������� �������
	}

	crds.Y = ROWS;
	// ������������� ������ � ������ �������
	SetConsoleCursorPosition(hConsole, crds);

	// ������� ������ �������
	printf("\xC0");
	for (int c = 0; c < COLS; ++c)
		printf("\xC4\xC4");
	printf("\xD9");
}
