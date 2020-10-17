#include <iostream>

using namespace std;

int main()
{
    float c, s, d, withdrawal;
    int n;

    cout << "Deposit amount = ";
    cin >> s;
    cout << "Percentage of the deposit = ";
    cin >> d;
    cout << "Number of months in the deposit = ";
    cin >> n;
    cout << "Withdrawal percentage = ";
    cin >> c;
    cout << endl;
    
    withdrawal = (((s*(d/100))*n) + s) * (c/100);
    s = ((s*(d/100))*n) + s;
    cout << "Your bill is " << s << " MDL" << endl;
    cout << "You will get " << withdrawal << " MDL";
}