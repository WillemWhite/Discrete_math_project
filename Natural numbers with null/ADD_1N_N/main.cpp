/*
** Добавление 1 к натуральному числу
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

LongN add1NtoN(const LongN& number)
{
    LongN result = number;
    int pos = 0;
    if (result.arrOfNums[pos] == 9)
    {
        // заменяем цифру, которая при добавлении к ней 1 равна 10, на 0
        do
        {
            result.arrOfNums[pos] = 0;
            pos++;
        } while (result.arrOfNums[pos] + 1 > 9);

        ++result.arrOfNums[pos]; // прибавляем 1
        if (pos > result.deg) // в случае, если увеличивается порядок
            ++result.deg; //например 999 + 1 = 1000
    }
    else
    {
        result.arrOfNums[pos] = result.arrOfNums[pos] + 1;
    }
    return result;
}

void add1NtoNtest()
{
    LongN num1 = { 5, {9,8,6,2,3,9} };
    LongN res1 = { 5, {0,9,6,2,3,9} };
    assert(comNNtoD(add1NtoN(num1) , res1) == 0);
    LongN num2 = { 7, {7,5,6,2,3,3,2,1} };
    LongN res2 = { 7, {8,5,6,2,3,3,2,1} };
    assert(comNNtoD(add1NtoN(num2) , res2) == 0);
}

int main()
{
    add1NtoNtest();
}
