/*
** Остаток от деления целого на целое(делитель отличен от нуля)
** Зависимости:
** DIV_ZZ_Z
** MUL_ZZ_Z
** SUB_ZZ_Z
** MUL_ZM_Z
** Доп. модули:
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

LongZ modZZtoZ(const LongZ& num1 , const LongZ& num2)
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
        if (((comNNtoD(nNum1 , nNum2) == 2) || (comNNtoD(nNum1 , nNum2) == 0)))
        {
            nResult = modNNtoN(nNum1 , nNum2);
            result = transNtoZ(nResult);

            if (pozZtoD(num1) == 2)
                return result;
            else
                return transNtoZ(subNNtoN(nNum2 , nResult));
        }
        else
        {
            if (pozZtoD(num1) == 2 || pozZtoD(num1) == 0)
            {
                result = num1;
                return result;
            }
            else
                return transNtoZ(subNNtoN(nNum2 , nNum1));
        }
        return { 0,0,{0} };
    }
    else
    {
        std::cerr << "Error: second number cannot be zero." << std::endl << std::endl;
        return { 0,0,{0} };
    }
}

int main()
{
    LongZ num1 = { 1, 3,{ 6, 2, 8, 4 } };
    LongZ num2 = { 0, 1,{ 4, 6 } };
    LongZ modZ = { 0, 1,{8, 3} };
    assert(comZZtoB(modZ , modZZtoZ(num1 , num2)));

    num1 = { 1, 3,{ 6, 2, 8, 4 } };
    num2 = { 1, 1,{ 4, 6 } };
    modZ = { 0, 1,{ 8, 3} };
    assert(comZZtoB(modZ , modZZtoZ(num1 , num2)));

    num1 = { 0, 3,{ 6, 2, 8, 4 } };
    num2 = { 1, 1,{ 4, 6 } };
    modZ = { 0, 1, { 6, 2} };
    assert(comZZtoB(modZ , modZZtoZ(num1 , num2)));

    return 0;
}
