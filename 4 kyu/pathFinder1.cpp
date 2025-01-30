// https://www.codewars.com/kata/5765870e190b1472ec0022a2


#include <iostream>
#include <string>
#include <unordered_set>


static bool inBounds(int pos, const std::string& maze)
{
	return pos >= 0 
		&& pos < static_cast<int>(maze.size()) 
		&& maze[pos] != '\n';
}


static bool scan_path(int pos, const std::string& maze, const int& n, std::unordered_set<int>& visited)
{
	if (pos == static_cast<int>(maze.size()) - 1) {
		return true;
	}

	if (!inBounds(pos, maze) ||
		maze[pos] == 'W' ||
		visited.count(pos) == 1) {
		return false;
	}

	visited.insert(pos);

	return scan_path(pos - 1, maze, n, visited)
		|| scan_path(pos + 1, maze, n, visited)
		|| scan_path(pos - n - 1, maze, n, visited)
		|| scan_path(pos + n + 1, maze, n, visited);
}


static bool path_finder(std::string maze) 
{
	const int n{ static_cast<int>(maze.find('\n')) };
	std::unordered_set<int> visited{};
	return scan_path(0, maze, n, visited);
}