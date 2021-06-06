/*
** Деление дробей (делитель отличен от нуля)
** Зависимости:
** MUL_ZZ_Z
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

LongQ divQQtoQ(const LongQ& number1 , const LongQ& number2)
{
    if (!(number2.num.deg == 0 && number2.num.arrOfNums[0] == 0))
    {
        LongQ result = { 0 };
        LongQ flippedNumber2 = { 0 };

        flippedNumber2.num = transNtoZ(number2.denom);
        flippedNumber2.num.sign = number2.num.sign;
        flippedNumber2.denom = absZtoN(number2.num);

        result.num = mulZZtoZ(number1.num , flippedNumber2.num);
        result.denom = mulNNtoN(number1.denom , flippedNumber2.denom);

        return redQtoQ(result);
    }
    else
    {
        std::cerr << "Error: denominator cannot be zero." << std::endl << std::endl;
        return { 0 };
    }
}

void divQQtoQTest()
{
    LongQ numbersTest[4] =
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
            {1, 0, {1}},
            {4, {1, 0, 4, 1, 1}}
        }
    };
    LongQ pseudoResultOfDivTest[4] =
    {
        {
            {1, 5, {0, 0, 0, 5, 7, 3}},
            {1, {7, 1}}
        },
        {
            {0, 2, {9, 1, 1}},
            {1, {6, 6}}
        },
        {
            {1, 5, {2, 2, 8, 0, 5, 2}},
            {0, {7}}
        },
        {
            {0, 0, {1}},
            {9, {0, 0, 0, 5, 2, 1, 5, 2, 4, 1}}
        }
    };
    LongQ resultsTest[4] =
    {
        divQQtoQ(numbersTest[0], numbersTest[1]),
        divQQtoQ(numbersTest[1], numbersTest[2]),
        divQQtoQ(numbersTest[2], numbersTest[3]),
        divQQtoQ(numbersTest[3], numbersTest[0]),
    };
    assert(comQQtoB(resultsTest[0] , pseudoResultOfDivTest[0]) == true);
    assert(comQQtoB(resultsTest[1] , pseudoResultOfDivTest[1]) == true);
    assert(comQQtoB(resultsTest[2] , pseudoResultOfDivTest[2]) == true);
    assert(comQQtoB(resultsTest[3] , pseudoResultOfDivTest[3]) == true);
}

int main()
{
    divQQtoQTest();
    return 0;
}
