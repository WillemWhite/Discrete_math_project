#ifndef HEAD_H
#define HEAD_H

#pragma comment(linker, "/STACK:16777216")

#include <iostream>

/* Разберёмся с нэймингом модулей и функций (немножечко английского):
** COMpare - сравнивать;
** Bool - понятно что;
** ADDition - сложение;
** Digit - цифра;
** MULtiplicate - умножать;
** SUBtraction - вычитание;
** DIV - целочисленное деление;
** MOD - остаток от деления;
** GCF - НОД числа;
** LCM - НОК числа;
** ABS - абсолютная величина(модуль) числа;
** POZitive - положительный;
** TRANS - преобразование;
** REDuction - сокращение;
** LED - старший коэффициент;
** DEGree - степень числа;
** DERivative - производная;
*/

const int SIZE = 100;

struct LongN
{
    signed short int deg; //номер старшей позиции числа(порядок, степень; меньше количества цифр!).
    signed short int arrOfNums[SIZE]; //числа могут быть и отрицательными в массиве, не забыть проверку.
};

struct LongZ
{
    signed short int sign; //знак числа. (1 если отрицательное и 0, если положтельное)
    signed short int deg; //номер старшей позиции числа(порядок, степень).
    signed short int arrOfNums[SIZE]; //числа могут быть и отрицательными в массиве, не забыть проверку.
};

struct LongQ
{
    LongZ num; //числитель, смысл длинного целого.
    LongN denom; //знаменатель, смысл длинного натурального.
};

struct LongP
{
    signed short int deg; //степень многочлена(Меньше количества коэффициентов!).
    LongQ odds[SIZE]; //массив рациональных коэффициентов.
};

/*Natural numbers:
******************************************************************************/
// COM_NN_D - Сравнение натуральных чисел: 
// 2 - если первое больше второго, 0, если равно, 1 иначе.
int comNNtoD(const LongN& , const LongN&);
//return по условию задания.

// NZER_N_B - Проверка на ноль: если число не равно нулю, то «да» иначе «нет».
bool notZeroNtoB(const LongN&);
//return по условию задания.

// ADD_1N_N - Добавление 1 к натуральному числу.
LongN add1NtoN(const LongN&);
//return по условию задания.

// ADD_NN_N - Сложение натуральных чисел.
LongN addNNtoN(const LongN& , const LongN&);
//return по условию задания.

// SUB_NN_N - Вычитание из первого большего натурального числа 
// второго меньшего или равного.
LongN subNNtoN(const LongN& , const LongN&);
//return по условию задания.

// MUL_ND_N - Умножение натурального числа на цифру.
LongN mulNDtoN(const LongN& , const int&);
//return по условию задания.

// MUL_Nk_N - Умножение натурального числа на 10^k.
LongN mulNktoN(const LongN& , const int&);
//return по условию задания.

// MUL_NN_N - Умножение натуральных чисел.
LongN mulNNtoN(const LongN& , const LongN&);
//return по условию задания.

// SUB_NDN_N - Вычитание из натурального другого натурального, 
// умноженного на цифру для случая с неотрицательным результатом.
LongN subNDNtoN(const LongN& , const int& , const LongN&);
//return по условию задания.

// DIV_NN_Dk - Вычисление первой цифры деления большего натурального на меньшее, 
// домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля).
LongN divNNtoDk(const LongN& , const LongN&);
//return по условию задания(записываете цифру в длинное натуральное).

// DIV_NN_N - Частное от деления большего натурального числа 
// на меньшее или равное натуральное с остатком(делитель отличен от нуля).
LongN divNNtoN(const LongN& , const LongN&);
//return по условию задания.

// MOD_NN_N - Остаток от деления большего натурального числа 
// на меньшее или равное натуральное с остатком(делитель отличен от нуля).
LongN modNNtoN(const LongN& , const LongN&);
//return по условию задания.

// GCF_NN_N - НОД натуральных чисел.
LongN GCFofNNtoN(const LongN& , const LongN&);
//return по условию задания.

// LCM_NN_N - НОК натуральных чисел.
LongN LCMofNNtoN(const LongN& , const LongN&);
//return по условию задания.

/*Integer numbers:
******************************************************************************/
// COM_ZZ_B - Сравнение целых чисел. 
bool comZZtoB(const LongZ& , const LongZ&);
// return по условию задания.

// ABS_Z_N - Абсолютная величина числа, результат - натуральное.
LongN absZtoN(const LongZ&);
//return по условию задания.

// POZ_Z_D - Определение положительности числа 
// (2 - положительное, 0 — равное нулю, 1 - отрицательное).
int pozZtoD(const LongZ&);
//return по условию задания.

// MUL_ZM_Z - Умножение целого на (-1).
LongZ mulZMtoZ(const LongZ&);
//return по условию задания.

// TRANS_N_Z - Преобразование натурального в целое.
LongZ transNtoZ(const LongN&);
//return по условию задания.

// TRANS_Z_N - Преобразование целого неотрицательного в натуральное.
LongN transZtoN(const LongZ&);
//return по условию задания.

// ADD_ZZ_Z - Сложение целых чисел.
LongZ addZZtoZ(const LongZ& , const LongZ&);
//return по условию задания.

// SUB_ZZ_Z - Вычитание целых чисел.
LongZ subZZtoZ(const LongZ& , const LongZ&);
//return по условию задания.

// MUL_ZZ_Z - Умножение целых чисел.
LongZ mulZZtoZ(const LongZ& , const LongZ&);
//return по условию задания.

// DIV_ZZ_Z - Частное от деления целого на целое (делитель отличен от нуля).
LongZ divZZtoZ(const LongZ& , const LongZ&);
//return по условию задания.

// MOD_ZZ_Z - Остаток от деления целого на целое(делитель отличен от нуля).
LongZ modZZtoZ(const LongZ& , const LongZ&);
//return по условию задания.

/*Rational numbers:
******************************************************************************/
// COM_QQ_B - сравнение дробей.
bool comQQtoB(const LongQ& , const LongQ&);
// return по условию задания.

// RED_Q_Q - Сокращение дроби.
LongQ redQtoQ(const LongQ&);
//return по условию задания.

// INT_Q_B - Проверка на целое, если рациональное число является целым, то «да», иначе «нет».
bool intQtoB(const LongQ&);
//return по условию задания.

// TRANS_Z_Q - Преобразование целого в дробное.
LongQ transZtoQ(const LongZ&);
//return по условию задания.

// TRANS_Q_Z - Преобразование дробного в целое(если знаменатель равен 1).
LongZ transQtoZ(const LongQ&);
//return по условию задания.

// ADD_QQ_Q - Сложение дробей.
LongQ addQQtoQ(const LongQ& , const LongQ&);
//return по условию задания.

// SUB_QQ_Q - Вычитание дробей.
LongQ subQQtoQ(const LongQ& , const LongQ&);
//return по условию задания.

// MUL_QQ_Q - Умножение дробей.
LongQ mulQQtoQ(const LongQ& , const LongQ&);
//return по условию задания.

// DIV_QQ_Q - Деление дробей (делитель отличен от нуля).
LongQ divQQtoQ(const LongQ& , const LongQ&);
//return по условию задания.

/*Polynomials:
******************************************************************************/
// COM_PP_B - Сравнение многочленов.
bool comPPtoB(const LongP& , const LongP&);
//return по условию задания.

// ADD_PP_P - Сложение многочленов.
LongP addPPtoP(const LongP& , const LongP&);
//return по условию задания.

// SUB_PP_P - Вычитание многочленов.
LongP subPPtoP(const LongP& , const LongP&);
//return по условию задания.

// MUL_PQ_P - Умножение многочлена на рациональное число.
LongP mulPQtoP(const LongP& , const LongQ&);
//return по условию задания.

// MUL_Pxk_P - Умножение многочлена на x^k.
LongP mulPxktoP(const LongP& , const int&);
//return по условию задания.

// LED_P_Q - Старший коэффициент многочлена.
LongQ ledPtoQ(const LongP&);
//return по условию задания.

// DEG_P_N - Степень многочлена.
int degPtoN(const LongP&);
//return по условию задания.

// FAC_P_Q - Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей.
LongQ facPtoQ(LongP&);
//return по условию задания (передаваемый аргумент изменяется!).

// MUL_PP_P - Умножение многочленов.
LongP mulPPtoP(const LongP& , const LongP&);
//return по условию задания.

// DIV_PP_P - Частное от деления многочлена на многочлен при делении с остатком.
LongP divPPtoP(const LongP& , const LongP&);
//return по условию задания.

// MOD_PP_P - Остаток от деления многочлена на многочлен при делении с остатком.
LongP modPPtoP(const LongP& , const LongP&);
//return по условию задания.

// GCF_PP_P - НОД многочленов.
LongP GCFofPPtoP(const LongP& , const LongP&);
//return по условию задания.

// DER_P_P - Производная многочлена.
LongP derPtoP(const LongP&);
//return по условию задания.

// NMR_P_P - Преобразование многочлена — кратные корни в простые.
LongP NMRofPtoP(const LongP&);
//return по условию задания.


//=====================================================================================================================
/* COM_NN_D
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
/* NZER_N_B
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
/* ADD_1N_N
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
/* ADD_NN_N
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
/* SUB_NN_N
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
/* MUL_ND_N
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
/* MUL_Nk_N
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
/* MUL_NN_N
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
/* SUB_NDN_N
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
/* DIV_NN_Dk
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
/* DIV_NN_N
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
/* MOD_NN_N
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
/* GCF_NN_N
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
/* LCM_NN_N
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
//=====================================================================================================================
/* COM_ZZ_B
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
/* ABS_Z_N
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
/* POZ_Z_D
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
/* MUL_ZM_Z
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
/* TRANS_N_Z
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
/* TRANS_Z_N
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
/* ADD_ZZ_Z
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
    else if (((pozZtoD(number1) == 1) && (pozZtoD(number2) == 2)) || ((pozZtoD(number1) == 2) && (pozZtoD(number2) == 1)))
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
/* SUB_ZZ_Z
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
/* MUL_ZZ_Z
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
/* DIV_ZZ_Z
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
/* MOD_ZZ_Z
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
//=====================================================================================================================
/* COM_QQ_B
** --------------------------------------------------------------------------------------------------------------------
** Сравнение рациональных. Дополнительный модуль.
** --------------------------------------------------------------------------------------------------------------------
*/
bool comQQtoB(const LongQ& numQ1 , const LongQ& numQ2)
{
    LongQ num1 = redQtoQ(numQ1);
    LongQ num2 = redQtoQ(numQ2);

    if (num1.num.deg == 0 && num1.num.arrOfNums[0] &&
        num2.num.deg == 0 && num2.num.arrOfNums[0])
        return true;
    else if (comNNtoD(num1.denom , num2.denom) == 0)
    {
        if (comZZtoB(num1.num , num2.num))
            return true;
        else
            return false;
    }
    else
        return false;
}
//=====================================================================================================================
/* RED_Q_Q
** --------------------------------------------------------------------------------------------------------------------
** Сокращение дроби.
** --------------------------------------------------------------------------------------------------------------------
*/
LongQ redQtoQ(const LongQ& number)
{
    LongQ copyNumber = number;
    if (!notZeroNtoB(absZtoN(number.num)))
    {
        copyNumber.num.sign = 0;
        copyNumber.denom = { 0,{1} };
    }
    LongN GFCofNumAndDenom = GCFofNNtoN(absZtoN(copyNumber.num) , copyNumber.denom);
    LongQ redNumber = { 0 };
    redNumber.num = divZZtoZ(copyNumber.num , transNtoZ(GFCofNumAndDenom));
    redNumber.denom = divNNtoN(copyNumber.denom , GFCofNumAndDenom);
    return redNumber;
}
//=====================================================================================================================
/* INT_Q_B
** --------------------------------------------------------------------------------------------------------------------
** Проверка на целое, если рациональное число является целым, то «да», иначе «нет».
** --------------------------------------------------------------------------------------------------------------------
*/
bool intQtoB(const LongQ& number)
{
    LongQ redNumber = redQtoQ(number);
    if (redNumber.denom.deg == 0 && redNumber.denom.arrOfNums[0] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//=====================================================================================================================
/* TRANS_Z_Q
** --------------------------------------------------------------------------------------------------------------------
** Преобразование целого в дробное.
** --------------------------------------------------------------------------------------------------------------------
*/
LongQ transZtoQ(const LongZ& oldNumber)
{
    LongQ transformedNumber = { 0 };

    transformedNumber.denom.arrOfNums[0] = 1;
    transformedNumber.denom.deg = 0;
    transformedNumber.num = oldNumber;

    return transformedNumber;
}
//=====================================================================================================================
/* TRANS_Q_Z
** --------------------------------------------------------------------------------------------------------------------
** Преобразование дробного в целое (если знаменатель равен 1).
** --------------------------------------------------------------------------------------------------------------------
*/
LongZ transQtoZ(const LongQ& oldNumber)
{
    if (intQtoB(oldNumber) == true)
    {
        LongQ redOldNumber = redQtoQ(oldNumber);
        LongZ transformedNumber = redOldNumber.num;

        return transformedNumber;
    }
    else
    {
        std::cerr << "Error. The denominator of the number is not equal to 1." << std::endl;
        return { 0 };
    }
}
//=====================================================================================================================
/* ADD_QQ_Q
** --------------------------------------------------------------------------------------------------------------------
** Сложение дробей.
** --------------------------------------------------------------------------------------------------------------------
*/
LongQ addQQtoQ(const LongQ& first , const LongQ& second)
{
    LongQ firstNum = first;
    LongQ secondNum = second;

    if (firstNum.num.deg == 0 && firstNum.num.arrOfNums[0] == 0)
    {
        firstNum.num.sign = 0;
        firstNum.denom.deg = 0;
        firstNum.denom.arrOfNums[0] = 1;
    }
    if (secondNum.num.deg == 0 && secondNum.num.arrOfNums[0] == 0)
    {
        secondNum.num.sign = 0;
        secondNum.denom.deg = 0;
        secondNum.denom.arrOfNums[0] = 1;
    }

    LongQ result = { 0 };

    result.denom = LCMofNNtoN(firstNum.denom , secondNum.denom);

    LongN num1 = divNNtoN(result.denom , firstNum.denom);
    LongN num2 = divNNtoN(result.denom , secondNum.denom);

    result.num = addZZtoZ(mulZZtoZ(firstNum.num , transNtoZ(num1)) , mulZZtoZ(secondNum.num , transNtoZ(num2)));

    return redQtoQ(result);
}
//=====================================================================================================================
/* SUB_QQ_Q
** --------------------------------------------------------------------------------------------------------------------
** Вычитание дробей.
** --------------------------------------------------------------------------------------------------------------------
*/
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
//=====================================================================================================================
/* MUL_QQ_Q
** --------------------------------------------------------------------------------------------------------------------
** Умножение дробей.
** --------------------------------------------------------------------------------------------------------------------
*/
LongQ mulQQtoQ(const LongQ& number1 , const LongQ& number2)
{
    LongQ result = { 0 };

    result.num = mulZZtoZ(number1.num , number2.num);
    result.denom = mulNNtoN(number1.denom , number2.denom);

    return redQtoQ(result);
}
//=====================================================================================================================
/* DIV_QQ_Q
** --------------------------------------------------------------------------------------------------------------------
** Деление дробей (делитель отличен от нуля).
** --------------------------------------------------------------------------------------------------------------------
*/
LongQ divQQtoQ(const LongQ& number1 , const LongQ& number2)
{
    if (!(number2.num.deg == 0 && number2.num.arrOfNums[0] == 0))
    {
        LongQ result = { 0 };
        LongQ flippedNumber2 = { 0 };

        flippedNumber2.num = transNtoZ(number2.denom);
        flippedNumber2.num.sign = number2.num.sign;
        flippedNumber2.denom = absZtoN(number2.num);

        result.num = mulZZtoZ(number1.num , flippedNumber2.num);
        result.denom = mulNNtoN(number1.denom , flippedNumber2.denom);

        return redQtoQ(result);
    }
    else
    {
        std::cerr << "Error: denominator cannot be zero." << std::endl << std::endl;
        return { 0 };
    }
}
//=====================================================================================================================
//=====================================================================================================================
/* COM_PP_B
** --------------------------------------------------------------------------------------------------------------------
** Дополнительный модуль: сравнение многочленов.
** --------------------------------------------------------------------------------------------------------------------
*/
bool comPPtoB(const LongP& pol1 , const LongP& pol2)
{
    if (pol1.deg == pol2.deg)
    {
        int i = 0;
        while (comQQtoB(pol1.odds[i] , pol2.odds[i]) && i <= pol1.deg)
        {
            i++;
            continue;
        }
        if (i == pol1.deg + 1)
            return true;
        else
            return false;
    }
    else
        return false;
}
//=====================================================================================================================
/* ADD_PP_P
** --------------------------------------------------------------------------------------------------------------------
** Сложение многочленов.
** --------------------------------------------------------------------------------------------------------------------
*/
LongP addPPtoP(const LongP& polynomial1 , const LongP& polynomial2)
{
    LongP result = { 0 };
    if (polynomial1.deg > polynomial2.deg)
    {
        result = polynomial1;

        for (int i = 0; i <= polynomial2.deg; i++)
        {
            result.odds[i] = addQQtoQ(polynomial1.odds[i] , polynomial2.odds[i]);
        }
        //проверка на "зануление" последних степеней
        while (result.deg > 0 && !notZeroNtoB(absZtoN(result.odds[result.deg].num)))
            result.deg--;
    }
    else
    {
        result = polynomial2;

        for (int i = 0; i <= polynomial1.deg; i++)
        {
            result.odds[i] = addQQtoQ(polynomial1.odds[i] , polynomial2.odds[i]);
        }
        //проверка на "зануление" последних степеней
        while (result.deg > 0 && !notZeroNtoB(absZtoN(result.odds[result.deg].num)))
            result.deg--;
    }

    return result;
}
//=====================================================================================================================
/* SUB_PP_P
** --------------------------------------------------------------------------------------------------------------------
** Вычитание многочленов.
** --------------------------------------------------------------------------------------------------------------------
*/
LongP subPPtoP(const LongP& pol1 , const LongP& pol2)
{
    LongP invPol2 = pol2;

    for (int i = 0; i <= pol2.deg; i++)
    {
        invPol2.odds[i].num = mulZMtoZ(pol2.odds[i].num);
    }

    return addPPtoP(pol1 , invPol2);
}
//=====================================================================================================================
/* MUL_PQ_P
** --------------------------------------------------------------------------------------------------------------------
** Умножение многочлена на рациональное число.
** --------------------------------------------------------------------------------------------------------------------
*/
LongP mulPQtoP(const LongP& polynomial , const LongQ& number)
{
    LongP result = { 0 };
    result.deg = polynomial.deg;

    if (!notZeroNtoB(absZtoN(number.num)))
        return { 0 };

    for (int i = 0; i <= polynomial.deg; i++)
    {
        result.odds[i] = mulQQtoQ(polynomial.odds[i] , number);
    }

    return result;
}
//=====================================================================================================================
/* LED_P_Q
** --------------------------------------------------------------------------------------------------------------------
** Старший коэффициент многочлена.
** --------------------------------------------------------------------------------------------------------------------
*/
LongQ ledPtoQ(const LongP& polynomial)
{
    // Просто возвращаем коэффициент, индекс которого равен степени многочлена.
    return polynomial.odds[polynomial.deg];
}
//=====================================================================================================================
/* DEG_P_N
** --------------------------------------------------------------------------------------------------------------------
** Степень многочлена.
** --------------------------------------------------------------------------------------------------------------------
*/
int degPtoN(const LongP& polynomial)
{
    return polynomial.deg; // выводим степень данного многочлена
}
//=====================================================================================================================
/* FAC_P_Q
** --------------------------------------------------------------------------------------------------------------------
** Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
** --------------------------------------------------------------------------------------------------------------------
*/
LongQ facPtoQ(LongP& polynomial)
{
    if (polynomial.deg == 0 && polynomial.odds[0].num.deg == 0 && polynomial.odds[0].num.arrOfNums[0] == 0)
    {
        std::cerr << "Error: polynomial cannot be zero." << std::endl << std::endl;
        return { 0 };
    }

    LongQ result = { 0 };

    result.denom = polynomial.odds[0].denom;

    for (int i = 1; i <= polynomial.deg; i++)
        result.denom = LCMofNNtoN(result.denom , polynomial.odds[i].denom);

    result.num = transNtoZ(absZtoN(polynomial.odds[0].num));
    for (int i = 1; i <= polynomial.deg; i++)
        result.num = transNtoZ(GCFofNNtoN(transZtoN(result.num) , absZtoN(polynomial.odds[i].num)));

    for (int i = 0; i <= polynomial.deg; i++)
        polynomial.odds[i] = divQQtoQ(polynomial.odds[i] , result);

    return result;
}
//=====================================================================================================================
/* MUL_PP_P
** --------------------------------------------------------------------------------------------------------------------
** Умножение многочленов.
** --------------------------------------------------------------------------------------------------------------------
*/
LongP mulPPtoP(const LongP& firstPol , const LongP& secondPol)
{
    LongP result = { 0 };

    result = mulPQtoP(secondPol , firstPol.odds[0]);
    for (int i = 1; i <= firstPol.deg; i++) {
        // i элеменет: a_i * x^i * (secondPol)
        LongP multiplication = mulPQtoP(mulPxktoP(secondPol , i) , firstPol.odds[i]);

        result = addPPtoP(multiplication , result);
    }

    // проверка на нули.
    while (result.deg > 0 && !notZeroNtoB(absZtoN(result.odds[result.deg].num)))
        result.deg--;

    return result;
}
//=====================================================================================================================
/* DIV_PP_P
** --------------------------------------------------------------------------------------------------------------------
** Частное от деления многочлена на многочлен при делении с остатком.
** --------------------------------------------------------------------------------------------------------------------
*/
LongP divPPtoP(const LongP& poly1 , const LongP& poly2)
{
    // копируем первый элемент для того, чтобы из него можно было вычитать.
    LongP copyPoly1 = poly1;
    LongP result = { 0 };
    // случай, когда можно делить (степень первого не меньше второго, иначе 0).
    if (degPtoN(poly1) >= degPtoN(poly2))
    {
        result.deg = degPtoN(poly1) - degPtoN(poly2);
        // для передвижения по массиву результата
        signed short int resDeg = result.deg;
        // пока не меньше степени делителя или! пока не 0
        // случай, если степень делителя равна 0
        while (degPtoN(copyPoly1) >= degPtoN(poly2) &&
            !(degPtoN(copyPoly1) == 0 &&
                copyPoly1.odds[0].num.deg == 0 &&
                copyPoly1.odds[0].num.arrOfNums[0] == 0))
        {
            LongQ coef = copyPoly1.odds[degPtoN(copyPoly1)];
            // коэффициент элемента результата
            result.odds[resDeg] = divQQtoQ(coef , poly2.odds[degPtoN(poly2)]);
            // передвигаемся дальше по элементам результата
            resDeg--;
            // вычитаем часть из первого
            copyPoly1 = subPPtoP(copyPoly1 ,
                mulPxktoP(mulPQtoP(poly2 , result.odds[resDeg + 1]) ,
                    degPtoN(copyPoly1) - degPtoN(poly2)));
        }

        return result;
    }
    else
    {
        return result; // если степень делителя больше делимого, то возвращаем {0}.
    }
}
//=====================================================================================================================
/* MOD_PP_P
** --------------------------------------------------------------------------------------------------------------------
** Остаток от деления многочлена на многочлен при делении с остатком.
** --------------------------------------------------------------------------------------------------------------------
*/
LongP modPPtoP(const LongP& first , const LongP& second)
{
    LongP quotient = divPPtoP(first , second);

    return subPPtoP(first , mulPPtoP(second , quotient));
}
//=====================================================================================================================
/* GCF_PP_P
** --------------------------------------------------------------------------------------------------------------------
** НОД многочленов.
** --------------------------------------------------------------------------------------------------------------------
*/
LongP GCFofPPtoP(const LongP& P_dividend , const LongP& P_divider)
{
    LongP dividend = P_dividend , divider = P_divider;
    while (!(degPtoN(divider) == 0 && divider.odds[0].num.deg == 0 &&
        divider.odds[0].num.arrOfNums[0] == 0))
    {
        LongP temp = divider;
        divider = modPPtoP(dividend , divider);
        dividend = temp;
    }
    return dividend;
}
//=====================================================================================================================
/* DER_P_P
** --------------------------------------------------------------------------------------------------------------------
** Производная многочлена.
** --------------------------------------------------------------------------------------------------------------------
*/
LongP derPtoP(const LongP& polynomial)
{
    LongP result = polynomial;

    if (degPtoN(result) > 0)
    {
        for (signed short int i = 1; i <= degPtoN(result); ++i)
        {
            result.odds[i - 1] = mulQQtoQ(result.odds[i] , { {0, 0, {i}}, {0, {1}} });
        }

        result.odds[degPtoN(result)] = { 0 };
        result.deg--;

        return result;
    }
    else
        return { 0 };
}
//=====================================================================================================================
/* NMR_P_P
** --------------------------------------------------------------------------------------------------------------------
** Преобразование многочлена — кратные корни в простые
** --------------------------------------------------------------------------------------------------------------------
*/
LongP NMRofPtoP(const LongP& Polynom)
{
    if (degPtoN(Polynom) < 2)
    {
        return Polynom;
    }
    // если есть корень кратности k, то он есть в НОД многочлена и его производной
    // в виде кратности k - 1. Простой же корень не входит в этот НОД. Доказательство простое.
    LongP result = { 0 };

    LongP derp = derPtoP(Polynom);

    result = GCFofPPtoP(Polynom , derPtoP(Polynom));

    if (degPtoN(result) == 0)
    {
        return Polynom;
    }

    // в НОД может входить посторонный коэф. в виде m(x-1)^(k-1)*...
    // это получается из-за того, что кратность не гарантирует отсутствие констант в записи
    // поэтому используем ранее использованную функцию по выносу НОД и НОК (при этом изменяя сам аргумент
    // в виде полинома).
    facPtoQ(result);

    // блок кода, инвертирующий знаки, если старший коэффициент отрицателен.
    if (ledPtoQ(result).num.sign == 1)
    {
        for (int i = 0; i <= result.deg; ++i)
            result.odds[i].num = mulZMtoZ(result.odds[i].num);
    }

    return divPPtoP(Polynom , result);
}
//=====================================================================================================================

#endif //HEAD_H
