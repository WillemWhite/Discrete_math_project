#ifndef L_RAT_H
#define L_RAT_H

#include "L_data_types.h"

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
/*****************************************************************************/

#endif //L_RAT_H
