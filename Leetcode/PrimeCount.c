//Leetcode 204 计数质数
//给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。

//version1：超时

#include <math.h>
#include <stdbool.h>

bool Isprime(int n){
    if(n==0||n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    for(int i=2;i<n;i++){
    //可优化为for(int i=2;i*i<n;i++),仍旧超时
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int countPrimes(int n){
    int count=0;
    int max=n;
    for(int i=0;i<max;i++){
        if(Isprime(i)){
            count++;
        }
    }
    return count;
}

//verison2：埃氏筛
int countPrimes(int n){
    if(n<=2){
        return 0;
    }else{
        int isPrime[n];
        memset(isPrime,1,sizeof(isPrime));
        int ans=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                ans+=1;
                if((long long )i*i<n){
                    for(int j=i*i;j<n;j+=i){
                        isPrime[j]=0;
                    }
                }
            }
        }
        return ans;
    }
}
