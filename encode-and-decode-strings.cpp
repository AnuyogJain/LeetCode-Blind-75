#include <bits/stdc++.h>
using namespace std;
 
string encode(vector<string> str) {
	string ans = "";
 
	for (string s: str) {
		ans = ans + to_string(s.size()) + "#" + s;
	}
 
	return ans;
}
 
vector<string> decode(string s) {
	vector<string> ans;
 
	for (int i = 0; i < s.size(); i++) {
		int j = i;
		string temp = "";
		while (j < s.size() && s[j] != '#') {
			temp += s[j];
			j++;
			i++;
		}
		int len = stoi(temp);
		string res = s.substr(i + 1, len);
		ans.push_back(res);
		i += len;
	}
 
	return ans;
}
 
int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<string> str(n);
 
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
 
	string encoded = encode(str);
 
	cout << encoded << endl;
 
	vector<string> decoded = decode(encoded);
 
	for (auto i: decoded)
		cout << i << " ";
	return 0;
}
