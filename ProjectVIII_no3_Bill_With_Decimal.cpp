// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Exam 8 No. 3 - Bill With Decimal
//				Course: CMPS 371 – Assembly Language (MASM)
//				Date: 1/29/2019
//
// Purpose: This program allows the user to specify a number of customers and each 
//			customer makes a separate order.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>

const float soda = 2.25, water = 1.75, juice = 2.80, ten_inch = 3.45, twelve_inch = 5.25;
float zero = 0, num_drinks, num_sand, sodas = 0, waters = 0, juices = 0, ten_inches = 0, twelve_inches = 0, total = 0;
char d_type; //drink type
int num_cust, i, s_type; //sandwich type

void displayMenu()
{
	std::cout << "-------7-11 Convenient Store-------\n\nDrinks\n  Soda (S)....$2.25\n  Water(W)....$1.75\n  Juice(J)....$2.80"
		"\n\nSandwiches\n  10 inches...$3.45\n  12 inches...$5.25\n\n";
}

void getOrder()
{
	std::cout << "How many drinks? ";
	std::cin >> num_drinks;
	std::cout << "\tWhat kind of drink (S=Soda, W=Water, J = Juice)? ";
	std::cin >> d_type;

	std::cout << "How many sandwiches? ";
	std::cin >> num_sand;
	std::cout << "\tWhat size of sandwich (10/12 inches)? ";
	std::cin >> s_type;

	switch (d_type)
	{
	case 'S': sodas = num_drinks;
		break;
	case 'W': waters = num_drinks;
		break;
	case 'J': juices = num_drinks;
		break;
	}

	switch (s_type)
	{
	case 10: ten_inches = num_sand;
		break;
	case 12: twelve_inches = num_sand;
		break;
	}
}

void displayTotal()
{
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << "Customer " << i << ", your total bill is $" << total << std::endl;
}

void setVariables()
{
	sodas = 0; waters = 0; juices = 0; ten_inches = 0; twelve_inches = 0; total = 0;
}

int main()
{
	std::cout << "Enter how many customers: ";
	std::cin >> num_cust;

	

	_asm
	{
			call displayMenu
			mov i, 0;
			mov ebx, num_cust;

	customer:
			cmp i, ebx
				Jge done

				mov total, 0
				call setVariables
				call getOrder
		//Calculate cost of sodas, add to total
		fld zero;//st[0] = total
		fld sodas; //st[0] = sodas st[1] = total
		fld soda; //st[0] = soda st[1] = sodas st[3] = total
		fmul; //st[0] = soda*sodas st[1] = total
		fadd; //st[0] = total

		//Calculate cost of waters, add to total
		fld waters; //st[0] = waters st[1] = total
		fld water; //st[0] = water st[1] = waters st[3] = total
		fmul; //st[0] = water*waters st[1] = total
		fadd; //st[0] = total

		//Calculate cost of juices, add to total
		fld juices; //st[0] = juices st[1] = total
		fld juice; //st[0] = juice st[1] = juices st[3] = total
		fmul; //st[0] = juice*juices st[1] = total
		fadd; //st[0] = total

		//Calculate cost of 10 inch sandwiches, add to total
		fld ten_inches;//st[0] = total
		fld ten_inch; //st[0] = ten_inch st[1] = ten_inches st[3] = total
		fmul; //st[0] = ten_inch*ten_inches st[1] = total
		fadd; //st[0] = total

		//Calculate cost of 12 inch sandwiches, add to total
		fld twelve_inches;//st[0] = total
		fld twelve_inch; //st[0] = twelve_inches st[1] = total
		fmul; //st[0] = twelve_inch*twelve_inches st[1] = total
		fadd; //st[0] = total

		fstp total;
		inc i
			fld zero;
		fmul;
		call displayTotal
			Jmp customer

			done:
	}


	system("pause");
	return 0;
}

/*-----------------------Output-----------------------------
Enter how many customers: 2
-------7-11 Convenient Store-------

Drinks
  Soda (S)....$2.25
  Water(W)....$1.75
  Juice(J)....$2.80

Sandwiches
  10 inches...$3.45
  12 inches...$5.25

How many drinks? 2
		What kind of drink (S=Soda, W=Water, J = Juice)? S
How many sandwiches? 3
		What size of sandwich (10/12 inches)? 10
Customer 1, your total bill is $14.85
How many drinks? 3
		What kind of drink (S=Soda, W=Water, J = Juice)? J
How many sandwiches? 2
		What size of sandwich (10/12 inches)? 12
Customer 2, your total bill is $18.90
Press any key to continue . . .
--------------------------------------------------------------*/