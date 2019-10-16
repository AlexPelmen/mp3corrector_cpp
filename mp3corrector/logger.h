#pragma once

#include <string>
#include <iostream>

using namespace std;

class Logger {
public:
	//just outputs message
	void out(string txt) { cout << txt << endl; }

	//outputs message and stop programm
	void stop(string txt);
};

