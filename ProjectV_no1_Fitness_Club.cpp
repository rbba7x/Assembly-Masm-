// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Project 4 No. 1 - Fitness Club
//			Course: CMPS 371 – Assembly Language (MASM)
//			Date: 1/16/2019
//
// Purpose: This program display a menu with membership prices based on gender and age
//	    then displays the price of a membership based on user input. The user is 
//	    asked if they want to continue and can repeat the process.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

string name;
char gender, ans = 'y';
int age, total, ageGroup;

void displayTotal()
{
	cout << name << ", your membership is $" << total << endl;
}

void getNameGender()
{
	cout << "Enter your name and gender: ";
	cin >> name >> gender;
}

void getFemaleAge()
{
	name = "Ms. " + name;

	cout << name << ", how old are you? ";
	cin >> age;
}

void getMaleAge()
{
	name = "Mr. " + name;

	cout << name << ", how old are you? ";
	cin >> age;
}

void YesNo()
{
	cout << "CONTINUE(y/n)? ";
	cin >> ans;
}
int main()
{
	cout << "------------ULV Fitness------------\nMale\n"
		"  Adults(age>19)............$150\n"
		"  Teenagers(13<=age<=19)....$100\n"
		"  Children(age<13)..........$30"
		"\n\nFemale\n"
		"  Adults(age>19)............$170\n"
		"  Teenagers(13<=age<=19)....$120\n"
		"  Children(age<13)..........$30\n\n";

	_asm
	{
		doLoop:
		call getNameGender;
		cmp gender, 'f';
		jne checkF
			jmp female

		checkF:
		cmp gender, 'F'
		jne male
		jmp female

			female :
		//Gender is female
		call getFemaleAge
	testG13:
		cmp age, 13;
		jnge childm;

	testL19:
		cmp age, 19;
		jnle adultm;
	teen:
		mov total, 120;
		jmp  done
			adult :
		mov total, 170;
		jmp  done
			child :
		mov total, 30;
		jmp  done

			male :
		//Gender is male
		call getMaleAge;
	test13:
		cmp age, 13;
		jnge childm;

	test19:
		cmp age, 19;
		jnle adultm;
	teen1:
		mov total, 100;
		jmp  done
			adultm :
		mov total, 150;
		jmp  done
			childm :
		mov total, 30;
		jmp  done

			done :
		call displayTotal;
		jmp yesno

		yesno:
		call YesNo
			cmp ans, 'y'
		Jne checkY
		Jmp doLoop
	checkY:
		cmp ans, 'Y'
			Jne finish
			Jmp doLoop
	finish:
	}

	system("pause");
	return 0;
}

/*-------------Output----------------
------------ULV Fitness------------
Male
  Adults(age>19)............$150
  Teenagers(13<=age<=19)....$100
  Children(age<13)..........$30

Female
  Adults(age>19)............$170
  Teenagers(13<=age<=19)....$120
  Children(age<13)..........$30

Enter your name and gender: John m
Mr. John, how old are you? 7
Mr. John, your membership is $30
CONTINUE(y/n)? Y
Enter your name and gender: Mary F
Ms. Mary, how old are you? 15
Ms. Mary, your membership is $120
CONTINUE(y/n)? n
Press any key to continue . . .
-----------------------------------*/
