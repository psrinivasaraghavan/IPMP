#include <bits/stdc++.h>
using namespace std;


int preced(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}


int perf(int a, int b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}


int eval(string tokens){
	int i;
	stack <int> vals;
	stack <char> ops;
	for(i = 0; i < tokens.length(); i++) {
		if(tokens[i] == ' ') continue;
		else if(tokens[i] == '(') ops.push(tokens[i]);
		else if(isdigit(tokens[i])) {
			int val = 0;
			while(i < tokens.length() && isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			vals.push(val);
			i--;
		}
		else if(tokens[i] == ')') {
			while(!ops.empty() && ops.top() != '(')
			{
				int v2 = vals.top();
				vals.pop();
				int v1 = vals.top();
				vals.pop();
				char op = ops.top();
				ops.pop();
				vals.push(perf(v1, v2, op));
			}
			if(!ops.empty())
			ops.pop();
		}
		else {
			while(!ops.empty() && preced(ops.top()) >= preced(tokens[i])){
				int v2 = vals.top();
				vals.pop();
				int v1 = vals.top();
				vals.pop();
				char op = ops.top();
				ops.pop();
				vals.push(perf(v1, v2, op));
			}
			ops.push(tokens[i]);
		}
	}
	while(!ops.empty()){
		int v2 = vals.top();
		vals.pop();	
		int v1 = vals.top();
		vals.pop();	
		char op = ops.top();
		ops.pop();
		vals.push(perf(v1, v2, op));
	}
	return vals.top();
}

int main() {
	cout << eval("10 + 2 * 6") << "\n";
	cout << eval("20 * 2 + 4") << "\n";
	cout << eval("30 * ( 5 + 7 )") << "\n";
	cout << eval("25 * ( 3 + 9 ) / 10");
	return 0;
}