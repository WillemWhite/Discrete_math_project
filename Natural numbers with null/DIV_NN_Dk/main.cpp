/*
** Вычисление первой цифры деления большего натурального на меньшее,
** домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)
** Зависимости:
** MUL_Nk_N
** COM_NN_D
** !Добавлена зависимость в ходе решения задачи:
** MUL_ND_N
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

LongN divNNtoDk(const LongN& Num1 , const LongN& Num2)
{
    LongN fNum = { 0,{0} } , sNum = { 0,{0} };

    // если первое - 0, то оно делится на любое натуральное кроме 0 и получается 0.
    if (!notZeroNtoB(Num1) && notZeroNtoB(Num2))
        return { 0 };

    switch (comNNtoD(Num1 , Num2))
    {
    case 2:
        fNum = Num1;
        sNum = Num2;
        break;
    case 1:
        fNum = Num2;
        sNum = Num1;
        break;
    case 0:
        LongN res = { 0, {1} };
        return res;
    }

    if (notZeroNtoB(sNum))
    {
        LongN part = { sNum.deg, {0} };

        for (int i = 0; i <= sNum.deg; ++i)
            part.arrOfNums[i] = fNum.arrOfNums[fNum.deg - sNum.deg + i];

        if (comNNtoD(sNum , part) == 2)
        {
            part = mulNktoN(part , 1);
            if (fNum.deg - sNum.deg >= 1) //чтобы лишний раз не ругалась ide
                //а так это естественно благодаря ранней отсортировке с помощью switch.
                part.arrOfNums[0] = fNum.arrOfNums[fNum.deg - sNum.deg - 1];
        }

        LongN k = { 0,{0} };
        LongN Fdigit = { 0,{0} };

        for (int i = 2; i <= 10; ++i)
        {
            int count = 0;

            k = mulNDtoN(sNum , i);

            if (comNNtoD(k , part) == 2)
            {
                k = mulNDtoN(sNum , i - 1);
                Fdigit.arrOfNums[0] = i - 1;
                break;
            }

            k = { 0,{0} };
        }
        return mulNktoN(Fdigit , fNum.deg - part.deg);
    }
    else
    {
        std::cerr << "Error: denominator cannot be zero." << std::endl << std::endl;
        return { 0,{0} };
    }
}

void divNNtoDkTests()
{
    const int testsCount = 3;
    LongN tests[testsCount][2] = { { {2, {1, 2, 1} }, {3, {6, 5, 3, 3} } }, { {4, {2, 8, 2, 5, 9} }, {3, {3, 2, 1, 1} } }, { {2, {2, 1, 2}}, {8, {7, 2, 1, 9, 6, 7, 4, 8, 8} } } }; // массив чисел 
    LongN rtests[testsCount] = { {1, {0, 2} }, {1, {0, 8} }, { 6, {0, 0, 0, 0, 0, 0, 4} } }; // массив результатов
    for (int i = 0; i < testsCount; ++i)
    {
        LongN res = divNNtoDk(tests[i][0] , tests[i][1]);
        assert(res.deg == rtests[i].deg); // проверка совпадения порядков 
        for (int j = 0; j <= rtests[i].deg; ++j)
            assert(res.arrOfNums[j] == rtests[i].arrOfNums[j]); // проверка совпадения цифр 
    }
}

int main()
{
    divNNtoDkTests();
    return 0;
}
