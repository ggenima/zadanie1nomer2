#include <iostream>
#include <fstream>
#include "Train.h"
#include <istream>
#include "sort.h"
#include <algorithm>

void boobleSort(int* arr, int n, bool (*comp)(int&, int&)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comp(arr[j], arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()

{
    ifstream in = ifstream("text.txt");
    if (!in) return 1;
    Train st[4];
    int n = 0; 
    Train h;
    while (in >> h) {
        st[n] = h; n++;
    }
    for (Train m : st)
        cout << m << "\n";
    ofstream of = ofstream("Train.bin");  
    of.write((char*)st, n * sizeof(Train));
    of.close();
    ifstream in1 = ifstream("Train.bin");
    in1.seekg(0, in1.end);
    int dl_fila = in1.tellg();; 
    int nZ = dl_fila / sizeof(Train);
    Train* arr = new Train[nZ];
    in1.seekg(0, 0);
    in1.read((char*)arr, nZ * sizeof(Train)); 
    for (int i = 0; i < nZ; i++)
    {
        cout << arr[i] << "\n";
    }

    qsort(arr, nZ, sizeof(Train), Train::compTime);
    for (int i = 0; i < nZ; i++)
    {
        cout << "sortTime   " << arr[i] << "\n";
    }
    qsort(arr, nZ, sizeof(Train), Train::compNumber);
    for (int i = 0; i < nZ; i++)
    {
        cout << "sortNumber  " << arr[i] << "\n";
    }

    int* numbers = new int[nZ];
    for (int i = 0; i < nZ; i++) {
        numbers[i] = arr[i].number;       
    }
    boobleSort(numbers, nZ, [](int& a, int& b) { return a > b; });
    for (int i = 0; i < nZ; i++)
        cout << numbers[i] << " ";
    cout << endl;
    int Key = 10; //СЮДА ПИСАТЬ НОМЕР ПОЕЗДА ЧТОБЫ ЕГО ПРОГРАММА НАШЛА 
    int index = binarySech(Key, numbers, nZ);
    if (index != -1)
        cout << "nomer " << Key << " nashel "  << "\n" << arr[index] << endl;
        
    else
        cout << "nomer " << Key << " ne nashel" << endl;
    return 0;
}




   // fstream in2 = fstream("Train.bin", ios::binary | ios: in2.read((char*)&Train, sizeof(Train))
    ///*Train train("Tver", 2, 14);
   // Train train1("Moscow", 3, 15);
   // train.number = 10;
   // train1.number = 10;*/
   // std::cout << train.station << " " << train.number << " " << train.time;
   // std::cout << train1.station << " " << train1.number << " " << train1.time;


