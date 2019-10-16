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
	//vector with 'songclass*'
	songlist songs;

	//iterator for songs-vector
	int iterator;

public:
	//constructor
	SongBuilder();

	//Getter. Get song from songs vector
	Song* get_song();
	
	//set iter to 0
	void iter_to_start() { iterator = 0; }

	//add songclass object 
	void create_song(fs::path _path, fs::path path_out);

	//call create song for every file in 'files'
	void create_songlist(filelist files, fs::path folder, fs::path path_out);
};

