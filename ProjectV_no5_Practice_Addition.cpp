// --------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Project 5 No. 5 - Practicing Addition
//			Course: CMPS 371 – Assembly Language (MASM)
//			Date: 1/16/2019
//
// Purpose: This program lets the user practice addition by generating 2 random integers
//	    and telling the user if their response is correct or not
//---------------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int n, r, x, y, ans, correct = 0, wrong = 0;
char resp = 'y';

void askContinue()
{
	cout << "CONTINUE(y/n)? ";
	cin >> resp;
}

void generateRand()
{
	r = rand() % 100;
}

void showProblem()
{
	cout << x << "+" << y << "= ? ";
	cin >> ans;
}

void showWrong()
{
	cout << "Wrong\n";
}

void showCorrect()
{
	cout << "Correct\n";
}

void showCorrectWrong()
{
	cout << "Number of correct answers = " << correct << endl;
	cout << "Number of wrong answers = " << wrong << endl;
}

int main()
{
	srand(time(0));
	_asm
	{
	doLoop:
					
	addition:
		call generateRand
			mov ebx, r; //r = rand()%100
		mov x, ebx;
		call generateRand
			mov ebx, r
			mov y, ebx //y = rand()%100
			call showProblem

			//Compute ebx = x+y
			mov ebx, x
			add ebx, y //ebx = x+y
			cmp ebx, ans
			Je correctAns
			wrongAns:
		call showWrong
			inc wrong
			jmp cont
			
			correctAns:
		call showCorrect
			inc correct
			
			cont:
			call askContinue
			cmp resp, 'y'
			jne checkY
			jmp addition

			checkY :
		cmp resp, 'Y'
			Jne done
			jmp addition

			done:
		call showCorrectWrong
	}

	system("pause");
	return 0;
}

/*--------------Output---------------
42+46= ? 88
Correct
CONTINUE(y/n)? y
4+8= ? 16
Wrong
CONTINUE(y/n)? N
Number of correct answers = 1
Number of wrong answers = 1
Press any key to continue . . .
-----------------------------------*/
