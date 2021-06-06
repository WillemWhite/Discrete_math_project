/*
** Умножение многочленов
** Зависимости:
** MUL_PQ_P
** MUL_Pxk_P
** ADD_PP_P
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
#include <cassert>
#include "head.h"

LongP mulPPtoP(const LongP& firstPol , const LongP& secondPol)
{
    LongP result = { 0 };

    result = mulPQtoP(secondPol , firstPol.odds[0]);
    for (int i = 1; i <= firstPol.deg; i++) {
        // i элеменет: a_i * x^i * (secondPol)
        LongP multiplication = mulPQtoP(mulPxktoP(secondPol , i) , firstPol.odds[i]);

        result = addPPtoP(multiplication , result);
    }

    // проверка на нули.
    while (result.deg > 0 && !notZeroNtoB(absZtoN(result.odds[result.deg].num)))
        result.deg--;

    return result;
}

int main() {
    LongP first = { 4,
    {
        {
            {0, 2, {0, 5, 2}},
            {0, {1}}
        },
        {
            {0, 2, {0, 5, 2}},
            {0, {1}}
        },
        {
            {0, 2, {0, 1, 5}},
            {0, {1}}
        },
        {
            {0, 2, {5, 2, 1}},
            {0, {1}}
        },
        {
            {1, 2, {0, 5, 2}},
            {0, {1}}
        }
    } };
    LongP second = { 3,
    {
        {
            {0, 0, {1}},
            {0, {1}}
        },
        {
            {0, 0, {1}},
            {0, {1}}
        },
        {
            {1, 0, {3}},
            {0, {1}}
        },
        {
            {0, 0, {1}},
            {0, {1}}
        }
    } };

    LongP result = mulPPtoP(first , second);
    assert(result.deg == 7);
    LongQ res = { {0, 2, {0, 5, 2 }}, { 0, {1} } };
    assert(result.odds[0].num.deg == res.num.deg);
    assert(result.odds[0].num.sign == res.num.sign);
    for (int i = 0; i <= result.odds[0].num.deg; i++)
        assert(result.odds[0].num.arrOfNums[i] == res.num.arrOfNums[i]);

    res = { {1, 2, { 0, 5, 2 }}, { 0, {1} } };
    assert(result.odds[7].num.deg == res.num.deg);
    assert(result.odds[7].num.sign == res.num.sign);
    for (int i = 0; i <= result.odds[7].num.deg; i++)
        assert(result.odds[7].num.arrOfNums[i] == res.num.arrOfNums[i]);

    res = { {1, 3, { 5, 0, 4, 1 }}, { 0, {1} } };
    assert(result.odds[4].num.deg == res.num.deg);
    assert(result.odds[4].num.sign == res.num.sign);
    for (int i = 0; i <= result.odds[4].num.deg; i++)
        assert(result.odds[4].num.arrOfNums[i] == res.num.arrOfNums[i]);

    return 0;
}
