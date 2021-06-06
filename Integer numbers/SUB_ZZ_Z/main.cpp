/*
** Вычитание целых чисел (по всей видимости из первого второе).
** Зависимости:
** POZ_Z_D
** ABS_Z_N
** COM_NN_D
** ADD_NN_N
** SUB_NN_N
** MUL_ZM_Z
** Добавленные модули:
** TRANS_N_Z
** ADD_ZZ_Z
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

LongZ subZZtoZ(const LongZ& number1 , const LongZ& number2)
{
    LongZ num1 = number1;
    LongZ invNum2 = mulZMtoZ(number2);
    return addZZtoZ(num1 , invNum2);
}

int main()
{
    LongZ number1[5] = {};
    number1[0] = { 0,2,{5,0,2} };
    number1[1] = { 1,2,{7,4,3} };
    number1[2] = { 0,3,{0,0,0,1} };
    number1[3] = { 1,3,{6,5,3,2} };
    number1[4] = { 0,0,{0} };


    LongZ number2[5] = {};
    number2[0] = { 1,1,{5,1} };
    number2[1] = { 0,2,{8,4,3} };
    number2[2] = { 0,1,{3,2} };
    number2[3] = { 0,2,{5,3,6} };
    number2[4] = { 0,3,{2,4,8,4} };


    LongZ result = subZZtoZ(number1[0] , number2[0]);

    assert(result.sign == 0);
    assert(result.deg == 2);
    assert(result.arrOfNums[0] == 0);
    assert(result.arrOfNums[1] == 2);
    assert(result.arrOfNums[2] == 2);

    result = subZZtoZ(number1[1] , number2[1]);
    assert(result.sign == 1);
    assert(result.deg == 2);
    assert(result.arrOfNums[0] == 5);
    assert(result.arrOfNums[1] == 9);
    assert(result.arrOfNums[2] == 6);

    result = subZZtoZ(number1[2] , number2[2]);
    assert(result.sign == 0);
    assert(result.deg == 2);
    assert(result.arrOfNums[0] == 7);
    assert(result.arrOfNums[1] == 7);
    assert(result.arrOfNums[2] == 9);

    result = subZZtoZ(number1[3] , number2[3]);
    assert(result.sign == 1);
    assert(result.deg == 3);
    assert(result.arrOfNums[0] == 1);
    assert(result.arrOfNums[1] == 9);
    assert(result.arrOfNums[2] == 9);
    assert(result.arrOfNums[3] == 2);

    result = subZZtoZ(number1[4] , number2[4]);
    assert(result.sign == 1);
    assert(result.deg == 3);
    assert(result.arrOfNums[0] == 2);
    assert(result.arrOfNums[1] == 4);
    assert(result.arrOfNums[2] == 8);
    assert(result.arrOfNums[3] == 4);

    return 0;
}
