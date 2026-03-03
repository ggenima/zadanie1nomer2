#include <iostream>
#include <fstream>
#include "Train.h"
int main()
{
    Train train("Tver", 2, 14);
    Train train1("Moscow", 3, 15);
    train.number = 10;
    train1.number = 10;
    std::cout << train.station << " " << train.number << " " << train.time;
    std::cout << train1.station << " " << train1.number << " " << train1.time;
}

