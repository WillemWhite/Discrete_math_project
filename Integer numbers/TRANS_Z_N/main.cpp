/*
**Преобразование целого неотрицательного в натуральное
**Зависимостей с другими модулями нет, функционал реализуется сразу.
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

LongN transZtoN(const LongZ& number)
{
    LongN result = { 0,{0} };

    if (number.sign == 0) // только положительное целое число является натуральным
    {
        // само число не изменяется => номер старшей позиции и сами цифры числа остаются теми же
        result.deg = number.deg;
        for (int i = 0; i <= result.deg; i++)
            result.arrOfNums[i] = number.arrOfNums[i];
    }
    else
    {
        std::cerr << "Error: integer must be positive or 0 to convert." << std::endl << std::endl;
        return { 0,0,{0} };
    }

    return result;
}

int main()
{
    LongZ numZ = { 0, 3,{ 6, 2, 8, 4 } };
    LongN numN = { 3,{ 6, 2, 8, 4 } };
    assert(comNNtoD(numN , transZtoN(numZ)) == 0);
    numZ = { 0, 4,{ 6, 5, 2, 8, 4 } };
    numN = { 4,{ 6, 5, 2, 8, 4 } };
    assert(comNNtoD(numN , transZtoN(numZ)) == 0);
    numZ = { 0, 2,{ 2, 8, 4 } };
    numN = { 2,{ 2, 8, 4 } };
    assert(comNNtoD(numN , transZtoN(numZ)) == 0);

    return 0;
}
