// этот модуль является дополнительным. Не входит в основной список.
#include <cassert>
#include "head.h"

bool comQQtoB(const LongQ& numQ1 , const LongQ& numQ2)
{
    LongQ num1 = redQtoQ(numQ1);
    LongQ num2 = redQtoQ(numQ2);

    if (num1.num.deg == 0 && num1.num.arrOfNums[0] &&
        num2.num.deg == 0 && num2.num.arrOfNums[0])
        return true;
    else if (comNNtoD(num1.denom , num2.denom) == 0)
    {
        if (comZZtoB(num1.num , num2.num))
            return true;
        else
            return false;
    }
    else
        return false;
}

int main() {
    LongQ first = {
            {1, 5, {1,4,3,5,6,3}},
            {0, {5}}
    };
    LongQ second = {
            {1, 3, {1,3,5,2}},
            {0, {2}}
    };

    bool result = comQQtoB(first , second);
    assert(result == false);

    first = {
            {1, 0, {0}},
            {0, {1}}
    };
    second = {
            {0, 0, {0}},
            {0, {2}}
    };

    result = comQQtoB(first , second);
    assert(result == true);

    first = {
            {1, 3, {5,2,1}},
            {0, {5}}
    };
    second = {
            {1, 2, {5,2}},
            {0, {1}}
    };

    result = comQQtoB(first , second);
    assert(result == true);

    return 0;
}
