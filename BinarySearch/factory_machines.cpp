// Problem Link: https://cses.fi/problemset/submit/1620/

#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

bool isPossible(ull curr_time, vector<ull>& v, ull t){
  ull tasks_can_be_done = 0;
  for(ull i=0;i<v.size();i++){
    tasks_can_be_done+=curr_time/v[i];
    if (tasks_can_be_done>=t)
    {
      return true;
    }
    
  }
  return tasks_can_be_done>=t;
}

int main(){
  ull n, t;
  cin>>n>>t; // n machines and t tasks 
  vector<ull> v(n);
  for(ull i=0;i<n;i++ ) cin>>v[i];
  ull low=*min_element(v.begin(), v.end());
  ull high = (ull)pow(10,18)+1;
  ull ans=0;
  while(low<=high){
    ull mid=(high-low)/2+low;
    if(isPossible(mid, v, t)){
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