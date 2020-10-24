#include <iostream>
#include <vector>
#include "SortVector.h"

using namespace std;

void print_array_num(int arr[], int n)
{
    for (int i = 0; i < n; i++) // Decoration
        cout << "---";
    cout << endl;
    for (int i = 0; i < n; i++) // Print the array element by element
        cout << arr[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) // Decoration
        cout << "---";
    cout << endl << endl;
}

void print_array_str(char arr[], int n)
{
    for (int i = 0; i < n; i++) // Decoration
        cout << "---";
    cout << endl;
    for (int i = 0; i < n; i++) // Print the array element by element
        cout << arr[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) // Decoration
        cout << "---";
    cout << endl << endl;
}

void shell_sort_ascending(int arr[], int n)
{
    int d = n;
    d = d/2;
    while (d>0)
    {
        for (int i = 0; i < n-d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] > arr[j+d])
            {
                int count = arr[j];
                arr[j] = arr[j+d];
                arr[j+d] = count;
                j--;
            }
        }
        d = d/2;
    }
}

void shell_sort_descending(int arr[], int n)
{
    int d = n;
    d = d/2;
    while (d>0)
    {
        for (int i = 0; i < n-d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] < arr[j+d])
            {
                int count = arr[j];
                arr[j] = arr[j+d];
                arr[j+d] = count;
                j--;
            }
        }
        d = d/2;
    }
}

void shell_sort_ascending_str(char arr[], int n)
{
    int d = n;
    d = d/2;
    while (d>0)
    {
        for (int i = 0; i < n-d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] > arr[j+d])
            {
                int count = arr[j];
                arr[j] = arr[j+d];
                arr[j+d] = count;
                j--;
            }
        }
        d = d/2;
    }
}

void shell_sort_descending_str(char arr[], int n)
{
    int d = n;
    d = d/2;
    while (d>0)
    {
        for (int i = 0; i < n-d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] < arr[j+d])
            {
                int count = arr[j];
                arr[j] = arr[j+d];
                arr[j+d] = count;
                j--;
            }
        }
        d = d/2;
    }
}
