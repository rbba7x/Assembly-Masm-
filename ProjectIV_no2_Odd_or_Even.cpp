// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Project 4 No. 2 - Odd or Even
//			Course: CMPS 371 – Assembly Language (MASM)
//			Date: 1/16/2019
//
// Purpose: This program accepts input of an integer and displays whether the number
//	    is even or odd
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int num;

void getNum()
{
	cout << "Enter a number: ";
	cin >> num;
}

void displayOdd()
{
	cout << "     " << num << " is odd\n";
}

void displayEven()
{
	cout << "     " << num << " is even\n";
}

int main()
{
	for (int i = 0; i < 3; ++i) {
		__asm
		{
			call getNum;
			mov eax, num; //eax=num
			cdq;
			mov ebx, 2; //ebx=2
			idiv ebx; //eax=number/2 edx=number%2

			cmp edx, 1;
			Je od;
		eve:
			call displayEven
				jmp done
				od :
			call displayOdd

				done :
		}
	}
	system("pause");
	return 0;
}

/*--------------Output-----------------------
Enter a number: 123
	 123 is odd
Enter a number: 12
	 12 is even
Enter a number: 335
	 335 is odd
Press any key to continue . . .
------------------------------------------*/
