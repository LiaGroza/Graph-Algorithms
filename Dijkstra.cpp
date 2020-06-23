#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;


int main(int argc, char * argv[])
{
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);

    vector<pair<int,int>> V[10001];
    int n,m,s;
    int d[10001]={ 0 };
    bool viz[10001] = { 0 };
    fin>>n>>m>>s;
    for (int i=0;i<m;i++)
    {
        int x,y,z;
        fin>>x>>y>>z;
        V[x].push_back({-z,y});
    }

    priority_queue<pair<int,int>> Q;
    Q.push({0,s});

    const int inf = 1e9;

    for (int i = 0; i<n; i++)
    {
        if(i!=s)
        {
            d[i]=-inf;
            Q.push({d[i],i});
        }
    }

    while(!Q.empty())
    {
        if(!viz[Q.top().second])
        {
            int nod = Q.top().second;
            for(auto i:V[nod])
            {
                if (i.first + d[nod] > d[i.second])
                {
                    Q.push({i.first + d[nod],i.second});
                    d[i.second] = i.first + d[nod];

                }
            }
            viz[nod]=1;
        }
        else
            Q.pop();
    }

    for (int i = 0; i < n; i++)
    {
        if(d[i]==-inf)
            fout<<"INF ";
        else
            fout<<-d[i]<<" ";
    }

    fin.close();
    fout.close();
    return 0;
}
