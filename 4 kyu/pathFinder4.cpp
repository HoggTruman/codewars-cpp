// https://www.codewars.com/kata/5a0573c446d8435b8e00009f

#include <vector>
#include <string>


std::vector<int> pos{ {0, 0} };
int dir{ 0 };

std::vector<int>& i_am_here(std::string path)
{
	size_t i{ 0 };

	do
	{
		if (isdigit(path[i]))
		{
			size_t next_turn{ path.find_first_of("lLrR", i) };
			int dist = next_turn == std::string::npos ?
				std::stoi(path.substr(i)) :
				std::stoi(path.substr(i, next_turn - i));

			if (dir == 0) {
				pos[0] += dist;
			}
			else if (dir == 1) {
				pos[1] -= dist;
			}
			else if (dir == 2) {
				pos[0] -= dist;
			}
			else if (dir == 3) {
				pos[1] += dist;
			}
			
			i = next_turn;
		}
		else
		{
			if (path[i] == 'l') {
				dir = (4 + dir - 1) % 4;
			}
			else if (path[i] == 'r') {
				dir = (dir + 1) % 4;
			}
			else {
				dir = (dir + 2) % 4;
			}

			++i;
		}
	} 
	while (i != std::string::npos
		&& i < path.size());
	
	return pos;
}