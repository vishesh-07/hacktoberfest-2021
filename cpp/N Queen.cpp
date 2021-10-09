#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>>&a,int row,int col,int n){
	for(int i=0;i<row;i++){
		if(a[i][col]=='Q'){
			return false;
		}
	}
	int r=row,c=col;
	while(r>=0 && c>=0){
		if(a[r][c]=='Q'){
			return false;
		}
		r--;c--;
	}
	r=row,c=col;
	while(r>=0 && c<n){
		if(a[r][c]=='Q'){
			return false;
		}
		r--;c++;
	}
	return true;
}
bool nQueen(vector<vector<char>>&a,int row,int n){
	if(row>=n){
		return true;
	}
	for(int j=0;j<n;j++){
		if(isSafe(a,row,j,n)){
			a[row][j]='Q';
			if(nQueen(a,row+1,n)==true){
				return true;
			}else{
				a[row][j]='*';
			}
		} 
	}
	return false;
}
int main(){
	int n;
	cout<<"Enter Number of Queens\n";
	cin>>n;
	vector<vector<char>>a(n,vector<char>(n,'*'));
	if(nQueen(a,0,n)==true){
		cout<<"One of the solution of "<<n<<" Queen problem is\n";
		for(auto i:a){
			for(auto j:i){
				cout<<j<<" ";
			}cout<<"\n";
		}	
	}else{
		cout<<"No solution exists\n";
	}
	return 0;
}
