#include <bits/stdc++.h>
    #include <iostream>
    // Div 3 prob. D
    using namespace std;
    #define ll long long
    #define mp make_pair
    #define pb push_back
    #define pll pair<long long,long long>
    #define pii pair<int,int>
    #define X first
    #define Y second
    #define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define endl '\n'
  bool f=false,fup=false; 
  const ll N=(1<<17)+10;
        ll arr[N];
        ll segtree[6*N];ll n;
void build(ll i,ll j,ll index,ll level)
{
    if(i==j){
        segtree[index]=arr[i];
        return;
    }
    ll mid=(i+j)>>1;
    build(i,mid,2*index+1,level-1);
    build(mid+1,j,2*index+2,level-1);
    if(level%2==0)
   segtree[index]=segtree[2*index+1] ^ segtree[2*index+2];
  else
  segtree[index]=segtree[2*index+1] | segtree[2*index+2];
   return;
}
void update(ll n,ll i,ll j,ll index,ll value,ll level)
{ 
  if(i == j)
  {
    segtree[n]=value;
    return;
  }
  ll mid=(i+j)>>1;
  if(mid>=index)

    update(2*n+1,i,mid,index,value,level-1);
 else
   update(2*n+2,mid+1,j,index,value,level-1);
   if(level%2==0)
  segtree[n]=segtree[2*n + 1] ^ segtree[2*n+2];
else
segtree[n]=segtree[2*n+1] | segtree[2*n+2];
  return;
}
    int main()
    {
        fast;
        ll m;
        cin>>n>>m;
        
        for(ll i=0;i<(1<<n);i++)
            cin>>arr[i];
        build(0,(1<<n)-1,0,n);
      //  for(int i=0;i<16;++i)
        //    cout<<segtree[i]<<endl;
        while(m--)
        {
            ll p,b;
            cin>>p>>b;
            update(0,0,(1<<n)-1,p-1,b,n);
            //fup=false;
            cout<<segtree[0]<<endl;
        }
        return 0;
    }