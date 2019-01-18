// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Project 6 No. 2 - Odd or Even
//			Course: CMPS 371 - Assembly Language (MASM)
//			Date: 1/16/2019
//
// Purpose: This program accepts integer numbers and determines whether they are even
//	    or odd
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int tries, i = 0, num, c = 1, num1;

void getNum()
{
	cout << "Enter a number: ";
	cin >> num;
	num1 = num;
}

void printOdd()
{
	cout << num1 << " is ODD\n";
}

void printEven()
{
	cout << num1 << " is EVEN\n";
}
int main()
{
	cout << "How many numbers would you like to try: ";
	cin >> tries;

	_asm
	{
		mov ecx, tries;
		mov edx, c; //dx=1

		forLoop:
		
		cmp i, 3;
		Jg done

			call getNum
			and num, 1;

			cmp num,1
			Je od
				
			eve:
			call printEven
			Jmp finish
			
			od:
			call printOdd
			Jmp finish

			finish:
			inc i
			Jmp forLoop

			done:
	}
	system("pause");
	return 0;
}

/*----------------Output--------------------
How many numbers would you like to try: 4
Enter a number: 124
124 is EVEN
Enter a number: 37
37 is ODD
Enter a number: 3456
3456 is EVEN
Enter a number: 555
555 is ODD
Press any key to continue . . .
---------------------------------------------*/
