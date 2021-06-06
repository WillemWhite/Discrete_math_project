#ifndef L_POL_H
#define L_POL_H

#include "L_data_types.h"

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
/*****************************************************************************/

#endif //L_POL_H
