//Rosculete, Robin:
//Lab 8
/****Intructor feedback DO NOT DELETE:
NG 100
3+5/7
3*5/7
x+y*a/b
w*t/q+v
a+b
a+b*c-d/e
a-b+c*d
a*b-c
c*j+k/d+z+g+n+f
n+b-c*j+k/d
****/
#include"mainHelper.h"

int main() {
	int optionNum = 0;
	TreeClass tree;
	TreeNode *obj=nullptr;

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
		cin.ignore(200,'\n');
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
		expression=convertInfixToPostfix(expression);
		tree.createExpressionTree(expression);
		tree.PrintOrders();
		for (int x = 0; x < expression.length()*10; ++x) {
			cout << "_";
		}
		cout << endl;
		tree.MakeEmpty();	
	}
}//end dipslatTraversals()

//Function purpose to convert infix expression to postfix expression an return the string
string convertInfixToPostfix(string infixExpression){
	Stack<char> tempStack;
	string postfixExpression="";

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

//Test Data

//1. Testing with multiple expressions in file
/*
Please enter an option bellow
        1.Display Tree Traversals
        2.Quit program!
1

Original expression is: x+y*a/b
Preorder:  +    x       /       *       y       a       b

Postorder: x    y       a       *       b       /       +

Inorder:     (  (x)  +  (  (  (y)  *  (a)  )  /  (b)  )  )
______________________________________________________________________

Original expression is: a*b/c+e
Preorder:  +    /       *       a       b       c       e

Postorder: a    b       *       c       /       e       +

Inorder:     (  (  (  (a)  *  (b)  )  /  (c)  )  +  (e)  )
______________________________________________________________________

Original expression is: x+z-y*b
Preorder:  -    +       x       z       *       y       b

Postorder: x    z       +       y       b       *       -

Inorder:     (  (  (x)  +  (z)  )  -  (  (y)  *  (b)  )  )
______________________________________________________________________

Original expression is: 2+3-8+6
Preorder:  +    -       +       2       3       8       6

Postorder: 2    3       +       8       -       6       +

Inorder:     (  (  (  (2)  +  (3)  )  -  (8)  )  +  (6)  )
______________________________________________________________________

Original expression is: x*y+3/b-1
Preorder:  -    +       *       x       y       /       3       b       1

Postorder: x    y       *       3       b       /       +       1       -

Inorder:     (  (  (  (x)  *  (y)  )  +  (  (3)  /  (b)  )  )  -  (1)  )
__________________________________________________________________________________________

Please enter an option bellow
        1.Display Tree Traversals
        2.Quit program!





Please enter an option bellow
		1.Display Tree Traversals
		2.Quit program!
1

Original expression is: 3+5/7
Preorder:  +    3       /       5       7

Postorder: 3    5       7       /       +

Inorder:     (  (3)  +  (  (5)  /  (7)  )  )
__________________________________________________

Original expression is: 3*5/7
Preorder:  /    *       3       5       7

Postorder: 3    5       *       7       /

Inorder:     (  (  (3)  *  (5)  )  /  (7)  )
__________________________________________________

Original expression is: x+y*a/b
Preorder:  +    x       /       *       y       a       b

Postorder: x    y       a       *       b       /       +

Inorder:     (  (x)  +  (  (  (y)  *  (a)  )  /  (b)  )  )
______________________________________________________________________

Original expression is: w*t/q+v
Preorder:  +    /       *       w       t       q       v

Postorder: w    t       *       q       /       v       +

Inorder:     (  (  (  (w)  *  (t)  )  /  (q)  )  +  (v)  )
______________________________________________________________________

Original expression is: a+b
Preorder:  +    a       b

Postorder: a    b       +

Inorder:     (  (a)  +  (b)  )
______________________________

Original expression is: a+b*c-d/e
Preorder:  -    +       a       *       b       c       /       d       e

Postorder: a    b       c       *       +       d       e       /       -

Inorder:     (  (  (a)  +  (  (b)  *  (c)  )  )  -  (  (d)  /  (e)  )  )
__________________________________________________________________________________________

Original expression is: a-b+c*d
Preorder:  +    -       a       b       *       c       d

Postorder: a    b       -       c       d       *       +

Inorder:     (  (  (a)  -  (b)  )  +  (  (c)  *  (d)  )  )
______________________________________________________________________

Original expression is: a*b-c
Preorder:  -    *       a       b       c

Postorder: a    b       *       c       -

Inorder:     (  (  (a)  *  (b)  )  -  (c)  )
__________________________________________________

Original expression is: c*j+k/d+z+g+n+f
Preorder:  +    +       +       +       +       *       c       j       /       k       d       z       g       n      f

Postorder: c    j       *       k       d       /       +       z       +       g       +       n       +       f      +

Inorder:     (  (  (  (  (  (  (c)  *  (j)  )  +  (  (k)  /  (d)  )  )  +  (z)  )  +  (g)  )  +  (n)  )  +  (f)  )
______________________________________________________________________________________________________________________________________________________

Original expression is: n+b-c*j+k/d
Preorder:  +    -       +       n       b       *       c       j       /       k       d

Postorder: n    b       +       c       j       *       -       k       d       /       +

Inorder:     (  (  (  (n)  +  (b)  )  -  (  (c)  *  (j)  )  )  +  (  (k)  /  (d)  )  )
______________________________________________________________________________________________________________

Original expression is: x+y*a/b
Preorder:  +    x       /       *       y       a       b

Postorder: x    y       a       *       b       /       +

Inorder:     (  (x)  +  (  (  (y)  *  (a)  )  /  (b)  )  )
______________________________________________________________________

Original expression is: a*b/c+e
Preorder:  +    /       *       a       b       c       e

Postorder: a    b       *       c       /       e       +

Inorder:     (  (  (  (a)  *  (b)  )  /  (c)  )  +  (e)  )
______________________________________________________________________

Original expression is: x+z-y*b
Preorder:  -    +       x       z       *       y       b

Postorder: x    z       +       y       b       *       -

Inorder:     (  (  (x)  +  (z)  )  -  (  (y)  *  (b)  )  )
______________________________________________________________________

Original expression is: 2+3-8+6
Preorder:  +    -       +       2       3       8       6

Postorder: 2    3       +       8       -       6       +

Inorder:     (  (  (  (2)  +  (3)  )  -  (8)  )  +  (6)  )
______________________________________________________________________

Original expression is: x*y+3/b-1
Preorder:  -    +       *       x       y       /       3       b       1

Postorder: x    y       *       3       b       /       +       1       -

Inorder:     (  (  (  (x)  *  (y)  )  +  (  (3)  /  (b)  )  )  -  (1)  )
__________________________________________________________________________________________

Please enter an option bellow
		1.Display Tree Traversals
		2.Quit program!


*/



//2.Testing with empty file or file not found
/*Please enter an option bellow
        1.Display Tree Traversals
        2.Quit program!
1
Error! Can't open Expression File , or file mifght be empty!

C:\Users\Robin\Desktop\Scoala\Anul 2\SEM #2\CS 136\LABS\LAB 8!\Debug\LAB 8!.exe (process 23492) exited with code 1.
Press any key to close this window . . .*/