#include <iostream>
#include "car.h"
using namespace std;

/// <summary>
///  Function checks if a given string can be an unsigned int
/// </summary>
/// <param name="str">string</param>
/// <returns>true if str is an unsigned int and false otherwise.</returns>
bool strIsUnsignedInt(char str[10])
{
	bool flag = true, nullFound = false;
	int endOfStr = 0;
	for (int i = 0; i < 9; i++)
	{
		if (str[i] == '\0' && !(nullFound))
		{
			endOfStr = i;
			nullFound = true;
		}
	}
	if (nullFound)
	{
		for (int i = 0; i < endOfStr; i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				flag = false;
			}
		}
	}
	else
	{
		flag = false;
	}
	return flag;
}

/// <summary>
///  converts a string to int. Assumes string can realy be converted!!!!
/// </summary>
/// <param name="str"> a string </param>
/// <returns>unsigned int - conversion from string</returns>
int convertToInt(char str[10])
{
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		if (str[i] == '\0')
		{
			break;
		}
		result = result * 10 + (str[i] - '0');
	}
	return result;
}

/// <summary>
///  creates two cars and then compares them according to there year and then engine value.
/// </summary>
int main()
{
	char make[10], model[10], color[10], year[10], engineVolume[10];
	int myYear = 0, myEngineVolume = 0;

	car *c1, *c2;
	bool correctInput = false;
	while (!correctInput)
	{
		cout << "\nEnter details for the first car:\nmake, model, year, engine volume (in cc), and color(a 10 - char string)" << endl;
		cin >> make >> model >> year >> engineVolume >> color;
		if (strIsUnsignedInt(year) && strIsUnsignedInt(engineVolume))
		{
			myYear = convertToInt(year);
			myEngineVolume = convertToInt(engineVolume);
			c1 = new car(make, model, color, myYear, myEngineVolume);
			//if one of the inputed values to car are invalid car will get default values!!
			//checks that the values were valid.
			if (!c1->isDefault())  
			{
				correctInput = true;
			}
		}
		else
		{
			cout << "ERROR, invalid input\nYear and engine volume must be positive numbers no longer than 9 digits long" << endl;
		}

	}
	
	correctInput = false;
	while (!correctInput)
	{
		cout << "Enter details for the second car:\nmake, model, year, engine volume (in cc), and color(a 10 - char string)" << endl;
		cin >> make >> model >> year >> engineVolume >> color;
		if (strIsUnsignedInt(year) && strIsUnsignedInt(engineVolume))
		{
			myYear = convertToInt(year);
			myEngineVolume = convertToInt(engineVolume);
			c2 = new car(make, model, color, myYear, myEngineVolume);
			//if one of the inputed values to car are invalid car will get default values!!
			//checks that the values were valid.
			if (!c2->isDefault())
			{
				correctInput = true;
			}
		}
		else
		{
			cout << "ERROR, invalid input\nYear and engine volume must be positive numbers"<< endl;
		}

	}

	////prints the newer car
	cout << "The newer car is:" << endl;
	switch (c1->greaterYear(*c2))
	{
	case 0:
		cout << "Both cars are equal!!!" << endl;
		break;
	case 1:
		c1->print();
		break;
	case -1:
		c2->print();
		break;
	default:
		cout << "ERROR!!!" << endl;
		break;
	}
	//prints car with greater engine volume
	cout << "Car with greater engine volume:" << endl;
	switch (c1->greaterEngineVolume(*c2))
	{
	case 0:
		cout << "Both cars are equal!!!" << endl;
		break;
	case 1:
		c1->print();
		break;
	case -1:
		c2->print();
		break;
	default:
		cout << "ERROR!!!" << endl;
		break;
	}

	
	delete c1;
	delete c2;
	return 0;
}