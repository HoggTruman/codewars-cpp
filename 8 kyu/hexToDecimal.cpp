// https://www.codewars.com/kata/57a4d500e298a7952100035d/cpp

#include <string>
#include <sstream>

static int hexToDec(std::string hexString)
{
    int result;
    std::stringstream ss{};
    ss << std::hex << hexString;
    ss >> result;
    return result;
}