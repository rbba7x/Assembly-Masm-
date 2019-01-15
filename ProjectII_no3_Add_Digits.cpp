// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project 2 No. 3 - Add digits of a number
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/09/2019
//
// Purpose: This program accepts a 3 digit number and adds the digits together   
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	short num, sum, h, t, u;

	cout << "Enter a 3 digit number: ";
	cin >> num;

	_asm
	{
		mov ax, num; //ax = num
		mov cx, 100; //cx = 100
		cdq; //num = dx:ax
		idiv cx; //h = ax, r  dx
		mov h, ax; //h = ax
		mov ax, dx;
		cdq; //dx=ax=r
		mov cx, 10; //cx=10
		idiv cx;//t=ax, u=dx
		mov t, ax;
		mov u, dx;

		//Compute sum h+t+u
		add ax, u;
		add ax, h;
		mov sum, ax;
	}

	cout << "Sum of digits in " << num << " is " << sum << endl;

	system("pause");
	return 0;
}

/*-----------Output----------------------------------
Enter a 3 digit number: 362
Sum of digits in 362 is 11
Press any key to continue . . .
---------------------------------------------------*/
