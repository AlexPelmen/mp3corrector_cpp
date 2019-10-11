#pragma once

#include <string>
#include <iostream>

using namespace std;

class Logger {
public:
	void out(string txt) { cout << txt << endl; }
	void stop(string txt)
	{
		cout << txt << endl;
		system("pause");
	}
};

