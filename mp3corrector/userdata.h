#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "logger.h"

extern Logger Log;

//Pathes to the needed resourses
class UserData {
private:
	std::string ffmpeg;
	std::string folder;
public:
	void set_data_from_args(int argc, char *argv[]);
	void get_ffmpeg_from_user();
	void get_folder_from_user();
	bool is_dir(std::string filename);
};

