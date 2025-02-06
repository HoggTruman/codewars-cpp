// TOO SLOW

#include <algorithm>
#include <iostream>

typedef unsigned long long ull;

static ull spinningRings(ull innerMax, ull outerMax) {
    ull inner{ innerMax };
    ull outer{ 1 };
    ull totalMoves{ 1 };

    const ull innerMod{ innerMax + 1 };
    const ull outerMod{ outerMax + 1 };

    while (inner != outer)
    {
        if (inner < outer)
        {
            ull outerDiff{ outerMax - outer };

            if (outer > innerMax || inner > outerDiff)
            {
                ull moves{ outerDiff + 1 };
                outer = 0;
                inner = (inner + innerMod - (moves % innerMod)) % innerMod;
                totalMoves += moves;
            }
            else
            {
                // inner will take fewer moves to wrap
                ull moves{ inner + 1 };
                outer = (outer + moves) % outerMod;
                inner = innerMax;
                totalMoves += moves;
            }
        }
        else if (2 * outerMax < inner + outer) // outerMax - outer < inner - outerMax rearranged to avoid underflow
        {
            // outer closer to outerMax than inner is to it
            ull moves{ outerMax - outer + 1 };
            outer = 0;
            inner -= moves; // mod not needed because moves is never big enough to cause wrap
            totalMoves += moves;
        }
        else
        {
            // go to midpoint (either inner and outer match or will be one past eachother)
            ull moves{ (inner - outer + 1) / 2 };
            inner = (inner - moves) % innerMod;
            outer = (outer + moves) % outerMod;
            totalMoves += moves;
        }          
        
    } 
    return totalMoves;
}



//int main()
//{
//
//    ull result = spinningRings(11346713121956, 144642768701211);
//
//    //Expected: equal to 151'748'376'204'305
//
//    
//    return 0;
//}