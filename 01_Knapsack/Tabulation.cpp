#include <bits/stdc++.h>

using namespace std;

int knapsack(int profit[],int weight[], int capacity, int size){
    int dp[size+1][capacity+1];      // declaring array to store values
    for(int i = 0; i < size+1; i++){
      for(int j = 0 ;j < capacity+1; j++){
          if(i == 0 || j == 0){      // initializing array
            dp[i][j] = 0;
          }
          else if(weight[i-1] <= j){
              dp[i][j] = max(dp[i-1][j], profit[i-1] + dp[i-1][j - weight[i-1]]);    // choose the max profit after selecting or discarding the current element
          }
          else{
              dp[i][j] = dp[i-1][j];    // discarding the element if weighs greater than current capacity
          }
      }
    }
    return dp[size][capacity];      // final profit
}

int main(){
    int profit[] = {60,100,120};
    int weight[] = {10,20,30};
    int capacity = 50;
    int size = sizeof(profit)/sizeof(profit[0]);
    
    int max_profit = knapsack(profit,weight,capacity,size);
    cout<<"Maximum profit: "<<max_profit;

  return 0;
}
