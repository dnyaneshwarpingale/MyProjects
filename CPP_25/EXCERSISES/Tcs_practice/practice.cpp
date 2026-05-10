#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >>n;

    unordered_map<string, string> mp;

    for (int i = 0; i < n; i++)
    {
        string sender, receiver, amount , timestamp;
        cin >> sender >> receiver >> amount >> timestamp;

        string key = sender + "-" + receiver + "-" + amount;

        auto it  = mp.find(key);
        if(it == mp.end())
        {
            mp[key] = timestamp;

        }else
        {
            if(it->second != timestamp)
            {
                cout << sender << " " << receiver << " " << amount << " " << timestamp << endl;
            }
        }

    }
}



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <pair<int, int>> arr(n);
    vector <pair<int,int>> dhp(n);
    vector <pair<float, float>> deep(n);
    vector <pair<int, int>> ab(n);
    for(int i = 0; i < n; i++ )
        cin >> arr [i].first >> arr[i].second;

    // selection sort
    for(int i = 0; i < n-1; i++)
    {
        int minIdx = i;

        for (int j = i+1; j < n; j++)
        {
            if(arr[j].first < arr[minIdx].first ||
            (arr[j].first == arr[minIdx].first && arr[j].second < arr[minIdx].second)
            )
                minIdx = j;  // found smaller pair
        }
        swap(arr[i], arr[minIdx]);
    }
}

#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
    private:
        vector<int> parent, bysize;
    public:
        DisjointSet(int n)
        {
            parent.resize(n+1);
            bysize.resize(n+1, 1);
            for(int i = 0; i <=n; i++)
                parent[i] =i;
        }

        // ultimate parent node
        int findPar(int n)
        {
            if(n == parent[n])
                return n;
            return parent[n] = findPar(parent[n]);
        }

        bool unionBySize(int u, int v)
        {
            int ult_u = findPar(u);
            int ult_v = findPar(v);

            if(ult_u == ult_v) return false;

            if(bysize[ult_u] <= bysize[ult_v])
            {
                parent [ult_u] = ult_v;
                bysize[ult_v] = bysize[ult_v] + bysize[ult_v]
            }
        }
};

using Edge = pair<int, pair<int,int>>;

int secondBestMST(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end())
    DisjointSet dsu(n);
    int mstCost = 0;
    vector<Edge> mstEdges;
}


int main ()
{
    int N, E;

    cin >> N >> E;

    vector<Edge> edges;
    for( int i = 0; i<E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }

    int result = secondBestMST(N, edges);
}