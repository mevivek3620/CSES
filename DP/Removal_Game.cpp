#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define ll long long
#define M 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define pii pair< int,int >
#define pll pair< ll,ll >
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define vii vector<pii>
#define vll vector<pll>
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define endc "\n"
#define MAX 100003
#define N 10003

using namespace std;

vi prime;
// int ans[N];
// unordered_set<ll>ans;
// prime numbers till n
void prime_numbers(int n) 
{
    vector<bool>primes(n+1,true);
    f(i,2,n+1)
    {
        if(primes[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                primes[j] = false;
            }
        }
    }
    f(i,2,n+1){
        if(primes[i])prime.pb(i);
    }
}

//calculate smallest prime factor for every number
vi spf(MAX);
void find_spf()
{
    // make every number's spf equal to itself
    f(i,1,MAX)spf[i] = i;

    //make even number's spf to 2
    for(int i=2;i<=MAX;i+=2){
        spf[i] = 2;
    }

    for(int i=3;i<=MAX;i+=2)
    {
        //check if i is prime
        if(spf[i] == i)
        {
            for(int j=i*i;j<=MAX;j+=i)
            {
                if(spf[j] == j)spf[j] = i;
            }
        }
    }
    
}

// int dp[100005][1003];

// int helper(int p[],int pages[],int x,int n){
//     if(x == 0 )return 0;
//     if(n == 0)return 0;

//     if(dp[x][n] != -1)return dp[x][n];

//     if(p[n-1] <= x)return dp[x][n] = max(pages[n-1] + helper(p,pages,x - p[n-1],n-1), helper(p,pages,x,n-1));
//     return dp[x][n] = helper(p,pages,x,n-1);

// }

// int helper(vi &a,int i,int n,int m){
    
//     if(i == n){
//         return 1;
//     }

//     if(a[i] == 0){
//         if(i - 1 >= 0){
//             int ans = 0;
//             a[i] = a[i-1] + 1;
//             if(a[i] <= m)ans += helper(a,i+1,n,m)%M;
//             a[i] = a[i-1] - 1;
//             if(a[i] != 0 )ans += helper(a,i+1,n,m)%M;
//             a[i] = a[i-1];
//             ans += helper(a,i+1,n,m)%M;
//             a[i] = 0;
//             return ans;
//         }
//         else{
//             int ans = 0;
//             f(j,1,m+1){
//                 a[i] = j;
//                 ans += helper(a,i+1,n,m)%M;
//             }
//             a[i] = 0;
//             return ans;
//         }
//     }
//     else{
//         if(i - 1 >= 0 && abs(a[i-1] - a[i]) > 1)return 0;
//         return helper(a,i+1,n,m);
//     }
// }

// int helper(int n,int m){
//     if(n == m )return 0;
//     if(n == 1)return m - 1;
//     if(m == 1)return n - 1;

//     if(dp[n][m] != -1)return dp[n][m];
//     int temp = n*m;
//     for(int i = 1;i < n;i++){
//         temp = min(temp,1 + helper(i,m) + helper(n - i,m));
//     }
//     for(int j = 1;j < m;j++){
//         temp = min(temp,1 + helper(n,j) + helper(n ,m - j));
//     }
//     return dp[n][m] = temp;
// }
// void helper(vi& x,int sum,int i,int n){
//     if(i == n){
//         if(sum != 0)s.insert(sum);
//         return;
//     }

//     helper(x,sum + x[i],i+1,n);
//     helper(x,sum,i+1,n);
// }

// void helper(vl &x,ll sum,ll& ans,int i,int j,int turn){
//     if(i > j){
//         ans = max(ans,sum);
//         return;
//     }

//     if(turn == 0){
//         helper(x,sum + x[i],ans,i+1,j,(turn^1));
//         helper(x,sum + x[j],ans,i,j - 1,(turn^1));
//     }
//     else{
//         helper(x,sum,ans,i+1,j,(turn^1));
//         helper(x,sum,ans,i,j-1,(turn^1));
//     }
// }

void solve(){
    int n;cin>>n;
    vl a(n);
    f(i,0,n)cin>>a[i];
    
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));

    for(int len = 1; len <= n; len++){
        for(int i = 0;i +len <= n;i++){
            int j = i + len - 1;
            ll x = (i + 2 <= j) ? dp[i+2][j] : 0;
            ll y = (i + 1 <= j-1) ? dp[i+1][j-1] : 0;
            ll z = (i <= j-2) ? dp[i][j-2] : 0;

            dp[i][j] = max(a[i] + min(x,y), a[j] + min(y,z));
        }
    }

    cout<<dp[0][n-1]<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--){
        solve();
    }
    
    return 0;
}