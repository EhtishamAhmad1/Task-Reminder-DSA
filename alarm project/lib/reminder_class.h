#include<iostream>
#include<fstream>
#include<string>
#include <cstring>
#include <Windows.h>
#include<mmsystem.h> 

#pragma once
using namespace std;
class reminder
{
public:
    int day,month,year,hour,min,alarm_id;
    char purpose[100];

	void create_alarm();
	void all_alarms();
    int alarm_id_func();
    int day1();
    int month1();
    int year1();
    int hour1();
    int min1();
    

    void write_alarm();
    void delete_alarm();
    void show_all_alarm();

    
};

void reminder::create_alarm()
{
    cout << "You selected to create a new Alarm\n";
    cout << "Enter alarm id: ";
    cin >> alarm_id;
    cout << "Enter Date: \n";
    cout << "Day: ";
    cin >> day;
    while (day > 31)
    {
        cout << "\tWrong Day entered!!! \n";
        cout << "Enter Day again : ";
        cin >> day;
    }
    cout << "Month: ";
    cin >> month;
    while (month > 12)
    {
        cout << "\tWrong Month entered!!! \n";
        cout << "Enter Month again : ";
        cin >> month;
    }
    cout << "year: ";
    cin >> year;
    while (year < 2022 || year > 2050)
    {
        cout << "\tWrong Year entered!!! \n";
        cout << "Enter Year again : ";
        cin >> year;
    }
    
    cout << "Enter Time: \n";
    cout << "Hour: ";
    cin >> hour;
    while (hour > 24)
    {
        cout << "\tWrong Hour entered!!! \n";
        cout << "Enter Hour again : ";
        cin >> hour;
    }
    cout << "Min:";
    cin >> min;
    while (min > 59)
    {
        cout << "\tWrong Minute entered!!! \n";
        cout << "Enter Minute again : ";
        cin >> min;
    }
    cout << "Enter Reminder Purpose: ";
    cin.ignore();
    cin.clear();
    cin.getline(purpose, 100);
    
}


void reminder::all_alarms() 
{   
        cout << "\t\t" << alarm_id << " \t" << day << " \t" << month << " \t" << year << " \t" << hour << " \t" << min << " \t  " << purpose << endl;
}

int reminder::alarm_id_func()
{
    return alarm_id;
}

int reminder::day1()
{
    return day;
}

int reminder::month1()
{
    return month;
}

int reminder::year1()
{
    return year;
}

int reminder::hour1()
{
    return hour;
}

int reminder::min1()
{
    return min;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void reminder::write_alarm()
{
    reminder r;
    fstream input;
    input.open("storage/reminder.txt", ios::binary | ios::app);
    if (!input)
    {
        cout << "file not created\n";
    }
    
    r.create_alarm();
   
    input.write((char*)&r, sizeof(r));
   
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,10);
    cout << "\t\tReminder created!!!\n\n";
    SetConsoleTextAttribute(h,7);
    PlaySound(TEXT("sound/google_join_sound.wav"),NULL,SND_SYNC);
    input.close();
}

void reminder::delete_alarm()
{
    int id;
    reminder r;
    cout << "Enter Alarm I.D to delete reminder : ";
    cin >> id;
    ifstream infile;
    ofstream outfile;
    infile.open("storage/reminder.txt", ios::binary | ios::in);
    outfile.open("storage/temp.txt", ios::binary | ios::out);
    if (!infile || !outfile)
    {
        cout << "File not found ";
    }
    else
    {
        while (infile.read((char*)&r, sizeof(r)))
        {
            if (r.alarm_id_func() != id)
            {
                outfile.write((char*)&r, sizeof(r));
            }
            
        }
         
        infile.close();
        outfile.close();

        HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,4);
        cout << "\t\t\"Reminder Deleted\"\n\n";
        SetConsoleTextAttribute(h,7);
        PlaySound(TEXT("sound/mac_delete.wav"),NULL,SND_SYNC);
        remove("storage/reminder.txt");
        rename("storage/temp.txt", "storage/reminder.txt");
    }
}

void reminder::show_all_alarm()
{
    reminder r;
    ifstream inFile;
    inFile.open("storage/reminder.txt", ios::binary | ios::in);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...\n\n";

    }
    else
    {
        cout << "\n\n\t\tALL REMINDERS LIST\n\n";
        cout << "\t\t==============================================================\n";
        cout << "\t\tID.\t" <<"DAY\t" << "MONTH\t" << "YEAR\t" << "HOUR\t" << "MINUTES\t" << "  PURPOSE\n";
        cout << "\t\t==============================================================\n";
        while (inFile.read((char*)&r, sizeof(r)))
        {
            
            HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,6);
            r.all_alarms();
            SetConsoleTextAttribute(h,7);
            
        }
        cout << "\n\n";
    }
    inFile.close();
}


