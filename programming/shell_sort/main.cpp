#include <iostream>
#include <vector>
#include "SortVector.h"

using namespace std;

int main()
{
    int array[] = {73, 90, 36, 60, 21, 75, 76, 33, 80, 51};
    int size = sizeof(array)/sizeof(array[0]);
    //cout << "\nOriginal array: " << endl;
    //print_array(array);
    
    shellSortAscendent(array, size);

    cout << "\nSorted array: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}