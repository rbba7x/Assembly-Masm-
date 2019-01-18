// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Project 6 No. 3 - Sprinklers
//			Course: CMPS 371 - Assembly Language (MASM)
//			Date: 1/16/2019
//
// Purpose: This program instantiates the Ax register and used it as a map of sprinklers.
//	    The active sprinklers are counted, and the defective sprinklers are identified
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

short n, k, w, v, on;

void displayNbase2()
{
	unsigned int y = n, t, c;
	c = 1 << 15; //c = 1000 0000 0000 0000 

	for (int i = 1; i <= 16; ++i)
	{
		t = y & c;
		if (t == 0)
			cout << 0;
		else
			cout << 1;

		if (i % 4 == 0)
			cout << " ";
		y = y << 1;
	}
	cout << endl;
}

void pOn()
{
	cout << on << " sprinklers are on\n";
}

void printDefective()
{
	cout << "Defective sprinklers are: ";
}

void pStop()
{
	cout << k + 1 << " ";
}


int main()
{
	cout << "Ax = ";
	_asm
	{
		//Display the content of eax at base 2
		mov n, 0x6A2F;
		call displayNbase2

			//Find how many are on
			mov bx, n;
			mov v, bx;
	turnedOn:
		cmp w, 15
			Jg printOn
		mov ax, 1
			and ax, v;

		cmp ax, 1
			Je increment

			doNothing:
		inc w;
		shr v,1;
		jmp turnedOn

			increment:
		inc on;
		inc w;
		shr v,1;
		jmp turnedOn

			printOn:
		call pOn
			jmp defective

			//Find defective
			defective:
			call printDefective
			stopped :
		cmp k, 15
			Jg done

			mov ax, 1;
		and ax, n

			cmp ax, 0
			Jne loopCheck2
			printStop :
		call pStop
			jmp loopCheck2

			loopCheck2 :
		shr n, 1
			inc k
			jmp stopped

			done:
	}
	cout << endl;
	system("pause");
	return 0;
}

/*------------------Output------------------
Ax = 0110 1010 0010 1111
9 sprinklers are on
Defective sprinklers are: 5 7 8 9 11 13 16
Press any key to continue . . .
-------------------------------------------*/
