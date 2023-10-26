#include<iostream>
using namespace std;
#include "Stack.h";

int precedence(char ch) {

	if (ch == '^') {
		return 3;
	}
	else if (ch == '*' || ch == '/') {
		return 2;
	}
	else if (ch == '+' || ch == '-') {
		return 1;
	}
	else
		return -1;
		
}
string infixToPostfix(string s) {

	Stack<int> st;
	string result;
	for (int i = 0; i < s.length(); i++) {

		//if operand then print
		if (s[i] >= 'a' && s[i] <= 'z'){
			result += s[i];
		}

		//if opening bracket then push
		else if (s[i] == '(') {
			st.push('(');
		}

		//if closing bracket pop until closing bracket is found
		else if (s[i] == ')') {
			while (st.stackTop() != '(' && !st.isEmpty()) {
				result += st.stackTop();
				st.pop();

			}
			//also pop the opening bracket
			if (!st.isEmpty()) {
				st.pop();
			}
		}
		else {
			while(!st.isEmpty() && precedence(st.stackTop()) > precedence(s[i])){
				result += st.stackTop();
				st.pop();
				
			}
			st.push(s[i]);
		}

		
		}
	while (!st.isEmpty()) {
		result += st.stackTop();
		st.pop();
	}
	return result;
}
string reverseString(string s) {

	string rs(s.length(), ' ');
	int j = 0;
	//reverse(s.begin(), s.end());
	for (int i = s.length(); i > 0; i--) {
		rs[j] = s[i-1];
		j++;
	}
	return rs;
}
string infixToPrefix(string s) {

	string rs = reverseString(s);
	for (int i = 0; i < rs.length(); i++) {
		if (rs[i] == '(') {
			rs[i] = ')';
		}
		else 
			if (rs[i] == ')') {
				rs[i] = '(';
			}
	}
	string result= infixToPostfix(rs);
	string itp = reverseString(result);
	return itp;
}

int main() {

	string s = "(a-b/c)*(a/k-l)";
	cout << "Postfix expression \n";
	cout<< infixToPostfix(s);
	cout << endl;

	cout << "Prefix expression \n";
	cout << infixToPrefix(s);

}