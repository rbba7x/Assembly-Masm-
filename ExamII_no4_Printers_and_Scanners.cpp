// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 2 No. 4 - Printers and Scanners
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/17/2019
//
// Purpose: This program displays how many scanners and printers are connected using
//	    a register as a map. Bits 8, 9, and 10 represent printers, bits 14, and 15
//	    represent scanners.
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

short n, t, c, printer, scanner;

void displayNbase2()
{
	cout << "Ax = ";
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

void displayPrinter()
{
	cout << "Printers connected: " << printer << endl;
}

void displayScanner()
{
	cout << "Scanners connected: " << scanner << endl;
}

int main()
{
	_asm
	{
		mov ax, 0x0F8E
		mov n, ax
		mov bx, ax
		mov cx, 1
		call displayNbase2

		shr bx, 1
		and cx, bx
		cmp cx, 0
		Jne scanner1

		scanner1 :
		inc scanner
			jmp tScanner2

			tScanner2 :
		mov cx, 1
			shr bx, 1
			and cx, bx
			cmp bx, 1;

		Je startPrinter

			scanner2 :
		add scanner, 2
			jmp startPrinter

			startPrinter :
		mov cx, 1
			shr bx, 4
			and cx, bx
			cmp cx, 0
			Je tPrinter2

			printer1 :
		inc printer
			jmp tPrinter2

			tPrinter2 :
		mov cx, 1
			shr bx, 1
			and cx, bx
			cmp cx, 0
			Je tPrinter4

			printer2 :
		add printer, 2
			jmp tPrinter4

			tPrinter4 :
		mov cx, 1
			shr bx, 1
			and cx, bx
			cmp cx, 0
			Je done

			printer4 :
		add printer, 4
			jmp done
			done :
		call displayPrinter
			call displayScanner

	}
	system("pause");
	return 0;
}

/*------------Output-------------
Ax = 0000 1111 1000 1110
Printers connected: 6
Scanners connected: 3
Press any key to continue . . .
--------------------------------*/
