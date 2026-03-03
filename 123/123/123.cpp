#include <iostream>
#include <fstream>
#include "Train.h"
int main()
{
    ifstream in = ifstream("text.txt");
    if (!in) return 1;
    Train st[4];
    int n = 0; 
    while (in >> st[n])n++;
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
   // fstream in2 = fstream("Train.bin", ios::binary | ios: in2.read((char*)&Train, sizeof(Train))
   
    
    
    
    ///*Train train("Tver", 2, 14);
   // Train train1("Moscow", 3, 15);
   // train.number = 10;
   // train1.number = 10;*/
   // std::cout << train.station << " " << train.number << " " << train.time;
   // std::cout << train1.station << " " << train1.number << " " << train1.time;
}

