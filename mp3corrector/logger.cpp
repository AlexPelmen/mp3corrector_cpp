#include "stdafx.h"
#include "logger.h"


//output message and stop
void Logger::stop(string txt)
{
	{
		cout << txt << endl;
		system("pause");
	}
}
