/*
** Умножение натурального числа на 10^k
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

using namespace std;

LongN mulNktoN(const LongN& naturalNumber , const int& k)
{
    LongN result = { naturalNumber.deg + k,{0} };

    for (int i = result.deg; i >= k; i--)//сдвигаем элементы массива вправо на К(начинаем с конца до К-го элемента)
    {
        result.arrOfNums[i] = naturalNumber.arrOfNums[i - k];
    }

    if (naturalNumber.deg == 0 && naturalNumber.arrOfNums[0] == 0)
        result = { 0,{0} };

    return result;
}

void mulNktoNtest()
{
    assert(comNNtoD(mulNktoN({ 3, {7, 2, 8, 4 } } , 0) , { 3,{7, 2, 8, 4 } }) == 0);
    assert(comNNtoD(mulNktoN({ 3, { 7, 2, 8, 4 } } , 2) , { 5, {0, 0, 7, 2, 8, 4 } }) == 0);
    assert(comNNtoD(mulNktoN({ 4, {6, 5, 2, 1, 5 } } , 4) , { 8, { 0, 0, 0, 0, 6, 5, 2, 1, 5 } }) == 0);
}

int main()
{
    mulNktoNtest();
    return 0;
}
