// https://www.codewars.com/kata/5b817c2a0ce070ace8002be0

#include<string>
#include<vector>

static std::string displayBoard(const std::vector<char>& board, unsigned short width) {
	std::string result{};

	for (size_t i{ 0 }; i < board.size(); ++i)
	{
		result += std::string() + " " + board[i] + " ";

		if (i != board.size() - 1)
		{
			result += ((i + 1) % width == 0)?
				"\n" + std::string(4 * width - 1, '-') + "\n":
				"|";
		}		
	}

	return result;
}