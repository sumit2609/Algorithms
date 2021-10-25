#include<bits/stdc++.h>
using namespace std;

int knapSack(int w, int wt[], int val[], int n) 
{        
    int dp[n+1][w+1];

   for(int i = 0; i<=n; i++){
       for(int j = 0; j<=w; j++){
           if(i == 0||j == 0)
                dp[i][j] = 0;
       }
    }
       
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=w; j++){
           if(wt[i-1]<=j){
               dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
           }else{
               dp[i][j] = dp[i-1][j];
           }
       }
    }
    return dp[n][w];
}

int main(){
    int n,w;
    //3,4
    cin>>n>>w;

    int val[n];
    int wt[n];

    //1,2,3
    for(int i = 0; i<n; i++)
        cin>>val[i];

    //4,5,1
    for(int i = 0; i<n; i++)
        cin>>wt[i];

    cout<<"maximum profit "<<knapSack(w,wt,val,n);
    
    return 0;
}