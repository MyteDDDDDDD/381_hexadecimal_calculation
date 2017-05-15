#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<list>
using namespace std;
string s;
stack<char> a;
stack<char> b;
list<char> l;

void checkOp(char c) {

	if (c == '(') {
		a.push(c);
	}
	else if (c == ')') {
		char cc = a.top();
		while (!cc == '(') {
			l.push_back(cc);
			cc = a.top();
		}
	}
	else  {
		if (a.empty())
			a.push(c);
		else if (c < a.top()) {//c* top+
			a.push(c);
		}
		else {
			l.push_back(a.top());
			a.pop();
			checkOp(c);
		}

	}
	while (!a.empty()) {
		l.push_back(a.top());
		a.pop();
	}
}

int calHex() {
	int sum = 0;
	char cc;
	while (!l.empty()) {
		cc = l.front();
		l.pop_front();
		if (cc == '*' || cc == '+') {
			int d1 = b.top();
			b.pop();
			int d2 = b.top();
			b.pop();
			if (cc == '*')
				sum = d1*d2;
			else
				sum = d1 + d2;
			b.push(sum);
		}
		else {
			b.push(cc);
		}
	}
	int result = b.top();
	b.pop();
	return result;
}
int cal(string s) {
	char c;
	int i = 1;
	l.clear();
	for (int i = 0; i < s.length(); i++) {
		c = s[i];
		char *p;
		
		char n = strtol(s.c_str(), &p, 16);
		checkOp(n);//intfix to post fix


	}
	return calHex();

}

int main() {
	getline(cin, s);
	while (!cin.eof()) {
		cal(s);
		getline(cin, s);
	}
	return 0;
}
