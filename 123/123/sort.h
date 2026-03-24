#include <iostream>
#include "Train.h"
#pragma once
int binarySech(int key, int* arr, int n) {
	int left = 0;
	int mid = 0;
	int right = n - 1 ;
    while (left < right) {
        mid = (left + right) / 2;
        if (key < arr[mid])right = mid;
        else if (key > arr[mid])left = mid;
        else return mid;
    }
    return -1;
}
