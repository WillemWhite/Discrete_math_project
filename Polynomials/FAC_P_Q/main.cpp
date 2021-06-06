/*
** Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
** Зависимости:
** ABS_Z_N
** TRANS_Z_N
** LCM_NN_N
** GCF_NN_N
** TRANS_N_Z
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

LongQ facPtoQ(LongP& polynomial)
{
    if (polynomial.deg == 0 && polynomial.odds[0].num.deg == 0 && polynomial.odds[0].num.arrOfNums[0] == 0)
    {
        std::cerr << "Error: polynomial cannot be zero." << std::endl << std::endl;
        return { 0 };
    }

    LongQ result = { 0 };

    result.denom = polynomial.odds[0].denom;

    for (int i = 1; i <= polynomial.deg; i++)
        result.denom = LCMofNNtoN(result.denom , polynomial.odds[i].denom);

    result.num = transNtoZ(absZtoN(polynomial.odds[0].num));
    for (int i = 1; i <= polynomial.deg; i++)
        result.num = transNtoZ(GCFofNNtoN(transZtoN(result.num) , absZtoN(polynomial.odds[i].num)));

    for (int i = 0; i <= polynomial.deg; i++)
        polynomial.odds[i] = divQQtoQ(polynomial.odds[i] , result);

    return result;
}

int main()
{
    LongP p1 = { 0 };
    p1.deg = 2;
    p1.odds[0] = { {1, 1,{0,1}}, { 0,{1} }, };
    p1.odds[1] = { {0, 0,{2}}, { 0,{2} }, };
    p1.odds[2] = { {1, 0,{5}}, { 0,{3} }, };

    LongQ resQ1 = { {0, 0, {1} }, {0, {6} } };

    LongP p1Res = { 0 };
    p1Res.deg = 2;
    p1Res.odds[0] = { {1, 1,{0,6}}, { 0,{1} }, };
    p1Res.odds[1] = { {0, 0,{6}}, { 0,{1} }, };
    p1Res.odds[2] = { {1, 1,{0,1}}, { 0,{1} }, };

    LongP p2 = { 0 };
    p2.deg = 2;
    p2.odds[0] = { {0, 1,{0,1}}, { 0,{4} }, };
    p2.odds[1] = { {0, 1,{0,6}}, { 0,{6} }, };
    p2.odds[2] = { {0, 1,{2,1}}, { 0,{9} }, };

    LongQ resQ2 = { {0,0, {2} }, {1, {6,3} } };

    LongP p2Res = { 0 };
    p2Res.deg = 2;
    p2Res.odds[0] = { {0, 1,{5,4}}, { 0,{1} }, };
    p2Res.odds[1] = { {0, 2,{0,8,1}}, { 0,{1} }, };
    p2Res.odds[2] = { {0, 1,{4,2}}, { 0,{1} }, };

    assert(comQQtoB(facPtoQ(p1) , resQ1) && comPPtoB(p1 , p1Res));
    assert(comQQtoB(facPtoQ(p2) , resQ2) && comPPtoB(p2 , p2Res));

    return 0;
}
