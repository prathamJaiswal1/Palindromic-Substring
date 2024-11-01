#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> palindromic(string &s){
    int n=s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    //dp[i][j]->sub(i..j) is palindrome or not
    for(int len=1; len<=n; len++){
        for(int i=0,j=len-1; j<n; i++,j++){
            if(len==1) dp[i][j]=true;
            else if(len==2) dp[i][j]=(s[i]==s[j]);
            else{
                dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
            }
        }
    }
    return dp;
}
int countSubstrings(string s) {
         int oddp=0,evenp=0;
         int n=s.size();
         for(int center=0;center<n;center++){
            //odd length palindrome
               int left=center,right=center;
               while(left>=0 && right<n && s[left]==s[right]){
                    oddp++;
                    left--,right++;
               }
               //even length palindrome
               left=center,right=center+1;
               while(left>=0 && right<n && s[left]==s[right]){
                    evenp++;
                    left--,right++;
               }
         }
         return oddp+evenp;
}
int main(){
    string s;cin>>s;
    cout<<countSubstrings(s)<<endl; // n^2
    return 0;
}