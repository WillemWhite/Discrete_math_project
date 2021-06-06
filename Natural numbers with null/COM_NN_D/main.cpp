/*
** Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.
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

int comNNtoD(const LongN& n1 , const LongN& n2)
{
    if (n1.deg == n2.deg)
    {
        int i = n1.deg;
        while ((i > 0) && (n1.arrOfNums[i] == n2.arrOfNums[i]))
        {
            --i;
        }
        if (n1.arrOfNums[i] > n2.arrOfNums[i])
            return 2;
        else if (n1.arrOfNums[i] == n2.arrOfNums[i])
            return 0;
        else
            return 1;
    }
    else if (n1.deg < n2.deg)
        return 1;
    else
        return 2;
}

void comNNtoDtest()
{

    assert(comNNtoD({ 3,{ 6, 2, 8, 4 } } , { 3, { 6, 2, 8, 4 } }) == 0);

    assert(comNNtoD({ 3,{ 1, 2, 3, 4 } } , { 2, {5, 7, 7} }) == 2);

}

int main()
{
    comNNtoDtest();
    return 0;
}
