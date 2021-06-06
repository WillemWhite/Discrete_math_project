/*
** Вычитание дробей
** Зависимости:
** LCM_NN_N
** MUL_ZZ_Z
** SUB_ZZ_Z
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

LongQ subQQtoQ(const LongQ& first , const LongQ& second)
{
    LongQ firstNum = first;
    LongQ secondNum = second;

    secondNum.num = mulZMtoZ(secondNum.num);

    LongQ result = { 0 };

    result.denom = LCMofNNtoN(firstNum.denom , secondNum.denom);

    LongN num1 = divNNtoN(result.denom , firstNum.denom);
    LongN num2 = divNNtoN(result.denom , secondNum.denom);

    result.num = addZZtoZ(mulZZtoZ(firstNum.num , transNtoZ(num1)) , mulZZtoZ(secondNum.num , transNtoZ(num2)));

    return redQtoQ(result);
}

int main() {

    LongQ first = {
            {0, 0, {1}},
            {0, {2}}

    };

    LongQ second = {
            {0, 0, {1}},
            {0, {5}}
    };


    LongQ result = subQQtoQ(first , second);

    assert(result.denom.deg == 1);
    assert(result.denom.arrOfNums[0] == 0);
    assert(result.denom.arrOfNums[1] == 1);
    assert(result.num.deg == 0);
    assert(result.num.sign == 0);
    assert(result.num.arrOfNums[0] == 3);

    first = {
            {0, 0, {0}},
            {0, {1}}
    };
    second = {
            {1, 0, {1}},
            {0, {2}}
    };

    result = subQQtoQ(first , second);

    assert(result.denom.deg == 0);
    assert(result.denom.arrOfNums[0] == 2);
    assert(result.num.deg == 0);
    assert(result.num.sign == 0);
    assert(result.num.arrOfNums[0] == 1);

    first = {
            {0, 0, {1}},
            {0, {5}}

    };
    second = {
            {0, 0, {1}},
            {0, {5}}
    };

    result = subQQtoQ(first , second);

    assert(result.num.deg == 0);
    assert(result.num.sign == 0);
    assert(result.num.arrOfNums[0] == 0);


    return 0;

}
