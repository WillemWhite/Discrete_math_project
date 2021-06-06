/*
** Преобразование целого в дробное
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

LongQ transZtoQ(const LongZ& oldNumber)
{
    LongQ transformedNumber = { 0 };
    transformedNumber.denom.arrOfNums[0] = 1;
    transformedNumber.num = oldNumber;
    return transformedNumber;
}

void transZtoQTest()
{
    LongZ integerTest[4] =
    {
        {1, 3, {4, 3, 2, 1}},
        {-1, 5, {4, 3, 2, 1, 7, 6}},
        {1, 0, {0}},
        {1, 0, {1}}
    };
    LongQ rationalTest[4] =
    {
        {
            {1, 3, {4, 3, 2, 1}},
            {0, {1}}
        },
        {
            {-1, 5, {4, 3, 2, 1, 7, 6}},
            {0, {1}}
        },
        {
            {1, 0, {0}},
            {0, {1}}
        },
        {
            {1, 0, {1}},
            {0, {1}}
        }
    };
    for (int i = 0; i < 4; i++)
    {
        LongQ transformedNumberTest = transZtoQ(integerTest[i]);
        assert(transformedNumberTest.denom.deg == 0);
        assert(transformedNumberTest.denom.arrOfNums[0] == 1);
        assert(transformedNumberTest.num.sign == rationalTest[i].num.sign);
        assert(transformedNumberTest.num.deg == rationalTest[i].num.deg);
        for (int j = 0; j <= transformedNumberTest.num.deg; j++)
        {
            assert(transformedNumberTest.num.arrOfNums[j] == rationalTest[i].num.arrOfNums[j]);
        }
    }
}

int main()
{
    transZtoQTest();
    return 0;
}
