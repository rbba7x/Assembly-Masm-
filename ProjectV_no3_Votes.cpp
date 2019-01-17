// ------------------------------------------------------------------------------------
//							Name: Ryan Beebe
//							Project 5 No. 3 - Count Votes
//							Course: CMPS 371 - Assembly Language (MASM)
//							Date: 1/16/2019
//
// Purpose: This program accepts a string of votes (y/n) then display how many of each
//			represented as a number and as stars
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int y, n;
char l;

void enterVotes()
{
	cout << "Enter a group of votes: ";
}

void readChar()
{
	cin.get(l);
}

void displayYes()
{
	cout << "Yes votes = " << y << " = ";
}

void displayNo()
{
	cout << "\nNo  votes = " << n << " = ";
}

void printStar()
{
	cout << "*";
}

int main()
{
	_asm
	{
		call enterVotes
		call  readChar

		whileLoop :
		cmp l, '\n'
			Je done
			cmp l, 'y'
			Jne checkY
			inc y;
	checkY:
		cmp l, 'Y'
			Jne checkn1
			inc y;
	checkn1:
		cmp l, 'n'
			Jne checkn2
			inc n;
	checkn2:
		cmp l, 'N'
			Jne readAgain
			inc n;
	readAgain:
		call readChar
			Jmp  whileLoop
			done:

	call displayYes
		doYes:
		call printStar
		dec y
		cmp y,0
			Jne doYes
			Jmp startNo

	startNo:
		call displayNo
		doNo:
			call printStar
			dec n
			cmp n,0
			Jne doNo
				Jmp doneC
				doneC:
	}
	
	cout << endl;

	system("pause");
	return 0;
}

/*-------------Output---------------
Enter a group of votes: yNNNYnyynN
Yes votes = 4 = ****
No  votes = 6 = ******
Press any key to continue . . .
-----------------------------------*/