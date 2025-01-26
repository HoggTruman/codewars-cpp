// https://www.codewars.com/kata/58678d29dbca9a68d80000d7/cpp

#include <string>
#include <stack>

void flip(char& bit)
{
	bit = (bit == '0') ? '1' : '0';
}


void skipToClosingBracket(const std::string& code, size_t& codeIndex)
{
	int openBrackets{ 1 };

	while (openBrackets != 0
		&& ++codeIndex < code.size())
	{
		if (code[codeIndex] == '[')
		{
			++openBrackets;
		}
		else if (code[codeIndex] == ']')
		{
			--openBrackets;
		}
	}
}


std::string interpreter(const std::string& code, const std::string& tape) {
	std::string newTape{ tape };
	size_t codeIndex{ 0 };
	size_t pointer{ 0 };
	std::stack<size_t> openBracketIndices{};

	do
	{
		if (code[codeIndex] == '>')
		{
			++pointer;
			if (pointer == tape.size()) { return newTape; }
		}
		else if (code[codeIndex] == '<')
		{
			if (pointer == 0) { return newTape; }
			--pointer;
		}
		else if (code[codeIndex] == '*')
		{
			flip(newTape[pointer]);
		}
		else if (code[codeIndex] == '[')
		{
			if (newTape[pointer] == '0')
			{
				skipToClosingBracket(code, codeIndex);
			}
			else
			{
				openBracketIndices.push(codeIndex);
			}
		}
		else if (code[codeIndex] == ']')
		{
			if (newTape[pointer] == '1')
			{
				codeIndex = openBracketIndices.top();
			}
			else
			{
				openBracketIndices.pop();
			}
		}
	} 
	while (++codeIndex < code.size());

	return newTape;
}
