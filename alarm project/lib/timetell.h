#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <ctime>
#include <fstream>
#include "reminder_class.h"
#include <queue>

using namespace std;

#pragma once

void timetell()
{
	reminder r;
	queue<reminder> mainQueue, tmpQueue;

	int count = 0;
	char choice1;
	time_t now;
    #pragma warning(disable : 4996); 

	struct tm nowLocal;

	now = time(NULL); 
	nowLocal = *localtime(&now);
	
	while(true)
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t-------------------\n";
		cout << "\t\t\t\t\t\t| DATE : " << nowLocal.tm_mday << " " << nowLocal.tm_mon + 1 << " " << nowLocal.tm_year + 1900<<" |" << endl;
		cout << "\t\t\t\t\t\t| TIME : " << nowLocal.tm_hour << " " << nowLocal.tm_min << " " << nowLocal.tm_sec<<"  |" << endl;
		cout<<"\t\t\t\t\t\t-------------------\n";
		nowLocal.tm_sec++;
		if (nowLocal.tm_sec == 60)
		{
			nowLocal.tm_min++;
			nowLocal.tm_sec = 0;

			if (nowLocal.tm_min == 60)
			{
				nowLocal.tm_hour++;
				nowLocal.tm_min = 0;

				if (nowLocal.tm_hour == 12)
				{
					nowLocal.tm_hour = 0;

				}
			}
		}
		if (count == 30)
		{
			count = 0;
			ifstream inFile;
			inFile.open("storage/reminder.txt", ios::binary | ios::in);
			if (!inFile)
			{
				cout << "File could not be open !! Press any Key...\n\n";

			}
			else
			{
				while (inFile.read((char*)&r, sizeof(r)))
				{
					mainQueue.push(r);
				}
				cout << "\n\n";
			}

			inFile.close();
		}
		
		while(!mainQueue.empty())
		{
			reminder r = mainQueue.front();
			tmpQueue.push(mainQueue.front());
			mainQueue.pop();

			if ((nowLocal.tm_year + 1900) == r.year1() && (nowLocal.tm_mon + 1) == r.month1() && nowLocal.tm_mday == r.day1())
			{
				if (nowLocal.tm_hour == r.hour1() && nowLocal.tm_min == r.min1())
				{
					
					PlaySound(TEXT("sound/alarm_sound.wav"),NULL,SND_ASYNC);
					cout<<"\t\t\t\t\t Reminder for "<<r.purpose;
					tmpQueue.pop();

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
						reminder r1;

						while (infile.read((char*)&r1, sizeof(r1)))
						{
							if (r1.alarm_id_func() != r.alarm_id)
							{
								outfile.write((char*)&r1, sizeof(r));
							}
						}
						infile.close();
						outfile.close();
						remove("storage/reminder.txt");
						rename("storage/temp.txt", "storage/reminder.txt");
						
						break;
					}
				}

			}
		}

		while(!tmpQueue.empty())
		{
			mainQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}
		
		count++;
		Sleep(1000);
	}
	
}