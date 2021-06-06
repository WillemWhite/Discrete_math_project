/*
** Умножение целого на(-1)
** Зависимостей с другими модулями нет, функционал реализуется сразу.
**
** Требование: оформлять функции (порядок аргументов и выходные данные) и использовать
** зависимые модули(если таковые есть) в точности с прототипом header файла
** (это сделано для стандартизации работы проекта).
**
** !!! В случае отсутствия у модуля каких-либо зависимостей необходимо сделать его
** как можно скорее и отправить на проверку !!!
**
** Желаю успехов, боец
** (-_-)
*/
#include <cassert>
#include "head.h"

LongZ mulZMtoZ(const LongZ& integer)
{
    LongZ result = { 0,{0} };

    if (integer.sign == 0)
    {
        result.sign = 1;
        result.deg = integer.deg;
        for (int i = integer.deg; i >= 0; --i)
        {
            result.arrOfNums[i] = integer.arrOfNums[i];
        }
    }
    else if (integer.sign == 1)
    {
        result.sign = 0;
        result.deg = integer.deg;
        for (int i = integer.deg; i >= 0; --i)
        {
            result.arrOfNums[i] = integer.arrOfNums[i];
        }
    }

    return result;
}

int main()
{
    LongZ numZ1 = { 0, 4,{ 6, 5, 2, 8, 4 } };
    LongZ numZM1 = { 1, 4,{ 6, 5, 2, 8, 4 } };
    LongZ numZ2 = { 1, 4,{ 6, 5, 2, 8, 4 } };
    LongZ numZM2 = { 0, 4,{ 6, 5, 2, 8, 4 } };
    LongZ numZ3 = { 0, 0,{ 0 } };
    LongZ numZM3 = { 0, 0,{ 0 } };

    assert(comZZtoB(mulZMtoZ(numZ1) , numZM1));
    assert(comZZtoB(mulZMtoZ(numZ2) , numZM2));
    assert(comZZtoB(mulZMtoZ(numZ3) , numZM3));

    return 0;
}
