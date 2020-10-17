#include <iostream>

#define ALLOCATE_SIZE 1000

using namespace std;

int input_array(int A[], int max_size)
{
    int top = 0;

    while (true)
    {
        int x;
        cin >> x;

        if (x == 0 || top == max_size) break;
        A[top] = x;
        top++;
    }
    return top;
}

void print_array(int A[], int N)
{
    for(int i = 0; i < N; ++i)
        cout << A[i] << " ";
    cout << "\n";
}

void insertion_sort(int A[], int N)
{
    for(int i = 1; i < N; ++i)
    {
        int old_position = i;
        while(old_position > 0 && A[old_position-1] > A[old_position])
        {
            int tmp = A[old_position-1];
            A[old_position-1] = A[old_position];
            A[old_position] = tmp;
            old_position -= 1; 
        }
    }
}

int main()
{   
    cout << "Enter numbers(at the end enter 0): ";
    int A[ALLOCATE_SIZE];
    int array_size;

    array_size = input_array(A, ALLOCATE_SIZE);
    insertion_sort(A, array_size);
    print_array(A, array_size);
    
    return 0;
}