#include <iostream>
#include <stack>
#include <string>
//Operand range from a-z, A-Z, 0 - 9 ---> Only if its based char c
bool isOperand(char c) {
	if (c >= '0' && c <= '9')
		return true;

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;

	return false;
}

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}


std::string postfixToInfix(std::string postfix) {
	std::stack<std::string> s;
	std::string infix = "";
	std::string left;
	std::string right;

	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] == ' ' || postfix[i] == ',') {
			continue;
		}
		else if (isOperand(postfix[i])) {
			std::string operand(1, postfix[i]);
			s.push(operand);
			
			
		}
		else if (isOperator(postfix[i])) {
			right = s.top();
			s.pop();
			left = s.top();
			s.pop();
			if (postfix[i] == '+' || postfix[i] == '-') {
				infix = "(" + left + postfix[i] + right + ")";
			}
			else
				infix = left + postfix[i] + right;
			s.push( infix );
			
		} 
		else s.push("" + postfix[i]);
		
		
	}
	return infix;
		

		



}




int main()
{
	std::string postfix;
	std::cout << "Enter a postfix expression ";
	std::getline(std::cin, postfix);
	std::string infix = postfixToInfix(postfix);
	std::cout << "postfix to infix: " << infix << std::endl;
	system("pause");
}