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

        string input_numb; // Строка с исходным числом.
        vector <int> vec_num; // Массив с исходным поразрядно разбитым числом.
        vector <string> answer; // Массив с исходным числом в 16-ичной системе счисления. Ответ.

        cout << "Введите целое число больше нуля: \n-> "; cin >> input_numb;
        checkInput(input_numb);

        system("cls");
        cout << "Исходное число (" << input_numb.size() << " знаков):" << endl;
        cout << input_numb << " |10\n" << endl;

        vec_num = form_vec(input_numb); // Массив с исходным поразрядно разбитым числом.


        bodyOfConvertTo16(vec_num, answer);

        cout<<"Исходное число в 16-ичной системе счисления: " << endl;

        for (int i = answer.size()-1; i >=0; i--) {
            cout << answer[i];
        }
        cout << " |16" << endl << endl;

        cout << "Хотите выполнить программу еще раз?\n1 - да\n0 - нет\n-> "; cin >> progr_loop; checkProgrLoop(progr_loop);
    }
}
