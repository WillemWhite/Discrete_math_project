#include <iostream>
#include <iomanip>
#include <conio.h>
#include "L_int.h"
#include "L_nat.h"
#include "L_pol.h"
#include "L_rat.h"
#include "in_out.h"
#include "interf_func.h"

using namespace std;

int main(int argc , char* argv[])
{
    setlocale(LC_ALL , "ru");
    system("title Система компьютерной алгебры.");
    system("color F0");

    bool exit = false;

    while (!exit)
    {
        system("cls");
        switch (mainMenu())
        {
        case '1': system("cls"); natMenu(); break;
        case '2': system("cls"); intMenu(); break;
        case '3': system("cls"); ratMenu(); break;
        case '4': system("cls"); polMenu(); break;
        case 'q': system("cls"); exit = true; break;
        case 'Q': system("cls"); exit = true; break;
        }
    }

    system("cls");
    cout << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t*Благодарю за пользование программой. По ошибкам обращаться на email: *" << endl;
    cout << "\t\t\t*         willemblack128@gmail.com или ssstukalov@stud.etu.ru         *" << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    cout << "\t\t\t\t\t\t******************" << endl;
    cout << "\t\t\t\t\t\t* Чести и удачи. *" << endl;
    cout << "\t\t\t\t\t\t******************" << endl;
    cout << endl << endl << endl << endl << endl << endl;

    system("pause");
    system("cls");

    return 0;
}
