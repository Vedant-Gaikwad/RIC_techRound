#include<iostream>
#include <stack>

using namespace std;

int precedence(char op) {
  if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*' || op == '/') {
    return 2;
  } else {
    return 0;
  }
}

string infixToPostfix(string infix) {
  stack<char> operators;
  string postfix = "";

  for (int i = 0; i < infix.length(); i++) {
    char ch = infix[i];

    if (isalnum(ch)) {
      postfix += ch;
    } else if (ch == '(') {
      operators.push(ch);
    } else if (ch == ')') {
      while (!operators.empty() && operators.top() != '(') {
        postfix += operators.top();
        operators.pop();
      }
      operators.pop(); // Pop '('
    } else {
      // Operator
      while (!operators.empty() && precedence(ch) <= precedence(operators.top())) {
        postfix += operators.top();
        operators.pop();
      }
      operators.push(ch);
    }
  }

  // Pop remaining operators
  while (!operators.empty()) {
    postfix += operators.top();
    operators.pop();
  }

  return postfix;
}

int main(){
  string infix;
  cout<<"enter infix: ";
  cin>>infix;
  string postfix=infixToPostfix(infix);
  cout<<"Postfix :"<<postfix<<endl;
  return 0;
}