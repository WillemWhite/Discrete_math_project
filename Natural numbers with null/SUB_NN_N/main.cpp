/*
** Вычитание из первого большего натурального числа второго меньшего или равного
** Зависимости:
** COM_NN_D
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

LongN subNNtoN(const LongN& first , const LongN& second)
{
    LongN copyFirst = { 0,{0} };
    LongN copySecond = { 0,{0} };

    switch (comNNtoD(first , second))
    {
    case 2:
        copyFirst = first;
        copySecond = second;
        break;
    case 1:
        copyFirst = second;
        copySecond = first;
        break;
    case 0:
        return copyFirst;
    }

    for (int i = 0; i <= copySecond.deg; i++)
    {
        if (copyFirst.arrOfNums[i] >= copySecond.arrOfNums[i])
            copyFirst.arrOfNums[i] = copyFirst.arrOfNums[i] - copySecond.arrOfNums[i];
        else
        {
            copyFirst.arrOfNums[i] += 10;
            copyFirst.arrOfNums[i + 1]--;
            copyFirst.arrOfNums[i] = copyFirst.arrOfNums[i] - copySecond.arrOfNums[i];
        }
    }

    for (int i = copySecond.deg + 1; i < copyFirst.deg; i++)
    {
        if (copyFirst.arrOfNums[i] == -1)
        {
            copyFirst.arrOfNums[i] += 10;
            copyFirst.arrOfNums[i + 1]--;
        }
    }

    int pos = copyFirst.deg;

    while (copyFirst.arrOfNums[pos] == 0 && pos > 0)
    {
        pos--;
    }

    copyFirst.deg = pos;

    return copyFirst;
}

int main()
{
    LongN n1 = { 10,{2,3,3,2,3,3,3,2,3,3,6} };
    LongN n2 = { 5,{1,2,5,3,2,5} };
    LongN n3 = { 10,{1,1,8,8,0,8,2,2,3,3,6} };
    LongN n4 = { 10,{0,9,2,5,8,2,2,2,3,3,6} };

    assert(comNNtoD(subNNtoN(n1 , n2) , n3) == 0);
    assert(comNNtoD(subNNtoN(n3 , n2) , n4) == 0);
}
