#ifndef TIME_H
#define TIME_H

class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time() = default;
	Time(int, int, int);
	~Time() = default;
	void SetHours(int);
	void SetMinutes(int);
	void SetSeconds(int);
	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;
	void PrintTime() const;
	void PrintTime(const std::string&) const;
	Time operator+(const Time&) const;
	Time operator&(const Time&) const;
};

void InputTime(int&, int&, int&);
int InputIntValue();

#endif TIME_H
