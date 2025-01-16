#include <iostream>
#include <vector>
#include <string>
#include <clocale>
#include <limits>
using namespace std;

/// �������� ��������� ����� � ������������ ������ ��� ������� 0.
void checkInput(string& inp_n);

/// �������� ��������� �������� ��� ����������/��������� ���������.
void checkProgrLoop(int& val);

/// ������������ ������� �� ������.
vector <int> form_vec(string& inp_n);

/// <summary>
/// �������������� ����� � ������ 16-���� ������� ���������.
/// </summary>
/// <param name="x = 12"></param>
/// <returns>C</returns>
string formTo16(int x);

/// ������� ������� "���������" �����(� ���� �������) �� 16.
/// ����� ����� � ���� ������� �� 16, ���������� ������� � �������������� ������ � ������� �������.
void dividColBy16(vector <int> divisible, vector <int>& result, int& remaind);

/// ������� ���������, �������� �� ����� ������16.
/// ���� ��, ���������� ��� � ������ � ������� � ��������� ������� ����.
bool checkRemains(vector <int> divisible, vector <string>& ans);

/// ���������� ���� ������� �� 16.
/// ���������� ������� �� ������� � �������������� ������, ���  ����� �������� 16-���� �����.
void bodyOfConvertTo16(vector <int> divisible_a, vector <string>& ans);