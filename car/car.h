#pragma once


class car
{
private:
	char make[10], model[10], color[10];
	int year, engineVolume;
public:
//c-tor:
	car();
	car(char _make[10], char _model[10], char _color[10], int m_year, int m_engineVolume);
//functions:
	void print();
	int greaterYear(car c);
	int greaterEngineVolume(car c);
	bool isDefault();
	void setToDefault();
};

