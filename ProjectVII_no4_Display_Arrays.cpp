// ------------------------------------------------------------------------------------
//							Name: Ryan Beebe
//							Project 7 No. 4 - Display Arrays
//							Course: CMPS 371 - Assembly Language (MASM)
//							Date: 1/23/2019
//
// Purpose: This program generates 7 random integers and stores them into an array. 
//          The array is displayed, sorted, then displayed again
//-------------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int s[7], r, x, i = 0;
bool sorted = false;

void displayUnsorted()
{
	cout << "Unsorted: ";
}

void displaySorted()
{
	cout << "\nSorted  : ";
}

void displayX()
{
	cout << x << " ";
}

void sortArray()
{
	sort(s, s + 7);
	sorted = true;
}

int main()
{
	srand(time(0));

	for (; i < 7; i++)
	{
		r = rand();
		s[i] = r;
	}

	_asm
	{
		call displayUnsorted
		lea esi, s
		mov i, 0

		forLoop:
		cmp i, 7
			Je callSort

			mov eax, [esi]
			mov x, eax
			call displayX
			inc i
			add esi, 4
			Jmp forLoop


			callSort :
		call displaySorted
			call sortArray
			lea esi, s
			mov i, 0

			sortedLoop :
			cmp i, 7
			Je done
			mov eax, [esi]
			mov x, eax
			call displayX
			inc i
			add esi, 4
			Jmp sortedLoop

			done :
	}
	cout << endl;
	system("pause");
}

/*-----------------Output-------------------------
Unsorted: 19359 2536 22478 2760 14083 20809 6727
Sorted  : 2536 2760 6727 14083 19359 20809 22478
Press any key to continue . . .
-------------------------------------------------*/