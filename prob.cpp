#include <bits/stdc++.h>
    #include <iostream>
    // Div 3 prob. D
    using namespace std;
    #define ll long long
    #define mp make_pair
    #define pb push_back
    #define pll pair<long long,long long>
    #define pii pair<ll,ll>
    #define X first
    #define Y second
    #define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define endl '\n'
     const ll mod=1000000007;

int main()
{    fast;
	ll t,k,a,b;
	cin>>t>>k;
	ll dp[100001][2],sum[100001];  //0-red 1-white
	for(ll i=0;i<=100000;i++)
		{dp[i][0]=0;dp[i][1]=0;sum[i]=0;}
	dp[0][0]=1;dp[0][1]=1;
	if(k==1){dp[1][0]=1;dp[1][1]=1;}
	else dp[1][0]=1;
	sum[1]=dp[1][0]+dp[1][1];
	//cout<<sum[1]<<endl;
	for(ll i=2;i<=100000;i++)
	{
      dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
     if(i-k>0)
      dp[i][1]=(dp[i-k][1]+dp[i-k][0])%mod;
     else if(i-k==0)
     	dp[i][1]=(dp[i][1]+dp[i-k][1])%mod;
     
    sum[i]=(sum[i-1]+dp[i][0]+dp[i][1])%mod;
   // cout<<sum[i]<<endl;
   // if(i>=4)break;
    }

	while(t--)
	{
		cin>>a>>b;
		cout<<((sum[b]%mod-sum[a-1]%mod)+mod)%mod<<endl;
	//cout<<dp[3][0]+dp[3][1]<<","<<dp[4][0]+dp[4][1]<<endl;
	}
	return 0;
}