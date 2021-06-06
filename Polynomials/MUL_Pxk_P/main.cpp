/*
** Умножение многочлена на x^k
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

LongP mulPxktoP(const LongP& polynomial , const int& k)
{
    LongP result = polynomial;

    if (k > 0)
    {
        // Увеличиваем степень многочлена на показатель степени x^k.
        result.deg += k;
        for (int i = result.deg; i >= k; i--)
        {
            // Переносим коэффициенты c i-ого на (i+k)-ое место.
            result.odds[i] = result.odds[i - k];

            // Зануляем элемент, из которого мы переносим число.
            // Для этого приравниваем числитель к 0, а знаменатель - к 1.
            result.odds[i - k].num = { 0,0,{0} };
            result.odds[i - k].denom = { 0,{1} };
        }

        for (int i = 0; i < k; ++i)
        {
            result.odds[i].num = { 0,0,{0} };
            result.odds[i].denom = { 0,{1} };
        }

        while (result.deg > 0 && !notZeroNtoB(absZtoN(result.odds[result.deg].num)))
            result.deg--;

        return result;
    }
    else if (k == 0)
        return result;
    else
    {
        std::cerr << "Error: k must be positive." << std::endl << std::endl;
        return { 0 };
    }
}

int main()
{
    LongP testPolynomials[3] =
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

    testPolynomial = mulPxktoP(testPolynomials[0] , 1);
    // - 10x^2 + 2x (+ 0)
    assert(testPolynomial.deg == 2);
    assert(testPolynomial.odds[0].num.sign == 0);
    assert(testPolynomial.odds[0].num.deg == 0);
    assert(testPolynomial.odds[0].num.arrOfNums[0] == 0);
    assert(testPolynomial.odds[0].denom.deg == 0);
    assert(testPolynomial.odds[0].denom.arrOfNums[0] == 1);
    assert(testPolynomial.odds[1].num.sign == 0);
    assert(testPolynomial.odds[1].num.deg == 0);
    assert(testPolynomial.odds[1].num.arrOfNums[0] == 2);
    assert(testPolynomial.odds[1].denom.deg == 0);
    assert(testPolynomial.odds[1].denom.arrOfNums[0] == 1);
    assert(testPolynomial.odds[2].num.sign == 1);
    assert(testPolynomial.odds[2].num.deg == 1);
    assert(testPolynomial.odds[2].num.arrOfNums[0] == 0);
    assert(testPolynomial.odds[2].num.arrOfNums[1] == 1);
    assert(testPolynomial.odds[2].denom.deg == 0);
    assert(testPolynomial.odds[2].denom.arrOfNums[0] == 1);

    testPolynomial = mulPxktoP(testPolynomials[1] , 1);
    // 3x^3 - 3/2x^2 - 9x (+ 0)
    assert(testPolynomial.deg == 3);
    assert(testPolynomial.odds[0].num.sign == 0);
    assert(testPolynomial.odds[0].num.deg == 0);
    assert(testPolynomial.odds[0].num.arrOfNums[0] == 0);
    assert(testPolynomial.odds[0].denom.deg == 0);
    assert(testPolynomial.odds[0].denom.arrOfNums[0] == 1);
    assert(testPolynomial.odds[1].num.sign == 1);
    assert(testPolynomial.odds[1].num.deg == 0);
    assert(testPolynomial.odds[1].num.arrOfNums[0] == 9);
    assert(testPolynomial.odds[1].denom.deg == 0);
    assert(testPolynomial.odds[1].denom.arrOfNums[0] == 1);
    assert(testPolynomial.odds[2].num.sign == 1);
    assert(testPolynomial.odds[2].num.deg == 0);
    assert(testPolynomial.odds[2].num.arrOfNums[0] == 3);
    assert(testPolynomial.odds[2].denom.deg == 0);
    assert(testPolynomial.odds[2].denom.arrOfNums[0] == 2);
    assert(testPolynomial.odds[3].num.sign == 0);
    assert(testPolynomial.odds[3].num.deg == 0);
    assert(testPolynomial.odds[3].num.arrOfNums[0] == 3);
    assert(testPolynomial.odds[3].denom.deg == 0);
    assert(testPolynomial.odds[3].denom.arrOfNums[0] == 1);

    testPolynomial = mulPxktoP(testPolynomials[1] , 0);
    // 3x^3 - 3/2x^2 - 9x (+ 0)
    assert(comPPtoB(testPolynomial , testPolynomials[1]));

    return 0;
}
