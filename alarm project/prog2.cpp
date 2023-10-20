#include"lib/timetell.h"

using namespace std;


int main()
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,11);
	timetell();
	SetConsoleTextAttribute(h,7);
}
	
