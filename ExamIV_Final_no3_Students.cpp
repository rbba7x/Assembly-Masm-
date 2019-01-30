// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Final Exam No. 3 - Students
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/30/2019
//
// Purpose: This program initializes a 2d array then displays the total of each column.
//			The column with the highest total is displayed.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int freshman, sophmores, juniors, seniors, i = 1, P[4][4] = { 33,31,20,20,23,22,24,30,10,20,30,40 };
short highest = 1;

void displayTotals()
{
	cout << "Freshman..... " << freshman << endl;
	cout << "Sophmores.... " << sophmores << endl;
	cout << "Juniors...... " << juniors << endl;
	cout << "Seniors...... " << seniors << endl;
}

void fHighest()
{
	cout << "\tFreshman students are the highest\n";
}

void soHighest()
{
	cout << "\tSophmore students are the highest\n";
}

void jHighest()
{
	cout << "\tJunior students are the highest\n";
}

void seHighest()
{
	cout << "\tSenior students are the highest\n";
}

int main()
{
	
	
	_asm
	{
		mov i, 0;
		mov freshman, 0;
		mov sophmores, 0;
		mov juniors, 0;
		mov seniors, 0;
		lea esi, P;

	fLoop:
		cmp i, 4
			Je findMax

		mov eax, [esi]
			add freshman, eax
			add esi, 4
			mov eax, [esi]
			add sophmores, eax
			add esi, 4
			mov eax, [esi]
			add juniors, eax
			add esi, 4
			mov eax, [esi]
			add seniors, eax
			add esi, 4
		inc i
			Jmp fLoop
		
			findMax :
		mov eax, freshman
		cmp sophmores, eax
			Jng checkJuniors

			sophmores:
			mov highest,2
			mov eax, sophmores
			jmp checkJuniors

			checkJuniors:
			cmp juniors, eax
				Jng checkSeniors

				juniors:
				mov highest, 3
				mov eax, juniors
				jmp checkSeniors

				checkSeniors:
			cmp seniors, eax
				Jng done

				seniors:
				mov highest, 4
				jmp done

					done:
				call displayTotals

					cmp highest, 1
					Jne soph

				call fHighest
					jmp finish

					soph:
				cmp highest, 2
					Jne jun

					call soHighest
					Jmp finish

					jun:
				cmp highest, 3
					Jne sen

					call jHighest
					Jmp finish

					sen:
				call seHighest
					Jmp finish
					


					finish:
	}

	system("pause");
}

/*-------------Output-----------
Freshman..... 66
Sophmores.... 73
Juniors...... 74
Seniors...... 90
Senior students are the highest
Press any key to continue . . .
--------------------------------*/