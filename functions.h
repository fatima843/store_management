#pragma once

#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<string>
#include<fstream>
#include <sstream>
#include "Stock.h"
#include "User.h"


using namespace std;

int i, n, m, non;
int toenter;

char M;
ifstream fin;
ofstream fout;
fstream fio;
void disp();

Stock st;
User us;

void addnew()
{
	system("cls");

	disp();
	_getch();
	//system("cls");
	cout << endl;
	cout << "\nEnter the No. of Products that you wish to add: ";
	cin >> n;

	if (n != 0)
	{
		int j, l, sum = 0;
		fout.open("shop.txt", ios::binary | ios::app);
		for (i = 0; i < n; i++)
		{
			cout << "\n\nInput the name, price and the quantity of item respectively:\n\n";
			st.get();
			fout.write((char*)&st, sizeof(st));
			cout << "\n\nitem updated";
			cin.get();
		}
		cout << "\n\nStock Updated!!";

		fout.close();
		cin.get();
		system("cls");
		disp();
	}
	else
	{
		fout.close();
		cin.get();
		system("cls");
		cout << "\n\nNo items to be added";
	}
}

void addnewperson()
{
	system("cls");
	_getch();
	system("cls");
	cout << "Customer's registry:\n\n";

	fout.open("customers.txt", ios::binary | ios::app);

	cout << "Please enter your name and password: " << endl;
	us.getid();
	fout.write((char*)&us, sizeof(us));
	cout << "\n\nuser added";
	cin.get();

	cout << "\n\nSystem updated!!";
	cout << "\n\nWelcome to our store!";

	fout.close();
	cin.get();
	system("cls");
}

void withdraw()
{
	if (non == 0)
		system("cls");
	char temp[100]; int qty;
	int i = 0;
	long pos = 0;
	if (non == 0)
		disp();
	cout << "\n\nEnter the product's name: \n" << endl;
	cin >> temp;
	cout << "\n\nEnter quantity: \n" << endl;
	cin >> qty;
	fio.open("shop.txt", ios::binary | ios::out | ios::in);
	while (fio)
	{
		pos = fio.tellp();
		fio.read((char*)&st, sizeof(st));
		if (st.stcheck(temp) == 0)
		{
			st.withd(qty);
			fio.seekp(pos);
			fio.write((char*)&st, sizeof(st));
			i++; break;
		}
	}

	if (i != 1)
		cout << "\n\n!!Record not found!!";
	fio.close();
	cin.get();
	//system("cls");
	//disp();
	_getch();
}

void refill()
{
	system("cls");
	char temp[100]; int qty;
	int i = 0;
	long pos = 0;
	disp();
	cout << "\n\nEnter the product's name: \n" << endl;
	cin >> temp;
	cout << "\n\nEnter quantity: \n" << endl;
	cin >> qty;
	fio.open("shop.txt", ios::binary | ios::out | ios::in);
	while (fio)
	{
		pos = fio.tellp();
		fio.read((char*)&st, sizeof(st));
		if (st.stcheck(temp) == 0)
		{

			st.refil(qty);
			fio.seekp(pos);
			fio.write((char*)&st, sizeof(st));
			i++; break;
		}
	}
	if (i != 1)
		cout << "\n\n!!Record not found!!";

	fio.close();
	system("cls");
	cin.get();
	disp(); cin.get();
}

void remove()
{
	system("cls");
	disp();
	_getch();
	//system("cls");
	int i = 0;
	char temp[30];
	cout << "\n\n\t\t\t\tDelete Record";
	cout << "\n\nEnter the name of the product:";
	cin >> temp;
	fout.open("temp.txt", ios::binary);
	fin.open("shop.txt", ios::binary);
	while (!fin.eof())
	{
		fin.read((char*)&st, sizeof(st));
		if (!fin.eof())
			if (st.stcheck(temp) == 0)
			{
				st.show();
				cout << "\n\n\t\tRecord deleted";
				i++;
			}
			else
				fout.write((char*)&st, sizeof(st));
	}
	if (i == 0)
		cout << "\n\n!!Record not found!!";
	fin.close();
	fout.close();
	remove("shop.txt");
	rename("temp.txt", "shop.txt");
}

void login()
{
	string UserName, Password;
	string UseEnter;
	string PassEnter;
	bool On_Off = true;
	bool Off = true;
	int countt = 0;
	int left = 3;
	toenter = 0;

	cout << "\n** Login to your Account ** \n";
	while (On_Off) {
		fstream user;
		user.open("dealer.txt", ios::in);
		if (countt < 3 && Off && user.is_open()) {
			if (countt > 0) {
				cout << "\nPassword or UserName are not correct!!" << endl;
				left--;
				cout << "You have " << left << " attempts left \n" << endl;
			}
			cout << "Enter UserName: " << endl;
			cin >> UseEnter;
			cout << "Enter Password: " << endl;
			cin >> PassEnter;
			countt++;
			string read;
			while (getline(user, read)) {
				stringstream convertor(read);
				convertor >> UserName >> Password;
				if (UseEnter == UserName && PassEnter == Password) {
					Off = false;
				}
			}
		}
		else if (!Off) {
			cout << "\n** Welcome! **\n\n";
			user.close();
			On_Off = false;
			toenter++;
		}
		else {
			cout << "\n** Try again later!! ** \n\n";
			user.close();
			On_Off = false;
		}
	}
}

void registry()
{
	string newName, checkName, newPass, confirmPass;
	int MiniPass;
	bool if_ON = true;
	bool oo = true;

	cout << "\n** Create New Account ** \n";

	while (oo) {
		cout << "Enter New UserName: ";
		cin >> newName;
		MiniPass = newName.length();
		fstream yusers;
		yusers.open("dealer.txt", ios::in);
		if (if_ON && MiniPass >= 1 && yusers.is_open()) {
			string readd;
			while (getline(yusers, readd)) {
				stringstream OnlyUsers(readd);
				OnlyUsers >> checkName;
				if (newName == checkName) {
					cout << "\n*" << newName << "* userName already exists. Try another one\n" << endl;
					if_ON = false;
				}
			}
			yusers.close();
			if (!if_ON) {
				if_ON = true;
			}
			else {
				oo = false;
			}
		}
	}

	while (true) {
		cout << "Enter New password: ";
		cin >> newPass;
		cout << "Confirm the password: ";
		cin >> confirmPass;
		MiniPass = newPass.length();

		if (MiniPass < 5) {
			cout << "\nYour password is weak, at least 5 letters\n \n";
		}
		else if (confirmPass == newPass) {
			fstream users;
			users.open("dealer.txt", ios::app);
			if (users.is_open()) {
				users << newName + " " + newPass << endl;
				users.close();
			}
			cout << "\n-----------------------------------\n";
			cout << "\nSuccessfully new account created! \n \n";
			cout << "-----------------------------------\n";
			break;
		}
		else {
			cout << "\nPassword confirmation not correct! \n" << endl;
		}
	}
	login();
}

bool loginemp()
{
	string UserName, Password;
	string UseEnter;
	string PassEnter;
	bool On_Off = true;
	bool Off = true;
	int countt = 0;
	int left = 3;

	cout << "\n** Login to your Account ** \n";
	while (On_Off) {
		//**
		fstream user;
		user.open("employee.txt", ios::in);
		if (countt < 3 && Off && user.is_open()) {
			if (countt > 0) {
				cout << "\nPassword or UserName are not correct!!" << endl;
				left--;
				cout << "You have " << left << " attempts left \n" << endl;
			}
			cout << "Enter UserName: " << endl;
			cin >> UseEnter;
			cout << "Enter Password: " << endl;
			cin >> PassEnter;
			countt++;
			string read;
			while (getline(user, read)) {
				stringstream convertor(read);
				convertor >> UserName >> Password;
				if (UseEnter == UserName && PassEnter == Password) {
					Off = false;
				}
			}
		}
		else if (!Off) {
			cout << "\n** Welcome! **\n\n";
			user.close();
			On_Off = false;
			return true;
		}
		else {
			cout << "\n** Try again later!! ** \n\n";
			user.close();
			On_Off = false;
			return false;
		}
	}
}

void registryemp()
{
	string newName1, checkName1, newPass1, confirmPass1;
	int MiniPass1;
	bool if_ON1 = true;
	bool oo1 = true;

	cout << "\n** Create New Account ** \n";

	while (oo1) {
		cout << "Enter New UserName: ";
		cin >> newName1;
		MiniPass1 = newName1.length();
		fstream yusers1;
		yusers1.open("employee.txt", ios::in);
		if (if_ON1 && MiniPass1 >= 1 && yusers1.is_open()) {
			string readd;
			while (getline(yusers1, readd)) {
				stringstream OnlyUsers(readd);
				OnlyUsers >> checkName1;
				if (newName1 == checkName1) {
					cout << "\n*" << newName1 << "* userName already exists. Try another one\n" << endl;
					if_ON1 = false;
				}
			}
			yusers1.close();
			if (!if_ON1) {
				if_ON1 = true;
			}
			else {
				oo1 = false;
			}
		}
	}

	while (true) {
		cout << "Enter New password: ";
		cin >> newPass1;
		cout << "Confirm the password: ";
		cin >> confirmPass1;
		MiniPass1 = newPass1.length();

		if (MiniPass1 < 5) {
			cout << "\nYour password is weak, at least 5 letters\n \n";
		}
		else if (confirmPass1 == newPass1) {
			fstream users1;
			users1.open("employee.txt", ios::app);
			if (users1.is_open()) {
				users1 << newName1 + " " + newPass1 << endl;
				users1.close();
			}
			cout << "\n-----------------------------------\n";
			cout << "\nSuccessfully new account created! \n \n";
			cout << "-----------------------------------\n";
			break;
		}
		else {
			cout << "\nPassword confirmation not correct! \n" << endl;
		}
	}
	loginemp();
}
