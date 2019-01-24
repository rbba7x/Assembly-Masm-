// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 3 No. 3 - 3D Array
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/24/2019
//
// Purpose: This program initializes a 3d array and displays the total along with
//			specified subsets
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	
	short  total, totalPink, totalLS, i, j, a[3][4][2] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 };
	//  Array used in assembly:
	//  Index: 000	001	010	011	020	021	030	031	100	101	110	111	120	121	130	131	200	201	210	211	220	221	230	231
	// Content: 1	 2	 3	 4	 5	 6	 7	 8	 9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24
	//	Bit:    2	 4	 6	 8	10	12	14	16	18	20	22	24	26	28	30	32	34	36	38	40	42	44	46	48

	_asm
	{
		//Find total of all shirts
		mov total, 0;
		mov i, 1;
		lea esi, a;
		mov eax, [esi]
		add total, ax
		add esi, 2

		loopTotal:
			cmp i, 23
			Jg findPink
			mov ax, [esi]
			add total, ax
			inc i
			add esi, 2
			Jmp loopTotal

		//Find total of pink shirts (row 3)
		findPink:
			mov i, 1;
			mov totalPink, 0
			lea esi, a;
			add esi, 32
			mov eax, [esi]
			add totalPink, ax
			add esi, 2
				loopPink:
				cmp i, 7
				Jg findLS
				mov ax, [esi]
				add totalPink, ax
				inc i
				add esi, 2
				Jmp loopPink

		//Find total of long sleeve shirts (slice 2)
		findLS :
			mov i, 1;
			mov totalLS, 0
			lea esi, a;
			add esi, 2
			mov eax, [esi]
			add totalLS, ax
			add esi, 4
				loopLS:
				cmp i, 11
				Jg done
				mov ax, [esi]
				add totalLS, ax
				inc i
				add esi, 4
				Jmp loopLS
		done :
	}

	cout << "Total no. of all shirts: " << total << endl;
	cout << "Total no. of pink shirts: " << totalPink << endl;
	cout << "Total no. of long sleeve shirts: " << totalLS << endl;
	
	system("pause");
}
/*---------------Output---------------
Total no. of all shirts: 300
Total no. of pink shirts: 164
Total no. of long sleeve shirts: 156
Press any key to continue . . .
-------------------------------------*/