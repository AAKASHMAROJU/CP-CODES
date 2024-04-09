// Pretty good Question 
// Problem Link: https://leetcode.com/problems/nth-magical-number/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    
    ll lcm(ll a, ll b){
        return a*b/__gcd(a,b);
    }
    
    bool isPossible(ll res, ll n, ll a, ll b){
        ll cnta=res/a;
        ll cntb=res/b;
        ll common = res/lcm(a,b);
        ll cnt = cnta+cntb-common;
        return cnt>=n;
    }
    
    
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll mod=1e9+7;
        if(__gcd(a,b)==min(a,b)){
            return (min(a,b)*(ll)n)%mod;
        }
        ll ans=-1;
        ll low = min(a,b);
        ll high = min(a,b)*(ll)n;
        while(low<=high){
            ll mid = (high-low)/2+low;
            if(isPossible(mid, n, a, b)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans%mod;
    }
};
int main(){
  int n, a, b;
  cin>>n>>a>>b;
  Solution *s = new Solution();
  cout<< s->nthMagicalNumber(n, a, b)<<endl;
  return 0;
}