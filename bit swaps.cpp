#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> v1,vector<int> v2,int n){
	for(int i=0;i<n;i++){
		if(v1[i]+v2[i]==0){
			return 0;
		}
	}
	return 1;
}
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	bool f=0;
	vector<vector<int>> vt(n,vector<int>(n,0));
	vector<bool> b(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j<i){
				vt[i][j]=vt[j][i];
			}else{
			   vt[i][j]=(v[i]&v[j]);	
			}	
		}
		
		vt[i][i]=1;
	}
	
	for(int i=0;i<n && f==0;i++){
		for(int j=i+1;j<n && f==0;j++){
		    if(vt[i][j] && i!=j){
		    	f=check(vt[i],vt[j],n);
			}
		}
	}
	if(f){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}