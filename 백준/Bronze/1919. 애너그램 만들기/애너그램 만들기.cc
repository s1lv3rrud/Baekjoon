#include <bits/stdc++.h>

using namespace std;

int main(int argc, char**argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v1(26);
	vector<int> v2(26);
	string s1, s2;
	int res=0;
	
	cin >> s1 >> s2;
	
	for(int i=0; i<s1.size(); i++)
		v1[s1.at(i)-'a']++;
	
	for(int i=0; i<s2.size(); i++)
		v2[s2.at(i)-'a']++;
	
	for(int i=0; i<26; i++)
		res+=abs(v1[i]-v2[i]);

	cout << res;
	 
	return 0;
}