#include <iostream>
using namespace std;

class Time{
	int hour, minute, second;
	void adjustTime()
	{
		if(second >= 60)
		{
			int a = second / 60;
			second %= 60;
			minute += a;
		}
		if(minute >= 60)
		{
			int a = minute / 60;
			second %= 60;
			hour += a;
		}
		if(second < 0)
		{
			minute--;
			second += 60;
		}
		if(minute < 0)
		{
			hour--;
			minute += 60;
		}

	}	
public:
	Time()
	{
		hour = minute = second = 0;
	}
	Time(int h, int m, int s)
	{
		hour = h; minute = m; second = s;
		adjustTime();	
	}
	void display()
	{
		cout << hour << ":";
		if(minute < 10) cout << "0";       
		cout << minute << ":";
		if(second < 10) cout << "0";       
		cout << second << endl;
	}
	Time operator ++()
	{
		second++;
		adjustTime();
		return *this;
	}
	Time operator --()
	{
		second--;
		adjustTime();
		return *this;
	}
	Time operator ++(int)
	{
		second++;
		adjustTime();
		return *this;
	}
	Time operator --(int)
	{
		second--;
		adjustTime();
		return *this;
	}
};

int main()
{
	Time t(5, 8, 58);
	t.display();
	t++, t++, t++, t++;
	t.display();
	t--;
	t.display();
	++t;
	t.display();
	--t, --t, --t, --t, --t;
	t.display();
	return 0;
}
