/*
** Старший коэффициент многочлена
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

LongQ ledPtoQ(const LongP& polynomial)
{
    // Просто возвращаем коэффициент, индекс которого равен степени многочлена.
    return polynomial.odds[polynomial.deg];
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
                    {1, 0, {2}},
                    {0, {1}}
                },
                {
                    {-1, 1, {0, 1}},
                    {0, {1}}
                }
            }
        },
        //  3x^2 - 3/2x - 9
        {
            2,
            {
                {
                    {-1, 0, {9}},
                    {0, {1}}
                },
                {
                    {-1, 0, {3}},
                    {0, {2}}
                },
                {
                    {1, 0, {3}},
                    {0, {1}}
                }
            }
        }
    };

    LongQ testLed = ledPtoQ(testPolynomials[0]);
    // -10
    assert(testLed.num.sign == -1);
    assert(testLed.num.deg == 1);
    assert(testLed.num.arrOfNums[0] == 0);
    assert(testLed.num.arrOfNums[1] == 1);
    assert(testLed.denom.deg == 0);
    assert(testLed.denom.arrOfNums[0] == 1);

    testLed = ledPtoQ(testPolynomials[1]);
    // 3
    assert(testLed.num.sign == 1);
    assert(testLed.num.deg == 0);
    assert(testLed.num.arrOfNums[0] == 3);
    assert(testLed.denom.deg == 0);
    assert(testLed.denom.arrOfNums[0] == 1);

    return 0;
}
