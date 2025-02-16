// https://www.codewars.com/kata/52bb6539a4cf1b12d90005b7

#include <vector>
#include <map>
#include <unordered_set>

using Field = std::vector<std::vector<int>>;


struct Pos {
	int row;
	int col;
};


static bool inBounds(Pos pos) {
	return pos.row >= 0
		&& pos.col >= 0
		&& pos.row < 10
		&& pos.col < 10;
}


static bool hasOccupiedSide(const Pos& pos, const Pos& forward, const Field& field) {
	Pos side1 = { pos.row + forward.col, pos.col + forward.row };
	Pos side2 = { pos.row - forward.col, pos.col - forward.row };
	return (inBounds(side1) && field[side1.row][side1.col] == 1)
		|| (inBounds(side2) && field[side2.row][side2.col] == 1);
}


static bool hasOccupiedDiagonal(const Pos& pos, const Field& field) {
	Pos downLeft{ pos.row + 1, pos.col - 1 };
	Pos downRight{ pos.row + 1, pos.col + 1 };
	Pos upLeft{ pos.row - 1, pos.col - 1 };
	Pos upRight{ pos.row - 1, pos.col + 1 };

	return (inBounds(downLeft) && field[downLeft.row][downLeft.col] == 1)
		|| (inBounds(downRight) && field[downRight.row][downRight.col] == 1)
		|| (inBounds(upLeft) && field[upLeft.row][upLeft.col] == 1)
		|| (inBounds(upRight) && field[upRight.row][upRight.col] == 1);
}


static bool validate_battlefield(Field field) 
{
	const std::vector<Pos> directions{ {{1, 0}, {0, 1}, {-1, 0}, {0, -1}} };
	std::map<int, int> shipCounts{};
	std::unordered_set<int*> shipSquares{};

	for (int i{ 0 }; i < 10; ++i)
	{
		for (int j{ 0 }; j < 10; ++j)
		{
			if (field[i][j] != 1 ||
				shipSquares.count(&field[i][j])) {
				continue;
			}

			shipSquares.insert(&field[i][j]);
			int shipSize{ 1 };

			for (const auto& dir : directions)
			{
				if (shipSize > 1) { 
					continue; 
				}

				Pos shipFront{ i + dir.row, j + dir.col };

				while (inBounds(shipFront)
					&& field[shipFront.row][shipFront.col] == 1)
				{
					if (shipSquares.count(&field[shipFront.row][shipFront.col]) ||
						hasOccupiedSide(shipFront, dir, field)) 
					{
						return false;
					}

					shipSquares.insert(&field[shipFront.row][shipFront.col]);
					shipFront = { shipFront.row + dir.row, shipFront.col + dir.col };
					++shipSize;
				}

				if (shipSize > 1 && hasOccupiedSide(shipFront, dir, field)) {
					// checks the sides of one past the front (diagonals of the front)
					return false;
				}
			}

			if (hasOccupiedDiagonal({ i, j }, field)) {
				return false;
			}
			++shipCounts[shipSize];
		}
	}
	
	return shipCounts[1] == 4
		&& shipCounts[2] == 3
		&& shipCounts[3] == 2
		&& shipCounts[4] == 1
		&& shipCounts.size() == 4;
}
