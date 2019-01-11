// ------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project 2 No. 2 - K Store Menu
//								Course: CMPS 371 - Assembly Language (MASM)
//								Date: 1/09/2019
//
// Purpose: This program displays a menu and allows the user to select how many items
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	cout << "-------K Store Menu-------\n Sandwich...$4\n Drink......$2\n Chips......$1\n" << endl;

	short sandwiches, drinks, chips, total;

	cout << "How many sandwiches? ";
	cin >> sandwiches;
	
	cout << "How many drinks? ";
	cin >> drinks;
	cout << "How many chips? ";
	cin >> chips;
	
	_asm
	{
		//Calculate cost of sandwiches, add to total
		mov bx, sandwiches; //bx = sandwiches
		mov ax, 4; //ax = 4
		imul bx; //dx:ax = 4*sandwiches
		mov total, ax; //total = 4*sandwiches
		mov cx, total; //cx = total = 4*sandwiches

		//Calculate cost of drinks, add to total
		mov bx, drinks; //bx = drinks
		mov ax, 2; //ax = 2
		imul bx; //dx:ax = 2*drinks
		add ax, cx; //ax = (4*sandwiches) + (2*drinks)
		mov total, ax; //total = (4*sandwiches) + (2*drinks)

		//Calculate cost of chips, add to total
		mov bx, chips; //bx = chips
		add total, bx; //total = (4*sandwiches) + (2*drinks) + chips
	}

	cout << "Your total bill is: $" << total << endl;

	system("pause");
	return 0;
}

/*----------Output-------------------
-------K Store Menu-------
 Sandwich...$4
 Drink......$2
 Chips......$1

How many sandwiches? 3
How many drinks? 2
How many chips? 4
Your total bill is: $20
Press any key to continue . . .
------------------------------------*/