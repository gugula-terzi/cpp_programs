#include <iostream>

using namespace std;


int increment(long inc[], long size) {
  int p1, p2, p3, s;

  p1 = p2 = p3 = 1;
  s = -1;
  do {
    if (++s % 2) {
      inc[s] = 8*p1 - 6*p2 + 1;
    } else {
      inc[s] = 9*p1 - 9*p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
	p1 *= 2;
  } while(3*inc[s] < size);  

  return s > 0 ? --s : 0;
}

template<class T>
void shellSort(T a[], long size) {
  long inc, i, j, seq[40];
  int s;

  // вычисление последовательности приращений
  s = increment(seq, size);
  while (s >= 0) {
	// сортировка вставками с инкрементами inc[] 
	inc = seq[s--];

    for (i = inc; i < size; i++) {
      T temp = a[i];
      for (j = i-inc; (j >= 0) && (a[j] > temp); j -= inc)
        a[j+inc] = a[j];
      a[j+inc] = temp;
    }
  }
}

/*
// Алгоритм shellsort по возрастанию
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


// Алгоритм shellsort по убыванию
int shellSortDescendent(int arr[], int N)
{
    for (int gap = N/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i += 1)
        {
            //sort sub lists created by applying gap
            int temp = arr[i]; 
            int j;

            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
            arr[j] = arr[j - gap]; arr[j] = temp;
        }
    }
    return 0;
}

// Главная функция
int main(){
    // Массив Элементов которые необходимо отсортировать
    int arr[] = {45,23,53,43,18,24,8,95,101}, i;
    
    // Расчитываем размер массива
    int N = sizeof(arr)/sizeof(arr[0]);
    cout << "Array that must be sorted: \n\t";
    for (int i=0; i<N; i++)
        cout << arr[i] << " ";
    shellSortAscendent(arr, N);

    cout << "\nAscending sorted array: \n\t";
    for (int i=0; i<N; i++)
        cout << arr[i] << " ";
    shellSortDescendent(arr, N);

    cout << "\nDescending sorted array: \n\t";
    for (int i=0; i<N; i++)
        cout << arr[i] << " ";
    return 0;
}
*/