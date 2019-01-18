// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 2 No. 1 - Scores
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/17/2019
//
// Purpose: This program accepts test scores then displays the max, min and average
//			
//-------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int score, max = 0, min = 0, total = 0, counter = 0, average, temp;

void enterScores()
{
	cout << "Enter a group of scores with -1 at the end: ";
}

void getScore()
{
	cin >> score;
}

void displayMax()
{
	cout << "Maximum score is " << max << endl;
}

void displayMin()
{
	cout << "Minimum score is " << min << endl;
}

void displayAverage()
{
	cout << "Average is " << average << endl;
}

void test()
{
	cout << "Comparing " << max << " and " << temp << endl;
}

int main()
{
	_asm
	{
		call enterScores
		call  getScore
		mov ecx, score;
		mov max, ecx;
		mov min, ecx;

	whileLoop:
		mov ebx, score //ebx = score
			cmp ebx, -1
			Je exitLoop

			addTotal :
		inc counter
			add total, ebx; //total = total+score
		jmp testMax

			testMax :
		cmp max, ebx;
		Jg testMin;

	newMax:
		mov max, ebx;
		jmp readAgain;

	testMin:
		cmp min, ebx;
		Jl readAgain;

	newMin:
		mov min, ebx;
		jmp readAgain;

	readAgain:
		call getScore;
		Jmp  whileLoop;

	exitLoop:
		call displayMax
			call displayMin
			mov eax, total;
		cdq;
		idiv counter;
		mov average, eax;
		call displayAverage

	}
	system("pause");
	return 0;
}

/*--------------------------Output--------------------------------
Enter a group of scores with -1 at the end: 30 70 10 90 50 -1
Maximum score is 90
Minimum score is 10
Average is 50
Press any key to continue . . .
----------------------------------------------------------------*/