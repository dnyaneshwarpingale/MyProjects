#include<bits/stdc++.h>
using namespace std;
  
class DisjointSet 
{
    private:
        vector<int> parent , bysize;

    public:
        DisjointSet(int n) 
        {
            parent.resize(n+1);
            bysize.resize(n+1, 1);
            for(int i = 0; i <=n; i++)
                parent[i] = i;
        }

        // ultimate parent code
        int findPar(int n)
        {
            if (n == parent[n]) return n;
            return parent[n] = findPar(parent[n]);
        }

        bool unionBySize(int u, int v)
        {
            int ult_u = findPar(u);
            int ult_v = findPar(v);

            if(ult_u == ult_v) return false;

            if (bysize[ult_u] <= bysize[ult_v])
            {
                parent [ult_u] = ult_v;
                bysize[ult_v] += bysize[ult_v];
            }
            else
            {
                parent[ult_v] = ult_v;
                bysize[ult_u] += bysize[ult_v];
            }
            return true;
        }
        int getSize(int u) 
        {
            return bysize[findPar(u)];
        }

};

// Edge = (weight, {u, v})

using Edge = pair<int, pair<int, int>>;

// kruskal while skipping one edge
int kruskalSkipping(int n, vector<Edge>& edges, int skipU, int skipV)
{
    DisjointSet dsu(n);
    int cost = 0, used =0;

    for (auto& e : edges)
    {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if((u == skipU && v == skipV) || (u == skipV && v == skipU))
            continue;
        
            if(dsu.unionBySize(u,v)) 
            {
                cost = cost + w;
                used ++; 
            }

    }
    return (used == n-1) ? cost : INT_MAX;
}

int secondBestMST(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    DisjointSet dsu(n);
    int mstCost = 0;
    vector<Edge> mstEdges;

    // Build MST
    for (auto& e : edges)
    {
        int u = e.second.first;
        int v = e.second.second;

        if( dsu.unionBySize(u,v))
        {
            mstCost = mstCost + e.first;
            mstEdges.push_back(e);
        }
    }
    
    int secondBest = INT_MAX;
    
    // try removing each MST edges
    for ( auto& e : mstEdges)
    {
        int u = e.second.first;
        int v = e.second.second;

        int newCost = kruskalSkipping(n, edges, u, v);
        if(newCost > mstCost)
            secondBest  = min(secondBest, newCost);
    }

    return (secondBest = INT_MAX) ? -1 : secondBest; 
}

int main()
{
    int N, E;

    cin >> N >> E;
    vector<Edge> edges;

    for(int i = 0; i< E; i++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u,v}});

    }

    int result = secondBestMST(N, edges);

    if(result == -1)
        cout << "No Second best MST exists\n";
    else
         cout << "Second Best MST cost:" << result << endl;

    return 0;

}