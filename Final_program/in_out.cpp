#include <iostream>
#include <iomanip>
#include <limits>
#include "L_int.h"
#include "L_nat.h"
#include "L_pol.h"
#include "L_rat.h"
#include "in_out.h"

// Автор всего интерфейса (in_out и function_interface) - Стукалов Сергей Гр.0375

using namespace std;

void inputN(LongN& num)
{
    cin.clear();

    num = { 0 };

    char sym = 0;

    int i = 0; // обратный разряд цифры

    bool zero = true;

    do
    {
        cin.get(sym);
        switch (sym)
        {
        case '1': num.arrOfNums[i] = 1; i++; zero = false; break;
        case '2': num.arrOfNums[i] = 2; i++; zero = false; break;
        case '3': num.arrOfNums[i] = 3; i++; zero = false; break;
        case '4': num.arrOfNums[i] = 4; i++; zero = false; break;
        case '5': num.arrOfNums[i] = 5; i++; zero = false; break;
        case '6': num.arrOfNums[i] = 6; i++; zero = false; break;
        case '7': num.arrOfNums[i] = 7; i++; zero = false; break;
        case '8': num.arrOfNums[i] = 8; i++; zero = false; break;
        case '9': num.arrOfNums[i] = 9; i++; zero = false; break;
        default: break;
        }
    } while (zero && sym != '\n');

    while (sym != '\n')
    {
        cin.get(sym);
        switch (sym)
        {
        case '0': num.arrOfNums[i] = 0; i++; break;
        case '1': num.arrOfNums[i] = 1; i++; break;
        case '2': num.arrOfNums[i] = 2; i++; break;
        case '3': num.arrOfNums[i] = 3; i++; break;
        case '4': num.arrOfNums[i] = 4; i++; break;
        case '5': num.arrOfNums[i] = 5; i++; break;
        case '6': num.arrOfNums[i] = 6; i++; break;
        case '7': num.arrOfNums[i] = 7; i++; break;
        case '8': num.arrOfNums[i] = 8; i++; break;
        case '9': num.arrOfNums[i] = 9; i++; break;
        default: break;
        }
    }

    if (i != 0)
        num.deg = i - 1;
    else
        num.deg = i;

    LongN buf = num;
    for (int i = 0; i <= num.deg; i++)
    {
        num.arrOfNums[i] = buf.arrOfNums[num.deg - i];
    }
}

void outN(const LongN& num)
{
    for (int i = num.deg; i >= 0; i--)
        cout << num.arrOfNums[i];
}

void inputZ(LongZ& num)
{
    cin.clear();

    num = { 0 };

    char sym = 0;
    cin.get(sym);

    int i = 0; // обратный разряд цифры
    switch (sym)
    {
    case '-': num.sign = 1; break;
    case '1': num.arrOfNums[i] = 1; i++; break;
    case '2': num.arrOfNums[i] = 2; i++; break;
    case '3': num.arrOfNums[i] = 3; i++; break;
    case '4': num.arrOfNums[i] = 4; i++; break;
    case '5': num.arrOfNums[i] = 5; i++; break;
    case '6': num.arrOfNums[i] = 6; i++; break;
    case '7': num.arrOfNums[i] = 7; i++; break;
    case '8': num.arrOfNums[i] = 8; i++; break;
    case '9': num.arrOfNums[i] = 9; i++; break;
    default: break;
    }

    bool zero = true;

    if (i == 0)
        zero = true;
    else
        zero = false;

    while (zero && sym != '\n')
    {
        cin.get(sym);
        switch (sym)
        {
        case '1': num.arrOfNums[i] = 1; i++; zero = false; break;
        case '2': num.arrOfNums[i] = 2; i++; zero = false; break;
        case '3': num.arrOfNums[i] = 3; i++; zero = false; break;
        case '4': num.arrOfNums[i] = 4; i++; zero = false; break;
        case '5': num.arrOfNums[i] = 5; i++; zero = false; break;
        case '6': num.arrOfNums[i] = 6; i++; zero = false; break;
        case '7': num.arrOfNums[i] = 7; i++; zero = false; break;
        case '8': num.arrOfNums[i] = 8; i++; zero = false; break;
        case '9': num.arrOfNums[i] = 9; i++; zero = false; break;
        default: break;
        }
    }

    while (sym != '\n')
    {
        cin.get(sym);
        switch (sym)
        {
        case '0': num.arrOfNums[i] = 0; i++; break;
        case '1': num.arrOfNums[i] = 1; i++; break;
        case '2': num.arrOfNums[i] = 2; i++; break;
        case '3': num.arrOfNums[i] = 3; i++; break;
        case '4': num.arrOfNums[i] = 4; i++; break;
        case '5': num.arrOfNums[i] = 5; i++; break;
        case '6': num.arrOfNums[i] = 6; i++; break;
        case '7': num.arrOfNums[i] = 7; i++; break;
        case '8': num.arrOfNums[i] = 8; i++; break;
        case '9': num.arrOfNums[i] = 9; i++; break;
        default: break;
        }
    }

    if (i != 0)
        num.deg = i - 1;
    else
        num.deg = i;

    LongZ buf = num;
    for (int i = 0; i <= num.deg; i++)
    {
        num.arrOfNums[i] = buf.arrOfNums[num.deg - i];
    }
}

void outZ(const LongZ& num)
{
    if (num.sign == 1 && !(num.deg == 0 && num.arrOfNums[0] == 0))
        cout << "-";
    for (int i = num.deg; i >= 0; i--)
        cout << num.arrOfNums[i];
}

void inputQ(LongQ& num)
{
    cin.clear();

    cout << "Пожалуйста, введите дробь в виде:" << endl << endl;
    cout << "\"  Целое число  \"" << endl;
    cout << "-----------------" << endl;
    cout << "Натуральное число" << endl << endl;
    cout << "Ввод дроби:" << endl;
    cout << "__________________________________________________________" <<
        "__________________________________________" << endl;

    inputZ(num.num);

    cout << "-----------------------------------------------------------" <<
        "-----------------------------------------" << endl;

    inputN(num.denom);

    cout << "__________________________________________________________" <<
        "__________________________________________" << endl << endl;

    if (num.denom.deg == 0 && num.denom.arrOfNums[0] == 0)
    {
        cout << "Внимание: вы ввели в качестве знаменателя ноль, поэтому число по умолчанию" << endl <<
            "будет заменено на дробь 0/1, то есть будет равна нулю." << endl << endl;
        num.num = { 0 };
        num.denom = { 0 };
        num.denom.arrOfNums[0] = 1;
    }
}

void outQ(const LongQ& num)
{
    if (num.num.deg >= num.denom.deg)
    {
        int numPos = num.num.deg - num.denom.deg;

        if (num.num.sign == 1)
        {
            cout << "-";
            numPos++;
        }

        for (int i = num.num.deg; i >= 0; --i)
        {
            cout << num.num.arrOfNums[i];
        }
        cout << endl;

        if (num.num.sign == 1)
            cout << " ";

        for (int i = num.num.deg; i >= 0; --i)
        {
            cout << "-";
        }
        cout << endl;

        for (int i = 0; i < (numPos + 1) / 2; ++i)
        {
            cout << " ";
        }

        for (int i = num.denom.deg; i >= 0; --i)
        {
            cout << num.denom.arrOfNums[i];
        }
        cout << endl << endl;
    }
    else
    {
        int numPos = num.denom.deg - num.num.deg - num.num.sign;

        for (int i = 0; i < numPos / 2; ++i)
        {
            cout << " ";
        }

        if (num.num.sign == 1)
        {
            cout << "-";
        }

        for (int i = num.num.deg; i >= 0; --i)
        {
            cout << num.num.arrOfNums[i];
        }
        cout << endl;

        for (int i = num.denom.deg; i >= 0; --i)
        {
            cout << "-";
        }
        cout << endl;

        for (int i = num.denom.deg; i >= 0; --i)
        {
            cout << num.denom.arrOfNums[i];
        }
        cout << endl << endl;
    }
}

void inputP(LongP& pol)
{
    pol = { 0 };

    cin.clear();

    cout << "Пожалуйста, введите степень многочлена, который будете вводить." << endl << endl;

    char sym = 0;
    int pos = 0; //для ограничения на разряды степени многочлена.
    bool zero = true;
    do
    {
        cin.get(sym);
        switch (sym)
        {
        case '1': pol.deg = 1; pos++; zero = false; break;
        case '2': pol.deg = 2; pos++; zero = false; break;
        case '3': pol.deg = 3; pos++; zero = false; break;
        case '4': pol.deg = 4; pos++; zero = false; break;
        case '5': pol.deg = 5; pos++; zero = false; break;
        case '6': pol.deg = 6; pos++; zero = false; break;
        case '7': pol.deg = 7; pos++; zero = false; break;
        case '8': pol.deg = 8; pos++; zero = false; break;
        case '9': pol.deg = 9; pos++; zero = false; break;
        default: break;
        }
    } while (zero && sym != '\n');

    while (pos != 2 && sym != '\n')
    {
        cin.get(sym);
        switch (sym)
        {
        case '0': pol.deg = 10 * pol.deg; pos++; break;
        case '1': pol.deg = 10 * pol.deg + 1; pos++; break;
        case '2': pol.deg = 10 * pol.deg + 2; pos++; break;
        case '3': pol.deg = 10 * pol.deg + 3; pos++; break;
        case '4': pol.deg = 10 * pol.deg + 4; pos++; break;
        case '5': pol.deg = 10 * pol.deg + 5; pos++; break;
        case '6': pol.deg = 10 * pol.deg + 6; pos++; break;
        case '7': pol.deg = 10 * pol.deg + 7; pos++; break;
        case '8': pol.deg = 10 * pol.deg + 8; pos++; break;
        case '9': pol.deg = 10 * pol.deg + 9; pos++; break;
        default: break;
        }
        cin.ignore(numeric_limits<streamsize>::max() , '\n');
    }

    cout << endl << endl;
    cin.clear();

    for (int i = pol.deg; i >= 0; i--)
    {
        cout << "Теперь введите рациональный коэффициент в виде дроби" <<
            " при X^" << i << ":" << endl;
        cout << "__________________________________________________________" <<
            "__________________________________________" << endl << endl;
        inputQ(pol.odds[i]);
        cout << endl;
    }
    cout << endl << "__________________________________________________________" <<
        "__________________________________________" << endl;
}

void outP(const LongP& pol)
{
    for (int k = 0; pol.deg - k * 5 >= 0; k++)
    {
        int symCount[5] = { 0 }; //хранит размер дробей

        LongP bufPol = { 0 }; //хранит полином строчки

        if (pol.deg - (k + 1) * 5 >= 0)
        {
            bufPol.deg = 4;
            for (int i = 0; i <= bufPol.deg; i++)
                bufPol.odds[i] = pol.odds[pol.deg - (k + 1) * 5 + 1 + i];
        }
        else
        {
            bufPol.deg = pol.deg - k * 5;
            for (int i = 0; i <= bufPol.deg; i++)
                bufPol.odds[i] = pol.odds[i];
        }

        for (int i = bufPol.deg; i >= 0; i--)
        {
            // присваиваем значения макс. размеров элементов рац. дробей.
            if (bufPol.odds[i].num.deg < bufPol.odds[i].denom.deg)
                symCount[i] = bufPol.odds[i].denom.deg;
            else
                symCount[i] = bufPol.odds[i].num.deg;
        }

        for (int i = bufPol.deg; i >= 0; i--)
        {
            cout << "  ";
            // пробелы для выравнивания по середине.
            int spc = (symCount[i] - bufPol.odds[i].num.deg) / 2;

            for (int j = 0; j < spc; j++)
                cout << " ";

            outN(absZtoN(bufPol.odds[i].num));

            spc = symCount[i] - spc - bufPol.odds[i].num.deg;

            for (int j = 0; j < spc + 6; j++)
                cout << " ";
        }

        cout << endl;

        for (int i = pol.deg - k * 5; i >= pol.deg - k * 5 - bufPol.deg; i--)
        {
            if (pol.odds[i].num.sign == 1)
                cout << "- ";
            else
                cout << "+ ";

            for (int j = 0; j <= symCount[i + k * 5 - pol.deg + bufPol.deg]; j++)
                cout << "-";

            cout << " X^" << i;
            if (i < 10)
                cout << " ";
            cout << " ";
        }

        cout << endl;

        for (int i = bufPol.deg; i >= 0; i--)
        {
            cout << "  ";
            // пробелы для выравнивания по середине.
            int spc = (symCount[i] - bufPol.odds[i].denom.deg) / 2;

            for (int j = 0; j < spc; j++)
                cout << " ";

            outN(bufPol.odds[i].denom);

            spc = symCount[i] - spc - bufPol.odds[i].denom.deg;

            for (int j = 0; j < spc + 6; j++)
                cout << " ";
        }
        cout << endl << endl;
    }
}
