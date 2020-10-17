#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> // Для использования встроенной функции сортировки sort()

using namespace std;

void print_array (vector<int> arr) // Печатает массив
{
    cout << "Indexes: " << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << setw(4) << i;
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << "----";
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << setw(4) << arr[i];
    cout << endl << endl;
}

int interpolating_search (vector<int> arr, int value_of_search) // Производит поиск методом интерполяции
{
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    
    while (arr[low] < value_of_search && arr[high] >= value_of_search)
    {
        mid = low + ((value_of_search - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        if (arr[mid] < value_of_search)
            low = mid + 1;
        else if (arr[mid] > value_of_search)
            high = mid - 1;
        else
            return mid;
    }
    
    if (arr[low] == value_of_search)
        return low;
    else
        return -1;
}

int main()
{
    vector<int> array;
    array = { 14, 24, 94, 80, 37, 95, 48, 38, 50, 40 };
    int value, result;
    
    cout << "Enter a value of search: ";
    cin >> value;

    sort(array.begin(), array.end());
    print_array(array);

    result = interpolating_search(array, value);
 
    if (result != -1)
        cout << "Value is found in an element with an index " << result << endl;
    else
        cout << "Value is not found" << result << endl;
    return 0;
}
