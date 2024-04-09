// Problem link https://cses.fi/problemset/task/2422

#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isPossibleMedian(ll num, ll n){
  ll cnt=0;
  for(ll i=1;i<=n;i++){
    cnt+=min(n,num/i);
  }
  return cnt>=n*n/2+1;
}

int main(){
  ll n;
  cin>>n;
  // n is odd 
  ll low=1;
  ll high=n*n;
  ll ans=-1;
  while(low<=high){
    ll mid = (low+high)/2;
    // mid might be the median ... and rows are already sorted 
    if(isPossibleMedian(mid, n)){
      ans=mid;
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  cout<<ans<<endl;
  return 0;
}
