// ------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project 3 No. 2 - 7-11 Convenient Store
//								Course: CMPS 371 - Assembly Language (MASM)
//								Date: 1/09/2019
//
// Purpose: This program displays a menu and allows the user to select how many items
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	const int soda = 2, water = 1, beer = 3, six_inch = 2, ten_inch = 3, twelve_inch = 5;
	int num_drinks, num_sand, s_type, sodas = 0, waters = 0, beers = 0, six_inches = 0, ten_inches = 0, twelve_inches = 0, total; //s_type = sandwich type
	char d_type; //drink type

	cout << "-------7-11 Convenient Store-------\n\nDrinks\n  Soda(S).....$2\n  Water(W)....$1\n  Beer(B).....$3"
			"\n\nSandwiches\n  6 inches....$2\n  10 inches...$3\n  12 inches...$5\n" << endl;

	cout << "How many drinks? ";
		cin >> num_drinks;
	cout << "\tWhat kind of drink (S=Soda, W=Water, B=Beer)? ";
		cin >> d_type;

	cout << "How many sandwiches? ";
		cin >> num_sand;
	cout << "\tWhat size of sandwich (6/10/12 inches)? ";
		cin >> s_type;

		switch (d_type)
		{
		case 'S': sodas = num_drinks;
			break;
		case 'W': waters = num_drinks;
			break;
		case 'B': beers = num_drinks;
			break;
		}

		switch (s_type)
		{
		case 6: six_inches = num_sand;
			break;
		case 10: ten_inches = num_sand;
			break;
		case 12: twelve_inches = num_sand;
			break;
		}

		_asm
		{
			//Calculate cost of sodas, add to total
			mov ebx, sodas; //bx = sodas
			mov eax, soda; //ax = soda = 2
			imul ebx; //dx:ax = 2*sodas
			mov total, eax; //total = 2*sodas

			//Calculate cost of waters, add to total
			mov eax, waters; //ax = waters
			add total, eax; //total = 2*sodas + waters

			//Calculate cost of beers, add to total
			mov ebx, beers; //bx = beers
			mov eax, beer; //ax = beer = 3
			imul ebx; //dx:ax = 3*beer
			add total, eax; //total = 2*sodas + waters + 3*beers

			//Calculate cost of 6 inch sandwiches, add to total
			mov ebx, six_inches; //bx = six_inches
			mov eax, six_inch; //ax = six_inch = 2
			imul ebx; //dx:ax = 2*six_inches
			add total, eax; //total = 2*sodas + waters + 3*beers + 2*six_inches

			//Calculate cost of 10 inch sandwiches, add to total
			mov ebx, ten_inches; //bx = ten_inches
			mov eax, ten_inch; //ax = ten_inch = 3
			imul ebx; //dx:ax = 3*ten_inches
			add total, eax; //total = 2*sodas + waters + 3*beers + 2*six_inches + 3*ten_inches

			//Calculate cost of 12 inch sandwiches, add to total
			mov ebx, twelve_inches; //bx = twelve_inches
			mov eax, twelve_inch; //ax = twelve_inch = 5
			imul ebx; //dx:ax = 5*twelve_inches
			add total, eax; //total = 2*sodas + waters + 3*beers + 2*six_inches + 3*ten_inches + 5*twelce_inches

		}

		cout << "Your total bill is $" << total << endl;;
	system("pause");
	return 0;
}

/*-----------------Output-------------------------------------
-------7-11 Convenient Store-------

Drinks
  Soda(S).....$2
  Water(W)....$1
  Beer(B).....$3

Sandwiches
  6 inches....$2
  10 inches...$3
  12 inches...$5

How many drinks? 2
		What kind of drink (S=Soda, W=Water, B=Beer)? S
How many sandwiches? 3
		What size of sandwich (6/10/12 inches)? 6
Your total bill is $10
Press any key to continue . . .

-------7-11 Convenient Store-------

Drinks
  Soda(S).....$2
  Water(W)....$1
  Beer(B).....$3

Sandwiches
  6 inches....$2
  10 inches...$3
  12 inches...$5

How many drinks? 2
		What kind of drink (S=Soda, W=Water, B=Beer)? B
How many sandwiches? 2
		What size of sandwich (6/10/12 inches)? 12
Your total bill is $16
Press any key to continue . . .
-------------------------------------------------------------*/