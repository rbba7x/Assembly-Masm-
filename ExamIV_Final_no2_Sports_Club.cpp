
// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Final Exam No. 2 - Sports Club
//			Course: CMPS 371 – Assembly Language (MASM)
//			Date: 1/30/2019
//
// Purpose: This program displays a menu with membership prices based on gender and age.
//	        The price is age * listed price.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <string>

std::string name;
char gender, cont = 'y';
int age, total;

void displayTotal()
{
	std::cout << name << ", your membership is $" << total << "\nCONTINUE(y/n)? ";
	std::cin >> cont;
}

void getData()
{
	std::cout << "Enter your name: ";
	std::cin >> name;

	std::cout << name << ", enter your age: ";
	std::cin >> age;

	std::cout << name << ", enter your gender(m/f): ";
	std::cin >> gender;
}

int main()
{
	std::cout << "-------24/7 SPORTS CLUB-------\nAdults(age>=20)\n"
		"  Male..........$10\n"
		"  Female........$20\n"
		"\nOthers(age<20)\n"
		"  Male..........$30\n"
		"  Female........$10\n\n";
	_asm
	{
		wloop:
		cmp cont, 'y';
		jne finish
			
		call getData;
		cmp gender, 'f';
		jne male

		female :
		//Gender is female
	testGE20:
		cmp age, 20;
		jge Adult;

	notAdult:
		add total, 10;
		je done;
	Adult:
		mov total, 20;
		jmp  done

		male :
		//Gender is male
	test20:
		cmp age, 20;
		jge mAdult;

	notAdultm:
		add total, 30;
		jmp done

	mAdult:
		mov total, 10;
		jmp  done

	done :
		mov eax, total;
		imul age;
		mov total, eax
		call displayTotal;
		jmp wloop
			
	finish:
	}

	system("pause");
	return 0;
}
/*-------------Output-------------
-------24/7 SPORTS CLUB-------
Adults(age>=20)
Male..........$10
Female........$20

Others(age<20)
Male..........$30
Female........$10

Enter your name: Tom
Tom, enter your age: 17
Tom, enter your gender(m/f): m
Tom, your membership is $510
CONTINUE(y/n)? y
Enter your name: Anna
Anna, enter your age: 40
Anna, enter your gender(m/f): f
Anna, your membership is $800
CONTINUE(y/n)? n
Press any key to continue . . .
----------------------------------*/