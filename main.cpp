#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<string>
#include<fstream>
#include <sstream>
#include "Stock.h"
#include "User.h"
#include "functions.h"


using namespace std;
void disp();


void disp()
{
	int i = 1;
	cout << "\n------------------------------------------------------------------";
	cout << "\n\n------------------\tITEMS IN THE STOCK\t------------------";
	cout << "\n\n------------------------------------------------------------------\n";
	cout << "\n\nPRODUCTS\t\tAVAILABLE STOCK\t\t\tPRICE";
	cout << "\n\n------------------------------------------------------------------\n";
	fin.open("shop.txt", ios::binary);
	while (!fin.eof())
	{
		fin.read((char*)&st, sizeof(st));
		if (!fin.eof())
		{
			if (fin.tellg() < 0)
			{
				i = 0; break;
			}
			st.show();
		}
	}
	if (i == 0)
	{
		cout << "\n\n\t\t\t!!Empty record room!!";
		_getch();
	}
	fin.close();

}


int main()
{
	char pass1[10], pass2[10];
	string password;
	string password2;
	int i, j;
	bool h;
	cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t Stop! Shop! It's the Top! ";
	_getch();
	system("cls");
main:
	cout << "\n\t\t  Happy to see you here!\n";
	cout << "\t---------------------------------------------";
	cout << "\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu\n\n\t\t   4. Register New user";
	cout << "\n\n\t---------------------------------------------\n";
	cout << "\n\nEnter Your Choice:\t";
	cin >> j;
	if (j == 1)
	{
		system("cls");
		login();
		if (toenter != 0)
		{
			system("cls");
		dealermenu:
			system("cls");
			cout << "------------------------------------------------------------------";
			cout << "\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Exit";
			cout << "\n\n\n--------------------------END OF MENU-----------------------------";
			cout << "\n\n Enter your Choice:\t";
			cin >> i;
			if (i == 1)
			{
				addnew();
				_getch();
				goto dealermenu;
			}

			else if (i == 2)
			{
				system("cls");
				disp();
				_getch();
				goto dealermenu;
			}
			else if (i == 3)
			{
				refill();
				goto dealermenu;
			}
			else if (i == 4)
			{
				remove();
				_getch();
				goto dealermenu;
			}
			else
			{
				system("cls");
				cout << "\n\n\n\t\t\tThank You !!";
				_getch();
				exit(0);
			}
		}
		else
		{
			cout << "\n\n\nAuthorised Personnel Only\n\n";
			_getch();
			_getch();
			_getch();
			_getch();
			_getch();
			_getch();
			exit(0);
		}
	}
	if (j == 2)
	{
	ques:
		cout << "\nAre you an old customer Y/N" << endl;
		cin >> M;
		if (M == 'N' || M == 'n')
		{
			addnewperson();
			system("cls");
			goto custmenu;
		}
		else if (M == 'y' || M == 'Y')
		{
		custmenu:
			system("cls");
			cout << "------------------------------------------------------------------";
			cout << "\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Exit";
			cout << "\n\n\n--------------------------END OF MENU-----------------------------";
			cout << "\n\n Enter your Choice:\t";
			cin >> i;

			if (i == 1)
			{
				char k;
				purchase:
				withdraw();
				cout << endl;
				non++;
				_getch();
				cout << "Would you like to purchase more items (Y/N) ?" << endl;
				cin >> k;
				cout << endl;
				if (k == 'y' || k == 'Y') 
					goto purchase;
				cout << "Thanks for your trust !!" << endl;
				cout << "Have a great day our customer :)" << endl;
				_getch();
				system("cls");
				disp();
				_getch();
				_getch();
				goto custmenu;
			}
			else if (i == 2)
			{
				system("cls");
				disp();
				_getch();
				goto custmenu;
			}

			else if (i == 3)
			{
				system("cls");
				cout << "\n\n\n\t\t\tThank You !!";
				_getch();
				exit(0);
			}
			else
			{
				system("cls");
				addnewperson();
				_getch(); 
				goto custmenu;
			}
		}
		else {
			system("cls");
			cout << "Rewrite your answer correctly: " << endl;
			goto ques;
		}
	}
	if (j == 3)
	{
		system("cls");
		h = loginemp();
		if (h)
		{
		empmenu:
			system("cls");
			cout << "------------------------------------------------------------------";
			cout << "\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Exit";
			cout << "\n\n\n--------------------------END OF MENU-----------------------------";
			cout << "\n\n Enter your Choice:\t";
			cin >> i;
			if (i == 1)
			{
				system("cls");
				disp();
				_getch();
				goto empmenu;
			}
			else if (i == 2)
			{
				refill();
				goto empmenu;
			}
			else
			{
				system("cls");
				cout << "\n\n\n\t\t\tThank You !!";
				_getch();
				exit(0);
			}
		}
		else
		{
			cout << "\n\nSorry!! Access Denied..\n\n";
			_getch();
			_getch();
			_getch();
			_getch();
			_getch();

			exit(0);
		}
	}
	if (j == 4) {
		system("cls");
		while (true) {
			system("cls");
			cout << "\n\t\t   REGISTRATION\n";
			cout << "\t---------------------------------------------";
			cout << "\n\n\t\t   1. New Dealer \n\n\t\t   2. New Customer \n\n\t\t   3. New Employee \n\n\t\t\n";
			cout << "\t---------------------------------------------\n";
			cout << "\n\tEnter your choice:\t";
			cin >> m;
			if (m == 1) {
				system("cls");
				cout << "\n\n\n\n\n\n\n\t\t\t\tEnter the password: ";

				for (int z = 0; z < 5; z++)
				{
					pass1[z] = _getch();
					system("cls");
					cout << "\n\n\n\n\n\n\n\t\t\t\tEnter the password: ";
					for (i = 1; i <= (z + 1); i++)
					{
						cout << "*";
					}
				}
				password = pass1;
				if (password.find("admin") == 0)
				{

					registry();
					cout << "Added successfully thank you !!" << endl;
					_getch();
					system("cls");
					goto dealermenu;
				}
				else {
					cout << "\n\n\n\t\t\tUnaccessible by unauthorized users!" << endl;
					_getch();
					system("cls");
					goto main;
				}
			}
			else if (m == 3) {
				system("cls");
				cout << "\n\n\n\n\n\n\n\t\t\t\tEnter the password: ";

				for (int z = 0; z < 5; z++)
				{
					pass1[z] = _getch();
					system("cls");
					cout << "\n\n\n\n\n\n\n\t\t\t\tEnter the password: ";
					for (i = 1; i <= (z + 1); i++)
					{
						cout << "*";
					}
				}
				password = pass1;
				if (password.find("admin") == 0)
				{

					registryemp();
					cout << "Added successfully thank you !!" << endl;
					_getch();
					system("cls");
					goto empmenu;
				}
				else {
					cout << "\n\n\n\t\t\tUnaccessible by unauthorized users!" << endl;
					_getch();
					system("cls");
					goto main;
				}
			}
			else if (m == 2)
			{
				system("cls");
				addnewperson();
				goto custmenu;
			}
			else {
				cout << "\n*Please re-enter correctly your choice of numbers*\n" << endl;
			}
		}
		_getch();
	}
	return 0;
	system("pause");
}