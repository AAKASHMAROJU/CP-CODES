
// Problem Link: codeforces.com/problemset/problem/702/C

#include<bits/stdc++.h>
using namespace std;
 



#define ll long long
 
int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> cities(n);
    vector<ll> towers(m);
    for(ll i=0;i<n;i++) cin>>cities[i];
    for(ll i=0;i<m;i++) cin>>towers[i];
    // for each city find out the nearest tower
    ll maxi=-1;
    for(ll i=0;i<n;i++){
        // for each city get the mindist 
        ll dist=LLONG_MAX;
        ll idx = lower_bound(towers.begin(), towers.end(), cities[i])-towers.begin();
        // cout<<idx<<endl;
        if(idx==m){
            // cout<<"Entered"<<endl;
          dist=min(dist, abs(cities[i]-towers[m-1]));
        }
        else{
          dist=min({dist,abs(cities[i]-towers[idx-1]), abs(cities[i]-towers[idx])});
        }
        // cout<<dist<<endl;
        maxi=max(dist, maxi);
    }
 
    cout<<maxi<<endl;
    return 0;
}