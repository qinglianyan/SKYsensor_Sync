#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MIN(a, b) (a<b?a:b)

int coinChange(int* coins, int coinsSize, 
                int amount) {
    int i, j, k;
    int m, n;
    const int cs=coinsSize, am=amount;
    int dp[coinsSize+1][amount+1];
    /**
     * dp[i][j]表示用[0, i]下标的硬币凑足总金额j所需要的最少的硬币个数
     * 对于当前硬币i，如果不用coin[i]，那么dp[i][j]=dp[i-1][j]
     * 如果至少需要一个coin[i]的话，那么dp[i][j]=dp[i][j-coins[i]]+1
     * 所以推导状态转移方程为：
     *  dp[i][j]=MIN( dp[i-1][j], dp[i][j-coins[i]]+1 )
    */
    // memset(dp, -1, sizeof(dp));
    for(i=0;i<=coinsSize;i++){
        for(j=0;j<=amount;j++){
            dp[i][j]=0x3f3f3f3f;
        }
    }
    // printf("0x3f = %d\n", temp);
    // printf("coins0 = %d\ncoins1 = %d\ncoins2 = %d\n", coins[0], coins[1], coins[2]);
    for(i=0;i<=coinsSize;i++){
        dp[i][0]=0;
    }

    // for(i=0;i<=coinsSize;i++){
    //     for(j=0;j<=amount;j++){
    //         printf("%d ", dp[i][j]);
    //     }printf("\n");
    // }
    // 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
    // 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    /**
     * -1说明这里不能用前i个正好凑到总金额
    */
    for(i=1;i<=coinsSize;i++){
        for(j=0;j<=amount;j++){
            for(k=0;k<=j/coins[i-1];k++){
                if(i==3&&j==4){
                    i=3;
                }
                if(dp[i-1][j-k*coins[i-1]]!=0x3f3f3f3f){
                    dp[i][j]=MIN(dp[i][j], dp[i-1][j-k*coins[i-1]]+k);
                }
            }
        }
        // // log
        // printf("--------------\n");
        // for(m=0;m<=coinsSize;m++){
        //     for(n=0;n<=amount;n++){
        //         printf("%d ", dp[m][n]);
        //     }printf("\n");
        // }
    }

    // for(i=1;i<=coinsSize;i++){
    //     // for(j=coins[i-1];j<=amount;j++){
    //     //     if(dp[i][j-coins[i-1]]!=0x3f){
    //     //         dp[i][j]=MIN(dp[i-1][j], dp[i][j-coins[i]]+1);
    //     //     }
    //     //     else{
    //     //         dp[i][j]=dp[i-1][j];
    //     //     }
    //     // }
    //     for(j=0;j<=amount;j++){
    //         if(j>=coins[i-1]&&dp[i][j-coins[i-1]]!=-1){
    //             dp[i][j]=MIN(dp[i-1][j], dp[i][j-coins[i]]+1);
    //         }
    //         else{
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    //     // log
    //     printf("--------------\n");
    //     for(m=0;m<=coinsSize;m++){
    //         for(n=0;n<=amount;n++){
    //             printf("%d ", dp[m][n]);
    //         }printf("\n");
    //     }
    // }
    if(dp[coinsSize][amount]==0x3f3f3f3f){
        return -1;
    }
    return dp[coinsSize][amount];
}

int main(){
    int i, j;
    int out;
    int coinsSize=3;
    int amount=11;
    int *coins=(int *)malloc(sizeof(int)*3);
    coins[0]=1, coins[1]=2, coins[2]=5;

    out=coinChange(coins, coinsSize, amount);
    printf("__out = %d__\n", out);
    return 0;
}