#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double amount;
    cin >> amount;
    double discount;

    if(amount < 1000)
        discount = 0.05;
    else if(amount < 5000)
        discount = 0.10;
    else
        discount = 0.15; // 15%

    double final = amount*(1-discount);

    cout << fixed << setprecision(2) << final;

    return 0;
}