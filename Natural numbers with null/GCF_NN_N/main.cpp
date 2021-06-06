/*
** НОД натуральных чисел
** Зависимости:
** MOD_NN_N
** COM_NN_D
** NZER_N_B
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

LongN GCFofNNtoN(const LongN& firstNumber , const LongN& secondNumber)
{
    LongN first = { 0,{0} };
    LongN second = { 0,{0} };

    switch (comNNtoD(firstNumber , secondNumber))
    {
    case 2:
        first = firstNumber;
        second = secondNumber;
        break;
    case 1:
        first = secondNumber;
        second = firstNumber;
        break;
    case 0:
        return firstNumber;
    }

    LongN result = { 0,{0} };

    while (notZeroNtoB(second))
    {
        LongN remainder = modNNtoN(first , second);

        first = second;
        second = remainder;
    }

    return first;
}

int main()
{
    LongN first = { 5, {0, 0, 3, 6, 4, 1} };
    LongN second = { 5, {5, 9, 2, 9, 5, 6} };

    assert(GCFofNNtoN(first , second).deg == 1 &&
        GCFofNNtoN(first , second).arrOfNums[0] == 5 &&
        GCFofNNtoN(first , second).arrOfNums[1] == 3);
    return 0;
}
