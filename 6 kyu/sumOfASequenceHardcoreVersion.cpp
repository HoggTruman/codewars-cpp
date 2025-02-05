// https://www.codewars.com/kata/587a88a208236efe8500008b

static long long int sequence_sum(long long int begin, long long int end, long long step) 
{
    if (((begin > end) && step > 0) ||
        ((begin < end) && step < 0))
    {
        return 0;
    }

    long long int n = (end - begin) / step + 1;
    long long int last_term = begin + (n - 1) * step;

    return n * (begin + last_term) / 2;
}