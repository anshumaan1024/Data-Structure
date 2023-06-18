#include<bits/stdc++.h>
using namespace std;

int lexicographicRank( string &str){
	
	int n = str.size();
	
	int count[256] = {0};
	for( int i=0 ; i<n; i++)
		count[str[i]]++;
		
	long fact[26];
	fact[0]=1;
	fact[1]=1;
	for( int i=2; i<26; i++)
		fact[i] = i*fact[i-1];
		
	int smallerLetters;
	int ans =0 ;
	
	for( int i=0; i<n ;i++){
		
		smallerLetters = 0;
		for(int j=0 ; j<256; j++){
			
			if(str[i]==j)
				break;
				
			if( count[j]==1)
				smallerLetters++;
		}
		
		count[str[i]]--;
		ans += smallerLetters * fact[n-1-i];
	}
	
	return ans + 1 ;
	
}

int main(){
	
	string str;
	cin >> str;
	
	cout << lexicographicRank(str);
}