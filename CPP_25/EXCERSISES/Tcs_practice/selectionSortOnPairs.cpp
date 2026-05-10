#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >>n;

    vector<pair<int,int>> arr(n);
    for(int i = 0; i< n; i++)
        cin >> arr[i].first >> arr[i].second;

    //---Selection sort-------
    for(int i = 0; i < n-1; i++)
    {
        int minIdx = i;    // assume current pos is minimum

        for (int j = i+1; j< n; j++)
        {
            if(arr[j].first < arr[minIdx].first || (arr[j].first == arr[minIdx].first && arr[j].second < arr[minIdx].second))
                minIdx = j;          // found smaller pair
        }
        swap(arr[i], arr[minIdx]);   // place minimum at position
    }

    for (auto& p : arr)
        cout << p.first << " " << p.second << "\n";
}

