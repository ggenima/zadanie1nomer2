
#pragma once
#include <fstream>
using namespace std;
class Train
{
public:
	char station[10];
	int number;
	int time;
	Train();
	Train(char* station, int number, int time);
	Train(const char* station, int number, int time);
	~Train();
	bool operator >(const Train& b);
	Train& operator = (const Train& b);
	friend ostream& operator<<(ostream& os, const Train& m) {
		return os << m.station << " " << m.number << " " << m.time;
	}
	friend istream& operator>>(istream& os, Train& m) {
		return os >> m.station >> m.number >> m.time;
	}
};