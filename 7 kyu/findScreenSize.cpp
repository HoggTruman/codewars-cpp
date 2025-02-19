// https://www.codewars.com/kata/5bbd279c8f8bbd5ee500000f

#include <string>

static std::string find_screen_height(int width, const std::string& ratio)
{
    size_t colonIndex{ ratio.find(':') };
    int leftRatio{ std::stoi(ratio.substr(0, colonIndex)) };
    int rightRatio{ std::stoi(ratio.substr(colonIndex + 1)) };
    int height{ width * rightRatio / leftRatio };
    return std::to_string(width) + "x" + std::to_string(height);
}