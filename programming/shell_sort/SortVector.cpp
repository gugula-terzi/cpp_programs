#include <iostream>
#include <vector>
#include "SortVector.h"

using namespace std;

void print_array (vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++) // Decoration
        cout << "---";
    cout << endl;
    for (int i = 0; i < arr.size(); i++) // Print the array element by element
        cout << arr[i] << " ";
    cout << endl;
    for (int i = 0; i < arr.size(); i++) // Decoration
        cout << "---";
    cout << endl;
}

int shellSortAscendent(int arr[], int N)
{
    for (int gap = N/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i += 1)
        {
            //sort sub lists created by applying gap
            int temp = arr[i]; int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap]; arr[j] = temp;
        }
    }
    return 0;
}
