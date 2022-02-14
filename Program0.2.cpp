// Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <iomanip>


using namespace std;

int recordNum = 0;
string names[1000];
int id[1000], md[1000], fi[1000], avr[1000];
char process;


void mainMenu() {
	
	cout << "===Main Menu===" << endl;
	cout << "1. Add record" << endl;
	cout << "2. Edit record" << endl;
	cout << "3. Delete record" << endl;
	cout << "4. Search record" << endl;
	cout << "5. List all records" << endl;
	cout << "6. Exit" << endl;
	cout << "Chose (1-6): ";
	process = getchar();
}

void recordAdd() {
	for (;;)
	{
		system("CLS");
		string firstname, lastname, FullName, again;
		int mids, finals, ID;
		double avreage;
		cout << "student ID = "; cin >> ID;
		cout << "First Name = "; cin >> firstname;
		cout << "Last Name = "; cin >> lastname;
		cout << "Mids = "; cin >> mids;
		cout << "Finals = "; cin >> finals;
		avreage = (mids * 0.4) + double(finals * 0.6);

		FullName = firstname + " " + lastname;
		id[recordNum] = ID;
		names[recordNum] = FullName;
		md[recordNum] = mids;
		fi[recordNum] = finals;
		avr[recordNum] = avreage;

		recordNum++;
		cout << "Do you want to add another record? (y/Y)(n/N) : "; cin >> again;
		if (again == "n" || again == "N")
		{
			break;
		}
	}


}

void recordEdit() {
	for (;;)
	{
		system("CLS");
		int ID;
		char again;
		char yesno;
		bool found = false;
		cout << "Enter the ID of the person you want to edit: "; cin >> ID;
		for (int i = 0; i < 1000; i++)
		{
			if (ID == id[i])
			{
				found = true;
				cout << "ID: " << id[i] << endl;
				cout << "Full name: " << names[i] << endl;
				cout << "Mids: " << md[i] << endl;
				cout << "Finals: " << fi[i] << endl;
				cout << "Is this is the person you want to Edit? (y/n)"; cin >> yesno;
				if (yesno == 'y' ||yesno=='Y')
				{
					string firstname, lastname, FullName, again;
					int mids, finals, ID;
					double avreage;
					//cout << "student ID = "; cin >> ID;
					cout << "First Name = "; cin >> firstname;
					cout << "Last Name = "; cin >> lastname;
					cout << "Mids = "; cin >> mids;
					cout << "Finals = "; cin >> finals;
					avreage = (mids * 0.4) + double(finals * 0.6);
					FullName = firstname + " " + lastname;
					//records[recordNum][0] = ID;
					names[i] = FullName;
					md[i] = mids;
					fi[i]= finals;
					avr[i] = avreage;
				}
			}
		}
		if (found == false)cout << endl << "Could not find the student" << endl;
		cout << "Do you want to edit another students information? (y/n)"; cin >> again;
		if (again == 'n' || again == 'N')
		{
			break;
		}
	}
}

void recordDelete() {
	for (;;)
	{
		system("CLS");
		
		int ID,n=0;
		char yesno,again;
		bool found = false;
		cout << "Enter Studint Id who you want to delete: "; cin >> ID;
		
		for (int i = 0; i <1000; i++)
		{
			if (id[i] == ID)
			{
				found = true;
				cout << "ID: " << id[n] << endl;
				cout << "Full Name: " << names[n] << endl;
				cout << "Mids: " << md[n] << endl;
				cout << "Finals: " << fi[n] << endl;
				cout << "Avreage: " << avr[n] << endl;
				cout << "Do you want to delete this student information ? (y/n) "; cin >> yesno;
				if (yesno == 'y' || yesno == 'Y')
				{
					id[n] = 0;
					names[n] = "";
					md[n] = 0;
					fi[n] = 0;
					avr[n] = 0;
				}
				break;
			}
			n++;
		}
		if(found==false)cout<<endl << "Could not find the student" << endl;
		
		cout << "Do you want to delete another student information? (y/n) "; cin >> again;
		if (again=='n'|| again=='N')
		{
			break;
		}
		

	}
}

void recordSearch() {
	for (;;)
	{
		system("CLS");
		int ID, n = 0;
		char yesno, again;
		cout << "Enter the student Id you want to search: "; cin >> ID;
		for (int i = 0; i < 1000; i++)
		{
			if (ID = id[i])
			{
				cout << "ID: " << id[n] << endl << "Full Name: " << names[n] << endl << "Mids: " << md[n] << endl << "Finals: " << fi[n] << endl << "Avreage: " << avr[n] << endl;
				break;
			}
			n++;
		}
		
		cout << "Do you want to Search another student information ? (y/n) "; cin >> yesno;
		if (yesno=='n'||yesno=='N')
		{
			break;
		}
	}
}

void recorList() {
    int t=0,x;
	t = (names[0].length() - 1);
	for (int i = 0;; i++)
	{
		if (i + t == 50) {
			x = i;
			break;
		}
	}
	cout << endl << endl << endl;
	cout << "ID" << setw(35) << "Full Name" << setw(x + 4) << "Mids" << setw(10) << "Finals" << setw(15) << "Avreage" << endl;;
	cout << "--" << setw(35) << "---------" << setw(x + 4) << "----" << setw(10) << "------" << setw(15) << "-------" << endl;;
	for (int i = 0; i < recordNum; i++)
	{
		if (names[i] == "") continue;
		cout << id[i];
		cout << setw(30) << names[i];
		
		cout << setw(x) << md[i];
		cout << setw(10) << fi[i];
		cout << setw(15) << avr[i];
		cout << endl << endl;
		
	}
	cout << endl << endl << endl;
	system("pause");
}




int main()
{

	//char AddRecord = '1', EditRecord = '2', DeleteRecord = '3', SearchRecord = '4', ListRecord = '5', Exit = '6';
	
	for (;;)
	{
		system("CLS");
		mainMenu();
		
		if (process == '1')
		{
			system("CLS");
			recordAdd();
		}
		else if (process=='2')
		{
			system("CLS");
			recordEdit();
		}
		else if (process=='3')
		{
			system("CLS");
			recordDelete();
		}
		else if (process=='4')
		{
			system("CLS");
			recordSearch();
		}

		else if (process == '5')
		{
			system("CLS");
			recorList();
		}
		else if (process=='6')
		{
			exit(0);
		}
		else
		{

		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
