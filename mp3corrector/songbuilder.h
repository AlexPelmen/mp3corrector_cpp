#pragma once

#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "songclass.h"


using namespace std;

namespace fs = boost::filesystem;
namespace ba = boost::algorithm;

typedef std::vector<Song*> songlist;
typedef std::vector<boost::filesystem::path> filelist;

class SongBuilder
{
private:
	int iterator;
	songlist songs;
public:
	SongBuilder();
	Song* get_song();
	
	void iter_to_start() { iterator = 0; }
	void create_song(fs::path _path, fs::path path_out);
	void create_songlist(filelist files, fs::path folder, fs::path path_out);
};

