// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Project 6 No. 1 - Inverse Case
//			Course: CMPS 371 - Assembly Language (MASM)
//			Date: 1/16/2019
//
// Purpose: This program accepts a sentence then switches the case of the letters
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

char l;

void enterSentence()
{
	cout << "Enter a sentence: ";
}

void readChar()
{
	cin.get(l);
}

void printL()
{
	cout << l;
}

void pSpace()
{
	cout << " ";
}

int main()
{
	_asm
	{
		call enterSentence
		call  readChar

		whileLoop :
		cmp l, '\n'
			Je done
		
	cmp l, 32
	Je printSpace

	cmp l, 97
	Jl checka 

	cap :
		sub l,32
		call printL
		jmp readAgain

	checka :
		add l, 32
			call printL
			jmp readAgain
	
	printSpace:
		call pSpace
		call readAgain

	readAgain:
		call readChar
			Jmp  whileLoop
			done :
	}

	cout << endl;
	system("pause");
	return 0;
}
/*------------Output--------------------
Enter a sentence: Today Is Tue
tODAY iS tUE
Press any key to continue . . .
--------------------------------------*/
