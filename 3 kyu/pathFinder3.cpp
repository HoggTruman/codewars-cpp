// https://www.codewars.com/kata/576986639772456f6f00030c


#include <string>
#include <vector>
#include <map>
#include <queue>


struct NodeRounds {
	NodeRounds(int node, int rounds)
	{
		this->node = node;
		this->rounds = rounds;
	}

	int node;
	int rounds;	
};


struct NodeRoundsComparator {
	bool operator()(NodeRounds a, NodeRounds b) {
		return a.rounds > b.rounds;
	}
};


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
			_queue = {};
			_queue.push(NodeRounds(0, 0));
			_min_rounds = {};

			while (_min_rounds.count(_goal) == 0)
			{
				NodeRounds next_node = _queue.top();
				_queue.pop();
				_min_rounds[next_node.node] = next_node.rounds;
				update_queue(next_node);
			}

			return _min_rounds[_goal];
		}


	private:
		std::string _maze;
		int _n;
		size_t _num_nodes;
		int _goal;		

		std::priority_queue<NodeRounds, std::vector<NodeRounds>, NodeRoundsComparator> _queue;
		std::map<int, int> _min_rounds{};


		bool in_bounds(const int& node)
		{
			return node >= 0
				&& node < static_cast<int>(_maze.size())
				&& _maze[node] != '\n';
		}


		void update_queue(const NodeRounds& nr)
		{
			const std::vector<int> adjacent_nodes{ {
				nr.node - 1,
				nr.node + 1,
				nr.node - _n - 1,
				nr.node + _n + 1
			} };

			for (const int& adj_node : adjacent_nodes)
			{
				if (in_bounds(adj_node) &&
					_min_rounds.count(adj_node) == 0)
				{
					int rounds{ nr.rounds + std::abs(static_cast<int>(_maze[nr.node] - _maze[adj_node])) };
					_queue.push(NodeRounds(adj_node, rounds));
				}
			}
		}
};


static int path_finder(std::string maze)
{
	PathFinder pathFinder(maze);
	return pathFinder.find_min_rounds();
}
