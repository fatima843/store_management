#include "Stock.h"
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

void Stock::get()
{
	cin >> name >> pr >> quant;

}
void Stock::get2()
{
	cin >> name >> quant;
}
void Stock::show()
{
	cout << "\n" << name << "\t\t\t\t" << quant << "\t\t\t" << pr;
}
void Stock::withd(int qty)
{
	if (quant >= qty)
	{
		quant -= qty;
		cout << "\n\nStock updated.\n";
		cout << "\n\nTotal price to be paid:" << pr * qty;
	}
	else
		cout << "\n\nInsufficient stock";
	_getch();
}

void Stock::refil(int qty)
{
	quant += qty;
	cout << "\n\nStock updated.";
	_getch();
}
int Stock::stcheck(char nm[30])
{
	if (strcmp(nm, name) == 0)
		return 0;
	else
		return 1;
}