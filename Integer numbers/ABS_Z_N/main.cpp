/*
** Абсолютная величина числа, результат - натуральное
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

LongN absZtoN(const LongZ& integer)
{
    LongN result = { 0, {0} };
    //Копируем номер старшей позиции
    result.deg = integer.deg;
    //Копируем массив
    for (int i = 0; i <= integer.deg; i++)
    {
        result.arrOfNums[i] = integer.arrOfNums[i];
    }

    return result;
}

int main()
{
    LongZ numZ = { 1, 3,{ 6, 2, 8, 4 } };
    LongN numN = { 3,{ 6, 2, 8, 4 } };
    assert(comNNtoD(numN , absZtoN(numZ)) == 0);
    numZ = { 1, 4,{ 6, 5, 2, 8, 4 } };
    numN = { 4,{ 6, 5, 2, 8, 4 } };
    assert(comNNtoD(numN , absZtoN(numZ)) == 0);
    numZ = { 1, 2,{ 2, 8, 4 } };
    numN = { 2,{ 2, 8, 4 } };
    assert(comNNtoD(numN , absZtoN(numZ)) == 0);

    return 0;
}
