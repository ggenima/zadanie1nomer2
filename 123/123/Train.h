
#pragma once
class Train
{
public:
	char station[10];
	int number;
	int time;
	Train();
	Train(char* station, int number, int time);
	Train(const char* station, int number, int time);
};