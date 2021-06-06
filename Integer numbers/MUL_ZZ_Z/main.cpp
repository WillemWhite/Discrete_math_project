/*
** Умножение целых чисел
** Зависимости:
** POZ_Z_D
** ABS_Z_N
** MUL_NN_N
** MUL_ZM_Z
** Доп. модули:
** TRANS_N_Z
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

LongZ mulZZtoZ(const LongZ& number1 , const LongZ& number2)
{
    LongN natNumber1 = absZtoN(number1); //необходимы для работы с натуральными числами
    LongN natNumber2 = absZtoN(number2);

    if (((pozZtoD(number1) == 1) && (pozZtoD(number2) == 2)) || (((pozZtoD(number1) == 2) && (pozZtoD(number2) == 1)))) //если числа разных знаков
    {
        return mulZMtoZ(transNtoZ(mulNNtoN(natNumber1 , natNumber2)));
    }
    else //если одинаковых
    {
        return transNtoZ(mulNNtoN(natNumber1 , natNumber2));
    }

}


int main()
{
    LongZ number1[3] = {};
    number1[0] = { 1,2,{5,0,2} };
    number1[1] = { 0,3,{5,0,2,9} };
    number1[2] = { 1,3,{0,0,0,1} };

    LongZ number2[3] = {};
    number2[0] = { 0,1,{5,1} };
    number2[1] = { 0,0,{0} };
    number2[2] = { 1,1,{3,2} };

    LongZ result = mulZZtoZ(number1[0] , number2[0]);
    assert(result.sign == 1);
    assert(result.deg == 3);
    assert(result.arrOfNums[0] == 5);
    assert(result.arrOfNums[1] == 7);
    assert(result.arrOfNums[2] == 0);
    assert(result.arrOfNums[3] == 3);

    result = mulZZtoZ(number1[1] , number2[1]);
    assert(result.sign == 0);
    assert(result.deg == 0);
    assert(result.arrOfNums[0] == 0);

    result = mulZZtoZ(number1[2] , number2[2]);
    assert(result.sign == 0);
    assert(result.deg == 4);
    assert(result.arrOfNums[0] == 0);
    assert(result.arrOfNums[1] == 0);
    assert(result.arrOfNums[2] == 0);
    assert(result.arrOfNums[3] == 3);
    assert(result.arrOfNums[4] == 2);

    return 0;
}
