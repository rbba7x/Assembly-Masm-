// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Exam 8 No. 2 - Quadratic Equation
//			Course: CMPS 371 – Assembly Language (MASM)
//			Date: 1/29/2019
//
// Purpose: This program asks for input for the variables of a quadratic equation. The
//	    roots are displayed.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>

int main()
{
	float zero = 0, two = 2, four = 4, a, b, c, root1, root2;

	std::cout << "To see the two real roots of X^2+bX+c=0, enter the a, b, and c values: ";
	std::cin >> a >> b >> c;

	b = 0 - b;
	_asm
	{		
		//Root 1
		fld zero;
		fld zero; //st[0] = 0
		fld b; //st[0] = b //st[1] = 0
		fsub; //st[0] = -b
		fld b;//st[0] = b st[1] = -b
		fld b; // st[0] = b st[1] = b st[2] = -b
		fmul; //st[0] = b^2 st[1] = -b
		fld four; //st[0] = 4 st[1] = b^2 st[2] = -b
		fld a; //st[0] = a st[1] = 4 st[2] = b^2 st[3] = -b
		fmul; //st[0] = 4a st[1] = b^2 st[2] = -b
		fld c;// st[0] = c st[1] = 4a st[2] = b^2 st[3] = -b
		fmul;//st[0]=4ac st[1] = b^2 st[3] = -b
		fsub;//st[0] = b^2-4ac st[1] = -b
		fsqrt;//st[0] = sqrt(b^2-4ac) st[1] = -b
		fsub; //st[0] = -b - sqrt(b^2-4ac)
		fld two;
		fld a;
		fmul;
		fdiv;
		fsub;
		fstp root1;

		//Root 2
		fld b; //st[0] = b //st[1] = 0
		fld b;//st[0] = b st[1] = -b
		fld b; // st[0] = b st[1] = b st[2] = -b
		fmul; //st[0] = b^2 st[1] = -b
		fld four; //st[0] = 4 st[1] = b^2 st[2] = -b
		fld a; //st[0] = a st[1] = 4 st[2] = b^2 st[3] = -b
		fmul; //st[0] = 4a st[1] = b^2 st[2] = -b
		fld c;// st[0] = c st[1] = 4a st[2] = b^2 st[3] = -b
		fmul;//st[0]=4ac st[1] = b^2 st[3] = -b
		fsub;//st[0] = b^2-4ac st[1] = -b
		fsqrt;//st[0] = sqrt(b^2-4ac) st[1] = -b
		fsub; //st[0] = -b - sqrt(b^2-4ac)
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp root2;

	}
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << "X1 = " << root1 << "\tX2 = " << root2 << std::endl;
	system("pause");
}

/*---------------------------------Output--------------------------------------------
To see the two real roots of X^2+bX+c=0, enter the a, b, and c values: 2.1 4.5 1.7
X1 = -0.49      X2 = -1.65
Press any key to continue . . .
------------------------------------------------------------------------------------*/
