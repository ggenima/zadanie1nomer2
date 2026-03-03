#include "Train.h"
#include <string.h>
Train::Train() {}
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
