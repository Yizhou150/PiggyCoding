#include<iostream>

using namespace std;

int main(){
	int N,M,tmp;
	cin>>N>>M;
	if(N>M){
		tmp=N;
		N=M;
		M=tmp;
	}
	int diff = M-N;
	for(int i=N+1;i<=N+1+diff;i++){
		cout<<i<<endl;
	} 
}