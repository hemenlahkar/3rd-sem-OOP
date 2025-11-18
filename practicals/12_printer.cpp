#include<iostream>
using namespace std;

class Printer{
public:
	virtual void display() const = 0;
	virtual ~Printer() {}
};

class LaserPrinter : public Printer{
	int pages_per_minute;
	string resolution;
	bool duplex;
public:
	LaserPrinter(int p, string r, bool d)
	{
		pages_per_minute = p;
		resolution = r;
		duplex = d;
	}
	void display() const override{
		cout << "Laser Printer Details: \n";
		cout << "Pages per minute: " << pages_per_minute << endl;
		cout << "Resolution: " << resolution << endl;
		cout << "Duplex printing: " << (duplex ? "YES" : "NO") << endl;
	}
};

class LinePrinter : public Printer{
	int line_per_minute;
	int characters_per_line;
public:
	LinePrinter(int l, int c)
	{
		line_per_minute = l;
		characters_per_line = c;
	}
	void display() const override {
		cout << "Line Printer Details:\n";
		cout << "Lines per Minute: " << line_per_minute << endl;
		cout << "Character per Line: " << characters_per_line << endl;
	}
};

class InkjetPrinter : public Printer{
	bool color;
	int cartridgeCount;
	string resolution;
public:
	InkjetPrinter(bool col, int cart, string res)
	{
		color = col;
		cartridgeCount = cart;
		resolution = res;
	}

	void display() const override{
		cout << "Inkjet Printer Details: " << endl;
		cout << "Color Printing: " << (color ? "YES" : "NO") << endl;
		cout << "Cartridge Count: " << cartridgeCount << endl;
		cout << "Resolution: " << resolution << endl;
	}
};

int main()
{
	Printer *printers[] = {
		new LaserPrinter(20, "1200x1200", true),
		new LinePrinter(1000, 80),
		new InkjetPrinter(true, 4, "4800x1200")
	};

	for(int i = 0; i < 3; i++)
	{
		printers[i]->display();
		cout << "----------------------------" << endl;
	}

	for(int i = 0; i < 3; i++)
		delete printers[i];

	return 0;
}
