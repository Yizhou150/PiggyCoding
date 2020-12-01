#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
typedef unsigned long long ll;
set<ll> d_numbers;


int main(){
	for(int i=1;i<=63;i++){
		for(int j=0;j<=63;j++){
			for(int len=1;len<=64;len++){
				if (len % (i+j) == 0 || len % (i+j) == i){
					int cur_len = 0;
					ll cur_d_number = 0;
					bool is_1 = true;
					while(cur_len <= len){
						if (is_1) {
							cur_d_number <<= i;
							cur_d_number += (1LL<<i) -1;
							cur_len += i;
							is_1 = false;
						} else{
							cur_d_number <<= j;
							cur_len += j;
							is_1 = true;
						}
					}
					d_numbers.insert(cur_d_number);
				}
			}
		}
	}
	ll X,Y;
	cin>>X>>Y;
	ll res=0;
	for(auto k:d_numbers){
		if(k>=X && k <=Y)
			res++;
	}
	cout<<res<<endl;
}