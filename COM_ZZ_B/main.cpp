// этот модуль является дополнительным. Не входит в основной список.
#include <cassert>
#include "head.h"

bool comZZtoB(const LongZ& num1 , const LongZ& num2)
{
    if (num1.sign == num2.sign)
    {
        if (num1.deg >= num2.deg)
        {
            for (int i = 0; i <= num1.deg; ++i)
            {
                if (num1.arrOfNums[i] != num2.arrOfNums[i])
                    return false;
            }
        }
        else
        {
            for (int i = 0; i <= num2.deg; ++i)
            {
                if (num1.arrOfNums[i] != num2.arrOfNums[i])
                    return false;
            }
        }
        return true;
    }
    else if (num1.deg == 0 && num1.arrOfNums[0] == 0 &&
        num2.deg == 0 && num2.arrOfNums[0] == 0)
        return true;
    else
        return false;
}

int main()
{
    assert(comZZtoB({ 1, 3,{ 6, 2, 8, 4 } } , { 0, 3, { 6, 2, 8, 4 } }) == false);

    assert(comZZtoB({ 0, 3,{ 1, 2, 3, 4 } } , { 0, 3, {5, 7, 7} }) == false);

    assert(comZZtoB({ 1, 3,{ 1, 2, 3, 4 } } , { 1, 3, {1, 2, 3, 4} }) == true);
    return 0;
}
