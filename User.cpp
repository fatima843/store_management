#include "User.h"
#include <iostream>
#include <string.h>

using namespace std;

void User::getid()
{
	cin >> pname >> passs2;
}
void User::print() {
	cout << "your registeration information are" << endl;
	cout << "Name :" << pname << endl;
	cout << "password :" << passs2 << endl;
}
int User::checkname(char nam[30])
{
	if (strcmp(nam, pname) == 0)
		return 0;
	else
		return 1;
}
int User::checkpass(char nam1[30])
{
	if (strcmp(nam1, passs2) == 0)
		return 0;
	else
		return 1;
}