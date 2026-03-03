#include "Train.h"
#include <iostream>
#include <string.h>
Train::Train() {
	std::cout << "structor\n";
}
Train::Train(char* station, int number, int time) {
	strcpy_s(this->station, 10, station);
	this->number = number;
	this->time = time;
}
Train::Train(const char* station, int number, int time) {
	strcpy_s(this->station, 10, station);
	this->number = number;
	this->time = time;
}
Train::~Train()
{
	std::cout << "destructor\n";
}
bool Train::operator>(const Train& b)
{
	return strcmp(this->station, b.station) > 0;

}


Train& Train::operator = (const Train& b)
{
	strcpy_s(this->station, b.station);
	this->number = b.number;
	this->time = b.time;
	return  *this;
}