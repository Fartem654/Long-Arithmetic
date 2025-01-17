#include "head.h"

void checkInput(string& inp_n) {
	int cur_siz = inp_n.size(), lead_zero = 0;
	bool check_loop = 1;

	while (check_loop) {
		cur_siz = inp_n.size();
		check_loop = 0;
		int i = 0;

		// Проверка на наличие пробелов в строке.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1) {
			system("cls");
			cout << "! В введенной строке был обнаружен пробел.\n";
			cout << "Введите целое число больше нуля без пробелов еще раз (пример: 102): \n-> ";
			cin >> inp_n;
			check_loop = 1;
		}

		// Проверка на наличие символов, кроме символов цифр от 0 до 9.
		while (i < cur_siz and !check_loop) {
			if ((int)inp_n[i] < 48 or (int)inp_n[i] > 57) {
				system("cls");
				cout << "-> " << inp_n << endl;
				cout << "В введном числе присутствует недопустимый символ! (" << inp_n[i] << ")\n";
				cout << "! Число должно состоять только из цифр от 0 до 9 и быть целым и неотрицательным. (Пример: 42)\n";
				cout << "Введите целое число больше нуля снова: \n-> ";
				cin >> inp_n;
				check_loop = 1;
			}
			i++;
		}	
	}

	//Подсчёт и удаление ведущих 0.
	int j = 0;
	while (inp_n[j] == '0') {
		lead_zero++; j++;
	}
	inp_n.erase(0, lead_zero);
	if (inp_n.size() == 0) inp_n = "0";
}

void checkProgrLoop(int& val) {
	bool f = 1;
	while(f){

		// Проверка на наличие недопустимых символов.
		if (cin.fail()){
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка!\nВведен недопустимый символ!\n! Введите '1' или '0'.\n";
			cout << "Хотите выполнить программу еще раз?\n1 - да\n0 - нет" << endl << "-> ";
			cin >> val;
			continue;
		}

		// Проверка на наличие пробелов в строке.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1) {
			system("cls");
			cout << "! Введите '1' или '0' без пробелов.\n";
			cout << "Хотите выполнить программу еще раз?\n1 - да\n0 - нет" << endl << "-> ";
			cin >> val;
			continue;
		}

		// Проверка на корректный ввод.
		if (val < 0 or val > 1) {
			system("cls");
			cout << "Введено недопустимое число!\n! Введите '1' или '0'.\n";
			cout << "Хотите выполнить программу еще раз?\n1 - да\n0 - нет" << endl << "-> ";
			cin >> val;
			continue;
		}
		f = 0;
	}
}

 vector <int> form_vec(string& input_numb) {
	 int cur_siz = input_numb.size();
	 vector <int> vec_num;
	 for (int i = 0; i < cur_siz; i++) {
		 vec_num.push_back((int)(input_numb[i] - '0'));
	 }
	 return vec_num;
}

string formTo16(int x){
	 string ans;
	 if (x >= 0 and x <= 9)
		 ans = to_string(x);
	 else {
		 ans = char(x + 55);
	 }
	 return ans;
 }

 void dividColBy16(vector <int> divisible, vector <int> &result, int &remaind) {
	 int len, part_of_divisible, subtrac, whole_pt; //
	 len = divisible.size();

	 part_of_divisible = divisible[0] * 10;// Выделяем 1 разряд делимого.
	 for (int i = 1; i < len; i++) {

		 // Спускаем разряды делимого до числа большего чем 16.
		 part_of_divisible += divisible[i];
		 if (part_of_divisible < 16 and i != len - 1) { 
			 part_of_divisible = part_of_divisible * 10 + divisible[i + 1];
			 if (i != 1) result.push_back(0);
			 i += 1;
		 }

		 // Находим целую часть.
		 whole_pt = part_of_divisible / 16;
		 result.push_back(whole_pt);

		 // Находим остаток.
		 subtrac = whole_pt * 16;
		 remaind = part_of_divisible - subtrac;
		 part_of_divisible = remaind * 10;
	 }
 }

bool checkRemains(vector <int> divisible, vector <string>& answer) {
	bool f = 1;
	if (divisible.size() <= 2) {
		if (divisible.size() == 1) { 
			f = 0;
			answer.push_back(formTo16(divisible[0]));
		}
		else if (divisible[0] * 10 + divisible[1] < 16) {
			f = 0;
			answer.push_back(formTo16(divisible[0] * 10 + divisible[1]));
		}
	}
	return f;
 }

void bodyOfConvertTo16(vector <int> divisible_a, vector <string> &answer) {
	 vector <int> divisible_b;
	 bool f = 1;
	 int remaind;

	 f = checkRemains(divisible_a, answer);
	 
	 while(f){
		 dividColBy16(divisible_a, divisible_b, remaind); // divisible_a - делимое; divisible_b - частное

		 divisible_a.clear(); // - освобождаем вектор для записи частного
		 answer.push_back(formTo16(remaind));// Формируем ответ

		f = checkRemains(divisible_b, answer);

		if(f){
			 dividColBy16(divisible_b, divisible_a, remaind); // divisible_b - делимое; divisible_a - частное

			 divisible_b.clear();
			 answer.push_back(formTo16(remaind)); 

			 f = checkRemains(divisible_a, answer);
		}
	 }
}