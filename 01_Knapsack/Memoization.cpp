#include <bits/stdc++.h>

using namespace std;

int knapsack(int profit[], int weight[], int capacity, int size, int** dp){
    if(capacity == 0 || size == 0){    // stopping condiiton for recursion
        return 0;
    }
    if(dp[size][capacity] != -1){      // if already calculated, return its value from array or proceed
      return dp[size][capacity];
    }
    
    else if(weight[size-1] <= capacity){      // return max profit when element is selected or discarded, store value in array for future reference
      return dp[size][capacity] = max(knapsack(profit,weight,capacity,size-1,dp), profit[size-1] + knapsack(profit,weight,capacity - weight[size-1], size-1,dp));
    }
    else{      // discard if the weight is greater than capacity
      return dp[size][capacity] = knapsack(profit,weight,capacity,size-1,dp);
    }
}

int main(){
    int profit[] = {60,100,120};
    int weight[] = {10,20,30};
    int capacity = 50;
    int size = sizeof(profit)/sizeof(profit[0]);
  
    int** dp = new int*[size+1];      
    for(int i = 0; i < size+1;i++){
      dp[i] = new int[capacity+1];
      memset(dp[i],-1, sizeof(int) * (capacity+1));
    }
    
    int max_profit = knapsack(profit,weight,capacity,size,dp);
    cout<<"Maximum profit: "<<max_profit;
  return 0;
}
