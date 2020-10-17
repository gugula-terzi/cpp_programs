#include <iostream>
#include <iomanip>

using namespace std; 

float percent = 0.2;

void crop_loss() // Начиная с какого года, будет собрано менее 5 тонн?
{   
    float weight = 20;
    float total = 20;
    int year = 1990;

    while (weight >= 1)
    {   
        cout << "In " << year << " harvest will be " << setprecision(3) << weight << " tons" << endl;
        weight = weight - (weight*percent);
        year += 2;
    }
    
}

void surplus_harvest() // В каком году суммарный урожай яблок превысит 90 тонн?
{    
    float weight = 20;
    float total = 20;
    int year = 1990;
    
    while (total <= 99)
    {
        cout << "In " << year << " harvest will be " << setprecision(3) << total << " tons" << endl;
        year += 2;
        weight = weight - (weight*percent);
        total += weight;
    }
    
}

int main()
{
    crop_loss();
    cout << endl;
    surplus_harvest();
}
