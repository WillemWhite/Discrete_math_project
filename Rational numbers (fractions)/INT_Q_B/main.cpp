/*
** Проверка на целое, если рациональное число является целым, то «да», иначе «нет»
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

bool intQtoB(const LongQ& number)
{
    LongQ redNumber = redQtoQ(number);
    if (redNumber.denom.deg == 0 && redNumber.denom.arrOfNums[0] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void intQtoBTest()
{
    LongQ rationalTest[4] =
    {
        {
            {1, 3, {4, 2, 2, 4}},
            {0, {4}}
        },
        {
            {-1, 5, {4, 3, 2, 1, 7, 6}},
            {0, {1}}
        },
        {
            {1, 3, {5, 8, 7, 5}},
            {1, {5, 6}}
        },
        {
            {1, 8, {1, 5, 9, 7, 2, 1, 1, 4, 6}},
            {2, {1, 2, 3}}
        }
    };
    assert(intQtoB(rationalTest[0]) == true);
    assert(intQtoB(rationalTest[1]) == true);
    assert(intQtoB(rationalTest[2]) == true);
    assert(intQtoB(rationalTest[3]) == false);
}

int main()
{
    intQtoBTest();
    return 0;
}
