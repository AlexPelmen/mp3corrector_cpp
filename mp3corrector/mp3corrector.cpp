// mp3corrector.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <boost/filesystem.hpp>

#include "userdata.h"
#include "logger.h"
#include "songbuilder.h"
#include "dirmanager.h"
#include "corrector.h"

using namespace std;

//class Logger for output
typedef std::vector<boost::filesystem::path> filelist;

Logger Log;

int main(int argc, char *argv[])
{	
	UserData * data = new UserData();
	//data->set_data_from_args( argc, argv );	//check args. Input data if the args are empty 
	Log.out( "All data is checked!" );
	
	setlocale(LC_ALL, "rus");
	namespace fs = boost::filesystem;

	DirManager dirman("C:\\Users\\Pelmen\\Desktop\\Test");
	filelist mp3s = dirman.get_mp3s();

	SongBuilder songbuilder;
	songbuilder.create_songlist( mp3s, dirman.get_folder(), dirman.get_twin_folder() );
	
	//Corrector corrector( data->get_ffmpeg() );
	Corrector corrector( "ffmpeg" );
	corrector.process(songbuilder);

	system("pause");
    return 0;
}

