/*
** Сложение целых чисел
** Зависимости:
** POZ_Z_D
** ABS_Z_N
** COM_NN_D
** ADD_NN_N
** SUB_NN_N
** MUL_ZM_Z
** Добавленные модули:
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



LongZ addZZtoZ(const LongZ& number1 , const LongZ& number2)
{
    LongZ result = { 0, 0, {0} };
    LongN nResult = { 0, {0} }; //структуры LongN необходимы для того, чтобы можно было использовать функции для натуральных чисел
    LongN naturalNumber1 = absZtoN(number1);
    LongN naturalNumber2 = absZtoN(number2);


    if (((pozZtoD(number1) == 1) && (pozZtoD(number2) == 1)) || (pozZtoD(number1) == 2) && (pozZtoD(number2) == 2)) // если числа одинакового знака, то
    {
        if (pozZtoD(number1) == 2) // если числа положительные
        {
            nResult = addNNtoN(naturalNumber1 , naturalNumber2); //сумма двух натур. чисел
            result = transNtoZ(nResult); ///перевод из натурального в целое
            return result;
        }
        else //иначе числа отрицательные
        {
            nResult = addNNtoN(naturalNumber1 , naturalNumber2);
            result = transNtoZ(nResult);
            result = mulZMtoZ(result);
            return result;
        }
    }

    else if (((pozZtoD(number1) == 1) && (pozZtoD(number2) == 2)) || ((pozZtoD(number1) == 2) && (pozZtoD(number2) == 1))) //если числа разных знаков
    {
        if (comNNtoD(naturalNumber1 , naturalNumber2) == 1)  //если второе число больше первого
        {
            if (pozZtoD(number1) == 1) //если первое число отрицательное
            {
                nResult = subNNtoN(naturalNumber2 , naturalNumber1);
                result = transNtoZ(nResult);
                return result;
            }
            else //если положительное
            {
                nResult = subNNtoN(naturalNumber2 , naturalNumber1);
                result = transNtoZ(nResult);
                result = mulZMtoZ(result);
                return result;
            }

        }
        else if (comNNtoD(naturalNumber1 , naturalNumber2) == 2) //если первое число больше второго
        {
            if (pozZtoD(number2) == 1) //если второе число отрицательное
            {
                nResult = subNNtoN(naturalNumber1 , naturalNumber2);
                result = transNtoZ(nResult);
                return result;
            }
            else //иначе
            {
                nResult = subNNtoN(naturalNumber1 , naturalNumber2);
                result = transNtoZ(nResult);
                result = mulZMtoZ(result);
                return result;
            }
        }
        else //сумма одинаковых чисел с разными знаками даст 0
        {
            result = { 0,0,{0} };
            return result; //изначально инициализировал как 0.
        }
    }
    else if (pozZtoD(number1) == 0 || (pozZtoD(number2) == 0))
    {
        if (pozZtoD(number1) == 0)
        {
            result = number2;
            return result;
        }
        else
        {
            result = number1;
            return result;
        }
    }

    return { 0,0,{0} };
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

    LongZ result = addZZtoZ(number1[0] , number2[0]);
    assert(result.sign == 0);
    assert(result.deg == 2);
    assert(result.arrOfNums[0] == 0);
    assert(result.arrOfNums[1] == 9);
    assert(result.arrOfNums[2] == 1);

    result = addZZtoZ(number1[1] , number2[1]);
    assert(result.sign == 0);
    assert(result.deg == 0);
    assert(result.arrOfNums[0] == 1);

    result = addZZtoZ(number1[2] , number2[2]);
    assert(result.sign == 0);
    assert(result.deg == 3);
    assert(result.arrOfNums[0] == 3);
    assert(result.arrOfNums[1] == 2);
    assert(result.arrOfNums[2] == 0);
    assert(result.arrOfNums[3] == 1);

    result = addZZtoZ(number1[3] , number2[3]);
    assert(result.sign == 1);
    assert(result.deg == 3);
    assert(result.arrOfNums[0] == 1);
    assert(result.arrOfNums[1] == 2);
    assert(result.arrOfNums[2] == 7);
    assert(result.arrOfNums[3] == 1);

    result = addZZtoZ(number1[4] , number2[4]);
    assert(result.sign == 0);
    assert(result.deg == 3);
    assert(result.arrOfNums[0] == 2);
    assert(result.arrOfNums[1] == 4);
    assert(result.arrOfNums[2] == 8);
    assert(result.arrOfNums[3] == 4);

    return 0;
}
