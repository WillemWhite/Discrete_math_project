/*
** Вычитание многочленов
** Зависимости:
** SUB_QQ_Q
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

LongP subPPtoP(const LongP& pol1 , const LongP& pol2)
{
    LongP invPol2 = pol2;

    for (int i = 0; i <= pol2.deg; i++)
    {
        invPol2.odds[i].num = mulZMtoZ(pol2.odds[i].num);
    }

    return addPPtoP(pol1 , invPol2);
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

    testPolynomial = subPPtoP(testPolynomials[0] , testPolynomials[1]);
    // -3x^2 - 17/2x + 11
    assert(testPolynomial.deg == 2);

    assert(testPolynomial.odds[0].num.sign == 0);
    assert(testPolynomial.odds[0].num.deg == 1);
    assert(testPolynomial.odds[0].num.arrOfNums[0] == 1);
    assert(testPolynomial.odds[0].num.arrOfNums[1] == 1);
    assert(testPolynomial.odds[0].denom.deg == 0);
    assert(testPolynomial.odds[0].denom.arrOfNums[0] == 1);

    assert(testPolynomial.odds[1].num.sign == 1);
    assert(testPolynomial.odds[1].num.deg == 1);
    assert(testPolynomial.odds[1].num.arrOfNums[0] == 7);
    assert(testPolynomial.odds[1].num.arrOfNums[1] == 1);
    assert(testPolynomial.odds[1].denom.deg == 0);
    assert(testPolynomial.odds[1].denom.arrOfNums[0] == 2);

    assert(testPolynomial.odds[2].num.sign == 1);
    assert(testPolynomial.odds[2].num.deg == 0);
    assert(testPolynomial.odds[2].num.arrOfNums[0] == 3);
    assert(testPolynomial.odds[2].denom.deg == 0);
    assert(testPolynomial.odds[2].denom.arrOfNums[0] == 1);

    return 0;
}
