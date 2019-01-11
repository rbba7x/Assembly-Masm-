// ------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Exam 1 No. 2 - Circle K
//								Course: CMPS 371 - Assembly Language (MASM)
//								Date: 1/11/2019
//
// Purpose: This program displays a menu and allows the user to select how many of each
//			item then displays the total bill
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	cout << "-------Circle K-------\nChips......$2\nDrink......$3\nHotdogs....$4\n" << endl;

	short hotdogs, drinks, chips, total;

	cout << "How many chips, drinks, and hotdogs? ";
	cin >> chips >> drinks >> hotdogs;

	_asm
	{
		//Calculate cost of hotdogs, add to total
		mov bx, hotdogs; //bx = hotdogs
		mov ax, 4; //ax = 4
		imul bx; //dx:ax = 4*hotdogs
		mov total, ax; //total = 4*hotdogs
		mov cx, total; //cx = total = 4*hotdogs

		//Calculate cost of drinks, add to total
		mov bx, drinks; //bx = drinks
		mov ax, 3; //ax = 3
		imul bx; //dx:ax = 3*drinks
		add ax, cx; //ax = (4*hotdogs) + (3*drinks)
		mov total, ax; //total = (4*hotdogs) + (3*drinks)

	   //Calculate cost of chips, add to total
		mov bx, chips; //bx = chips
		mov ax, 2; //ax=2
		imul bx; //dx:ax = 2*chips
		add total, ax; //total = (4*hotdogs) + (3*drinks) + (2*chips)
	}

	cout << "Your total bill is: $" << total << endl;

	system("pause");
	return 0;
}

/*------------------------Output-------------------
-------Circle K-------
Chips......$2
Drink......$3
Hotdogs....$4

How many chips, drinks, and hotdogs? 2 2 3
Your total bill is: $22
Press any key to continue . . .
-------------------------------------------------*/