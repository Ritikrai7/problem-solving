
#include <bits/stdc++.h>
using namespace std;
int longestSubstring( string s){
 unordered_map<char,int>hash;
    int l=0;
    int r=0;
    int maxLen=0;
    int n=s.size();
    while(r<n){
        if(hash.count(s[r]) && hash[s[r]]>=l){
            l=hash[s[r]]+1;
        }
        int len=r-l+1;
        maxLen=max(len,maxLen);
        hash[s[r]]=r;
        r++;
    }
    return maxLen;
}
int main(){
    string s="abcabcbb";
    cout<<longestSubstring(s)<<endl;;
}