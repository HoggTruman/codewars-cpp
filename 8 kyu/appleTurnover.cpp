// https://www.codewars.com/kata/580a094553bd9ec5d800007d/cpp

#include <string>

static std::string apple(const int x) {
    return x * x > 1000 ? 
        "It's hotter than the sun!!" : 
        "Help yourself to a honeycomb Yorkie for the glovebox.";
}