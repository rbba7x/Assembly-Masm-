// ------------------------------------------------------------------------------------
//							Name: Ryan Beebe
//							Project 5 No. 2 - Count Grades
//							Course: CMPS 371 - Assembly Language (MASM)
//							Date: 1/16/2019
//
// Purpose: This program accepts grades A, B, and C then displays how many of each were
//		    entered
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int a, b, c;
char l;

void enterGrades()
{
	cout << "Enter 8 grades (A,B,C): ";
}

void readChar()
{
	cin.get(l);
}

int main()
{
	_asm
	{
		call enterGrades
		call  readChar
		
		whileLoop :
			cmp l, '\n'
			Je done 
			cmp l, 'a'
				Jne checkA
				inc a;
					checkA:
						cmp l, 'A'
						Jne checkb1
						inc a;
							checkb1:
								cmp l, 'b'
								Jne checkb2
								inc b;
									checkb2:
										cmp l, 'B'
										Jne checkc1
										inc b;
											checkc1:
												cmp l, 'c'
												Jne checkc2
												inc c;
													checkc2:
														cmp l, 'C'
														Jne readAgain
														inc c;
	readAgain:
		call readChar
		Jmp  whileLoop 
	done:
	}

	cout << "No. of 'A' scores = " << a << endl;
	cout << "No. of 'B' scores = " << b << endl;
	cout << "No. of 'C' scores = " << c << endl;

	system("pause");
	return 0;
}
/*------------Output--------------------
Enter 8 grades (A,B,C): AbbBcCaA
No. of 'A' scores = 3
No. of 'B' scores = 3
No. of 'C' scores = 2
Press any key to continue . . .
--------------------------------------*/