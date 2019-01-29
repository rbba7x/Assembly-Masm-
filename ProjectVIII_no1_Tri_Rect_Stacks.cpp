// ------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//			Exam 8 No. 1 - Triangle,Rectangle,Stack
//			Course: CMPS 371 – Assembly Language (MASM)
//			Date: 1/28/2019
//
// Purpose: This program asks for input for the dimensions of a triangle and rectangle
//	    then creates 2 threads to calculate the area and perimeter of each shape
//	    respectively. The areas and perimeters are displayed.
//-------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <thread>

float t_area, t_perim, a, b, c, h, r_area, r_perim, lngth, width, one_half = 0.5;

void triangle_calculations()
{
	_asm
	{
		//Perimeter of triangle = a+b+c = abc++
		fld a; //st[0] = a
		fld b; //st[0] = b, st[1] = a
		fld c; //st[0] = c, st[1] = b, st[2] = a
		fadd; //st[0] = b+c, st[1] = a
		fadd; //st[0] = a+b+c
		fstp t_perim; //t_perim = a+b+c
		
		//Area of triangle = 0.5*c*h = 0.5c*h*
		fld one_half; //st[0] = 0.5
		fld c; //st[0] = c, //st[1] = 0.5
		fmul; //st[0] = 0.5*c
		fld h; //st[0] = h, //st[1] = 0.5*c
		fmul; //st[0] = 0.5*c*h
		fstp t_area; //t_area = 0.5*c*h
	}
}

void rectangle_calculations()
{
	_asm
	{
		//Perimeter of rectangle = 2*width+2*length = width+width+length+length = wwll+++
		fld width; //st[0] = width
		fld width; //st[0] = width, st[1] = width
		fadd; //st[0] = 2width
		fld lngth; //st[0] = length, st[1] = 2width
		fld lngth; //st[0] = length, st[1] = length, st[2] = 2width
		fadd; // st[0] = 2length, st[1] = 2width
		fadd; //st[0] = 2width+2length
		fstp r_perim; //r_perim = 2width+2length
		//Area of rectangle = width*length = wl*
		fld width; //st[0] = width
		fld lngth; //st[0] = length, st[1] = width
		fmul; //st[0] = width*length
		fstp r_area; //r_area = width*length
	}
}

int main()
{
	std::cout << "Enter the values of a,b,c, and h for the triangle: ";
	std::cin >> a >> b >> c >> h;
	
	std::cout << "Enter the length and width of the rectangle: ";
	std::cin >> lngth >> width;

	std::thread first(triangle_calculations); // spawn new thread that calls triangle_calculations()
	std::thread second(rectangle_calculations); // spawn new thread that calls rectangle_calculations()

	//Wait until all calculations are done
	first.join();
	second.join();

	//Print results
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << "Triangle\n\tArea     : " << t_area << "\n\tPerimeter: " << t_perim;
	std::cout << "\nRectangle\n\tArea     : " << r_area <<"\n\tPerimeter: " << r_perim << std::endl;
	
	system ("pause");
}
/*----------------------------Output----------------------------------
Enter the values of a,b,c, and h for the triangle: 4.3 6.1 9.5 10.7
Enter the length and width of the rectangle: 15.1 10.6
Triangle
Area     : 50.83
Perimeter: 19.90
Rectangle
Area     : 160.06
Perimeter: 51.40
Press any key to continue . . .
----------------------------------------------------------------------*/
