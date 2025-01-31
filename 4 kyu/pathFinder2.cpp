// https://www.codewars.com/kata/57658bfa28ed87ecfa00058a/cpp


#include <iostream>
#include <string>
#include <queue>
#include <vector>


static bool inBounds(int pos, const std::string& maze)
{
	return pos >= 0
		&& pos < static_cast<int>(maze.size())
		&& maze[pos] != '\n';
}


static bool scan_pos(
	const int& pos, 
	const int& dist, 
	const std::string& maze, 
	const int& n, 
	std::vector<int>& distances, 
	std::queue<std::pair<int, int>>& tasks)
{
	if (!inBounds(pos, maze) ||
		maze[pos] == 'W' ||
		distances[pos] >= 0) {
		return false;
	}

	distances[pos] = dist;

	if (pos == static_cast<int>(maze.size()) - 1) {
		return true;
	}

	tasks.push({ pos - 1, dist + 1 });
	tasks.push({ pos + 1, dist + 1 });
	tasks.push({ pos - n - 1, dist + 1 });
	tasks.push({ pos + n + 1, dist + 1 });

	return false;
}


static int path_finder(std::string maze) {
	const int goal{ static_cast<int>(maze.size() - 1) };
	const int n{ static_cast<int>(maze.find('\n')) };
	std::vector<int> distances(maze.size(), -1);
	std::queue<std::pair<int, int>> tasks{ {{ 0, 0 }} };

	while (!tasks.empty())
	{
		auto [pos, dist] = tasks.front();
		tasks.pop();
		if (scan_pos(pos, dist, maze, n, distances, tasks)) {
			break;
		}
	}

	return distances[goal];
}
