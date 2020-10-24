#include <iostream>
#include <vector>
#include "SortVector.h"

using namespace std;

int main()
{
    int num_array[] = {73, 90, 36, 60, 21, 75, 76, 33, 80, 51};
    char str_array[] = {'A', 'C', 'M', 'K', 'B', 'P', 'T'};
    
    int str_size = sizeof(str_array)/sizeof(str_array[0]);
    int num_size = sizeof(num_array)/sizeof(num_array[0]);
    
    cout << "Original array:" << endl;
    print_array_num(num_array, num_size);
    
    shell_sort_ascending(num_array, num_size);
    cout << "Ascending sorted array with numbers:" << endl;
    print_array_num(num_array, num_size);

    shell_sort_descending(num_array, num_size);
    cout << "Descending sorted array with numbers:" << endl;
    print_array_num(num_array, num_size);

    shell_sort_ascending_str(str_array, str_size);
    cout << "Ascending sorted array with characters:" << endl;
    print_array_str(str_array, str_size);

    shell_sort_descending_str(str_array, str_size);
    cout << "Descending sorted array with characters:" << endl;
    print_array_str(str_array, str_size);
}