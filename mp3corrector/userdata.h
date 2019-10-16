#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <boost/filesystem.hpp>
#include "logger.h"

extern Logger Log;
namespace fs = boost::filesystem;

//Pathes to the needed resourses
class UserData {
private:
	fs::path ffmpeg;
	fs::path folder;
public:

	//getters
	fs::path get_ffmpeg() { return ffmpeg; }
	fs::path get_folder() { return folder; }

	void set_data_from_args(int argc, char *argv[]);
	void get_ffmpeg_from_user();
	void get_folder_from_user();
};

