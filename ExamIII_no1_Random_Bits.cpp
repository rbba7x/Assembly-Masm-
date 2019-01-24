// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 3 No. 1 - Random Bits
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/24/2019
//
// Purpose: This program generates 10 random shorts then displays them using a byte
//			as a map
//-------------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
using namespace std;

short r, n, i = 1, k = 0;

void displayBase2()//display n at base 2
{
	cout << "Ax = ";
	unsigned short y = n, t, c = 1 << 15;

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

void generateRand()
{
	r = rand() % 17;
}

void pText()
{
	cout << "Generated random numbers are: ";
}

void pNumbers()
{
	cout << k + 1 << " ";
}

int main()
{
	//Get seed value
	srand(time(0));

	_asm
	{
		loop1 :
		call generateRand
			cmp r, 1
			jne checkTwo
			one :
		add bx, 1
			jmp checkLoop

		checkTwo :
			cmp r, 2;
			jne two
				two :
					add bx, 2;
					jmp checkLoop

		checkThree :
			cmp r, 3;
			jne three
				three :
					add bx, 4;
					jmp checkLoop

		checkFour :
			cmp r, 4;
			jne four
				four :
					add bx, 8;
					jmp checkLoop

		checkFive :
			cmp r, 5;
			jne five
				five :
					add bx, 16;
					jmp checkLoop

		checkSix :
			cmp r, 6;
			jne six
				six :
					add bx, 32;
					jmp checkLoop

		checkSeven :
			cmp r, 7
			jne seven
				seven :
					add bx, 64;
					jmp checkLoop

		checkEight :
			cmp r, 8;
			jne eight
				eight :
					add bx, 128;
					jmp checkLoop

		checkNine :
			cmp r, 9;
			jne nine
				nine :
					add bx, 256;
					jmp checkLoop

		checkTen :
			cmp r, 10;
			jne ten
				ten :
					add bx, 512;
					jmp checkLoop

		checkEleven :
			cmp r, 11;
			jne eleven
				eleven :
					add bx, 1024;
					jmp checkLoop

		checkTwelve :
			cmp r, 12;
			jne twelve
				twelve :
					add bx, 2048;
					jmp checkLoop

		checkThirteen :
			cmp r, 13;
			jne thirteen
				thirteen :
					add bx, 4096;
					jmp checkLoop

		checkFourteen :
			cmp r, 14;
			jne fourteen
				fourteen :
					add bx, 8192;
					jmp checkLoop

		checkFifteen :
			cmp r, 15;
			jne fifteen
				fifteen :
					add bx, 16384;
					jmp checkLoop

		checkSixteen :
			cmp r, 16;
			jne sixteen
				sixteen :
					add bx, 32768;
					jmp checkLoop

		checkLoop :
			inc i
			cmp i, 10
			Jng again
			jmp display
				again :
					jmp loop1

		display :
			mov n, bx;
			call displayBase2
			call pText
			jmp stopped

		stopped :
			cmp k, 16
			Jg done
			mov ax, 1;
			and ax, n
			cmp ax, 1
			Jne loopCheck2
		printNumbers :
			call pNumbers
			jmp loopCheck2

		loopCheck2 :
			shr n, 1
			inc k
			jmp stopped

		done :
	}
	cout << endl;
	system("pause");
}
/*--------------Output----------------
Ax = 0010 0000 0001 0100
Generated random numbers are: 3 5 14
Press any key to continue . . .
------------------------------------*/