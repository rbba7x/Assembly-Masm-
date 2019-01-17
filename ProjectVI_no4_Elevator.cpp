// ------------------------------------------------------------------------------------
//							Name: Ryan Beebe
//							Project 6 No. 4 - Elevator
//							Course: CMPS 371 - Assembly Language (MASM)
//							Date: 1/16/2019
//
// Purpose: This program generates 10 random integers and uses them as floors on an
//			elevator which is displayed as a 16 bit binary number. The floors selected
//			are displayed as integers in base 10.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
using namespace std;

short r, n, i = 1, newV, old[9], k = 0, temp1;

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

void generateRand()
{
	newV = 0;
	r = rand() % 17;
	old[i - 1] = r;
}

//Verify that if the button has been pushed, it cannot be pushed again
void checkPrevious()
{
	for (int j = 0; j < 10; ++j) 
	{
		if (old[j] == r)
			newV = 1;
	}
}

void printEleStop()
{
	cout << "Elevator will stop at the following floors: ";
}

void pStop()
{
	cout << k+1 << " ";
}

int main()
{
	//Get seed value
	srand(time(0));

	_asm
	{
			call checkPrevious
			cmp newV, 1
			Jne loop1
			jmp checkLoop
			
	loop1:
		call generateRand
			cmp r, 1
		jne checkTwo
		one:
		add bx, 1
			jmp checkLoop

		checkTwo :
			cmp r, 2;
		jne two
			two:
		add bx, 2;
		jmp checkLoop

	checkThree:
		cmp r, 3;
		jne three
			three :
		add bx, 4;
		jmp checkLoop

	checkFour:
		cmp r, 4;
		jne four
			four :
		add bx, 8;
		jmp checkLoop

	checkFive:
		cmp r, 5;
		jne five
			five :
		add bx, 16;
		jmp checkLoop

	checkSix:
		cmp r, 6;
		jne six
			six :
		add bx, 32;
		jmp checkLoop

	checkSeven:
		cmp r, 7
		jne seven
			seven :
		add bx, 64;
		jmp checkLoop

	checkEight:
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

	checkLoop:
			inc i
			cmp i,10
				Jng again
				jmp display
				again: 
			jmp loop1
			
	display:
	mov n, bx;
	call displayNbase2
		call printEleStop
		jmp stopped
		
		stopped:
	cmp k, 16
		Jg done
		
		mov ax, 1;
	and ax, n
			
			cmp ax,1
			Jne loopCheck2
			printStop:
		call pStop
			jmp loopCheck2

			loopCheck2:
		shr n, 1
			inc k
		jmp stopped

			done:
		}
		cout << endl;
	system ("pause");
	return 0;
}
/*-----------------------Output-----------------------
Ax = 0110 0000 0001 0010
Elevator will stop at the following floors: 2 5 14 15
Press any key to continue . . .
------------------------------------------------------*/