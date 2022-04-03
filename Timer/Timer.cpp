/*
issues:
 - timer doesn't do two 0's
 - timer file isn't deleted after program is done
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
using namespace std;

const char* location = "C:\\Users\\alex\\timer.txt";

void timer(ofstream& myfile)
{
    int sec = 0, min = 0, hr = 0;
    while (hr < 24)
    {
		myfile.open(location, ios::out | ios::trunc);
		myfile << hr << ":" << min << ":" << sec << endl;

		Sleep(1000); // wait one second
		sec++;

		if (sec >= 60)
		{
			min++;

			if (min >= 60)
			{
				hr++;
				min = 0;
			}

			sec = 0;
		}
		myfile.close();
    }
}

int main()
{
	cout << "~ Stream Timer! ~" << endl;
    ofstream myfile;
    timer(myfile);
    return 0;
}

