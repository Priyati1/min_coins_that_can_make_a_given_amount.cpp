#include<iostream>
using namespace std;
int min_demo(int *coins,int amount,int n){
	//base case
	if(amount==0){
		return 0;
	}
	//recursive case
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if(amount-coins[i]>=0){
			int chhota_amount=amount-coins[i];
			int chhota_ans=min_demo(coins,chhota_amount,n);
			if(chhota_ans!=INT_MAX && chhota_ans<ans){
				ans=chhota_ans+1;
			}
		}
	}
	return ans;
}

int min_demo_top(int *coins,int amount,int n,int *dp){
	//base case
	if(amount==0){
		return dp[amount]=0;
	}

	if(dp[amount]!=-1){
		return dp[amount];
	}
	//recursive case
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if(amount-coins[i]>=0){
			int chhota_amount=amount-coins[i];
			int chhota_ans=min_demo_top(coins,chhota_amount,n,dp);
			if(chhota_ans!=INT_MAX && chhota_ans<ans){
				ans=chhota_ans+1;
			}
		}
	}
	return dp[amount]=ans;
}

int min_demo_bottom(int *coins,int amount,int n){
	int *dp=new int[n+1];
	for(int i=0;i<=n;i++){
		dp[i]=INT_MAX;
	} 
	dp[0]=0;
	for(int rup=1;rup<=n;rup++){
		for(int i=0;i<n;i++){
			if(rup-coins[i]>=0){
				int chhota_amount=rup-coins[i];
				dp[rup]=min(dp[chhota_amount]+1,dp[rup]);
			}
		}
	}
	for(int i=0;i<=amount;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[amount];
}
int main(){
	int coins[]={1,3,5,10};
	int n=sizeof(coins)/sizeof(int);
	int amount;
	cin>>amount;
	cout<<min_demo(coins,amount,n)<<endl;
	int dp[1000];
	for(int i=0;i<1000;i++){
		dp[i]=-1;
	}
	cout<<min_demo_top(coins,amount,n,dp)<<endl;
	return 0;
}