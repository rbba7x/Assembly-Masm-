// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project 5 No. 4 - Grades
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/16/2019
//
// Purpose: This program accepts grades and calculates the average, max, and minimum
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int students, grade, max = 0, min = 0, average = 0, i = 2, total = 0, temp;

void getGrade()
{
	cin >> grade;
}

void enterGrade()
{
	cout << "Please enter the number of students: ";
	cin >> students;
	cout << "Enter " << students << " grades: ";
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

int main()
{	
	_asm
	{
		call enterGrade
		call getGrade;
		mov ecx, students //ecx = students
		mov eax, grade;
		mov max, eax;
		mov min, eax;
		add total, eax;

		forLoop :
		mov ecx, students //ecx = students
			cmp i, ecx
			Jg exitLoop	

				addTotal :
			call getGrade;
			mov ebx, grade //ebx = grade
				add total, ebx; //total = total+grade
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
		inc i
		Jmp  forLoop;

	exitLoop:
		call displayMax
			call displayMin
			dec i
		mov eax, total;
		cdq;
		idiv i;
		mov average, eax;
		call displayAverage

	}

	system("pause");
	return 0;
}

/*-------------------Output----------------
Please enter the number of students: 5
Enter 5 grades: 32 78 47 96 84
Maximum score is 96
Minimum score is 32
Average is 67
Press any key to continue . . .
-------------------------------------------*/