// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project 2 No. 6 - Celsius to Fahrenheit
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/09/2019
//
// Purpose: This program accepts a temperature in Celsius and converts it to Fahrenheit
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int temp_c, temp_f;

	cout << "Enter temperature in Celsius: ";
	cin >> temp_c;

	_asm
	{
		mov eax, temp_c; //eax = temp_c
		mov ebx, 9; //ebx = 9
		imul ebx; //edx:eax = 9*temp_c
		mov ebx, 5; //ebx = 5
		idiv ebx; //eax = 9*temp_c/5
		add eax, 32; //eax = 9*temp_c/5 + 32
		mov temp_f, eax; //temp_f = = 9*temp_c/5 + 32
	}

	cout << temp_c << "C is " << temp_f << "F" << endl;

	system("pause");
	return 0;
}

/*-------------Output----------------------
Enter temperature in Celsius: 35
35C is 95F
Press any key to continue . . .
-----------------------------------------*/
