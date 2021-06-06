#ifndef L_INT_H
#define L_INT_H

#include "L_data_types.h"

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
/*****************************************************************************/

#endif //L_INT_H
