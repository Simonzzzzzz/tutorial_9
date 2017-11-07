// Student name:	ZHOU Zhenghao
// Student ID  :	54381018


#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>  // pow(double x, double y), compute the value of x to power y

using namespace std;

bool isOperator(char c)
{
   return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}

double evaluateOperator(char opr, double d1, double d2)
{
	//This print statement is for debugging purpose.
	//cout << "evaluate " << d1 << " " << opr << " " << d2 << endl;

	switch (opr) 
	{
		case '+' : return d1 + d2;
		case '-' : return d1 - d2;
		case '*' : return d1 * d2;
		case '/' : return d1 / d2;
		case '$' : return pow(d1, d2);
		default : return 0;
	}
}

double nextOperand(const string& expr, int& i)
{
	int j = i;
	while (j < expr.length() && expr[j] != ' ')
		j++;

	string number = expr.substr(i, j-i);
	i = j;

	return stod(number);
}

//------------------- function to evaluate postfix expression

double evaluate_postfix(const string& postfix_expr)
{
	stack<double> S;
	int i=0;
	double temp;
	while(i<postfix_expr.length()){
		if(postfix_expr[i]==' '){
			i++;
		}
		else{
			if(!isOperator(char(postfix_expr[i]))){
				temp=nextOperand(postfix_expr,i);
				S.push(temp);
			}
			else{
				double temp_2=S.top();
				S.pop();
				double temp_1=S.top();
				S.pop();
				temp=evaluateOperator(char(postfix_expr[i]),temp_1,temp_2);
				S.push(temp);
				i++;
			}
		}
	}
	double value=S.top();
	// Your codes

	return value; // dummy return statement
}

//------------------- function to evaluate prefix expression

// Hint: structure of the data record to be kept in the stack is given below.

struct stackItem
{
	char symb;  // operator
	int count;  // number of operands associated with the operator that have been seen
	double d1;  // value of the left-operand
	/*
	double d2;  // value of the right-operand, this field is optional
	*/
};

double evaluate_prefix(const string& prefix_expr)
{
	stack<stackItem> S;
	stackItem x;

	// Your codes

	return 0; // dummy return statement
}

//----------------------------- main()

int main()
{	
	cout << "----- Evaluate Postfix Expression -----" << endl << endl;

	ifstream infile("postfix_expr.txt");
	if (!infile.is_open())
	{
		cout << "Error: cannot open postfix_expr.txt" << endl;
		system("pause");
		exit(0);
	}

	string postfix_expr;
	while (getline(infile, postfix_expr))
	{
		double value = evaluate_postfix(postfix_expr);
		cout << "postfix expression: " << postfix_expr << " = " << value << endl << endl;
	}
	infile.close();

	cout << "----- Evaluate Prefix Expression -----" << endl << endl;

	infile.open("prefix_expr.txt");
	if (!infile.is_open())
	{
		cout << "Error: cannot open prefix_expr.txt" << endl;
		system("pause");
		exit(0);
	}

	string prefix_expr;
	while (getline(infile, prefix_expr))
	{		
		double value = evaluate_prefix(prefix_expr);
		cout << "prefix expression: " << prefix_expr << " = " << value << endl << endl;
	}
	infile.close();

	system("pause");
	exit(0);
}