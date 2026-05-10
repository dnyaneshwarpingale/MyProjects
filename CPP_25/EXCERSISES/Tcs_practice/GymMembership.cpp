  #include <iostream>
  using namespace std;

  int main()
  {
    int months;
    cin >> months;

    if (months <= 0 ) 
    {
        cout << "Invalid Input";

    } else if(months <=1)
    {
        cout << "Cost:2000";
    }else if(months <=3)
    {
        cout << "Cost:5000";
    }else if(months <= 6)
    {
        cout << "Cost:9000";
    }else {
        cout << "Cost : 15000";
    }

    return 0;
  }