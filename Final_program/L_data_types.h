#ifndef L_DATA_TYPES
#define L_DATA_TYPES

#pragma comment(linker, "/STACK:100000000")

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

#endif //L_DATA_TYPES
