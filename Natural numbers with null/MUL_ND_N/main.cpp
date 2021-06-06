/*
** Умножение натурального числа на цифру
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


LongN mulNDtoN(const LongN& naturalNumber , const int& numeral)
{
    LongN result = { 0,{0} };
    int summNumber = 0;
    result.deg = naturalNumber.deg;
    if (numeral == 0) // условие, при котором натуральное число домножается на нуль => номер старший степени = 0 и число = 0
    {
        result.deg = 0;
        result.arrOfNums[0] = 0;
        return result;
    }
    for (int i = 0; i <= naturalNumber.deg; i++)
    {
        int multiplication = naturalNumber.arrOfNums[i] * numeral; // умножение цифры в ячейке на другую цифру
        result.arrOfNums[i] = (multiplication + summNumber) % 10; // фактическая цифра в данной ячейке
        summNumber = (multiplication + summNumber) / 10; // цифра в "уме", которую суммируют для числа следующего разряда
    }
    if (summNumber != 0) // если при выходе из цикла for цифра в "уме" ненулевая, то степень повышается на 1, а следующей ячейке 
    //присваивается значение цифры в "уме"
    {
        result.deg++;
        result.arrOfNums[result.deg] = summNumber;
    }
    return result;
}

int main()
{
    const int count = 5;
    LongN test[count] = {};
    test[0] = { 2, { 5,0,2 } };
    test[1] = { 0, {0} };
    test[2] = { 2, {9,9,9} };
    test[3] = { 2, {2,4,0} };


    int D[count];
    D[0] = 7;
    D[1] = 0;
    D[2] = 4;
    D[3] = 0;

    LongN result = mulNDtoN(test[0] , D[0]);
    assert(result.deg == 3);
    assert(result.arrOfNums[0] == 5);
    assert(result.arrOfNums[1] == 3);
    assert(result.arrOfNums[2] == 4);
    assert(result.arrOfNums[3] == 1);

    result = mulNDtoN(test[1] , D[1]);
    assert(result.deg == 0);
    assert(result.arrOfNums[0] == 0);

    result = mulNDtoN(test[2] , D[2]);
    assert(result.deg == 3);
    assert(result.arrOfNums[0] == 6);
    assert(result.arrOfNums[1] == 9);
    assert(result.arrOfNums[2] == 9);
    assert(result.arrOfNums[3] == 3);

    result = mulNDtoN(test[3] , D[3]);
    assert(result.deg == 0);
    assert(result.arrOfNums[0] == 0);
    return 0;
}
