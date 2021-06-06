/*
** Сокращение дроби
** Зависимости:
** ABS_Z_N
** GCF_NN_N
** DIV_ZZ_Z
** (то есть при создании данного модуля должны использоваться функции этих модулей).
**
** В случае неимения решения модуля (в соответствующем проекте) на данный момент, прошу
** использовать в коде прототипы функций, что описал в header файле (все функции называются
** примерно также, как и модули).
**
** А как появится решение, можете скопировать код функции соответствующего проекта для
** своей  программы и протестировать ее на различные входные данные. С технологией
** тестирования определюсь позднее.
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

LongQ redQtoQ(const LongQ& number)
{
    LongQ copyNumber = number;
    if (!notZeroNtoB(absZtoN(number.num)))
    {
        copyNumber.num.sign = 0;
        copyNumber.denom = { 0,{1} };
    }
    LongN GFCofNumAndDenom = GCFofNNtoN(absZtoN(copyNumber.num) , copyNumber.denom);
    LongQ redNumber = { 0 };
    redNumber.num = divZZtoZ(copyNumber.num , transNtoZ(GFCofNumAndDenom));
    redNumber.denom = divNNtoN(copyNumber.denom , GFCofNumAndDenom);
    return redNumber;
}

void redQtoQTest()
{
    LongQ initialNumbersTest[4] =
    {
        {
            {1, 6, {0, 0, 0, 0, 0, 0, 1}},
            {0, {8}}
        },
        {
            {0, 3, {4, 0, 6, 3}},
            {2, {6, 3, 6}}
        },
        {
            {0, 3, {2, 6, 6, 2}},
            {2, {7, 4, 8}}
        },
        {
            {1, 4, {1, 0, 1, 9, 9}},
            {4, {1, 0, 4, 1, 1}}
        }
    };
    LongQ pseudoRedNumbersTest[4] =
    {
        {
            {1, 5, {0, 0, 0, 5, 2, 1}},
            {0, {1}}
        },
        {
            {0, 1, {7, 1}},
            {0, {3}}
        },
        {
            {0, 1, {2, 2}},
            {0, {7}}
        },
        {
            {1, 2, {3, 1, 1}},
            {1, {3, 1}}
        }
    };
    for (int i = 0; i < 4; i++)
    {
        LongQ redNumberTest = redQtoQ(initialNumbersTest[i]);
        assert(redNumberTest.num.sign == pseudoRedNumbersTest[i].num.sign);
        assert(redNumberTest.num.deg == pseudoRedNumbersTest[i].num.deg);
        for (int j = 0; j <= redNumberTest.num.deg; j++)
        {
            assert(redNumberTest.num.arrOfNums[j] == pseudoRedNumbersTest[i].num.arrOfNums[j]);
        }
        assert(redNumberTest.denom.deg == pseudoRedNumbersTest[i].denom.deg);
        for (int j = 0; j <= redNumberTest.denom.deg; j++)
        {
            assert(redNumberTest.denom.arrOfNums[j] == pseudoRedNumbersTest[i].denom.arrOfNums[j]);
        }
    }
}

int main()
{
    redQtoQTest();
    return 0;
}
