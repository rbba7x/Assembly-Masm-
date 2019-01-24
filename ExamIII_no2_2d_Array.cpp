// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 3 No. 2 - Diagonals
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/24/2019
//
// Purpose: This program initializes a 2d array then totals each diagonal
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int totalLD, totalRD, i = 1, a[4][4] = { 3,9,8,1,7,2,11,9,13,4,11,6,8,7,6,4 };
	//LD = Left down diagonal, RD = Right down diagonal

	_asm
	{
		mov totalLD, 0;
		mov totalRD, 0;
		lea esi, a;

		mov eax, [esi]
		add totalLD, eax
		add esi, 20

		loopTotalLD:
			cmp i, 3
			Jg findTotalRD
			mov eax, [esi]
			add totalLD, eax
			add esi, 20
			inc i
			Jmp loopTotalLD
			
				findTotalRD:
			mov i, 0
			lea esi, a;
			add esi, 12
			mov eax, [esi]
			add totalRD, eax
			add esi, 12
				loopTotalRD:
					cmp i, 2
					Jg done
					mov eax, [esi]
					add totalRD, eax
					add esi, 12
					inc i
					Jmp loopTotalRD

			done:
	}

	cout << "The diagonal 1 total is: " << totalRD << endl;
	cout << "The diagonal 2 total is: " << totalLD << endl;
	system("pause");
}
/*----------Output-------------
The diagonal 1 total is: 24
The diagonal 2 total is: 20
Press any key to continue . . .
-------------------------------*/