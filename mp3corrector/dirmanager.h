#pragma once
#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "logger.h"


using namespace std;
namespace fs = boost::filesystem;
typedef std::vector<boost::filesystem::path> filelist;

class DirManager
{
private:
	fs::path folder;
	fs::path twin_folder;

	string folder_name;
	string twin_folder_name;

	filelist mp3s;
	filelist folders;
public:
	DirManager( fs::path _path);

	//getters
	fs::path get_folder() { return folder; }
	fs::path get_twin_folder() { return twin_folder; }
	string get_folder_name() { return folder_name; }
	string get_twin_folder_name() { return twin_folder_name; }
	filelist get_mp3s() { return mp3s; }

	string create_twin_folder();
	void create_subfolders();
	void find_files();
};

