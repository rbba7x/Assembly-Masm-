// ------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project 1 No. 6 - Rectangle and Triangle
//								Course: CMPS 371 - Assembly Language (MASM)
//								Date: 1/09/2019
//
// Purpose: This program accepts input for the dimensions of a rectangle and a triangle
//          then displays the areas and perimeters of the shapes.
//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	short width, leng, rect_perim, rect_area, tri_perim, tri_area, a, b, c, h;;

	cout << "Enter the values of width and length of the rectangle: ";
	cin >> width >> leng;

	cout << "Enter the values of a, b, c, and h of the triangle: ";
	cin >> a >> b >> c >> h;

	_asm
	{
		//Find triangle perimeter
		mov ax, a; //ax = a
		add ax, b; //ax = a+b
		add ax, c; //ax = a+b+c
		mov tri_perim, ax; // tri_perim = a+b+c

		//Find rectangle perimeter
		mov bx, width; //bx = width
		add bx, leng; //bc = width+length
		add bx, bx; //bx=2width+2length
		mov rect_perim, bx; //rect_perim = 2width+2length

		//Find triangle area
		mov cx, 2;//cx=2
		mov ax, c;//ax=c
		imul h; //dx:ax = ch
		idiv cx; //ax = (ch)/2 dx=(ch)%2
		mov tri_area, ax; //tri_area=(ch)/2

		//Find rectangle area
		mov ax, width; //ax=width
		imul leng; //dx:ax = width*leng
		mov rect_area, ax; //rect_area = width*leng
	}
	
	cout << "Rectangle: perimeter= " << rect_perim << "  area=" << rect_area << endl;
	cout << "Triangle: perimeter=" << tri_perim << "  area=" << tri_area << endl;

	system("pause");
	return 0;
}

/*----------------------------------Output------------------------
Enter the values of width and length of the rectangle: 5 10
Enter the values of a, b, c, and h of the triangle: 7 6 10 5
Rectangle: perimeter= 30  area=50
Triangle: perimeter=23  area=25
Press any key to continue . . .
-----------------------------------------------------------------*/