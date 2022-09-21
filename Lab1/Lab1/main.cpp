#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	Time time1;
	int hours;
	int minutes;
	int seconds;
	InputTime(hours, minutes, seconds);
	time1.SetSeconds(seconds);
	time1.SetMinutes(minutes);
	time1.SetHours(hours);
	system("CLS");
	time1.PrintTime();
	system("pause");
	system("CLS");
	InputTime(hours, minutes, seconds);
	system("CLS");
	Time time2(hours, minutes, seconds);
	string partOfDay = "a.m.";
	if (hours > 12)
	{
		partOfDay = "p.m.";
	}
	time2.PrintTime(partOfDay);
	system("pause");
	system("CLS");
	time1.PrintTime();
	cout << endl;
	time2.PrintTime();
	cout << "time3 = ";
	Time time3 = time1 + time2;
	time3.PrintTime();
	system("pause");
	system("CLS");
	Time time4 = time1 & time2;
	time4.PrintTime();
	return 0;
}
