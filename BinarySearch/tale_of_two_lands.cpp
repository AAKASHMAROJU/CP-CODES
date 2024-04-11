// Problem Link: https://codeforces.com/problemset/problem/1166/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n;
  cin>>n;
  vector<ll> v(n);
  for(ll i=0;i<n;i++){
  ll a;
  cin>>a;
  v[i]=abs(a);
  } 
  sort(v.begin(), v.end());

  ll cnt=0;
  for(ll i=0;i<n;i++){
    ll idx=upper_bound(v.begin(), v.end(), 2*v[i])-v.begin();
    cnt+=idx-i-1;
  }
  cout<<cnt<<endl;
  return 0;
}