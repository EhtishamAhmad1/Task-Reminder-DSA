#include<iostream>
using namespace std;
void menu()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,3);
    cout<<"   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"   ||   ______   ____    ____               ____   ____   _      _   ____   _        ____   ____   ____   ||"<<endl;
    cout<<"   ||  |__  __| | __ |  | ___|  || //      | __ | | ___| | \\    / | |_  _| | \\   || | __ | | ___| | __ |  ||"<<endl;
    cout<<"   ||     ||    ||__||  ||___   ||//       ||__|| ||__   ||\\\\__//||   ||   ||\\\\  || ||  || ||__   ||__||  ||"<<endl;
    cout<<"   ||     ||    | __ |  |___ |  | |        | _ _| | __|  || \\__/ ||   ||   || \\\\ || ||  || | __|  | _ _|  ||"<<endl;
    cout<<"   ||     ||    ||  ||   ___||  ||\\\\       || \\\\  ||___  ||      ||  _||_  ||  \\\\|| ||__|| ||___  || \\\\   ||"<<endl;
    cout<<"   ||     ||    ||  ||  |____|  || \\\\      ||  \\\\ |____| ||      || |____| ||   \\_| |____| |____| ||  \\\\  ||"<<endl;
    cout<<"   ||                                                                                                     ||"<<endl;
    cout<<"   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"<<endl;
    SetConsoleTextAttribute(h,7);
}
