#include <iostream>
#include <stack>
#include <string>
using namespace std;

void checkSyntax(string&);

int main(){
	string code;
	cout << "Enter line of code to be reviewed below.\n\n";
	getline(cin, code);
	checkSyntax(code);
	return 0;
}

// Checks paranthesis and brackets to be balanced
void checkSyntax(string& line){
	stack<char> charStack;
	for (string::iterator it = line.begin(); it != line.end(); it++){
		if (*it == '(' || *it == '{')
			charStack.push(*it);
	}
	for (string::iterator it = line.begin(); it != line.end(); it++){
		if (*it == '}' && charStack.top() == '{')
			charStack.pop();
		else if (*it == ')' && charStack.top() == '(')
			charStack.pop();
	}
	if (charStack.empty())
		cout << "Valid c++ code";
	else
		cout << "Invalid c++ code, " << charStack.top() << " is missing a closer.";
}
