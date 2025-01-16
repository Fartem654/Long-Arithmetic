#include <iostream>
#include <vector>
#include <string>
#include <clocale>
#include <limits>
using namespace std;

/// Проверка введённого числа и формирование строки без ведущих 0.
void checkInput(string& inp_n);

/// Проверка введённого значения для повторения/окончания программы.
void checkProgrLoop(int& val);

/// Формирование вектора из строки.
vector <int> form_vec(string& inp_n);

/// <summary>
/// Преобразование чисел в формат 16-чной системы счисления.
/// </summary>
/// <param name="x = 12"></param>
/// <returns>C</returns>
string formTo16(int x);

/// Функция деления "столбиком" числа(в виде вектора) на 16.
/// Делит число в виде вектора на 16, записывает частное в результирующий вектор и передаёт остаток.
void dividColBy16(vector <int> divisible, vector <int>& result, int& remaind);

/// Функция проверяет, является ли число меньше16.
/// Если да, записывает его в вектор с ответом и завершает внешний цикл.
bool checkRemains(vector <int> divisible, vector <string>& ans);

/// Поочередно елит частное на 16.
/// Записывает остаток от деления в результирующий вектор, тем  самым формируя 16-чное число.
void bodyOfConvertTo16(vector <int> divisible_a, vector <string>& ans);