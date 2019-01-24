// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Project 7 No. 3 - 3d Array
//			Course: CMPS 371 - Assembly Language (MASM)
//			Date: 1/23/2019
//
// Purpose: This program initializes a 3d array then displays the total along with 
//          specified subsets.
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int medium, total, i, j, sSleeve, blue, a[3][3][2] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };

	_asm
	{
		mov total, 0;
		mov medium, 0;
		mov j, 0;
		mov sSleeve, 0;
		mov blue, 0;
		mov i, 1;

		lea esi, a;
		mov eax, [esi]
			add total, eax
			add esi, 4

			loopTotal:
		cmp i, 17
			Jg findMed
			mov eax, [esi]
			add total, eax
			inc i
			add esi, 4
			Jmp loopTotal
	

			findMed :
		mov i, 0;
		lea esi, a;
		add esi, 8;
		
	loopMed1:
		cmp i, 1
			Jg med2
		mov eax, [esi]
			add medium, eax
			inc i
			add esi, 4
			Jmp loopMed1

			med2:
		cmp j, 1
		Jg findSS
			inc j
		mov i,0
		add esi, 16
		jmp loopMed1
			
			findSS:
		mov i, 0;
		lea esi, a;
	loopSS:
		cmp i, 8
			Jg findBlue
			mov eax, [esi]
			add sSleeve, eax
			inc i
			add esi, 8
			Jmp loopSS

			findBlue:
		mov i, 0;
		lea esi, a;
		add esi, 24
			loopBlue:
		cmp i, 5
			Jg done
			mov eax, [esi]
			add blue, eax
			inc i
			add esi, 4
			Jmp loopBlue

			done :
	}

	cout << "Total no. of shirts: " << total << endl;
	cout << "Total no. of medium: " << medium << endl;
	cout << "Total no. short sleeves: " << sSleeve << endl;
	cout << "Total no. of blue: " << blue << endl;

	system("pause");
}

/*------------Output------------
Total no. of shirts: 171
Total no. of medium: 57
Total no. short sleeves: 81
Total no. of blue: 57
Press any key to continue . . .
--------------------------------*/
