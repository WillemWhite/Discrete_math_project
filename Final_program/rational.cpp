#include <iostream>
#include "L_int.h"
#include "L_nat.h"
#include "L_pol.h"
#include "L_rat.h"

//=====================================================================================================================
/* COM_QQ_B - Доп. модуль. Стукалов Сергей Гр.0375
** --------------------------------------------------------------------------------------------------------------------
** Сравнение рациональных. Дополнительный модуль.
** --------------------------------------------------------------------------------------------------------------------
*/
bool comQQtoB(const LongQ& numQ1 , const LongQ& numQ2)
{
    LongQ num1 = redQtoQ(numQ1);
    LongQ num2 = redQtoQ(numQ2);

    if (num1.num.deg == 0 && num1.num.arrOfNums[0] == 0 &&
        num2.num.deg == 0 && num2.num.arrOfNums[0] == 0)
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
/* RED_Q_Q - Виктор Яблоков Гр.0375
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
/* INT_Q_B - Виктор Яблоков Гр.0375
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
/* TRANS_Z_Q - Виктор Яблоков Гр.0375
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
/* TRANS_Q_Z - Виктор Яблоков Гр.0375
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
/* ADD_QQ_Q - Александр Гирвиц Гр.0375
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
/* SUB_QQ_Q - Александр Гирвиц Гр.0375
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
/* MUL_QQ_Q - Виктор Яблоков Гр.0375
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
/* DIV_QQ_Q - Виктор Яблоков Гр.0375
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
