#include "func.h"
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int progr_loop = 1; 

    ///Программа перевода многозначного числа (с количеством знаков больше 20) в систему счисления с основанием шестнадцать.

    // Основной цикл программы.
    while(progr_loop){
        system("cls");
        cout << "Программа перевода многозначного числа в систему счисления с основанием шестнадцать.\n";

        string input_numb;
        cout << "Введите целое число больше нуля: \n-> "; cin >> input_numb;
        checkInput(input_numb);

        system("cls");
        cout << "Исходное число (" << input_numb.size() << " знаков):" << endl;
        cout << input_numb << " |10\n" << endl;

        vector <int> vec_num = form_vec(input_numb);
        vector <string> quotient;

        bodyOfConvertTo16(vec_num, quotient);

        cout<<"Исходное число в 16-ичной системе счисления: " << endl;

        for (int i = quotient.size()-1; i >=0; i--) {
            cout << quotient[i];
        }
        cout << " |16" << endl << endl;

        cout << "Хотите выполнить программу еще раз?\n1 - да\n0 - нет\n-> "; cin >> progr_loop; checkProgrLoop(progr_loop);
    }
}
