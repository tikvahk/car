#include "car.h"
#include <iostream>
using namespace std;

/// <summary>
///  checks if a given string ends with a null terminator.
/// </summary>
/// <param name="str">string</param>
/// <returns>true if str ends with null terminator</returns>
bool hasNullTerminator(char str[10])
{
	int i = 0;
	bool hasNull = false;
	for (i = 0; i < 10 && !(hasNull) ; i++)
	{
		if (str[i] == '\0')
		{
			hasNull = true;
		}
	}
	if (hasNull)
		return true;
	return false;
}


/// <summary>
///  empty car constructor
/// </summary>
car::car()
{
	setToDefault();
}

/// <summary>
/// car constructor
/// </summary>
car::car(char m_make[10], char m_model[10], char m_color[10], int m_year, int m_engineVolume)
{
	//valides that all strings end with a null terminator.
	if (hasNullTerminator(m_make) && hasNullTerminator(m_model) && hasNullTerminator(m_color)) 
	{
		if (m_year > 0 && m_engineVolume > 0)
		{
			this->year = m_year;
			this->engineVolume = m_engineVolume;
			strncpy(this->make, m_make, 10);
			strncpy(this->model, m_model, 10);
			strncpy(this->color, m_color, 10);
		}
		else
		{
			cout << "ERROR, invalid input\nYear and engine volume most be positive numbers." << endl;
			//give car default values
			setToDefault(); 
		}
	}
	else
	{
		cout << "ERROR, invalid input.\nMake sure input isn't longer than 9 characters." << endl;
		//give car default values
		setToDefault(); 
	}
}

/// <summary>
///  prints cars details 
/// </summary>
void car::print()
{
	cout << "make = " << this->make << endl;
	cout << "model = " << this->model << endl;
	cout << "year = " << this->year << endl;
	cout << "engine volume = " << this->engineVolume << endl;
	cout << "color = " << this->color << endl;
}

/// <summary>
///  compares two cars by year.
/// </summary>
/// <param name="c2">second car to compare</param>
///<returns>0 if equal -1 if c2 is greater else 1</returns>
int car::greaterYear(car c2)
{
	int result = 0;
	if (this->year > c2.year)
	{
		result = 1;
	}
	return (this->year < c2.year) ? -1 : result;
}


/// <summary>
///  compares two cars by engine volume.
/// </summary>
/// <param name="c2">second car to compare</param>
///<returns>0 if equal -1 if c2 is greater else 1</returns>
int car::greaterEngineVolume(car c2)
{
	int result = 0;
	if (this->engineVolume > c2.engineVolume)
	{
		result = 1;
	}
	return (this->engineVolume < c2.engineVolume) ? -1 : result;
}

/// <summary>
///  checks if car has has the default values
/// </summary>
/// <returns>true if car has the default values</returns>
bool car::isDefault()
{
	if (this->make[0] == '\0' && this->color[0] == '\0' && this->engineVolume == 0 && this->model[0] == '\0' && this->year == 0)
		return true;
	return false;
}

/// <summary>
///  sets cars details to default values
/// </summary>
void car::setToDefault()
{
	this->make[0] = '\0';
	this->color[0] = '\0';
	this->engineVolume = 0;
	this->model[0] = '\0';
	this->year = 0;
}