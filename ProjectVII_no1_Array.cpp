// ------------------------------------------------------------------------------------
//							Name: Ryan Beebe
//							Project 7 No. 1 - 1d Array
//							Course: CMPS 371 - Assembly Language (MASM)
//							Date: 1/23/2019
//
// Purpose: This program declares and initializes an array. The values in the array
//          are added, and the total is displayed along with the max and min values
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int max, min, total, i, a[7] = { 33,66,11,17,20,25,10 };

	_asm
	{
		mov total, 0;
		mov i, 1;
		lea esi, a;
		mov eax, [esi]
			mov max, eax
			mov min, eax
			add total, eax
			add esi, 4

	loopTotal:
		cmp i, 6
		Jg done
		mov eax,[esi]
			add total, eax

			cmp eax, max
			Jng checkMin

			newMax:
			mov max, eax
			jmp outLoop

			checkMin:
		cmp eax, min
			Jnl outLoop

			newMin:
			mov min, eax 
				Jmp outLoop

			outLoop:
			inc i
			add esi, 4
			Jmp loopTotal
			done:
	}

	cout << "Total: " << total << endl;
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	system("pause");
	return 0;
}

/*----------Output--------------
Total: 182
Max: 66
Min: 10
Press any key to continue . . .
-------------------------------*/