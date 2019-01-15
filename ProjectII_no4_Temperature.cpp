// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project 2 No. 4 - Fahrenheit to Celsius
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/09/2019
//
// Purpose: This program accepts a temperature in Fahrenheit and converts it to Celsius
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	short temp_f, temp_c;

	cout << "Enter temperature in Fahrenheit: ";
	cin >> temp_f;

	_asm
	{
		mov ax, temp_f; //ax = temp_f
		mov bx, 32; //bx = 32
		sub  ax, bx; //ax = temp_f-32
		mov cx, 5; //cx = 5
		imul cx; //dx:ax = 5*(temp_f-32)
		mov bx, 9; //bx = 9
		idiv  bx; //ax = 5*(temp_f-32)/9, dx = 5*(temp_f-32)%9
		mov temp_c, ax; //temp_c =  5*(temp_f-32)/9
	}

	cout << temp_f << "F is " << temp_c << "C" << endl;

	system("pause");
	return 0;
}

/*------------Output-------------------------
Enter temperature in Fahrenheit: 95
95F is 35C
Press any key to continue . . .
-------------------------------------------*/
