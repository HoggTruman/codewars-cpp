// https://www.codewars.com/kata/58f4cc4e43251b1be6000082

#include <string>
#include <vector>
#include <queue>
#include <map>


struct Path {
	int moves = -1;
	int distance = 0;
	char directionTo = 0;
	int prevPos = -1;
};


class IceMazeSolver 
{
	public:
		IceMazeSolver(const std::string& map)
		{
			_map = map;
			_startPos = static_cast<int>(map.find('S'));
			_endPos = static_cast<int>(map.find('E'));
			_rowLength = static_cast<int>(map.find('\n'));
			_directions = {
				{ 'l', -1 },
				{ 'r', 1 },
				{ 'u', -_rowLength - 1 },
				{ 'd', _rowLength + 1 }
			};
		}

		std::vector<char> solveMaze()
		{
			std::vector<Path> positionPaths(_map.size());
			positionPaths[_startPos].moves = 0;
			std::queue<int> positionQueue{};
			positionQueue.push(_startPos);
			
			while (!positionQueue.empty())
			{
				int currentPos{ positionQueue.front() };
				Path& currentPath{ positionPaths[currentPos] };
				positionQueue.pop();

				if (positionPaths[_endPos].moves != -1 &&
					currentPath.moves >= positionPaths[_endPos].moves)
				{
					break;
				}

				for (const auto& [direction, _] : _directions)
				{
					int nextPos{ findNextPosition(currentPos, direction) };
					if (nextPos == currentPos) { continue; }
					Path& nextPath{ positionPaths[nextPos] };

					if (nextPath.moves == -1)
					{
						// next position not visited
						nextPath.moves = currentPath.moves + 1;
						nextPath.distance = currentPath.distance + calculateDistance(currentPos, nextPos);
						nextPath.directionTo = direction;
						nextPath.prevPos = currentPos;
						positionQueue.push(nextPos);
					}
					else if (nextPath.moves == currentPath.moves + 1)
					{
						// update if reachable in same number of moves but lower distance
						int distance{ currentPath.distance + calculateDistance(currentPos, nextPos) };
						if (distance < nextPath.distance) 
						{
							nextPath.distance = distance;
							nextPath.directionTo = direction;
							nextPath.prevPos = currentPos;
						}						
					}
				}
			}

			return positionPaths[_endPos].moves != -1?
				constructFullPath(positionPaths):
				std::vector<char>();
		}


	private:
		const char obstacle{ '#' };
		const char nonSlip{ 'x' };
		const char endTile{ 'E' };

		std::string _map;
		int _startPos;
		int _endPos;
		int _rowLength;
		std::map<char, int> _directions;


		bool inBounds(int& pos)
		{
			return pos >= 0
				&& pos < static_cast<int>(_map.size())
				&& _map[pos] != '\n';
		}


		int findNextPosition(const int& startPos, const char& direction)
		{
			int nextPos{ startPos + _directions[direction] };
			while (inBounds(nextPos)
				&& _map[nextPos] != IceMazeSolver::obstacle)
			{				
				if (_map[nextPos] == IceMazeSolver::nonSlip ||
					_map[nextPos] == IceMazeSolver::endTile) {
					return nextPos;
				}
				nextPos += _directions[direction];
			}

			return nextPos - _directions[direction];
		}


		int calculateDistance(const int& startPos, const int& endPos)
		{
			int indexDiff{ std::abs(endPos - startPos) };

			return indexDiff < _rowLength?
				indexDiff:
				indexDiff / (_rowLength + 1);
		}


		std::vector<char> constructFullPath(std::vector<Path>& positionPaths)
		{
			int currentPos{ _endPos };
			Path& currentPath{ positionPaths[_endPos] };
			std::vector<char> result(currentPath.moves);

			while (currentPos != _startPos)
			{
				result[currentPath.moves - 1] = currentPath.directionTo;
				currentPos = currentPath.prevPos;
				currentPath = positionPaths[currentPos];
			}

			return result;
		}
};


static std::vector<char> ice_maze_solver(const std::string& map)
{
	IceMazeSolver solver(map);
	return solver.solveMaze();
}
