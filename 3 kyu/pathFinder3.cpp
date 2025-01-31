// https://www.codewars.com/kata/576986639772456f6f00030c

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <unordered_set>
#include <algorithm>


class PathFinder
{
	public:
		PathFinder(std::string& maze)
		{
			_maze = maze;
			_n = static_cast<int>(maze.find('\n'));
			_num_nodes = static_cast<size_t>(_n * _n);
			_goal = static_cast<int>(maze.size() - 1);
		}


		int find_min_rounds()
		{
			if (_n == 1) {
				return 0;
			}

			_rounds = std::vector<int>(_maze.size(), std::numeric_limits<int>::max());
			_rounds[0] = 0;
			_completed_nodes = {};

			while (_completed_nodes.size() < _num_nodes
				&& _completed_nodes.count(_goal) == 0)
			{
				int next_node = find_shortest_incomplete();
				_completed_nodes.insert(next_node);
				update_rounds(next_node);
			}

			return _rounds[_goal];
		}


	private:
		std::string _maze;
		int _n;
		size_t _num_nodes;
		int _goal;		

		std::vector<int> _rounds{};
		std::unordered_set<int> _completed_nodes{};


		bool in_bounds(const int& node)
		{
			return node >= 0
				&& node < static_cast<int>(_maze.size())
				&& _maze[node] != '\n';
		}


		void update_rounds(const int& node)
		{
			const std::vector<int> adjacent_nodes{ {
				node - 1,
				node + 1,
				node - _n - 1,
				node + _n + 1
			} };

			for (const int& adj_node : adjacent_nodes)
			{
				if (in_bounds(adj_node) &&
					_completed_nodes.count(adj_node) == 0)
				{
					_rounds[adj_node] = std::min(
						_rounds[node] + std::abs(static_cast<int>(_maze[node] - _maze[adj_node])),
						_rounds[adj_node]);
				}
			}
		}


		int find_shortest_incomplete()
		{
			size_t min_rounds_node{};
			int min_rounds{ std::numeric_limits<int>::max() };

			for (size_t i{ 0 }; i < _rounds.size(); ++i)
			{
				if (_rounds[i] < min_rounds &&
					_completed_nodes.count(i) == 0)
				{
					min_rounds_node = i;
					min_rounds = _rounds[i];
				}
			}

			return static_cast<int>(min_rounds_node);
		}
};


static int path_finder(std::string maze)
{
	PathFinder pathFinder(maze);
	return pathFinder.find_min_rounds();
}


int main()
{
	std::string s1 =
		"000\n"
		"000\n"
		"000";

	std::string failing =
		"289\n"
		"241\n"
		"124";

	int result{ path_finder(failing) };
	
	return 0;
}