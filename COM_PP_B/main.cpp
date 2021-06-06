#include <cassert>
#include "head.h"

bool comPPtoB(const LongP& pol1 , const LongP& pol2)
{
    if (pol1.deg == pol2.deg)
    {
        int i = 0;
        while (comQQtoB(pol1.odds[i] , pol2.odds[i]) && i <= pol1.deg)
        {
            i++;
            continue;
        }
        if (i == pol1.deg + 1)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    LongP p1 = { 0 };
    p1.deg = 2;
    p1.odds[0] = { {1, 6,{0,0,0,0,0,0,1}}, { 0,{8} }, };
    p1.odds[1] = { {1, 6,{0,0,0,0,0,0,1}}, { 0,{8} }, };
    p1.odds[2] = { {1, 6,{0,0,0,5,0,0,1}}, { 0,{8} }, };

    LongP p2 = { 0 };
    p2.deg = 2;
    p2.odds[0] = { {1, 6,{0,0,0,0,0,0,1}}, { 0,{8} }, };
    p2.odds[1] = { {1, 6,{0,0,0,0,0,0,1}}, { 0,{8} }, };
    p2.odds[2] = { {1, 6,{0,0,0,5,0,0,1}}, { 0,{8} }, };

    assert(comPPtoB(p1 , p2) == true);
    return 0;
}
