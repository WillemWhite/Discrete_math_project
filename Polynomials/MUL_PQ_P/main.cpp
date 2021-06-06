/*
** Умножение многочлена на рациональное число
** Зависимости:
** MUL_QQ_Q
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

LongP mulPQtoP(const LongP& polynomial , const LongQ& number)
{
    LongP result = { 0 };
    result.deg = polynomial.deg;

    if (!notZeroNtoB(absZtoN(number.num)))
        return { 0 };

    for (int i = 0; i <= polynomial.deg; i++)
    {
        result.odds[i] = mulQQtoQ(polynomial.odds[i] , number);
    }

    return result;
}

int main()
{
    LongP testPolynomials[2] =
    {
        //  - 10x + 2
        {
            1,
            {
                {
                    {0, 0, {2}},
                    {0, {1}}
                },
                {
                    {1, 1, {0, 1}},
                    {0, {1}}
                }
            }
        },
        //  3x^2 - 3/2x - 9
        {
            2,
            {
                {
                    {1, 0, {9}},
                    {0, {1}}
                },
                {
                    {1, 0, {3}},
                    {0, {2}}
                },
                {
                    {0, 0, {3}},
                    {0, {1}}
                }
            }
        }
    };

    LongP testPolynomial;

    // Пришлось проверять каждый элемент отдельно, иначе assert выдаёт ошибку.

    testPolynomial = mulPQtoP(testPolynomials[0] , { {0, 0, {3}}, {0, {1}} });
    // -30x + 6
    assert(testPolynomial.deg == 1);
    assert(testPolynomial.odds[0].num.sign == 0);
    assert(testPolynomial.odds[0].num.deg == 0);
    assert(testPolynomial.odds[0].num.arrOfNums[0] == 6);
    assert(testPolynomial.odds[0].denom.deg == 0);
    assert(testPolynomial.odds[0].denom.arrOfNums[0] == 1);
    assert(testPolynomial.odds[1].num.sign == 1);
    assert(testPolynomial.odds[1].num.deg == 1);
    assert(testPolynomial.odds[1].num.arrOfNums[0] == 0);
    assert(testPolynomial.odds[1].num.arrOfNums[1] == 3);
    assert(testPolynomial.odds[1].denom.deg == 0);
    assert(testPolynomial.odds[1].denom.arrOfNums[0] == 1);

    testPolynomial = mulPQtoP(testPolynomials[1] , { {1, 0, {2}}, {0, {1}} });
    // -6x^2 + 3x + 18
    assert(testPolynomial.deg == 2);
    assert(testPolynomial.odds[0].num.sign == 0);
    assert(testPolynomial.odds[0].num.deg == 1);
    assert(testPolynomial.odds[0].num.arrOfNums[0] == 8);
    assert(testPolynomial.odds[0].num.arrOfNums[1] == 1);
    assert(testPolynomial.odds[0].denom.deg == 0);
    assert(testPolynomial.odds[0].denom.arrOfNums[0] == 1);
    assert(testPolynomial.odds[1].num.sign == 0);
    assert(testPolynomial.odds[1].num.deg == 0);
    assert(testPolynomial.odds[1].num.arrOfNums[0] == 3);
    assert(testPolynomial.odds[1].denom.deg == 0);
    assert(testPolynomial.odds[1].denom.arrOfNums[0] == 1);
    assert(testPolynomial.odds[2].num.sign == 1);
    assert(testPolynomial.odds[2].num.deg == 0);
    assert(testPolynomial.odds[2].num.arrOfNums[0] == 6);
    assert(testPolynomial.odds[2].denom.deg == 0);
    assert(testPolynomial.odds[2].denom.arrOfNums[0] == 1);

    return 0;
}
