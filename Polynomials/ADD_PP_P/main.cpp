/*
** Сложение многочленов
** Зависимости:
** ADD_QQ_Q
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
#include <iostream>
#include "head.h"

LongP addPPtoP(const LongP& polynomial1 , const LongP& polynomial2)
{
    LongP result = { 0 };
    if (polynomial1.deg > polynomial2.deg)
    {
        result = polynomial1;

        for (int i = 0; i <= polynomial2.deg; i++)
        {
            result.odds[i] = addQQtoQ(polynomial1.odds[i] , polynomial2.odds[i]);
        }
        //проверка на "зануление" последних степеней
        while (result.deg > 0 && !notZeroNtoB(absZtoN(result.odds[result.deg].num)))
            result.deg--;
    }
    else
    {
        result = polynomial2;

        for (int i = 0; i <= polynomial1.deg; i++)
        {
            result.odds[i] = addQQtoQ(polynomial1.odds[i] , polynomial2.odds[i]);
        }
        //проверка на "зануление" последних степеней
        while (result.deg > 0 && !notZeroNtoB(absZtoN(result.odds[result.deg].num)))
            result.deg--;
    }

    return result;
}

void addPPtoPTest()
{
    LongP polynomialsTest[3] = { 0 };
    polynomialsTest[0].deg = 2;
    polynomialsTest[0].odds[0] = { {1, 6, {0,0,0,0,0,0,1}}, {0, {8}}, };
    polynomialsTest[0].odds[1] = { {1, 6, {0,0,0,0,0,0,1}}, {0, {8}}, };
    polynomialsTest[0].odds[2] = { {1, 6, {0,0,0,0,0,0,1}}, {0, {8}}, };

    polynomialsTest[1].deg = 3;
    polynomialsTest[1].odds[0] = { {1, 6, {0,0,0,0,0,0,1}}, {0, {8}}, };
    polynomialsTest[1].odds[1] = { {1, 6, {0,0,0,0,0,0,1}}, {0, {8}}, };
    polynomialsTest[1].odds[2] = { {0, 6, {0,0,0,0,0,0,1}}, {0, {8}}, };
    polynomialsTest[1].odds[3] = { {0, 4, {3, 8, 9, 1, 2}}, {2, {1,3,9}}, };

    polynomialsTest[2].deg = 4;
    polynomialsTest[2].odds[0] = { {1, 3, {2, 7, 9, 4}}, {0, {4}}, };
    polynomialsTest[2].odds[1] = { {1, 1, {2,1}}, {0, {7}}, };
    polynomialsTest[2].odds[2] = { {0, 8, {0,0,0,1,4,8,1,7,9}}, {0, {3}}, };
    polynomialsTest[2].odds[3] = { {0, 3, {0,0,0,1}}, {0, {7}}, };
    polynomialsTest[2].odds[4] = { {1, 1, {0,4}}, {0, {1}}, };

    LongP pseudoResults[3] = { 0 };
    pseudoResults[0].deg = 3;
    pseudoResults[0].odds[0] = { {1, 5, {0,0,0,0,5,2}}, {0,{1}}, };
    pseudoResults[0].odds[1] = { {1, 5, {0,0,0,0,5,2}}, {0,{1}}, };
    pseudoResults[0].odds[2] = { {0, 0, {0}}, {0, {1}}, };
    pseudoResults[0].odds[3] = { {0, 4, {3, 8, 9, 1, 2}}, {2, {1,3,9}}, };

    pseudoResults[1].deg = 4;
    pseudoResults[1].odds[0] = { {1, 5, {3,4,2,6,2,1}}, {0, {1}}, };
    pseudoResults[1].odds[1] = { {1, 5, {2,1,0,5,7,8}}, {0, {7}}, };
    pseudoResults[1].odds[2] = { {0, 8, {0,0,0,2,2,8,3,2,3}}, {0,{1}}, };
    pseudoResults[1].odds[3] = { {0, 3, {0,0,0,1}}, {0, {7}}, };
    pseudoResults[1].odds[4] = { {1, 1, {0,4}}, {0, {1}}, };

    pseudoResults[2].deg = 4;
    pseudoResults[2].odds[0] = { {1, 5, {3,4,2,6,2,1}}, {0, {1}}, };
    pseudoResults[2].odds[1] = { {1, 5, {2,1,0,5,7,8}}, {0, {7}}, };
    pseudoResults[2].odds[2] = { {0, 8, {0,0,0,2,7,0,4,2,3}}, {0,{1}}, };
    pseudoResults[2].odds[3] = { {0, 3, {7,5,1,8}}, {1, {9,4}}, };
    pseudoResults[2].odds[4] = { {1, 1, {0,4}}, {0, {1}}, };

    assert(comPPtoB(addPPtoP(polynomialsTest[0] , polynomialsTest[1]) , pseudoResults[0]));
    assert(comPPtoB(addPPtoP(polynomialsTest[0] , polynomialsTest[2]) , pseudoResults[1]));
    assert(comPPtoB(addPPtoP(polynomialsTest[1] , polynomialsTest[2]) , pseudoResults[2]));
}

int main()
{
    addPPtoPTest();
    return 0;
}
