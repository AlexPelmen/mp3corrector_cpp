// mp3corrector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <windows.h>
#include "userdata.h"
#include "logger.h"

using namespace std;

//class Logger for output

Logger Log;

int main(int argc, char *argv[])
{	
	UserData * data = new UserData();
	data->set_data_from_args( argc, argv );	//check args and input data, if args are empty 
	Log.out( "All data is checked!" );



	system("pause");
    return 0;
}

