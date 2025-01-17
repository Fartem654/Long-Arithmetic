#include "head.h"

void checkInput(string& inp_n) {
	int cur_siz = inp_n.size(), lead_zero = 0;
	bool check_loop = 1;

	while (check_loop) {
		cur_siz = inp_n.size();
		check_loop = 0;
		int i = 0;

		// �������� �� ������� �������� � ������.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1) {
			system("cls");
			cout << "! � ��������� ������ ��� ��������� ������.\n";
			cout << "������� ����� ����� ������ ���� ��� �������� ��� ��� (������: 102): \n-> ";
			cin >> inp_n;
			check_loop = 1;
		}

		// �������� �� ������� ��������, ����� �������� ���� �� 0 �� 9.
		while (i < cur_siz and !check_loop) {
			if ((int)inp_n[i] < 48 or (int)inp_n[i] > 57) {
				system("cls");
				cout << "-> " << inp_n << endl;
				cout << "� ������� ����� ������������ ������������ ������! (" << inp_n[i] << ")\n";
				cout << "! ����� ������ �������� ������ �� ���� �� 0 �� 9 � ���� ����� � ���������������. (������: 42)\n";
				cout << "������� ����� ����� ������ ���� �����: \n-> ";
				cin >> inp_n;
				check_loop = 1;
			}
			i++;
		}	
	}

	//������� � �������� ������� 0.
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

		// �������� �� ������� ������������ ��������.
		if (cin.fail()){
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������!\n������ ������������ ������!\n! ������� '1' ��� '0'.\n";
			cout << "������ ��������� ��������� ��� ���?\n1 - ��\n0 - ���" << endl << "-> ";
			cin >> val;
			continue;
		}

		// �������� �� ������� �������� � ������.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1) {
			system("cls");
			cout << "! ������� '1' ��� '0' ��� ��������.\n";
			cout << "������ ��������� ��������� ��� ���?\n1 - ��\n0 - ���" << endl << "-> ";
			cin >> val;
			continue;
		}

		// �������� �� ���������� ����.
		if (val < 0 or val > 1) {
			system("cls");
			cout << "������� ������������ �����!\n! ������� '1' ��� '0'.\n";
			cout << "������ ��������� ��������� ��� ���?\n1 - ��\n0 - ���" << endl << "-> ";
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

	 part_of_divisible = divisible[0] * 10;// �������� 1 ������ ��������.
	 for (int i = 1; i < len; i++) {

		 // �������� ������� �������� �� ����� �������� ��� 16.
		 part_of_divisible += divisible[i];
		 if (part_of_divisible < 16 and i != len - 1) { 
			 part_of_divisible = part_of_divisible * 10 + divisible[i + 1];
			 if (i != 1) result.push_back(0);
			 i += 1;
		 }

		 // ������� ����� �����.
		 whole_pt = part_of_divisible / 16;
		 result.push_back(whole_pt);

		 // ������� �������.
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
		 dividColBy16(divisible_a, divisible_b, remaind); // divisible_a - �������; divisible_b - �������

		 divisible_a.clear(); // - ����������� ������ ��� ������ ��������
		 answer.push_back(formTo16(remaind));// ��������� �����

		f = checkRemains(divisible_b, answer);

		if(f){
			 dividColBy16(divisible_b, divisible_a, remaind); // divisible_b - �������; divisible_a - �������

			 divisible_b.clear();
			 answer.push_back(formTo16(remaind)); 

			 f = checkRemains(divisible_a, answer);
		}
	 }
}