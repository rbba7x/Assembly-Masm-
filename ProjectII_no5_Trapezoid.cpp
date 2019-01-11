// ------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project 2 No. 5 - Trapezoid
//								Course: CMPS 371 - Assembly Language (MASM)
//								Date: 1/09/2019
//
// Purpose: This program accepts dimensions of a trapezoid then displays the perimeter 
//          and the area of the trapezoid
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, h, perimeter, area;

	cout << "        a" << endl;
	cout << "    ___________" << endl;
	cout << "   / |         \\  " << endl;
	cout << "b /  | h        \\ c " << endl;
	cout << " /   |           \\ " << endl;
	cout << "/_________________\\  " << endl;
	cout << "        d          " << endl;

	cout << "Enter values for a, b, c, d, and h: ";
	cin >> a >> b >> c >> d >> h;

	_asm
	{
		//Find perimeter
		mov eax, a; //eax = a
		add eax, b; //eax = a + b
		add eax, c; //eax = a + b + c
		add eax, d; //eax = a+ b + c + d
		mov perimeter, eax; //perimeter =  = a+ b + c + d

		//Find area
		mov eax, d; //eax = d
		imul h; //edx:eax = dh
		mov area, eax; //area = dh
	}

	cout << "Area = dh = " << area << endl;
	cout << "Perimeter = a+b+c+d = " << perimeter << endl;
	system("pause");
	return 0;
}

/*------------Output-------------------------------
		a
	___________
   / |         \
b /  | h        \ c
 /   |           \
/_________________\
		d
Enter values for a, b, c, d, and h: 7 5 6 10 4
Area = dh = 40
Perimeter = a+b+c+d = 28
Press any key to continue . . .
-------------------------------------------------*/