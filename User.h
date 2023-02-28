#pragma once

class User {
private:
	char pname[15];
	char passs2[15];

public:
	char copy[15];
	void getid();
	void print();
	int checkname(char nam[30]);
	int checkpass(char nam1[30]);

};
