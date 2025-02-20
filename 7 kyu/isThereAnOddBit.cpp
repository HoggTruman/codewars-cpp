// https://www.codewars.com/kata/5d6f49d85e45290016bf4718

static bool any_odd(unsigned x) {
    x >>= 1;
    while (x > 0) {
        if (x % 2 == 1) {
            return true;
        }
        x >>= 2;
    }
    return false;
}