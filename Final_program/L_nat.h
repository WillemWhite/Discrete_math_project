#ifndef L_NAT_H
#define L_NAT_H

#include "L_data_types.h"

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
/*****************************************************************************/

#endif //L_NAT_H
