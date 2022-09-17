#include"mainHelper.h"

int main() {
	int optionNum = 0;
	TreeClass tree;
	TreeNode* obj = nullptr;

	while (optionNum != QUIT) {
		menu(optionNum);
		switch (optionNum)
		{
		case DISPLAY:dipslayTraversals();
			break;
		case QUIT: break;

		default:
			cout << "Wrong Input please try again" << endl;
			break;
		}
	}
	return 0;
}
//function purpose to print user menu to screen and return option num
void menu(int& optionNum) {
	cout << "\nPlease enter an option bellow\n\t"
		<< DISPLAY << ".Display Tree Traversals\n\t"
		<< QUIT << ".Quit program!" << endl;
	if (!(cin >> optionNum)) {

		cin.clear();
		cin.ignore(200, '\n');
	}

}//end menu()

//function purpose to read from expressin file, and print inorder, preoder, post order traversal of expressions from file
void dipslayTraversals() {
	fstream expressionFile;
	string expression = "";
	TreeClass tree;
	expressionFile.open("ExpressionFile.txt");
	if (expressionFile.fail() || expressionFile.peek() == ofstream::traits_type::eof()) {
		cout << "Error! Can't open Expression File , or file might be empty!" << endl;
		exit(1);
	}
	while (!(expressionFile.eof())) {
		getline(expressionFile, expression);
		cout << "\nOriginal expression is: " << expression;
		expression = convertInfixToPostfix(expression);
		tree.createExpressionTree(expression);
		tree.PrintOrders();
		for (int x = 0; x < expression.length() * 10; ++x) {
			cout << "_";
		}
		cout << endl;
		tree.MakeEmpty();
	}
}//end dipslatTraversals()

//Function purpose to convert infix expression to postfix expression an return the string
string convertInfixToPostfix(string infixExpression) {
	Stack<char> tempStack;
	string postfixExpression = "";

	for (int x = 0; x < infixExpression.length(); ++x) {
		if (isalnum(infixExpression[x])) {
			postfixExpression += infixExpression[x];
		}
		else {
			if (tempStack.isEmpty()) tempStack.push(infixExpression[x]);
			else {
				if (precedence(infixExpression[x]) > precedence(tempStack.peek())) {

					tempStack.push(infixExpression[x]);

				}
				else if ((precedence(infixExpression[x] == precedence(tempStack.peek()))) && infixExpression[x] == '^') {
					tempStack.push(infixExpression[x]);

				}
				else {
					while (!(tempStack.isEmpty()) && precedence(infixExpression[x]) <= precedence(tempStack.peek())) {

						postfixExpression += tempStack.peek();
						tempStack.pop();

					}tempStack.push(infixExpression[x]);
				}
			}

		}//End else 

	}//end for Loop

	while (!tempStack.isEmpty()) {
		postfixExpression += tempStack.peek();
		tempStack.pop();
	}

	return postfixExpression;
}//End convertInfixToPostfix

//Function purpose to return the precedence of opertators
int precedence(char operataor)
{
	if (operataor == '+' || operataor == '-') return 1;
	else if (operataor == '*' || operataor == '/') return 2;
	else if (operataor == '^') return 3;

	else return -1;
}//end precedence()