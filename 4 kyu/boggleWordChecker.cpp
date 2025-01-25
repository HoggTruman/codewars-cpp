// https://www.codewars.com/kata/57680d0128ed87c94f000bfd/cpp

#include <vector>
#include <string>
#include <unordered_set>
#include <string_view>


bool in_bounds(const size_t& row, const size_t& col, const size_t& boardSize)
{
	return row >= 0 
		&& row < boardSize 
		&& col >= 0 
		&& col < boardSize;
}


bool check_chain(
	const size_t& r, 
	const size_t& c, 
	const std::vector<std::vector<char>>& board, 
	const std::string_view& remainingWord, 
	std::unordered_set<const char*>& visited)
{
	if (remainingWord.empty())
	{
		return true;
	}

	visited.insert(&board[r][c]);

	for (size_t r_next{ r == 0? 0: r - 1 }; r_next <= r + 1; ++r_next)
	{
		for (size_t c_next{ c == 0? 0: c - 1 }; c_next <= c + 1; ++c_next)
		{
			if (in_bounds(r_next, c_next, board.size()) &&
				visited.count(&board[r_next][c_next]) == 0 &&
				remainingWord.front() == board[r_next][c_next] &&
				check_chain(r_next, c_next, board, std::string_view(remainingWord).substr(1), visited))
			{
				return true;
			}
		}
	}

	visited.erase(&board[r][c]);
	return false;	
}


bool check_word(const std::vector<std::vector<char>>& board, const std::string& word)
{
	std::unordered_set<const char*> visited{};	

	for (size_t r{ 0 }; r < board.size(); ++r)
	{
		for (size_t c{ 0 }; c < board.size(); ++c)
		{
			if (board[r][c] == word.front() &&
				check_chain(r, c, board, std::string_view(word).substr(1), visited))
			{
				return true;
			}
		}
	}

	return false;
}