#ifndef MAIN_H
#define MAIN_H
#include<iostream>
#include<string>
#include<fstream>
#include"TreeClass.h"

using namespace std;
using std::string;
enum menuOPtions { DEFAULT, DISPLAY, QUIT };

void menu(int& optionNum);
string convertInfixToPostfix(string infixExpression);
int precedence(char operataor);
void dipslayTraversals();

#endif 
