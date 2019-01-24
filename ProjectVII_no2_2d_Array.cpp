// ------------------------------------------------------------------------------------
//							Name: Ryan Beebe
//							Project 7 No. 2 - 2d Array
//							Course: CMPS 371 - Assembly Language (MASM)
//							Date: 1/23/2019
//
// Purpose: This program creates a 2d array to represent an inventory table of shirts.
//          The shirts are totaled and subsets are displayed.
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int total, totalGreen, totalXL, i, a[4][4] = { 10,20,30,40,20,10,40,30,5,15,20,25,30,25,20,15 };

	_asm
	{
		mov total, 0;
		mov totalGreen, 0;
		mov totalXL, 0;
		mov i, 1;
		lea esi, a;
		mov eax, [esi]
			add total, eax
			add esi, 4

		loopTotal:
			cmp i, 15
			Jg findGreen
			mov eax, [esi]
			add total, eax
			inc i
			add esi, 4
			Jmp loopTotal

			findGreen:
				mov i, 0;
				lea esi, a;
				add esi, 16;
				mov eax, [esi]
				add totalGreen, eax
				add esi,4
			loopGreen:
				cmp i, 2
				Jg findXL
				mov eax, [esi]
				add totalGreen, eax
				inc i
				add esi, 4
				Jmp loopGreen

			findXL:
				mov i, 0;
				lea esi, a;
				add esi, 12;
				mov eax, [esi]
					add totalXL, eax
					add esi, 16
				loopXL:
					cmp i, 2
					Jg done
					mov eax, [esi]
					add totalXL, eax
					inc i
					add esi, 16
					Jmp loopXL

		done :
	}

	cout << "Total no. of shirts: " << total << endl;
	cout << "Total no. green: " << totalGreen << endl;
	cout << "Total no. XL: " << totalXL << endl;
	system("pause");
}

/*------------Output------------
Total no. of shirts: 355
Total no. green: 100
Total no. XL: 110
Press any key to continue . . .
--------------------------------*/