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
	//check args. Input data if the args are empty 
	UserData data;
	data.set_data_from_args( argc, argv );	
	Log.out( "All data is checked!" );
	
	setlocale(LC_ALL, "rus");
	namespace fs = boost::filesystem;

	//create pathes and twin directories
	DirManager dirman( data.get_folder() );
	filelist mp3s = dirman.get_mp3s();

	Log.out( "Twin folders has been created!" );

	//song builder class to create song objects for every .mp3 file
	SongBuilder songbuilder;
	songbuilder.create_songlist( mp3s, dirman.get_folder(), dirman.get_twin_folder() );

	//corrector executes cmd command to correct every .mp3
	Corrector corrector( data.get_ffmpeg() );
	corrector.process(songbuilder);

	Log.out("Finished!");

	system("pause");
    return 0;
}

