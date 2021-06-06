#include <iostream>
#include <iomanip>
#include <conio.h>
#include <limits>
#include "L_int.h"
#include "L_nat.h"
#include "L_pol.h"
#include "L_rat.h"
#include "in_out.h"
#include "interf_func.h"

// Автор всего интерфейса (in_out и function_interface) - Стукалов Сергей Гр.0375

using namespace std;

char mainMenu()
{
    system("cls");
    cout << "\tПриветствуем вас в нашей программе!" << endl <<
        "---------------------------------------------------" << endl <<
        "Для начала выберете нужный вам тип данных:" << endl << endl;
    cout << "1. Натуральные числа с нулём." << endl <<
        "2. Целые числа." << endl <<
        "3. Рациональные числа." << endl <<
        "4. Многочлены." << endl << endl;
    cout << "Для перехода к соответствующему заглавию введите цифру, соответствующую номеру типа данных."
        << endl << endl << "Для выхода введите q или Q на клавиатуре." << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    char param = 0;

    param = _getch();

    system("cls");

    return param;
}

void natMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");
        cout << "Выберете модуль, который хотите использовать: " << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl <<
            "a.) COM_NN_D - Сравнение натуральных чисел." << endl <<
            "b.) NZER_N_B - Проверка на ноль: если число не равно нулю, " << endl <<
            "то «да» иначе «нет»." << endl <<
            "c.) ADD_1N_N - Добавление 1 к натуральному числу." << endl <<
            "d.) ADD_NN_N - Сложение натуральных чисел." << endl <<
            "e.) SUB_NN_N - Вычитание из первого большего натурального " << endl <<
            "числа второго меньшего или равного." << endl <<
            "f.) MUL_ND_N - Умножение натурального числа на цифру." << endl <<
            "g.) MUL_Nk_N - Умножение натурального числа на 10^k." << endl <<
            "h.) MUL_NN_N - Умножение натуральных чисел." << endl <<
            "j.) SUB_NDN_N - Вычитание из натурального другого натурального, " << endl <<
            "умноженного на цифру для случая с неотрицательным результатом." << endl <<
            "k.) DIV_NN_Dk - Вычисление первой цифры деления большего натурального на меньшее, " << endl <<
            "домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля)." << endl <<
            "l.) DIV_NN_N - Частное от деления большего натурального числа на меньшее или равное " << endl <<
            "натуральное с остатком(делитель отличен от нуля)." << endl <<
            "m.) MOD_NN_N - Остаток от деления большего натурального числа на меньшее или равное " << endl <<
            "натуральное с остатком(делитель отличен от нуля)." << endl <<
            "n.) GCF_NN_N - НОД натуральных чисел." << endl <<
            "o.) LCM_NN_N - НОК натуральных чисел." << endl << endl <<
            "Для перехода к соответствующему заглавию нажмите на латинскую букву," << endl <<
            "соответствующую нужному модулю." << endl << endl <<
            "Для выхода введите q или Q на клавиатуре." << endl <<
            "-------------------------------------------------------------------------------------------" << endl;

        char param = 0;
        param = _getch();

        switch (param)
        {
        case 'a': system("cls"); comNNtoDmMenu(); break;
        case 'b': system("cls"); notZeroNtoBmMenu(); break;
        case 'c': system("cls"); add1NtoNmMenu(); break;
        case 'd': system("cls"); addNNtoNmMenu(); break;
        case 'e': system("cls"); subNNtoNmMenu(); break;
        case 'f': system("cls"); mulNDtoNmMenu(); break;
        case 'g': system("cls"); mulNktoNmMenu(); break;
        case 'h': system("cls"); mulNNtoNmMenu(); break;
        case 'j': system("cls"); subNDNtoNmMenu(); break;
        case 'k': system("cls"); divNNtoDkmMenu(); break;
        case 'l': system("cls"); divNNtoNmMenu(); break;
        case 'm': system("cls"); modNNtoNmMenu(); break;
        case 'n': system("cls"); GCFofNNtoNmMenu(); break;
        case 'o': system("cls"); LCMofNNtoNmMenu(); break;
        case 'q': system("cls"); exit = true; break;
        case 'Q': system("cls"); exit = true; break;
        }
    }
}

void intMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");
        cout << "Выберете модуль, который хотите использовать: " << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl <<
            "a.) COM_ZZ_B - Сравнение целых чисел." << endl <<
            "b.) ABS_Z_N - Абсолютная величина числа, результат - натуральное." << endl <<
            "c.) POZ_Z_D - Определение положительности числа." << endl <<
            "d.) MUL_ZM_Z - Умножение целого на (-1)." << endl <<
            "e.) TRANS_N_Z - Преобразование натурального в целое." << endl <<
            "f.) TRANS_Z_N - Преобразование целого неотрицательного в натуральное." << endl <<
            "g.) ADD_ZZ_Z - Сложение целых чисел." << endl <<
            "h.) SUB_ZZ_Z - Вычитание целых чисел." << endl <<
            "j.) MUL_ZZ_Z - Умножение целых чисел." << endl <<
            "k.) DIV_ZZ_Z - Частное от деления целого на целое (делитель отличен от нуля)." << endl <<
            "l.) MOD_ZZ_Z - Остаток от деления целого на целое (делитель отличен от нуля)." << endl << endl <<
            "Для перехода к соответствующему заглавию нажмите на букву, соответствующую нужному модулю." <<
            endl << endl << "Для выхода введите q или Q на клавиатуре." << endl <<
            "-------------------------------------------------------------------------------------------" << endl;

        char param = 0;
        param = _getch();

        switch (param)
        {
        case 'a': system("cls"); comZZtoBmMenu(); break;
        case 'b': system("cls"); absZtoNmMenu(); break;
        case 'c': system("cls"); pozZtoDmMenu(); break;
        case 'd': system("cls"); mulZMtoZmMenu(); break;
        case 'e': system("cls"); transNtoZmMenu(); break;
        case 'f': system("cls"); transZtoNmMenu(); break;
        case 'g': system("cls"); addZZtoZmMenu(); break;
        case 'h': system("cls"); subZZtoZmMenu(); break;
        case 'j': system("cls"); mulZZtoZmMenu(); break;
        case 'k': system("cls"); divZZtoZmMenu(); break;
        case 'l': system("cls"); modZZtoZmMenu(); break;
        case 'q': system("cls"); exit = true; break;
        case 'Q': system("cls"); exit = true; break;
        }
    }
}

void ratMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");
        cout << "Выберете модуль, который хотите использовать: " << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl <<
            "a.) COM_QQ_B - Сравнение дробей." << endl <<
            "b.) RED_Q_Q - Сокращение дроби." << endl <<
            "c.) INT_Q_B - Проверка на целое, если рациональное число является целым." << endl <<
            "d.) TRANS_Z_Q - Преобразование целого в дробное." << endl <<
            "e.) TRANS_Q_Z - Преобразование дробного в целое (если знаменатель равен 1)." << endl <<
            "f.) ADD_QQ_Q - Сложение дробей." << endl <<
            "g.) SUB_QQ_Q - Вычитание дробей." << endl <<
            "h.) MUL_QQ_Q - Умножение дробей." << endl <<
            "j.) DIV_QQ_Q - Деление дробей (делитель отличен от нуля)." << endl << endl <<
            "Для перехода к соответствующему заглавию нажмите на букву, соответствующую нужному модулю." <<
            endl << endl << "Для выхода введите q или Q на клавиатуре." << endl <<
            "-------------------------------------------------------------------------------------------" << endl;

        char param = 0;
        param = _getch();

        switch (param)
        {
        case 'a': system("cls"); comQQtoBmMenu(); break;
        case 'b': system("cls"); redQtoQmMenu(); break;
        case 'c': system("cls"); intQtoBmMenu(); break;
        case 'd': system("cls"); transZtoQmMenu(); break;
        case 'e': system("cls"); transQtoZmMenu(); break;
        case 'f': system("cls"); addQQtoQmMenu(); break;
        case 'g': system("cls"); subQQtoQmMenu(); break;
        case 'h': system("cls"); mulQQtoQmMenu(); break;
        case 'j': system("cls"); divQQtoQmMenu(); break;
        case 'q': system("cls"); exit = true; break;
        case 'Q': system("cls"); exit = true; break;
        }
    }
}


void polMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");
        cout << "Выберете модуль, который хотите использовать: " << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl <<
            "a.) COM_PP_B - Сравнение многочленов." << endl <<
            "b.) ADD_PP_P - Сложение многочленов." << endl <<
            "c.) SUB_PP_P - Вычитание многочленов." << endl <<
            "d.) MUL_PQ_P - Умножение многочлена на рациональное число." << endl <<
            "e.) MUL_Pxk_P - Умножение многочлена на x^k." << endl <<
            "f.) LED_P_Q - Старший коэффициент многочлена." << endl <<
            "g.) DEG_P_N - Степень многочлена." << endl <<
            "h.) FAC_P_Q - Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей." << endl <<
            "j.) MUL_PP_P - Умножение многочленов." << endl <<
            "k.) DIV_PP_P - Частное от деления многочлена на многочлен при делении с остатком." << endl <<
            "l.) MOD_PP_P - Остаток от деления многочлена на многочлен при делении с остатком." << endl <<
            "m.) GCF_PP_P - НОД многочленов." << endl <<
            "n.) DER_P_P - Производная многочлена." << endl <<
            "o.) NMR_P_P - Преобразование многочлена — кратные корни в простые." << endl << endl <<
            "Для перехода к соответствующему заглавию введите число, соответствующее нужному модулю." <<
            endl << endl << "Для выхода введите q или Q на клавиатуре." << endl <<
            "-------------------------------------------------------------------------------------------" << endl;

        char param = 0;
        param = _getch();

        switch (param)
        {
        case 'a': system("cls"); comPPtoBmMenu(); break;
        case 'b': system("cls"); addPPtoPmMenu(); break;
        case 'c': system("cls"); subPPtoPmMenu(); break;
        case 'd': system("cls"); mulPQtoPmMenu(); break;
        case 'e': system("cls"); mulPxktoPmMenu(); break;
        case 'f': system("cls"); ledPtoQmMenu(); break;
        case 'g': system("cls"); degPtoNmMenu(); break;
        case 'h': system("cls"); facPtoQmMenu(); break;
        case 'j': system("cls"); mulPPtoPmMenu(); break;
        case 'k': system("cls"); divPPtoPmMenu(); break;
        case 'l': system("cls"); modPPtoPmMenu(); break;
        case 'm': system("cls"); GCFofPPtoPmMenu(); break;
        case 'n': system("cls"); derPtoPmMenu(); break;
        case 'o': system("cls"); NMRofPtoPmMenu(); break;
        case 'q': system("cls"); exit = true; break;
        case 'Q': system("cls"); exit = true; break;
        }
    }
}


void comNNtoDmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "COM_NN_D" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        int res = comNNtoD(num1 , num2);

        switch (res)
        {
        case 0: cout << "Числа равны." << endl << endl; break;
        case 1: cout << "Второе число больше первого." << endl << endl; break;
        case 2: cout << "Первое число больше второго." << endl << endl; break;
        }

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void notZeroNtoBmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "NZER_N_B" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Проверка на ноль: если число не равно нулю, то «да» иначе «нет»." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите число:" << endl << endl;
        inputN(num1);

        bool res = notZeroNtoB(num1);

        switch (res)
        {
        case true: cout << "Введённое число не является нулём." << endl << endl; break;
        case false: cout << "Введённое число - это ноль." << endl << endl; break;
        }

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void add1NtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "ADD_1N_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Добавление 1 к натуральному числу." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите число:" << endl << endl;
        inputN(num1);

        cout << "Сумма с единицей:" << endl << endl;

        LongN res = add1NtoN(num1);

        outN(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void addNNtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "ADD_NN_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сложение натуральных чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        cout << "Сумма:" << endl << endl;

        LongN res = addNNtoN(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void subNNtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "SUB_NN_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Вычитание из первого большего натурального числа второго меньшего или равного." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        if (comNNtoD(num1 , num2) != 1)
        {
            cout << "Разность:" << endl << endl;

            LongN res = subNNtoN(num1 , num2);

            outN(res);

            cout << endl << endl;
        }
        else
        {
            cout << "Ошибка ввода: второе должно быть меньше или равно первому. Повторите снова." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void mulNDtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_ND_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Умножение натурального числа на цифру." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите число:" << endl << endl;
        inputN(num1);

        int num2 = 0;
        cout << "Введите цифру (от 0 до 9):" << endl << endl;
        cin >> num2;

        if (num2 > 9 || num2 < 0)
        {
            cout << "Неверный ввод, попробуйте ещё раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Произведение:" << endl << endl;

        LongN res = mulNDtoN(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void mulNktoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_Nk_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Умножение натурального числа на 10^k." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите число:" << endl << endl;
        inputN(num1);

        int num2 = 0;
        cout << "Введите k (не меньше 0):" << endl << endl;
        cin >> num2;
        cin.ignore();

        if (num2 < 0)
        {
            cout << "Неверный ввод, попробуйте ещё раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Произведение:" << endl << endl;

        LongN res = mulNktoN(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void mulNNtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_NN_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Умножение натуральных чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        cout << "Произведение:" << endl << endl;

        LongN res = mulNNtoN(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void subNDNtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "SUB_NDN_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Вычитание из натурального другого натурального, умноженного на " << endl <<
            "цифру для случая с неотрицательным результатом." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        int num2 = 0;
        cout << "Введите цифру (от 0 до 9):" << endl << endl;
        cin >> num2;
        cin.ignore();

        if (num2 > 9 || num2 < 0)
        {
            cout << "Неверный ввод, попробуйте ещё раз." << endl << endl;
            continue;
        }

        LongN num3 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num3);

        if (comNNtoD(num1 , mulNDtoN(num3 , num2)) == 1)
        {
            cout << "Неверный ввод, попробуйте ещё раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Разность:" << endl << endl;

        LongN res = subNDNtoN(num1 , num2 , num3);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void divNNtoDkmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "DIV_NN_Dk" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Вычисление первой цифры деления большего натурального на меньшее," << endl <<
            "домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля)." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        if (comNNtoD(num1 , num2) == 1 || !notZeroNtoB(num2))
        {
            cout << "Неверный ввод, попробуйте ещё раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Первая цифра деления представима в виде:" << endl << endl;

        LongN res = divNNtoDk(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void divNNtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "DIV_NN_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Частное от деления большего натурального числа на меньшее " << endl <<
            "или равное натуральное с остатком(делитель отличен от нуля)." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        if (comNNtoD(num1 , num2) == 1 || !notZeroNtoB(num2))
        {
            cout << "Неверный ввод, попробуйте ещё раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Частное от деления:" << endl << endl;

        LongN res = divNNtoN(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void modNNtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MOD_NN_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Остаток от деления большего натурального числа на меньшее или " << endl <<
            "равное натуральное с остатком(делитель отличен от нуля)." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        if (comNNtoD(num1 , num2) == 1 || !notZeroNtoB(num2))
        {
            cout << "Неверный ввод, попробуйте ещё раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Остаток от деления:" << endl << endl;

        LongN res = modNNtoN(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void GCFofNNtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "GCF_NN_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "НОД натуральных чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        cout << "НОД:" << endl << endl;

        LongN res = GCFofNNtoN(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void LCMofNNtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "LCM_NN_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "НОК натуральных чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputN(num1);

        LongN num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputN(num2);

        cout << "НОК:" << endl << endl;

        LongN res = LCMofNNtoN(num1 , num2);

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void comZZtoBmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "COM_ZZ_B" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сравнение целых чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputZ(num1);

        LongZ num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputZ(num2);

        bool res = comZZtoB(num1 , num2);

        if (res)
            cout << "Целые числа равны друг другу." << endl << endl;
        else
            cout << "Целые числа не равны друг другу." << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void absZtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "ABS_Z_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Абсолютная величина числа, результат - натуральное." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите целое число:" << endl << endl;
        inputZ(num1);

        LongN res = absZtoN(num1);

        cout << "Абсолютное значение целого числа:" << endl << endl;

        outN(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void pozZtoDmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "POZ_Z_D" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)" << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputZ(num1);

        int res = pozZtoD(num1);

        switch (res)
        {
        case 0: cout << "Число равно нулю." << endl << endl; break;
        case 1: cout << "Число отрицательное." << endl << endl; break;
        case 2: cout << "Число положительное." << endl << endl; break;
        }

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void mulZMtoZmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_ZM_Z" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Умножение целого на (-1)." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите целое число:" << endl << endl;
        inputZ(num1);

        LongZ res = mulZMtoZ(num1);

        cout << "Умноженное на (-1):" << endl << endl;

        outZ(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void transNtoZmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "TRANS_N_Z" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Преобразование натурального в целое." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongN num1 = { 0 };
        cout << "Введите натуральное число:" << endl << endl;
        inputN(num1);

        LongZ res = transNtoZ(num1);

        cout << "Целое:" << endl << endl;

        outZ(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void transZtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "TRANS_Z_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Преобразование целого неотрицательного в натуральное." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите натуральное число:" << endl << endl;
        inputZ(num1);

        if (pozZtoD(num1) != 1)
        {
            LongN res = transZtoN(num1);

            cout << "Целое:" << endl << endl;

            outN(res);
        }
        else
        {
            cout << "Неверный ввод, попробуйте еще раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void addZZtoZmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "ADD_ZZ_Z" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сложение целых чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputZ(num1);

        LongZ num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputZ(num2);

        cout << "Сумма:" << endl << endl;

        LongZ res = addZZtoZ(num1 , num2);

        outZ(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void subZZtoZmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "SUB_ZZ_Z" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Вычитание целых чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputZ(num1);

        LongZ num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputZ(num2);

        cout << "Разность:" << endl << endl;

        LongZ res = subZZtoZ(num1 , num2);

        outZ(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void mulZZtoZmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_ZZ_Z" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Умножение целых чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputZ(num1);

        LongZ num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputZ(num2);

        cout << "Произведение:" << endl << endl;

        LongZ res = mulZZtoZ(num1 , num2);

        outZ(res);

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void divZZtoZmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "DIV_ZZ_Z" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Частное от деления целого на целое (делитель отличен от нуля)." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputZ(num1);

        LongZ num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputZ(num2);

        if (pozZtoD(num2) != 0)
        {
            cout << "Частное от деления целого на целое:" << endl << endl;

            LongZ res = divZZtoZ(num1 , num2);

            outZ(res);
        }
        else
        {
            cout << "Неверный ввод, попробуйте еще раз" << endl << endl;
            system("pause");
            continue;
        }

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void modZZtoZmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MOD_ZZ_Z" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Остаток от деления целого на целое (делитель отличен от нуля)." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputZ(num1);

        LongZ num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputZ(num2);

        if (pozZtoD(num2) != 0)
        {
            cout << "Остаток от деления целого на целое:" << endl << endl;

            LongZ res = modZZtoZ(num1 , num2);

            outZ(res);
        }
        else
        {
            cout << "Неверный ввод, попробуйте еще раз" << endl << endl;
            system("pause");
            continue;
        }

        cout << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void comQQtoBmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "COM_QQ_B" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сравнение рациональных чисел." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongQ num1 = { 0 };
        cout << "Введите первое число:" << endl << endl;
        inputQ(num1);

        LongQ num2 = { 0 };
        cout << "Введите второе число:" << endl << endl;
        inputQ(num2);

        bool res = comQQtoB(num1 , num2);

        if (res)
            cout << "Рациональные числа равны друг другу." << endl << endl;
        else
            cout << "Рациональные числа не равны друг другу." << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void redQtoQmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "RED_Q_Q" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сокращение дроби." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongQ num1 = { 0 };
        cout << "Введите рациональное число:" << endl << endl;
        inputQ(num1);

        LongQ res = redQtoQ(num1);

        cout << "Сокращённая дробь:" << endl << endl;

        outQ(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void intQtoBmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "INT_Q_B" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Проверка на целое, если рациональное число является целым, то «да», иначе «нет»." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongQ num1 = { 0 };
        cout << "Введите рациональное число:" << endl << endl;
        inputQ(num1);

        bool res = intQtoB(num1);

        if (res)
            cout << "Рациональное число является целым." << endl << endl;
        else
            cout << "Рациональное число не является целым." << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void transZtoQmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "TRANS_Z_Q" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Преобразование целого в дробное." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongZ num1 = { 0 };
        cout << "Введите целое число:" << endl << endl;
        inputZ(num1);

        LongQ res = transZtoQ(num1);

        cout << "Рациональное из целого:" << endl << endl;

        outQ(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void transQtoZmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "TRANS_Q_Z" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Преобразование дробного в целое (если знаменатель равен 1)." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongQ num1 = { 0 };
        cout << "Введите рациональное число:" << endl << endl;
        inputQ(num1);

        num1 = redQtoQ(num1);

        if (num1.denom.deg == 0 && num1.denom.arrOfNums[0] == 1)
        {
            LongZ res = transQtoZ(num1);

            cout << "Целое из рационального:" << endl << endl;

            outZ(res);

            cout << endl << endl;
        }
        else
        {
            cout << "Неверный ввод, попробуйте еще раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void addQQtoQmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "ADD_QQ_Q" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сложение дробей." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongQ num1 = { 0 };
        cout << "Введите первое рациональное число:" << endl << endl;
        inputQ(num1);

        LongQ num2 = { 0 };
        cout << "Введите второе рациональное число:" << endl << endl;
        inputQ(num2);

        LongQ res = addQQtoQ(num1 , num2);

        cout << "Сумма рациональных чисел равна:" << endl << endl;

        outQ(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void subQQtoQmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "SUB_QQ_Q" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Разность дробей." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongQ num1 = { 0 };
        cout << "Введите первое рациональное число:" << endl << endl;
        inputQ(num1);

        LongQ num2 = { 0 };
        cout << "Введите второе рациональное число:" << endl << endl;
        inputQ(num2);

        LongQ res = subQQtoQ(num1 , num2);

        cout << "Разность рациональных чисел равна:" << endl << endl;

        outQ(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void mulQQtoQmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_QQ_Q" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Произведение дробей." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongQ num1 = { 0 };
        cout << "Введите первое рациональное число:" << endl << endl;
        inputQ(num1);

        LongQ num2 = { 0 };
        cout << "Введите второе рациональное число:" << endl << endl;
        inputQ(num2);

        LongQ res = mulQQtoQ(num1 , num2);

        cout << "Произведение рациональных чисел равно:" << endl << endl;

        outQ(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void divQQtoQmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "DIV_QQ_Q" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Деление дробей (делитель отличен от нуля!)." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongQ num1 = { 0 };
        cout << "Введите первое рациональное число:" << endl << endl;
        inputQ(num1);

        LongQ num2 = { 0 };
        cout << "Введите второе рациональное число:" << endl << endl;
        inputQ(num2);

        if (pozZtoD(num2.num) != 0)
        {
            LongQ res = divQQtoQ(num1 , num2);

            cout << "Деление рациональных чисел даёт:" << endl << endl;

            outQ(res);
        }
        else
        {
            cout << "Неверный ввод, повторите еще раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void comPPtoBmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "COM_PP_B" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сравнение многочленов." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод первого многочлена:" << endl << endl;
        inputP(num1);

        LongP num2 = { 0 };
        cout << "Ввод второго многочлена:" << endl << endl;
        inputP(num2);

        bool res = comPPtoB(num1 , num2);

        if (res)
            cout << "Многочлены равны друг другу." << endl << endl;
        else
            cout << "Многочлены не равны друг другу." << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void addPPtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "ADD_PP_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Сложение многочленов." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод первого многочлена:" << endl << endl;
        inputP(num1);

        LongP num2 = { 0 };
        cout << "Ввод второго многочлена:" << endl << endl;
        inputP(num2);

        LongP res = addPPtoP(num1 , num2);

        cout << "Сумма многочленов равна:" << endl << endl;

        outP(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void subPPtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "SUB_PP_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Разность многочленов." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод первого многочлена:" << endl << endl;
        inputP(num1);

        LongP num2 = { 0 };
        cout << "Ввод второго многочлена:" << endl << endl;
        inputP(num2);

        LongP res = subPPtoP(num1 , num2);

        cout << "Разность многочленов равна:" << endl << endl;

        outP(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void mulPQtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_PQ_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Умножение многочлена на рациональное число." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод многочлена:" << endl << endl;
        inputP(num1);

        LongQ num2 = { 0 };
        cout << "Ввод рационального числа:" << endl << endl;
        inputQ(num2);

        LongP res = mulPQtoP(num1 , num2);

        cout << "Произведение многочлена на рациональное число:" << endl << endl;

        outP(res);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}
void mulPxktoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_Pxk_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Умножение многочлена на x^k." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод многочлена:" << endl << endl;
        inputP(num1);

        int k = 0;
        cout << "Ввод степени x:" << endl << endl;
        cin >> k;
        cin.ignore();

        if (num1.deg + k < 99)
        {
            LongP res = mulPxktoP(num1 , k);

            cout << "Произведение многочлена на x^k:" << endl << endl;

            outP(res);
        }
        else
        {
            cout << "Неверный ввод, повторите еще раз." << endl << endl;
            system("pause");
            continue;
        }

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void ledPtoQmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "LED_P_Q" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Старший коэффициент многочлена." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод многочлена:" << endl << endl;
        inputP(num1);

        cout << "Старший коэффициент многочлена:" << endl << endl;

        outQ(ledPtoQ(num1));

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void degPtoNmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "DEG_P_N" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Степень многочлена." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод многочлена:" << endl << endl;
        inputP(num1);

        cout << "Степень многочлена:" << endl << endl;

        cout << degPtoN(num1) << endl << endl;

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void facPtoQmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "FAC_P_Q" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод многочлена:" << endl << endl;
        inputP(num1);

        cout << "Коэффициент при многочлене с НОД и НОК:" << endl << endl;

        outQ(facPtoQ(num1)); // здесь же и по ссылке изменяется аргумент.

        cout << "Сам многочлен после изменения:" << endl << endl;

        outP(num1);

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void mulPPtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MUL_PP_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Умножение многочленов." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод первого многочлена:" << endl << endl;
        inputP(num1);

        LongP num2 = { 0 };
        cout << "Ввод второго многочлена:" << endl << endl;
        inputP(num2);

        cout << "Произведение многочленов:" << endl << endl;

        outP(mulPPtoP(num1 , num2));

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void divPPtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "DIV_PP_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Частное от деления многочлена на многочлен при делении с остатком." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод первого многочлена:" << endl << endl;
        inputP(num1);

        LongP num2 = { 0 };
        cout << "Ввод второго многочлена:" << endl << endl;
        inputP(num2);

        cout << "Частное от деления многочлена на многочлен при делении с остатком:" << endl << endl;

        outP(divPPtoP(num1 , num2));

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void modPPtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MOD_PP_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Остаток от деления многочлена на многочлен при делении с остатком." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод первого многочлена:" << endl << endl;
        inputP(num1);

        LongP num2 = { 0 };
        cout << "Ввод второго многочлена:" << endl << endl;
        inputP(num2);

        cout << "Остаток от деления многочлена на многочлен при делении с остатком:" << endl << endl;

        outP(modPPtoP(num1 , num2));

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void GCFofPPtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "MOD_PP_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "НОД многочленов." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод первого многочлена:" << endl << endl;
        inputP(num1);

        LongP num2 = { 0 };
        cout << "Ввод второго многочлена:" << endl << endl;
        inputP(num2);

        cout << "НОД многочленов:" << endl << endl;

        outP(GCFofPPtoP(num1 , num2));

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void derPtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "DER_P_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Производная многочлена." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод многочлена:" << endl << endl;
        inputP(num1);

        cout << "Его производная:" << endl << endl;

        outP(derPtoP(num1));

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}

void NMRofPtoPmMenu()
{
    bool exit = false;

    while (!exit)
    {
        system("cls");

        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "NMR_P_P" << endl;
        cout << "--------------------------------------------------------" <<
            "-----------------------------------" << endl;
        cout << "Преобразование многочлена — кратные корни в простые." << endl;
        cout << "________________________________________________________" <<
            "___________________________________" << endl << endl;

        LongP num1 = { 0 };
        cout << "Ввод многочлена:" << endl << endl;
        inputP(num1);

        cout << "После преобразований:" << endl << endl;

        outP(NMRofPtoP(num1));

        cout << "Для выхода из модуля введите q или Q. Если же хотите попробовать " << endl <<
            "еще раз, то просто введите что угодно кроме этого." << endl << endl;

        char sym = _getch();

        if (sym == 'q' || sym == 'Q')
            exit = true;

        system("cls");
    }
}
