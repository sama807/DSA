#include<iostream>
#include "Stack.h"
#include <math.h>
using namespace std;

int prefixEvaluation(string str) {

	Stack<int> s;
	int op1, op2;
	char ch;

	for (int i = str.length() - 1; i >= 0; i--) {

		//check that it's operator or not
		if (str[i] >= '0' && str[i] <= '9') {

			s.push(str[i]- '0');

		}
		else {

			op1 = s.stackTop();
			s.pop();
			op2 = s.stackTop();
			s.pop();

			switch (str[i]) {

				case '+':
					s.push(op1 + op2);
					break;

				case '-':
					s.push(op1 - op2);
					break;

				case '*':
					s.push(op1 * op2);
					break;

				case '/':
					s.push(op1 / op2);
					break;

				case '^':
					s.push(pow(op1,op2));
					break;


			}
			
		}
	}
	return s.stackTop();
}

int postfixEvaluation(string str) {

	Stack<int> s;
	int op1, op2;

	for (int i =0 ; i < str.length(); i++) {

		//check that it's operator or not
		if (str[i] >= '0' && str[i] <= '9') {

			s.push(str[i] - '0');

		}
		else {

			op1 = s.stackTop();
			s.pop();
			op2 = s.stackTop();
			s.pop();

			switch (str[i]) {

			case '+':
				s.push(op1 + op2);
				break;

			case '-':
				s.push(op1 - op2);
				break;

			case '*':
				s.push(op1 * op2);
				break;

			case '/':
				s.push(op2 / op1);
				break;

			case '^':
				s.push(pow(op1, op2));
				break;


			}

		}
	}
	return s.stackTop();

}
int main() {

	string s = "-+7*45+20";
	cout << prefixEvaluation(s);

	cout << endl;
	string s2 = "46+2/5*7+";
	cout << postfixEvaluation(s2);



}