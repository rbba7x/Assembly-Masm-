// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project 4 No. 3 - Devisable by 3
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/16/2019
//
// Purpose: This program accepts input of a 3 digit integer and displays whether the
//			number is devisable by 3 or not by adding the digits together and dividing
//			by 3
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int num, sum, h, t, u;

void getNum()
{
	cout << "Enter a 3 digit integer number: ";
	cin >> num;
}

void devisable()
{
	cout << "  " << num << " is divisable by 3\n";
}

void notDevisable()
{
	cout << "  " << num << " is not divisable by 3\n";
}

void displaySum()
{
	cout << "  Total of digits is " << sum << endl;
}

int main()
{
	for (int i = 0; i < 2; ++i) {
		_asm
		{
			call getNum;
			mov eax, num; //ax = num
			mov ecx, 100; //cx = 100
			cdq; //num = dx:ax
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
			mov ebx, 3; //ebx=3
			idiv ebx; //eax=number/2 edx=number%2

			cmp edx, 0;
			Jne devis;
		notDevis:
			call displaySum
				call devisable
				jmp done
				devis :
			call displaySum
				call notDevisable

				done :
		}
	}
	system("pause");
	return 0;
}

/*-----------------Output---------------------
Enter a 3 digit integer number: 125
  Total of digits is 8
  125 is not divisable by 3
Enter a 3 digit integer number: 225
  Total of digits is 9
  225 is divisable by 3
Press any key to continue . . .
--------------------------------------------*/