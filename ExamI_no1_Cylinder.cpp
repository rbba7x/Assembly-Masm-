// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 1 No. 1 - Cylinder
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/11/2019
//
// Purpose: This program accepts the radius and height of a cylinder then calculates
//			the volume and surface area
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int r, h, volume, sArea;

	cout << "Enter the values for r and h: ";
	cin >> r >> h;

	_asm
	{
		//Calculate volume
		mov	eax, r; //eax = r
		mov ebx, r; //ebx = r
		imul ebx; //edx:eax = r^2
		mov ebx, 3; //ebx = 3
		imul ebx; //edx:eax = 3*r^2
		imul h; //edx:eax = 3*r^2*h
		mov volume, eax; //volume = 3*r^2*h

		//Calculate surface area
		mov	eax, r; //eax = r
		mov ebx, r; //ebx = r
		imul ebx; //edx:eax = r^2
		mov ebx, 3; //ebx = 3
		imul ebx; //edx:eax = 3*r^2
		mov ebx, 2; //ebx = 2
		imul ebx; //edx:eax = 2*3*r^2
		mov sArea, eax; //sArea = 2*3*r^2
		mov	eax, r; //eax = r
		mov ebx, 2; //ebx = 2
		imul bx; //edx:eax = 2*r
		mov ebx, 3; //ebx = 3
		imul ebx; //edx:eax = 3*2*r^2
		imul h; //edx:eax =3*2*r^2^h
		add sArea, eax; //sArea = 2*3*r^2 + 3*2*r^2^h

	}

	cout << "Volume = " << volume << endl;
	cout << "Surface Area = " << sArea << endl;

	system("pause");
	return 0;
}

/*--------------Output---------------
Enter the values for r and h: 6 10
Volume = 1080
Surface Area = 576
Press any key to continue . . .
------------------------------------*/
