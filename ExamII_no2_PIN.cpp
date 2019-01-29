// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 2 No. 2 - PIN Number
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/17/2019
//
// Purpose: This program accepts a 3 digit PIN and tests if the total if the digits is
//	    devisable by 2. Not devisable by 2 is not accepted as a valid PIN
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int pin, sum, h, t, u;
char ans;

void getpin()
{
	cout << "Enter a 3 digit int PIN: ";
	cin >> pin;
}

void devisable()
{
	cout << "  " << pin << " is a valid PIN number\n";
}

void notDevisable()
{
	cout << "  " << pin << " is not not a valid PIN number\n";
}

void YesNo()
{
	cout << "CONTINUE(y/n)? ";
	cin >> ans;
}

int main()
{
	_asm
	{
	doLoop:
		call getpin;
		mov eax, pin; //ax = pin
		mov ecx, 100; //cx = 100
		cdq; //pin = dx:ax
		idiv ecx; //h = ax, r  dx
		mov h, eax; //h = ax
		mov eax, edx;
		cdq; //dx=ax=r
		mov ecx, 10; //cx=10
		idiv ecx;//t=ax, u=dx
		mov t, eax;
		mov u, edx;

		//Compute sum h+t+u
		add eax, u;
		add eax, h;
		mov sum, eax;

		mov eax, sum; //eax=sum
		cdq;
		mov ebx, 2; //ebx=2
		idiv ebx; //eax=pin/2 edx=sum%2

		cmp edx, 0;
		Jne devis;
	notDevis:
		call devisable
			jmp yesno
			devis :

		call notDevisable

			yesno :
		call YesNo
			cmp ans, 'y'
			Jne checkY
			Jmp doLoop

			checkY :
		cmp ans, 'Y'
			Jne done
			Jmp doLoop
			done :
	}

	system("pause");
	return 0;
}
/*---------------Output---------------
Enter a 3 digit int PIN: 214
214 is not not a valid PIN number
CONTINUE(y/n)? y
Enter a 3 digit int PIN: 833
833 is a valid PIN number
CONTINUE(y/n)? n
Press any key to continue . . .
-------------------------------------*/
