#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //

const int MAXN=-1;

void solve(int i, int f, vector<int> &cortes, vector<vector<int>> &dp){
    if(dp[i][f]!=-1) return;
    else{
        auto lo=upper_bound(cortes.begin(), cortes.end(), i);
        auto hi=upper_bound(cortes.begin(), cortes.end(), f, greater());
        cout<<(lo[0])<<(hi[0])<<endl;
        if(hi-lo>0){
            int res=200'000'000;
            forn(j,hi-lo){
                solve(i, lo[j],cortes,dp);
                solve(lo[j], f,cortes,dp);
                res=min(min(res, dp[i][lo[j]]), dp[lo[j]][f]);
            }
        }
        else dp[i][f]=0;
    }
}

int main() {
    int n,l=1;
    while (1)
    {
        cin>>l;
        if(l==0) break;
        cin>>n;
        vector<int> cortes(n);
        vector<vector<int>> dp(n, vector(n,-1));
        forr(i,0,n) cin>>cortes[i];
        solve(0,l,cortes,dp);
        cout<<dp[0][l]<<'\n';
    }
    
    return 0;
}