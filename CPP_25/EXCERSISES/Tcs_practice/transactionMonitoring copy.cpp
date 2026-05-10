#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, string> mp;

    for (int i = 0; i < n; i++)
    {
        string sender, receiver, amount , timestamp;
        cin >> sender >> receiver >> amount >> timestamp;

        string key = sender + "-" + receiver + "-" + amount;

        auto it = mp.find(kdey);
        if(it == mp.end())
        {
            
            mp[key] = timestamp;
        }else
        {
                 if(it->second != timestamp)
               {
                cout << sender << " " <<receiver << " " << amount << " "<< timestamp << endl;
                
               }
        }
        
    }
    return 0;
}