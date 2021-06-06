﻿/*
** Частное от деления многочлена на многочлен при делении с остатком
** Зависимости:
** DIV_QQ_Q
** DEG_P_N
** MUL_Pxk_P
** SUB_PP_P
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

LongP divPPtoP(const LongP& poly1 , const LongP& poly2)
{
    // копируем первый элемент для того, чтобы из него можно было вычитать.
    LongP copyPoly1 = poly1;
    LongP result = { 0 };
    // случай, когда можно делить (степень первого не меньше второго, иначе 0).
    if (degPtoN(poly1) >= degPtoN(poly2))
    {
        result.deg = degPtoN(poly1) - degPtoN(poly2);
        // для передвижения по массиву результата
        signed short int resDeg = result.deg;
        // пока не меньше степени делителя или! пока не 0
        // случай, если степень делителя равна 0
        while (degPtoN(copyPoly1) >= degPtoN(poly2) &&
            !(degPtoN(copyPoly1) == 0 &&
                copyPoly1.odds[0].num.deg == 0 &&
                copyPoly1.odds[0].num.arrOfNums[0] == 0))
        {
            LongQ coef = copyPoly1.odds[degPtoN(copyPoly1)];
            // коэффициент элемента результата
            result.odds[resDeg] = divQQtoQ(coef , poly2.odds[degPtoN(poly2)]);
            // передвигаемся дальше по элементам результата
            resDeg--;
            // вычитаем часть из первого
            copyPoly1 = subPPtoP(copyPoly1 ,
                mulPxktoP(mulPQtoP(poly2 , result.odds[resDeg + 1]) ,
                    degPtoN(copyPoly1) - degPtoN(poly2)));
        }

        return result;
    }
    else
    {
        return result; // если степень делителя больше делимого, то возвращаем {0}.
    }
}

int main()
{
    LongP p1 = { 0 };
    p1.deg = 2;
    p1.odds[0] = { {1, 1,{0,1}}, { 0,{1} }, };
    p1.odds[1] = { {0, 0,{2}}, { 0,{2} }, };
    p1.odds[2] = { {1, 0,{5}}, { 0,{3} }, };

    LongP p2 = { 0 };
    p2.deg = 1;
    p2.odds[0] = { {1, 1,{0,6}}, { 0,{1} }, };
    p2.odds[1] = { {0, 0,{6}}, { 0,{1} }, };

    LongP p12Res = { 0 };
    p12Res.deg = 1;
    p12Res.odds[0] = { {1, 1,{7,4}}, { 1,{8,1} }, };
    p12Res.odds[1] = { {1, 0,{5}}, { 1,{8,1} }, };

    LongP p3 = { 0 };
    p3.deg = 2;
    p3.odds[0] = { {1, 1,{0,6}}, { 0,{1} }, };
    p3.odds[1] = { {0, 0,{6}}, { 0,{1} }, };
    p3.odds[2] = { {1, 1,{0,1}}, { 0,{1} }, };
    p3.odds[3] = { {1, 0,{5}}, { 1,{8,1} }, };

    LongP p23Res = { 0 };
    p23Res.deg = 0;
    p23Res.odds[0] = { {0,0,{0}},{0,{0}} };

    assert(comPPtoB(divPPtoP(p1 , p2) , p12Res));
    assert(comPPtoB(divPPtoP(p2 , p3) , p23Res));

    return 0;
}
