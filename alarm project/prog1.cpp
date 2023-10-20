#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<ctime>
#include<time.h>
#include<Windows.h>

#include"lib/reminder_class.h"
#include"lib/intro_menu.h"
using namespace std;


int main()
{
	reminder r;

	menu();
	char choice;
	do
	{
	
		cout << "   \t\t\t\t\t1-Create a Reminder \n";
		cout << "   \t\t\t\t\t2-Delete a Reminder \n";
		cout << "   \t\t\t\t\t3-Show all Reminders\n";
		cout << "   \t\t\t\t\t4-Exit\n";
		cout << "\n   \t\t\t\t\tChoose your option : ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			r.write_alarm();
			break;

		case '2':
			r.delete_alarm();
			break;

		case '3':
			r.show_all_alarm();
			break;
		case '4':
			cout<<"\tProgram Exited!!!!!";
			break;
		default:
			cout << "\nPlease choose valid option\n\n";
		}
	} while (choice != '4');
}
	
