/*
* Creator:     Kozlova Elizabeth Paula
*
* Title:	   Coordinates Check (Enhanced) 
*
* Description:
*			   This program is used to determine whether the point with the entered coordinates is within the rectangle, which dimensions were also entered by the user
*
*/

#include <iostream>
using namespace std;

//function prototypes 

void pointInRectangle(double width, double height, double x, double y, bool& inRectangle);
void calculationPart(double& width, double& height, double& x, double& y, bool& inRectangle);

//main function

int main()
{
	double width = 0, height = 0, x = 0, y = 0;
	bool inRectangle;

	pointInRectangle(width, height, x, y, inRectangle);

	return 0;
}

//function which performs the main task of the program 
void pointInRectangle(double width, double height, double x, double y, bool& inRectangle)
{
	/*
	initializing a variable with bool data type, which will be used in the while - loop checking the
	entered dimensions of the rectangle and exiting the loop if both of the entered dimensions are equal to zero
	*/

	bool checker = false;

	//accepting the dimensions from the user 

	cout << "Enter width of the rectangle: ";
	cin >> width;
	cout << "Enter height of the rectangle: ";
	cin >> height;

	//while-loop, that is checking the dimensions of the rectangle

	while (checker != true)
	{
		//option 1: both entered width and height are valid 

		if ((width > 0) && (height > 0))
		{
			calculationPart(width, height, x, y, inRectangle);
			checker = false;
			cout << "Enter width of the rectangle: ";
			cin >> width;
			cout << "Enter height of the rectangle: ";
			cin >> height;
		}

		//option 2: both entered width and height are invalid  

		else if (((width < 0) && (height < 0)) || ((width < 0) && (height == 0)) || ((width == 0) && (height < 0)))
		{
			while (width <= 0)
			{
				cout << "The entered value of width is invalid. Please, enter the width again: ";
				cin >> width;
			}
			while (height <= 0)
			{
				cout << "The entered value of height is invalid. Please, enter the height again: ";
				cin >> height;
			}
			calculationPart(width, height, x, y, inRectangle);
			checker = false;
			cout << "Enter width of the rectangle: ";
			cin >> width;
			cout << "Enter height of the rectangle: ";
			cin >> height;
		}

		//option 3: entered height is invalid 

		else if (((width > 0) && (height < 0)) || ((width > 0) && (height == 0)))
		{
			while (height <= 0)
			{
				cout << "The entered value of height is invalid. Please, enter the height again: ";
				cin >> height;
			}
			calculationPart(width, height, x, y, inRectangle);
			checker = false;
			cout << "Enter width of the rectangle: ";
			cin >> width;
			cout << "Enter height of the rectangle: ";
			cin >> height;
		}

		//option 4: entered width is invalid 

		else if (((width < 0) && (height > 0)) || ((width == 0) && (height > 0)))
		{
			while (width <= 0)
			{
				cout << "The entered value of width is invalid. Please, enter the width again: ";
				cin >> width;
			}
			calculationPart(width, height, x, y, inRectangle);
			checker = false;
			cout << "Enter width of the rectangle: ";
			cin >> width;
			cout << "Enter height of the rectangle: ";
			cin >> height;
		}

		//option 5: both entered height and width are equal to zero - leads to exiting the loop and program termination

		else if ((width == 0) && (height == 0))
			checker = true;
	}
	cout << "Goodbye!" << endl;
}

//function that determines whether a point is in the rectangle of not 

void calculationPart(double& width, double& height, double& x, double& y, bool& inRectangle)
{
	//initializing two additional variables that will be helpful for the calculation part 

	double w, h;

	w = width / 2;
	h = height / 2;

	//accepting the coordinates from the user 

	cout << "Please, enter the two coordinates of the point: ";
	cin >> x;
	cin >> y;

	//determining whether the point is in the rectangle or not 

	if ((x <= w) && (y <= h))
		inRectangle = true;
	else
		inRectangle = false;

	//displaying the answer 

	if (inRectangle == true)
		cout << "Point (" << x << ", " << y << ") is in the rectangle." << endl;
	else
		cout << "Point (" << x << ", " << y << ") is not in the rectangle." << endl;
}