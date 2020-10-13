#include <bits/stdc++.h>
using namespace std;

ifstream fin("date.in");
const int oo=2e9;
int n,m, cost[20][20], dp[(1<<18)+5][20], tata[(1<<18)+5][20];

void Build()
{
    int Smax;
    Smax=(1<<n)-1;
    for(int stare=0; stare<=Smax; stare++)
        for(int i=0; i<n; i++) {
            dp[stare][i]=oo;
            tata[stare][i] = -1;
        }
    dp[1][0]=0;

    for(int stare=1; stare<=Smax; stare++)
        for(int i=0; i<n; i++)
            if(dp[stare][i]!=oo)
                for(int j=0; j<n; j++)
                    if(cost[i][j] && !((1<<j) & stare))
                        if(dp[(1<<j) + stare][j] > dp[stare][i]+cost[i][j]) {
                            dp[(1<<j) + stare][j] = dp[stare][i]+cost[i][j];
                            tata[(1<<j) + stare][j] = i;
                        }

    int sol=oo;
    int final_index = -1;
    for(int i=1; i<n; i++)
        if(cost[i][0] && dp[Smax][i] + cost[i][0] < sol) {
        	sol = dp[Smax][i];
            final_index = i;
            // sol=min(sol,dp[Smax][i]+cost[i][0]);
        }

    if(sol==oo)
        cout<<"Nu exista solutie";
    else
    {
        int masca = Smax;
     cout<<1<<" ";
    while (final_index != -1) {
    	cout << final_index+1 << " ";
        int masca_nou = masca - (1<<final_index);
        final_index = tata[masca][final_index];
        masca = masca_nou;
    }
    cout << "\n";
    }


}

int main()
{
    fin>>n;
    int x,y,c;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fin>>cost[i][j];

    Build();
    fin.close();
    return 0;
}
