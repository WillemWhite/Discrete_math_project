#include <iostream>
#include "L_int.h"
#include "L_nat.h"
#include "L_pol.h"
#include "L_rat.h"

//=====================================================================================================================
/* COM_NN_D - Яна Попкова Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Сравнение натуральных чисел: 2 - если первое больше второго,
** 0, если равно, 1 иначе.
** --------------------------------------------------------------------------------------------------------------------
*/
int comNNtoD(const LongN& n1 , const LongN& n2)
{
    if (n1.deg == n2.deg)
    {
        int i = n1.deg;
        while ((i > 0) && (n1.arrOfNums[i] == n2.arrOfNums[i]))
        {
            --i;
        }
        if (n1.arrOfNums[i] > n2.arrOfNums[i])
            return 2;
        else if (n1.arrOfNums[i] == n2.arrOfNums[i])
            return 0;
        else
            return 1;
    }
    else if (n1.deg < n2.deg)
        return 1;
    else
        return 2;
}
//=====================================================================================================================
/* NZER_N_B - Яна Попкова Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Проверка на ноль: если число не равно нулю, то «да» иначе «нет».
** --------------------------------------------------------------------------------------------------------------------
*/
bool notZeroNtoB(const LongN& number)
{
    if (number.deg != 0 || number.arrOfNums[0] != 0)
        return true;
    else
        return false;
}
//=====================================================================================================================
/* ADD_1N_N - Яна Попкова Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Добавление 1 к натуральному числу
** Зависимостей с другими модулями нет , функционал реализуется сразу.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN add1NtoN(const LongN& number)
{
    LongN result = number;
    int pos = 0;
    if (result.arrOfNums[pos] == 9)
    {
        // заменяем цифру, которая при добавлении к ней 1 равна 10, на 0
        do
        {
            result.arrOfNums[pos] = 0;
            pos++;
        } while (result.arrOfNums[pos] + 1 > 9);

        ++result.arrOfNums[pos]; // прибавляем 1
        if (pos > result.deg) // в случае, если увеличивается порядок
            ++result.deg; //например 999 + 1 = 1000
    }
    else
    {
        result.arrOfNums[pos] = result.arrOfNums[pos] + 1;
    }
    return result;
}
//=====================================================================================================================
/* ADD_NN_N - Яна Попкова Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Сложение натуральных чисел.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN addNNtoN(const LongN& n1 , const LongN& n2)
{
    LongN result = { 0,{0} };
    LongN naturalNumber1 = n1;
    LongN naturalNumber2 = n2;
    if (comNNtoD(naturalNumber1 , naturalNumber2) != 2)
    {
        for (int i = 0; i <= n2.deg; ++i)
        {
            //Следующая цифра заполняется делением на 10 суммы цифр предыдушего порядка.
            result.arrOfNums[i + 1] = ((n1.arrOfNums[i] + n2.arrOfNums[i] + result.arrOfNums[i]) / 10);

            //Цифра заполняется остатком от деления на 10 суммы цифр текущего порядка.
            result.arrOfNums[i] = (n1.arrOfNums[i] + n2.arrOfNums[i] + result.arrOfNums[i]) % 10;
        }
        if (result.arrOfNums[n2.deg + 1] != 0)
            result.deg = n2.deg + 1;
        else
            result.deg = n2.deg;
    }
    else
    {
        for (int i = 0; i <= n1.deg; ++i)
        {
            //Следующая цифра заполняется делением на 10 суммы цифр предыдушего порядка.
            result.arrOfNums[i + 1] = ((n1.arrOfNums[i] + n2.arrOfNums[i] + result.arrOfNums[i]) / 10);

            //Цифра заполняется остатком от деления на 10 суммы цифр текущего порядка.
            result.arrOfNums[i] = (n1.arrOfNums[i] + n2.arrOfNums[i] + result.arrOfNums[i]) % 10;
        }
        if (result.arrOfNums[n1.deg + 1] != 0)
            result.deg = n1.deg + 1;
        else
            result.deg = n1.deg;
    }
    return result;
}
//=====================================================================================================================
/* SUB_NN_N - Иван Сарницкий Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Вычитание из первого большего натурального числа второго меньшего или равного.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN subNNtoN(const LongN& first , const LongN& second)
{
    LongN copyFirst = { 0,{0} };
    LongN copySecond = { 0,{0} };

    switch (comNNtoD(first , second))
    {
    case 2:
        copyFirst = first;
        copySecond = second;
        break;
    case 1:
        copyFirst = second;
        copySecond = first;
        break;
    case 0:
        return copyFirst;
    }

    for (int i = 0; i <= copySecond.deg; i++)
    {
        if (copyFirst.arrOfNums[i] >= copySecond.arrOfNums[i])
            copyFirst.arrOfNums[i] = copyFirst.arrOfNums[i] - copySecond.arrOfNums[i];
        else
        {
            copyFirst.arrOfNums[i] += 10;
            copyFirst.arrOfNums[i + 1]--;
            copyFirst.arrOfNums[i] = copyFirst.arrOfNums[i] - copySecond.arrOfNums[i];
        }
    }

    for (int i = copySecond.deg + 1; i < copyFirst.deg; i++)
    {
        if (copyFirst.arrOfNums[i] == -1)
        {
            copyFirst.arrOfNums[i] += 10;
            copyFirst.arrOfNums[i + 1]--;
        }
    }

    int pos = copyFirst.deg;

    while (copyFirst.arrOfNums[pos] == 0 && pos > 0)
    {
        pos--;
    }

    copyFirst.deg = pos;

    return copyFirst;
}
//=====================================================================================================================
/* MUL_ND_N - Сергей Матвеев Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Умножение натурального числа на цифру.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN mulNDtoN(const LongN& naturalNumber , const int& numeral)
{
    LongN result = { 0,{0} };
    int summNumber = 0;
    result.deg = naturalNumber.deg;

    // условие, при котором натуральное число домножается на нуль 
    if (numeral == 0)

    {
        result.deg = 0;
        result.arrOfNums[0] = 0;
        return result;
    }
    for (int i = 0; i <= naturalNumber.deg; i++)
    {
        // умножение цифры в ячейке на другую цифру
        int multiplication = naturalNumber.arrOfNums[i] * numeral;
        // фактическая цифра в данной ячейке
        result.arrOfNums[i] = (multiplication + summNumber) % 10;
        // цифра в "уме", которую суммируют для числа следующего разряда
        summNumber = (multiplication + summNumber) / 10;
    }
    // если при выходе из цикла for цифра в "уме" ненулевая, то 
    // степень повышается на 1, а следующей ячейке присваивается значение цифры в "уме"
    if (summNumber != 0)
    {
        result.deg++;
        result.arrOfNums[result.deg] = summNumber;
    }
    return result;
}
//=====================================================================================================================
/* MUL_Nk_N - Марк Ревазов Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Умножение натурального числа на 10^k.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN mulNktoN(const LongN& naturalNumber , const int& k)
{
    LongN result = { naturalNumber.deg + k,{0} };

    //сдвигаем элементы массива вправо на К(начинаем с конца до К-го элемента)
    for (int i = result.deg; i >= k; i--)
    {
        result.arrOfNums[i] = naturalNumber.arrOfNums[i - k];
    }

    if (naturalNumber.deg == 0 && naturalNumber.arrOfNums[0] == 0)
        result = { 0,{0} };

    return result;
}
//=====================================================================================================================
/* MUL_NN_N - Рычков Павел Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Умножение натуральных чисел.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN mulNNtoN(const LongN& fNum , const LongN& sNum)
{
    LongN result = { 0,{0} };
    for (int i = 0; i <= sNum.deg; ++i)
    {
        result = addNNtoN(mulNktoN(mulNDtoN(fNum , sNum.arrOfNums[i]) , i) , result);
    }
    return result;
}
//=====================================================================================================================
/* SUB_NDN_N - Рычков Павел Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Вычитание из натурального другого натурального,
** умноженного на цифру для случая с неотрицательным результатом.
** --------------------------------------------------------------------------------------------------------------------
*/
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
//=====================================================================================================================
/* DIV_NN_Dk - Рычков Павел Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Вычисление первой цифры деления большего натурального на меньшее,
** домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля).
** --------------------------------------------------------------------------------------------------------------------
*/
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
//=====================================================================================================================
/* DIV_NN_N - Марк Ревазов Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Частное от деления большего натурального числа на меньшее
** или равное натуральное с остатком(делитель отличен от нуля).
** --------------------------------------------------------------------------------------------------------------------
*/
LongN divNNtoN(const LongN& Num1 , const LongN& Num2)
{
    LongN fNum = { 0, {0} };
    LongN sNum = { 0, {0} };

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

        int pos = fNum.deg - sNum.deg;

        LongN result = { divNNtoDk(fNum,sNum).deg, {0} };

        while (pos >= 0)
        {
            while (comNNtoD(sNum , part) == 2 && pos > 0)
            {
                part = mulNktoN(part , 1);
                pos--;
                part.arrOfNums[0] = fNum.arrOfNums[pos];
            }

            if (comNNtoD(sNum , part) != 2)
            {
                int deg = divNNtoDk(part , sNum).deg;
                result.arrOfNums[deg + pos] = divNNtoDk(part , sNum).arrOfNums[deg];
                part = subNDNtoN(part , result.arrOfNums[deg + pos] , sNum);
            }
            else
                break;
        }

        return result;
    }
    else
    {
        std::cerr << "Error: denominator cannot be zero." << std::endl << std::endl;
        return { 0,{0} };
    }
}
//=====================================================================================================================
/* MOD_NN_N - Марк Ревазов Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Остаток от деления большего натурального числа на меньшее
** или равное натуральное с остатком(делитель отличен от нуля).
** --------------------------------------------------------------------------------------------------------------------
*/
LongN modNNtoN(const LongN& natNumber1 , const LongN& natNumber2)
{
    LongN fNum = { 0, {0} };
    LongN sNum = { 0, {0} };

    switch (comNNtoD(natNumber1 , natNumber2))
    {
    case 2:
        fNum = natNumber1;
        sNum = natNumber2;
        break;
    case 1:
        fNum = natNumber2;
        sNum = natNumber1;
        break;
    case 0:
        LongN res = { 0, {0} };
        return res;
    }

    LongN result = { 0,{0} };

    if (notZeroNtoB(sNum))
    {
        LongN stack1 = divNNtoN(fNum , sNum); //деление чисел нацело
        LongN stack2 = mulNNtoN(sNum , stack1); //умножение второго числа на результат деления
        result = subNNtoN(fNum , stack2); //вычитание полученных чисел
    }
    else
    {
        std::cerr << "Error: denominator cannot be zero." << std::endl << std::endl;
        return { 0,{0} };
    }
}
//=====================================================================================================================
/* GCF_NN_N - Александр Гирвиц Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** НОД натуральных чисел.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN GCFofNNtoN(const LongN& firstNumber , const LongN& secondNumber)
{
    LongN first = { 0,{0} };
    LongN second = { 0,{0} };

    switch (comNNtoD(firstNumber , secondNumber))
    {
    case 2:
        first = firstNumber;
        second = secondNumber;
        break;
    case 1:
        first = secondNumber;
        second = firstNumber;
        break;
    case 0:
        return firstNumber;
    }

    LongN result = { 0,{0} };

    while (notZeroNtoB(second))
    {
        LongN remainder = modNNtoN(first , second);

        first = second;
        second = remainder;
    }

    return first;
}
//=====================================================================================================================
/* LCM_NN_N - Никита Бусько Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** НОК натуральных чисел.
** --------------------------------------------------------------------------------------------------------------------
*/
LongN LCMofNNtoN(const LongN& Num1 , const LongN& Num2)
{
    // НОК - частное от деления произведения чисел на их НОД.
    LongN result = divNNtoN(mulNNtoN(Num1 , Num2) , GCFofNNtoN(Num1 , Num2));

    return result;
}
//=====================================================================================================================
