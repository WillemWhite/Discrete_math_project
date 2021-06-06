/*
** Частное от деления большего натурального числа на меньшее или равное
** натуральное с остатком(делитель отличен от нуля)
** Зависимости:
** DIV_NN_Dk
** SUB_NDN_N
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


LongN divNNtoN(const LongN& Num1 , const LongN& Num2)
{
    LongN fNum = { 0, {0} };
    LongN sNum = { 0, {0} };

    // если первое - 0, то оно делится на любое натуральное кроме 0 и получается 0.
    if (!notZeroNtoB(Num1) && notZeroNtoB(Num2))
        return { 0 };

    switch (comNNtoD(Num1 , Num2))
    {
    case 2:
        fNum = Num1;
        sNum = Num2;
        break;
    case 1:
        fNum = Num2;
        sNum = Num1;
        break;
    case 0:
        LongN res = { 0, {1} };
        return res;
    }

    if (notZeroNtoB(sNum))
    {
        LongN part = { sNum.deg, {0} };

        for (int i = 0; i <= sNum.deg; ++i)
            part.arrOfNums[i] = fNum.arrOfNums[fNum.deg - sNum.deg + i];

        int pos = fNum.deg - sNum.deg;

        LongN result = { divNNtoDk(fNum,sNum).deg, {0} };

        while (pos >= 0)
        {
            while (comNNtoD(sNum , part) == 2 && pos > 0)
            {
                part = mulNktoN(part , 1);
                pos--;
                part.arrOfNums[0] = fNum.arrOfNums[pos];
            }

            if (comNNtoD(sNum , part) != 2)
            {
                int deg = divNNtoDk(part , sNum).deg;
                result.arrOfNums[deg + pos] = divNNtoDk(part , sNum).arrOfNums[deg];
                part = subNDNtoN(part , result.arrOfNums[deg + pos] , sNum);
            }
            else
                break;
        }

        return result;
    }
    else
    {
        std::cerr << "Error: denominator cannot be zero." << std::endl << std::endl;
        return { 0,{0} };
    }
}
void divNNtoNtest()
{
    assert(comNNtoD(divNNtoN({ 3,{ 7, 2, 8, 4 } } , { 0, {1} }) , { 3,{ 7, 2, 8, 4 } }) == 0);
    assert(comNNtoD(divNNtoN({ 3,{ 6, 2, 8, 4 } } , { 3, { 6, 2, 8, 4 } }) , { 0,{1} }) == 0);
    assert(comNNtoD(divNNtoN({ 3,{ 1, 2, 3, 4 } } , { 2, {5, 7, 7} }) , { 0, {5} }) == 0);
}
int main()
{
    divNNtoNtest();
}
