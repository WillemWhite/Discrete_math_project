/*
** Вычитание из натурального другого натурального, умноженного на цифру
** для случая с неотрицательным результатом
** Зависимости:
** SUB_NN_N
** MUL_ND_N
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
#include <iostream>
#include <cassert>
#include "head.h"

LongN subNDNtoN(const LongN& fNum , const int& digit , const LongN& sNum)
{
    LongN mult = mulNDtoN(sNum , digit);
    if (comNNtoD(fNum , mult) == 2)
        return subNNtoN(fNum , mult);
    else if (comNNtoD(fNum , mult) == 0)
        return { 0,{0} };
    else
    {
        std::cerr << "Error: the second numver cannot be greater than the first." << std::endl << std::endl;
        return { 0,{0} };
    }
}

void subNDNtoNtests()
{
    const int testsCount = 3;
    LongN testsNum[testsCount][2] = { { {3, {6, 5, 3, 9} }, {2, {1, 2, 1} } }, { {4, {2, 8, 2, 5, 1} }, {3, {8, 9, 6, 1} } }, { {3, {7, 2, 1, 9} }, {2, {6, 8, 9} } } }; // массив чисел
    int testsDigit[testsCount] = { 9, 9, 4 }; // массив цифр
    LongN rtests[testsCount] = { {3, {7, 6, 2, 8} }, {0, 0}, {3, {3, 8, 1, 5} } }; // массив результатов
    for (int i = 2; i < 3; ++i)
    {
        LongN res = subNDNtoN(testsNum[i][0] , testsDigit[i] , testsNum[i][1]);
        assert(res.deg == rtests[i].deg); // проверка совпадения порядков 
        for (int j = 0; j <= rtests[i].deg; ++j)
            assert(res.arrOfNums[j] == rtests[i].arrOfNums[j]); // проверка совпадения цифр 
    }
}

int main()
{
    subNDNtoNtests();
    return 0;
}
