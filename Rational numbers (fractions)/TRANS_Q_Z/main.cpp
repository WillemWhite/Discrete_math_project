/*
** Преобразование дробного в целое (если знаменатель равен 1)
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
#include <iostream>
#include <cassert>
#include "head.h"

LongZ transQtoZ(const LongQ& oldNumber)
{
    if (intQtoB(oldNumber) == true)
    {
        LongQ redOldNumber = redQtoQ(oldNumber);
        LongZ transformedNumber = redOldNumber.num;
        return transformedNumber;
    }
    else
    {
        std::cerr << "Error. The denominator of the number is not equal to 1." << std::endl;
        return { 0 };
    }
}

void transQtoZTest()
{
    LongQ rationalTest[4] =
    {
        {
            {1, 3, {4, 3, 2, 1}},
            {0, {1}}
        },
        {
            {1, 5, {4, 3, 2, 1, 7, 6}},
            {0, {1}}
        },
        {
            {0, 0, {0}},
            {0, {1}}
        },
        {
            {1, 0, {1}},
            {0, {1}}
        }
    };
    LongZ integerTest[4] =
    {
        {1, 3, {4, 3, 2, 1}},
        {1, 5, {4, 3, 2, 1, 7, 6}},
        {0, 0, {0}},
        {1, 0, {1}}
    };
    for (int i = 0; i < 4; i++)
    {
        LongZ transformedNumberTest = transQtoZ(rationalTest[i]);
        assert(transformedNumberTest.sign == integerTest[i].sign);
        assert(transformedNumberTest.deg == integerTest[i].deg);
        for (int j = 0; j <= transformedNumberTest.deg; j++)
        {
            assert(transformedNumberTest.arrOfNums[j] == integerTest[i].arrOfNums[j]);
        }
    }
}

int main()
{
    transQtoZTest();
    return 0;
}
