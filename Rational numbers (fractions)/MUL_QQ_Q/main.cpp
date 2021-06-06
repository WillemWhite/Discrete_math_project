/*
** Умножение дробей
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

LongQ mulQQtoQ(const LongQ& number1 , const LongQ& number2)
{
    LongQ result = { 0 };
    result.num = mulZZtoZ(number1.num , number2.num);
    result.denom = mulNNtoN(number1.denom , number2.denom);
    return redQtoQ(result);
}

void mulQQtoQTest()
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
            {1, 4, {1, 0, 1, 9, 9}},
            {4, {1, 0, 4, 1, 1}}
        }
    };
    LongQ pseudoResultOfMulTest[3] =
    {
        {
            {1, 6, {0, 0, 0, 5, 2, 1, 2}},
            {0, {3}}
        },
        {
            {0, 2, {4, 7, 3}},
            {1, {1, 2}}
        },
        {
            {1, 3, {6, 8, 4, 2}},
            {1, {1, 9}}
        }
    };
    for (int i = 0; i < 3; i++)
    {
        LongQ resultOfMulTest = mulQQtoQ(numbersTest[i] , numbersTest[i + 1]);
        assert(resultOfMulTest.num.sign == pseudoResultOfMulTest[i].num.sign);
        assert(resultOfMulTest.num.deg == pseudoResultOfMulTest[i].num.deg);
        for (int j = 0; j <= resultOfMulTest.num.deg; j++)
        {
            assert(resultOfMulTest.num.arrOfNums[j] == pseudoResultOfMulTest[i].num.arrOfNums[j]);
        }
        assert(resultOfMulTest.denom.deg == pseudoResultOfMulTest[i].denom.deg);
        for (int j = 0; j <= resultOfMulTest.denom.deg; j++)
        {
            assert(resultOfMulTest.denom.arrOfNums[j] == pseudoResultOfMulTest[i].denom.arrOfNums[j]);
        }
    }
}

int main()
{
    mulQQtoQTest();
    return 0;
}
