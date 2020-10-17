#include <iostream>

using namespace std;

int main()
{
    int population;
    float birth_rate, death_rate, death_and_birth_ratio;
    
    cout << "Enter percentage of birth rate: ";
    cin>> birth_rate;
    cout<<"Enter percentage of death rate: ";
    cin >> death_rate;
    death_and_birth_ratio = birth_rate - death_rate;
    cout << "Ratio of mortality to birth rate = " << death_and_birth_ratio << endl;
}