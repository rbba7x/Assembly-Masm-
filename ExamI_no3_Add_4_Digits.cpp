// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 1 No. 3 - Add digits of a 4 digit number
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/11/2019
//
// Purpose: This program accepts a 4 digit number and adds the digits together   
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	short num, sum, h, t, u, th;

	cout << "Enter a 4 digit number: ";
	cin >> num;

	_asm
	{
		mov ax, num; //ax = num
		mov cx, 1000; //cx = 1000
		cdq; //num = dx:ax
		idiv cx; //th = ax, r = dx
		mov th, ax; //th = num/1000
		mov ax, dx; //ax = num%1000
		cdq;
		mov cx, 100; //cx = 100
		cdq; 
		idiv cx; //ax = ax/100
		mov h, ax; //h = ax
		mov ax, dx;
		cdq; 
		mov cx, 10; //cx=10
		idiv cx;//t=ax, u=dx
		mov t, ax;
		mov u, dx;

		//Compute sum th+h+t+u
		add ax, u;
		add ax, h;
		add ax, th;
		mov sum, ax;
	}

	cout << "Sum of digits in " << num << " is " << sum << endl;

	system("pause");
	return 0;
}

/*-------------Output------------------
Enter a 4 digit number: 2468
Sum of digits in 2468 is 20
Press any key to continue . . .
-------------------------------------*/
