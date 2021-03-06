/*
** Остаток от деления большего натурального числа на меньшее или равное
** натуральное с остатком(делитель отличен от нуля)
** Зависимости:
** DIV_NN_N
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
#include<cassert>
#include "head.h"

LongN modNNtoN(const LongN& natNumber1 , const LongN& natNumber2)
{
    LongN fNum = { 0, {0} };
    LongN sNum = { 0, {0} };

    switch (comNNtoD(natNumber1 , natNumber2))
    {
    case 2:
        fNum = natNumber1;
        sNum = natNumber2;
        break;
    case 1:
        fNum = natNumber2;
        sNum = natNumber1;
        break;
    case 0:
        LongN res = { 0, {0} };
        return res;
    }

    LongN result = { 0,{0} };

    if (notZeroNtoB(sNum))
    {
        LongN stack1 = divNNtoN(fNum , sNum); //деление чисел нацело
        LongN stack2 = mulNNtoN(sNum , stack1); //умножение второго числа на результат деления
        result = subNNtoN(fNum , stack2); //вычитание полученных чисел
    }
    else
    {
        std::cerr << "Error: denominator cannot be zero." << std::endl << std::endl;
        return { 0,{0} };
    }
}

void modNNtoNtest()
{
    assert(comNNtoD(modNNtoN({ 3,{ 6, 2, 8, 4 } } , { 3, { 6, 2, 8, 4 } }) , { 0,{0} }) == 0);
    assert(comNNtoD(modNNtoN({ 3,{ 1, 2, 3, 4 } } , { 2, {5, 7, 7} }) , { 2, {6,4,4} }) == 0);
}
int main()
{
    modNNtoNtest();
    return 0;
}
