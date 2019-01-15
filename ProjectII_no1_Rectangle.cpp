// ------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project 2 No. 1 - Rectangle
//				Course: CMPS 371 - Assembly Language (MASM)
//				Date: 1/09/2019
//
// Purpose: This program accepts input for the dimensions of a rectangle then displays
//          the area and perimeter of the rectangle.
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	short width, leng, rect_perim, rect_area; 

	cout << " ---------------------" << endl;
	cout << "|                     |" << endl;
	cout << "|                     | Width" << endl;
	cout << " ---------------------" << endl;
	cout << "        Length" << endl << endl;

	cout << "Enter the measurement of the width: ";
	cin >> width;

	cout << "Enter the measurement of the length: ";
	cin >> leng;

	_asm
	{
		//Find rectangle perimeter
		mov bx, width; //bx = width
		add bx, leng; //bc = width+length
		add bx, bx; //bx=2width+2length
		mov rect_perim, bx; //rect_perim = 2width+2length

		//Find rectangle area
		mov ax, width; //eax=width
		imul leng; //edx:eax = width*leng
		mov rect_area, ax; //rect_area = width*leng
	}

	cout << "Area = " << rect_area << endl << "Perimeter = " << rect_perim << endl;

	system("pause");
	return 0;
}

/*---------------Output-----------------------------
 ---------------------
|                     |
|                     | Width
 ---------------------
		Length

Enter the measurement of the width: 23
Enter the measurement of the length: 44
Area = 1012
Perimeter = 134
Press any key to continue . . .
--------------------------------------------------*/
