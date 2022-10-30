#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

const double PI = 3.141592653589793;

int32_t result;

int32_t val(const char* formula) {
	char Storage[70] = { 0 };
	char Excit[70] = { 0 };

	int32_t StringCounter = 0;
	int32_t m = 1;
	int32_t k = 1;

	for (StringCounter = 0; StringCounter < strlen(formula); StringCounter++) {

		switch (formula[StringCounter]) {
		case ' ':
			break;

		case '*':
			if (Storage[m - 1] == '*' || Storage[m - 1] == '/') {
				m--;
				Excit[k] = Storage[m];
				Storage[m] = '*';
				m++;
				k++;
				Excit[k] = ' ';
				k++;
			}
			else {
				Storage[m] = '*';
				m++;
			}
			break;
		case '/':
			if (Storage[m - 1] == '*' || Storage[m - 1] == '/') {
				m--;
				Excit[k] = Storage[m];
				Storage[m] = '/';
				m++;
				k++;
				Excit[k] = ' ';
				k++;
			}
			else {
				Storage[m] = '/';
				m++;
			}
			break;
		case '+':
			if (Storage[m - 1] == '*' || Storage[m - 1] == '/') {
				m--;
				Excit[k] = Storage[m];
				Storage[m] = '+';
				m++;
				k++;
				Excit[k] = ' ';
				k++;
			}
			else {
				Storage[m] = '+';
				m++;
			}
			break;
		case '-':
			if (Storage[m - 1] == '*' || Storage[m - 1] == '/') {
				m--;
				Excit[k] = Storage[m];
				Storage[m] = '-';
				m++;
				k++;
				Excit[k] = ' ';
				k++;
			}
			else if (formula[StringCounter - 1] == '(' && (isdigit(formula[StringCounter + 1]) ||
				formula[StringCounter + 1] == '(')) {
				Storage[m] = 'm';
				m++;
			}
			else {
				Storage[m] = '-';
				m++;
			}
			break;
		case '(':
			Storage[m] = formula[StringCounter];
			m++;
			break;
		case ')':
			m--;
			while (Storage[m] != '(') {
				Excit[k] = Storage[m];
				Storage[m] = 0;
				k++;
				m--;
				Excit[k] = ' ';
				k++;
			}
			break;
		default:
			Excit[k] = formula[StringCounter];
			k++;
			if (isdigit(formula[StringCounter + 1])) {
				break;
			}
			else {
				Excit[k] = ' ';
				k++;
				break;
			}
		}
	}

	int32_t scounter = m - 1;

	while (Storage[scounter] != 0) {
		Excit[k] = Storage[scounter];
		k++;
		scounter--;
	}

	int32_t Calculation[25] = { 0 };

	int32_t RecordCount = 2;

	for (int32_t CalcCount = 1; CalcCount < k; CalcCount++) {
		switch (Excit[CalcCount]) {
		case '0':
			Calculation[RecordCount] *= 10;
			break;
		case '1':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 1;
			break;
		case '2':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 2;
			break;
		case '3':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 3;
			break;
		case '4':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 4;
			break;
		case '5':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 5;
			break;
		case '6':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 6;
			break;
		case '7':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 7;
			break;
		case '8':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 8;
			break;
		case '9':
			Calculation[RecordCount] *= 10;
			Calculation[RecordCount] += 9;
			break;
		case '+':
			Calculation[RecordCount - 2] += Calculation[RecordCount - 1];
			Calculation[RecordCount - 1] = 0;
			RecordCount--;
			RecordCount--;
			break;
		case '-':
			Calculation[RecordCount - 2] -= Calculation[RecordCount - 1];
			Calculation[RecordCount - 1] = 0;
			RecordCount--;
			RecordCount--;
			break;
		case '*':
			Calculation[RecordCount - 2] *= Calculation[RecordCount - 1];
			Calculation[RecordCount - 1] = 0;
			RecordCount--;
			RecordCount--;
			break;
		case '/':
			Calculation[RecordCount - 2] /= Calculation[RecordCount - 1];
			Calculation[RecordCount - 1] = 0;
			RecordCount--;
			RecordCount--;
			break;
		case ' ':
			RecordCount++;
			break;
		case 'm':
			Calculation[RecordCount - 1] *= (-1);
			RecordCount--;
			break;
		}
	}
	return Calculation[2];
}

int main(void) {

	HMODULE hlib = LoadLibrary(TEXT("Dll_fun.dll"));
	if (hlib == NULL) {
		std::cout << "hlib error\n";
	}
	else {
		std::cout << "hlib open!\n";
	}
	_getch();

	double x = PI * 30 / 180;

	typedef double(*func_sin) (double x);

	double res_dll_sin = 0;
	if (hlib == NULL) {
		std::cout << "func error\n";
	}
	else {
		func_sin func = (func_sin)GetProcAddress(hlib, "func_sin");
		res_dll_sin = func(x);
	}

	result = val("(((-2)*(200)))/(-2)") * res_dll_sin;
	std::cout << "result = " << result;


	FreeLibrary(hlib);
	return 0;
}