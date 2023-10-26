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
		s.push(op1 / op2);
		break;

	case '^':
		s.push(pow(op1, op2));
		break;


	}

}
	}
	return s.stackTop();
}

int postfixEvaluation(string str) {

	Stack<int> s;
	int op1, op2;

	for (int i = 0; i < str.length(); i++) {

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
int evaluate(int op1, int op2, char ch) {

	char output= ' ';
	switch (ch) {

	case '+':
		output = op1 + op2;
		break;

	case '-':
		output= (op1 - op2);
		break;

	case '*':
		output = (op1 * op2);
		break;

	case '/':
		output= (op2 / op1);
		break;

	case '^':
		output = (pow(op1, op2));
		break;


	}
	return output;
}

bool isDigit(char ch) {

	if (ch >= '0' && ch <= '9') {
		
		return true;
	}
	return false;
}
int infixEvaluation(string str) {

	Stack<int>oprndSt;
	Stack<int>oprtrSt;
	int op1, op2;
	string newStr="";
	int result = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (isDigit(str[i])){

			int num = 0;
			//check if more than two digits
			while ( isDigit(str[i]) && i<str.length()) {

				num = num * 10 + (str[i] - '0');
				i++;
			}
			
			i--;
			oprndSt.push(num);
			
		}
		
		else if (str[i] == '(') {

			oprtrSt.push(str[i]);
		}

		else if (str[i] == ')') {

			while (oprtrSt.stackTop() != '(') {

				op1 = oprndSt.stackTop();
				oprndSt.pop();
				op2 = oprndSt.stackTop();
				oprndSt.pop();

				char ch = oprtrSt.stackTop();
				oprtrSt.pop();

				int r = evaluate(op1, op2, ch);
				oprndSt.push(r);


			}
			
			oprtrSt.pop();
		}
		else {

			if (oprtrSt.isEmpty()) {

				oprtrSt.push(str[i]);
			}
			else if (precedence(str[i]) < precedence(oprtrSt.stackTop())) {

					op1 = oprndSt.stackTop();
					oprndSt.pop();
					op2 = oprndSt.stackTop();
					oprndSt.pop();

					char ch = oprtrSt.stackTop();
					oprtrSt.pop();

					int r = evaluate(op1, op2, ch);
					oprndSt.push(r);


					oprtrSt.push(str[i]);
			}

			else {

				oprtrSt.push(str[i]);

			}
			


		}
	}
	while (!oprtrSt.isEmpty()) {

		op1 = oprndSt.stackTop();
		oprndSt.pop();
		op2 = oprndSt.stackTop();
		oprndSt.pop();

		char ch = oprtrSt.stackTop();
		oprtrSt.pop();

		int r = evaluate(op1, op2, ch);
		oprndSt.push(r);

		result = oprndSt.stackTop();
	}

	return result;
}
int main() {

	string s = "-+7*45+20";
	cout << prefixEvaluation(s);

	cout << endl;
	string s2 = "46+2/5*7+";
	cout << postfixEvaluation(s2);

	string s3 = "5/(5*(2+1))*2-10";
	cout << infixEvaluation(s3);
	cout << endl;
	cout << infixEvaluation("20+20*10/30");


}

