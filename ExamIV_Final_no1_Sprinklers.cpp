// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Final Exam No. 1 - Sprinklers
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/30/2019
//
// Purpose: This program loads 16 bits into a register then displays the integer
//			representation for bits 6,7,8 then 10,11,12
//-------------------------------------------------------------------------------------

#include <iostream>

short n, fyard, byard;

void displayNbase2()
{
	std::cout << "Ax = ";
	short x = 1 << 15, t; 

	for (int i = 1; i <= 16; ++i)
	{
		t = n & x;
		if (t == 0)
			std::cout << 0;
		else
			std::cout << 1;

		if (i % 4 == 0)
			std::cout << " ";
		n = n << 1;
	}
	std::cout << std::endl;
}


void displayfyard()
{
	std::cout << "fyards connected: " << fyard << std::endl;
}

void displaybyard()
{
	std::cout << "byards connected: " << byard << std::endl;
}

int main()
{
	_asm
	{
		mov ax, 0xCFDC
		mov n, ax
		mov bx, ax
		mov cx, 1
		call displayNbase2

		//Find front yard (bits 6,7,8)
		mov cx, 1
			shr bx, 5
			and cx, bx
			cmp cx, 0
			Je tfyard2

			fyard1 :
		inc fyard
			jmp tfyard2

			tfyard2 :
		mov cx, 1
			shr bx, 1
			and cx, bx
			cmp cx, 0
			Je tfyard4

			fyard2 :
		add fyard, 2
			jmp tfyard4

			tfyard4 :
		mov cx, 1
			shr bx, 1
			and cx, bx
			cmp cx, 0
			Je fyardDone

			fyard4 :
		add fyard, 4
			jmp fyardDone
			fyardDone :
		call displayfyard
		
		//Find back yard (bits 10,11,12)
			mov cx, 1
			shr bx, 2
			and cx, bx
			cmp cx, 0
			Je tbyard2

		byard1 :
			inc byard
			jmp tbyard2

		tbyard2 :
			mov cx, 1
			shr bx, 1
			and cx, bx
			cmp cx, 0
			Je tbyard4

		byard2 :
			add byard, 2
			jmp tbyard4

		tbyard4 :
			mov cx, 1
			shr bx, 1
			and cx, bx
			cmp cx, 0
			Je done

		byard4 :
			add byard, 4
			jmp done

		done :
			call displaybyard
	}
	system("pause");
	return 0;
}
/*-------------Output---------------
Ax = 1100 1111 1101 1100
fyards connected: 6
byards connected: 7
Press any key to continue . . .
-----------------------------------*/