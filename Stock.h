#pragma once

class Stock
{
	char name[20], pass[10];
	float pr; int quant;

public:
	void get();
	void get2();
	void show();
	void withd(int qty);
	void refil(int qty);
	int stcheck(char nm[30]);
};
