#include <iostream>
#include "L_int.h"
#include "L_nat.h"
#include "L_pol.h"
#include "L_rat.h"

//=====================================================================================================================
/* COM_ZZ_B - Доп. модуль. Сергей Стукалов Гр.0375
**--------------------------------------------------------------------------------------------------------------------
** Сравнение целых чисел.
**--------------------------------------------------------------------------------------------------------------------
*/
bool comZZtoB(const LongZ& num1 , const LongZ& num2)
{
    if (num1.sign == num2.sign)
    {
        if (num1.deg >= num2.deg)
        {
            for (int i = 0; i <= num1.deg; ++i)
            {
                if (num1.arrOfNums[i] != num2.arrOfNums[i])
                    return false;
            }
        }
        else
        {
            for (int i = 0; i <= num2.deg; ++i)
            {
                if (num1.arrOfNums[i] != num2.arrOfNums[i])
                    return false;
            }
        }
        return true;
    }
    else if (num1.deg == 0 && num1.arrOfNums[0] == 0 &&
        num2.deg == 0 && num2.arrOfNums[0] == 0)
        return true;
    else
        return false;
}
//=====================================================================================================================
/* ABS_Z_N - Иван Сарницкий Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Абсолютная величина числа, результат - натуральное.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN absZtoN(const LongZ& integer)
{
    LongN result = { 0, {0} };
    //Копируем номер старшей позиции
    result.deg = integer.deg;
    //Копируем массив
    for (int i = 0; i <= integer.deg; i++)
    {
        result.arrOfNums[i] = integer.arrOfNums[i];
    }

    return result;
}
//=====================================================================================================================
/* POZ_Z_D - Иван Сарницкий Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное).
** --------------------------------------------------------------------------------------------------------------------
*/
int pozZtoD(const LongZ& integer)
{
    if (integer.deg == 0 && integer.arrOfNums[0] == 0)
        return 0;
    else
        switch (integer.sign)
        {
        case 0: return 2; break;
        case 1: return 1; break;
        default: return 2;
        }
}
//=====================================================================================================================
/* MUL_ZM_Z - Иван Сарницкий Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Умножение целого на (-1).
** --------------------------------------------------------------------------------------------------------------------
*/
LongZ mulZMtoZ(const LongZ& integer)
{
    LongZ result = { 0,{0} };

    if (integer.sign == 0)
    {
        result.sign = 1;
        result.deg = integer.deg;
        for (int i = integer.deg; i >= 0; --i)
        {
            result.arrOfNums[i] = integer.arrOfNums[i];
        }
    }
    else if (integer.sign == 1)
    {
        result.sign = 0;
        result.deg = integer.deg;
        for (int i = integer.deg; i >= 0; --i)
        {
            result.arrOfNums[i] = integer.arrOfNums[i];
        }
    }

    return result;
}
//=====================================================================================================================
/* TRANS_N_Z - Мария Лукина Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Преобразование натурального в целое.
** --------------------------------------------------------------------------------------------------------------------
*/
LongZ transNtoZ(const LongN& number)
{
    LongZ result = { 0, {0} };
    result.sign = 0; // натуральные числа всегда положительны => знак '+'

    // само число не изменятеся => номер старшей позиции и сами цифры числа не меняются
    result.deg = number.deg;
    for (int i = 0; i <= result.deg; i++)
        result.arrOfNums[i] = number.arrOfNums[i];

    return result;
}
//=====================================================================================================================
/* TRANS_Z_N - Мария Лукина Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Преобразование целого неотрицательного в натуральное.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN transZtoN(const LongZ& number)
{
    LongN result = { 0,{0} };

    if (number.sign == 0) // только положительное целое число является натуральным
    {
        // само число не изменяется => номер старшей позиции и сами цифры числа остаются теми же
        result.deg = number.deg;
        for (int i = 0; i <= result.deg; i++)
            result.arrOfNums[i] = number.arrOfNums[i];
    }
    else
    {
        std::cerr << "Error: integer must be positive or 0 to convert." << std::endl << std::endl;
        return { 0,0,{0} };
    }

    return result;
}
//=====================================================================================================================
/* ADD_ZZ_Z - Сергей Матвеев Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Сложение целых чисел.
** --------------------------------------------------------------------------------------------------------------------
*/
LongZ addZZtoZ(const LongZ& number1 , const LongZ& number2)
{
    LongZ result = { 0, 0, {0} };
    //структуры LongN необходимы для того, чтобы можно было использовать функции для натуральных чисел
    LongN nResult = { 0, {0} };
    LongN naturalNumber1 = absZtoN(number1);
    LongN naturalNumber2 = absZtoN(number2);

    // если числа одинакового знака, то
    if (((pozZtoD(number1) == 1) && (pozZtoD(number2) == 1)) || (pozZtoD(number1) == 2) && (pozZtoD(number2) == 2))
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
    //если числа разных знаков
    else if (((pozZtoD(number1) == 1) &&
        (pozZtoD(number2) == 2)) ||
        ((pozZtoD(number1) == 2) &&
            (pozZtoD(number2) == 1)))
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
//=====================================================================================================================
/* SUB_ZZ_Z - Сергей Матвеев Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Вычитание целых чисел.
** --------------------------------------------------------------------------------------------------------------------
*/
LongZ subZZtoZ(const LongZ& number1 , const LongZ& number2)
{
    LongZ num1 = number1;
    LongZ invNum2 = mulZMtoZ(number2);

    return addZZtoZ(num1 , invNum2);
}
//=====================================================================================================================
/* MUL_ZZ_Z - Сергей Матвеев Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Умножение целых чисел.
** --------------------------------------------------------------------------------------------------------------------
*/
LongZ mulZZtoZ(const LongZ& number1 , const LongZ& number2)
{
    LongN natNumber1 = absZtoN(number1); //необходимы для работы с натуральными числами
    LongN natNumber2 = absZtoN(number2);

    //если числа разных знаков
    if (((pozZtoD(number1) == 1) && (pozZtoD(number2) == 2)) || (((pozZtoD(number1) == 2) && (pozZtoD(number2) == 1))))
    {
        return mulZMtoZ(transNtoZ(mulNNtoN(natNumber1 , natNumber2)));
    }
    else //если одинаковых
    {
        return transNtoZ(mulNNtoN(natNumber1 , natNumber2));
    }

}
//=====================================================================================================================
/* DIV_ZZ_Z - Никита Бусько Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Частное от деления целого на целое (делитель отличен от нуля).
** --------------------------------------------------------------------------------------------------------------------
*/
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
//=====================================================================================================================
/* MOD_ZZ_Z - Никита Бусько Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Остаток от деления целого на целое(делитель отличен от нуля).
** --------------------------------------------------------------------------------------------------------------------
*/
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
//=====================================================================================================================
