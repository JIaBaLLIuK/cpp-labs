#include <iostream>
#include "Time.h"

using namespace std;

Time::Time(int _hours, int _minutes, int _seconds)
{
	if (_hours < 0 || _hours > 23)
	{
		hours = -1;
	}
	else
	{
		hours = _hours;
	}
	if (_minutes < 0 || _minutes > 59)
	{
		minutes = -1;
	}
	else
	{
		minutes = _minutes;
	}
	if (_seconds < 0 || _seconds > 59)
	{
		seconds = -1;
	}
	else
	{
		seconds = _seconds;
	}
}

void Time::SetHours(int _hours)
{
	while (_hours < 0 || _hours > 24)
	{
		cout << "You made a mistake! You need to re-enter hour's amount." << endl;
		cin >> _hours;
	}
	hours = _hours;
}

void Time::SetMinutes(int _minutes)
{
	while (_minutes < 0 || _minutes > 59)
	{
		cout << "You made a mistake! You need to re-enter minutes's amount." << endl;
		cin >> _minutes;
	}
	minutes = _minutes;
}

void Time::SetSeconds(int _seconds)
{
	while (_seconds < 0 || _seconds > 59)
	{
		cout << "You made a mistake! You need to re-enter second's amount." << endl;
		cin >> _seconds;
	}
	seconds = _seconds;
}

int Time::GetHours() const
{
	return hours;
}

int Time::GetMinutes() const
{
	return minutes;
}

int Time::GetSeconds() const
{
	return seconds;
}

void Time::PrintTime() const
{
	if (hours == -1 || minutes == -1 || seconds == -1)
	{
		cout << "You entered the wrong time! It cannot be printed." << endl;
	}
	else
	{
		cout << hours << " hours " << minutes << " minutes " << seconds << " seconds." << endl;
	}
}

void Time::PrintTime(const string& partOfDay) const
{
	if (hours == -1 || minutes == -1 || seconds == -1)
	{
		cout << "You entered the wrong time! It cannot be printed." << endl;
		return;
	}
	int tempHours = hours;
	if (hours > 12)
	{
		tempHours -= 12;
	}
	if (hours < 10)
	{
		cout << "0" << tempHours << ":";
	}
	else
	{
		cout << tempHours << ":";
	}
	if (minutes < 10)
	{
		cout << "0" << minutes << ":";
	}
	else
	{
		cout << minutes << ":";
	}
	if (seconds < 10)
	{
		cout << "0" << seconds << " " << partOfDay << endl;
	}
	else
	{
		cout << seconds << " " << partOfDay << endl;
	}
}

Time Time::operator+(const Time& another) const
{
	Time newTime;
	newTime.hours = hours + another.hours;
	newTime.minutes = minutes + another.minutes;
	newTime.seconds = seconds + another.seconds;
	return newTime;
}

Time Time::operator&(const Time& another) const
{
	Time newTime;
	newTime.hours = hours & another.hours;
	newTime.minutes = minutes & another.minutes;
	newTime.seconds = seconds & another.seconds;
	return newTime;
}

void InputTime(int& hours, int& minutes, int& seconds)
{
	cout << "Input hour's amount (0 - 23):" << endl;
	hours = InputIntValue();
	cout << "Input minute's amount (0 - 59):" << endl;
	minutes = InputIntValue();
	cout << "Input second's amount (0 - 59):" << endl;
	seconds = InputIntValue();
}

int InputIntValue()
{
	bool isCorrectNumber;
	int number;
	do
	{
		cin >> number;
		if (cin.fail())
		{
			cout << "You made a mistake! Please, re-enter the number:" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			isCorrectNumber = false;
		}
		else
		{
			isCorrectNumber = true;
		}
	} while (!isCorrectNumber);
	system("CLS");
	return number;
}
