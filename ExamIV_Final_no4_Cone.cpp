// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Final Exam No. 4 - Cone
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/30/2019
//
// Purpose: This program accepts user input for radius and height of a cone. The cone's
//			surface area and volume are calculated and displayed.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float r, h, pi = 3.14, three = 3, sArea, volume;

	cout << "Enter the values of radius and height: ";
	cin >> r >> h;

	_asm
	{
		//Surface area = pi*r*sqrt((r*r)+(h*h)) + pi*(r*r)
		//Postfix = pi r * sqrt(r r * h h * +) * pi r r * * +
		fld pi; //st[0] = pi
		fld r; //st[0] = r, st[1] = pi
		fmul; //st[0] = pi*r
		fld r;
		fld r;
		fmul;  //st[0] = r^2, st[1] = pi*r
		fld h;
		fld h;
		fmul; //st[0] = h^2 st[1] = r^2 st[2] = pi*r
		fadd; //st[0] = (r^2 + h^2), st[1] = pi*r
		fsqrt; //st[0] = sqrt(r^2 + h^2), st[1] = pi*r
		fmul; //st[0] = ((pi*r) * sqrt(r^2 + h^2))
		fld pi; //st[0] = pi, st[1] = ((pi*r) * sqrt(r^2 + h^2))
		fld r;
		fld r;
		fmul; //st[0] = r^2, st[1] = pi, st[2] = ((pi*r) * sqrt(r^2 + h^2))
		fmul; //st[0] = r^2 * pi, st[1] = ((pi*r) * sqrt(r^2 + h^2))
		fadd; //st[0] = ((pi*r) * sqrt(r^2 + h^2)) + r^2 * pi
		fstp sArea; 

		//Volume = h*pi*r*r/3
		//Postfix = h pi * r r * * 3 /
		fld h; //st[0] = h
		fld pi; //st[0] = pi, st[1] = h
		fmul; //st[0] = h*pi
		fld r;
		fld r;
		fmul; //st[0] = r^2, st[1] = h*pi
		fmul; //st[0] = (h*pi * r^2)
		fld three; //st[0] = 3, st[1] = (h*pi * r^2)
		fdiv; //st[0] = (h*pi * r^2)/3
		fstp volume;
	}

	cout << fixed << showpoint << setprecision(2);
	cout << "Surface area = " << sArea;
	cout << "\nVolume = " << volume << endl;

	system("pause");
}

/*-------------------Output-----------------------
Enter the values of radius and height: 5.32 15.4
Surface area = 361.04
Volume = 456.20
Press any key to continue . . .
-------------------------------------------------*/