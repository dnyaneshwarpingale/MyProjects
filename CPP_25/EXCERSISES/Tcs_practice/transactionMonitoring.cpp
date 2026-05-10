#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    set<pair<string,string>> seen; // track (sender, reciever) pairs
    int prevTime = -1;  // No prev transactions

    for (int i =0; i < N; i++)
    {
        string sender , receiver;
        int timestamp, amount;
        cin >> sender >> receiver >> timestamp >> amount;

        //Rule 1 : Duplicate check
        if(seen.count({sender, receiver}))
        {
            cout << "Error:Duplicate Transaction";
            return 0; // terminate
        }

        seen.insert({sender, receiver});

        // Rule 2: Fraud Detection
        if(prevTime != -1 && (timestamp- prevTime >60))
        {
            cout << "Fraud Detected";
            return 0; // Terminate
        }

        prevTime = timestamp; // Update for next iteration
    }
    cout << "All Transaction valid";
    return 0;

}