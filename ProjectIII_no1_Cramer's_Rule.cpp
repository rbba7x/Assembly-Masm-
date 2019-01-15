// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project 3 No. 1 - Cramer's  Rule (System of Equations)
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/09/2019
//
// Purpose: This program accepts values for a system of equations then solves
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	short a, b, c, d, e, f, x, y, bottom, temp;

	cout << "This program solves the system:\n{aX + bY = c\n{dX + eY = f\n" << endl;
	cout << "      c*e-b*f            a*f-c*d\nX = ------------  Y = ------------ \n      a*e-b*d            a*e-b*d\n" << endl;
	
	cout << "Enter values for a, b, and c: ";
	cin >> a >> b >> c;

	cout << "Enter values for d, e, and f: ";
	cin >> d >> e >> f;

	_asm
	{
		//Solve for x
		//Denominator
		mov ax, a; //ax = a
		imul e; //dx:ax = a*e
		mov cx, ax; //cx = a*e
		mov ax, b; //ax = b
		imul d; //ax = b*d
		sub cx, ax; //cx = a*e - b*d
		mov temp, cx;
		mov bottom, cx; //bottom = a*e - b*d

		//Numerator
		mov ax, c; //ax = c
		imul e; //dx:ax = c*e
		mov cx, ax; //cx = c*e
		mov ax, b; //ax = b
		imul f; //dx:ax = b*f
		sub cx, ax; //cx = c*e-b*f
		mov ax, cx; //ax = c*e-b*f
		cwd;

		idiv bottom; //dx:ax = c*e-b*f/a*e - b*d
		mov x, ax; //x = c*e-b*f/a*e - b*d

		//Solve for Y
		//Numerator
		mov ax, a; //ax = a
		imul f; //dx:ax = a*f
		mov cx, ax; //cx = a*f
		mov ax, c; //ax = c
		imul d; //dx:ax = c*d
		sub cx, ax; //cx = a*f-c*d
		mov ax, cx; //ax = a*f-c*d
		cwd;

		idiv bottom; //dx:ax = c*e-b*f/a*e - b*d
		mov y, ax; //x = c*e-b*f/a*e - b*d
	}

	cout << "X = " << x << "\nY = " << y << endl;

	system("pause");
	return 0;
}

/*---------------Output---------------------------
This program solves the system:
{aX + bY = c
{dX + eY = f

	  c*e-b*f            a*f-c*d
X = ------------  Y = ------------
	  a*e-b*d            a*e-b*d

Enter values for a, b, and c: 3 1 1
Enter values for d, e, and f: 1 -2 5
X = 1
Y = -2
Press any key to continue . . .
-------------------------------------------------*/
