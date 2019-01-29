// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 2 No. 3 - 24hr Store
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/17/2019
//
// Purpose: This program displays a menu and allows the user to enter how many customers
//	    and select how many items each customer wants
//-------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

const int soda = 4, beer = 5, hamburger = 7, pizza = 9;
int counter = 0, customers, num_drinks, num_food, sodas, beers, hamburgers, pizzas, total; //f_type = food type
char d_type, f_type; //drink type
string name;

void displayMenu()
{
	cout << "-------24 hour Store-------\n\nDrinks\n Soda(s)..........$4\n Beer(b)..........$5"
		"\n\nFood\n Hamburgers(h)....$7\n Mini Pizza(p)....$9\n";
}

void numCustomers()
{
	cout << "Enter the number of customers: ";
	cin >> customers;
}

void numItems()
{
	cout << name << ", how many drinks and food would you like: ";
	cin >> num_drinks >> num_food;
}

void itemType()
{
	cout << " What kind of drink (s/b)? ";
	cin >> d_type;

	cout << " What kind of food (h/p)? ";
	cin >> f_type;
}

void setVari()
{
	switch (d_type)
	{
	case 's': sodas = num_drinks;
		break;
	case 'b': beers = num_drinks;
		break;
	}

	switch (f_type)
	{
	case 'h': hamburgers = num_food;
		break;
	case 'p': pizzas = num_food;
		break;
	}
}

void displayTotal()
{
	cout << "   Your total bill is $" << total << endl;
}

void getName()
{
	cout << "\nEnter your name: ";
	cin >> name;
}

void constructor()
{
	total = 0;
	sodas = 0;
	beers = 0;
	hamburgers = 0;
	pizzas = 0;
}

int main()
{
	_asm
	{
		call displayMenu;
		call numCustomers;

	forLoop:
		call constructor;
		call getName;
		call numItems;
		call itemType;
		call setVari;

		//Calculate cost of sodas, add to total
		mov ebx, sodas; //bx = sodas
		mov eax, soda; //ax = soda = 4
		imul ebx; //dx:ax = 4*sodas
		mov total, eax; //total = 4*sodas

		//Calculate cost of beers, add to total
		mov ebx, beers; //bx = beers
		mov eax, beer; //ax = beer = 5
		imul ebx; //dx:ax = 5*beer
		add total, eax; //total = 4*sodas +  5*beers

		//Calculate cost of hamburgers, add to total
		mov ebx, hamburgers; //bx = hamburgers
		mov eax, hamburger; //ax = hamburger = 7
		imul ebx; //dx:ax = 7*hamburgers
		add total, eax; //total = 4*sodas + 5*beers + 7*hamburgers

		//Calculate cost of pizzas, add to total
		mov ebx, pizzas; //bx = pizzas
		mov eax, pizza; //ax = pizza = 9
		imul ebx; //dx:ax = 9*pizzas
		add total, eax; //total = 4*sodas + 5*beers + 7*hamburgeres + 9*pizzas

		call displayTotal;

		inc counter;
		mov ebx, counter;
		cmp ebx, customers
			Jl forLoop
			done :
	}

	cout << endl;

	system("pause");
	return 0;
}

/*-------------------------Output-----------------------------
-------24 hour Store-------

Drinks
Soda(s)..........$4
Beer(b)..........$5

Food
Hamburgers(h)....$7
Mini Pizza(p)....$9
Enter the number of customers: 2

Enter your name: John
John, how many drinks and food would you like: 2 3
What kind of drink (s/b)? b
What kind of food (h/p)? h
Your total bill is $31

Enter your name: Mary
Mary, how many drinks and food would you like: 3 4
What kind of drink (s/b)? s
What kind of food (h/p)? p
Your total bill is $48

Press any key to continue . . .
----------------------------------------------------------*/
