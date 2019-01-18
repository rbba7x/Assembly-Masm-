// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Project 4 No. 1 - Membership
//			Course: CMPS 371 – Assembly Language (MASM)
//			Date: 1/16/2019
//
// Purpose: This program display a menu with membership prices based on gender and age
//	    then displays the price of a membership based on user input.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

string name;
char gender;
int age, total, ageGroup;

void displayTotal()
{
	cout << name << ", your membership is $" << total << endl;
}

void getData()
{
	cout << "Enter your name: ";
	cin >> name;

	cout << name << ", enter your age and gender(m/f): ";
	cin >> age >> gender;
}

int main()
{
	cout << "-------La Verne Private Club-------\nMale\n"
		"  Children(age<13)..........$50\n"
		"  Teenagers(13<=age<=19)....$70\n"
		"  Adults(age>19)............$100"
		"\n\nFemale\n"
		"  Children(age<13)..........$40\n"
		"  Teenagers(13<=age<=19)....$80\n"
		"  Adults(age>19)............$120\n\n";

	_asm
	{
		call getData;
		cmp gender, 'f';
		jne male
	
	female:
		//Gender is female
		testG13:
			cmp age, 13;
			jnge childm;

			testL19:
				cmp age, 19;
				jnle adultm;
					teen:
						mov total, 80;
						jmp  done
					adult:
						mov total, 120;
						jmp  done
			child:
				mov total, 40;
				jmp  done

	male:
		//Gender is male
		test13:
			cmp age, 13;
			jnge childm;
			
			test19:
				cmp age, 19;
				jnle adultm;
					teen1:
						mov total, 70;
						jmp  done
					adultm :
						mov total, 100;
						jmp  done
			childm:
				mov total, 50;
				jmp  done

			done:
		call displayTotal;
	}
	
	system("pause");
	return 0;
}

/*-------------Output--------------------------
-------La Verne Private Club-------
Male
  Children(age<13)..........$50
  Teenagers(13<=age<=19)....$70
  Adults(age>19)............$100

Female
  Children(age<13)..........$40
  Teenagers(13<=age<=19)....$80
  Adults(age>19)............$120

Enter your name: Mary
Mary, enter your age and gender(m/f): 17 f
Mary, your membership is $80
Press any key to continue . . .

-------La Verne Private Club-------
Male
  Children(age<13)..........$50
  Teenagers(13<=age<=19)....$70
  Adults(age>19)............$100

Female
  Children(age<13)..........$40
  Teenagers(13<=age<=19)....$80
  Adults(age>19)............$120

Enter your name: John
John, enter your age and gender(m/f): 10 m
John, your membership is $50
Press any key to continue . . .

-------La Verne Private Club-------
Male
  Children(age<13)..........$50
  Teenagers(13<=age<=19)....$70
  Adults(age>19)............$100

Female
  Children(age<13)..........$40
  Teenagers(13<=age<=19)....$80
  Adults(age>19)............$120

Enter your name: Jack
Jack, enter your age and gender(m/f): 15 m
Jack, your membership is $70
Press any key to continue . . .

-------La Verne Private Club-------
Male
  Children(age<13)..........$50
  Teenagers(13<=age<=19)....$70
  Adults(age>19)............$100

Female
  Children(age<13)..........$40
  Teenagers(13<=age<=19)....$80
  Adults(age>19)............$120

Enter your name: Joe
Joe, enter your age and gender(m/f): 34 m
Joe, your membership is $100
Press any key to continue . . .
-------------------------------------------------*/
