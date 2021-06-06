/*
** Частное от деления целого на целое (делитель отличен от нуля)
** Зависимости:
** ABS_Z_N
** POZ_Z_D
** DIV_NN_N
** ADD_1N_N
** Доп. функции:
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

LongZ divZZtoZ(const LongZ& num1 , const LongZ& num2)
{
    LongZ result = { 0, 0, {0} };
    // Ввод переменной для натурального результата
    LongN nResult = { 0, 0, {0} };
    //Перевод операндов в натуральные 
    LongN nNum1 = absZtoN(num1);
    LongN nNum2 = absZtoN(num2);

    if (notZeroNtoB(nNum2))
    {
        //Проверка на то, что первый натуральный операнд больше второго
        if (comNNtoD(nNum1 , nNum2) == 2 || comNNtoD(nNum1 , nNum2) == 0)
        {
            nResult = divNNtoN(nNum1 , nNum2);
            result = transNtoZ(nResult);

            if (comNNtoD(mulNNtoN(nResult , nNum2) , nNum1) == 0)
            {
                if ((num1.sign + num2.sign) % 2 == 0)
                    return result;
                else
                    return (mulZMtoZ(result));
            }
        }
        else
        {
            result = { 0, 0, {0} }; //Если модуль первого операнда оказался меньше второго
        }

        if (pozZtoD(num1) == 2 && pozZtoD(num2) == 2)
            return result;

        else if (pozZtoD(num1) == 2 && pozZtoD(num2) == 1)
            return mulZMtoZ(result);

        else if (pozZtoD(num1) == 1 && pozZtoD(num2) == 2)
            return (mulZMtoZ(transNtoZ(add1NtoN(nResult))));

        else if (pozZtoD(num1) == 1 && pozZtoD(num2) == 1)
            return (transNtoZ(add1NtoN(nResult)));
        else
            return result;
    }
    else
    {
        std::cerr << "Error: second number cannot be zero." << std::endl << std::endl;
        return { 0,0,{0} };
    }
}

void divZZtoZtest()
{
    assert(comZZtoB(divZZtoZ({ 0,0,{5} } , { 0,0,{2} }) , { 0,0,{2} }) == 1);
    assert(comZZtoB(divZZtoZ({ 1,1,{0, 5} } , { 0,0,{2} }) , { 1,1,{5, 2} }) == 1);
    assert(comZZtoB(divZZtoZ({ 0,0,{5} } , { 1,0,{2} }) , { 1,0,{2} }) == 1);
}

int main()
{
    divZZtoZtest();
    return 0;
}
