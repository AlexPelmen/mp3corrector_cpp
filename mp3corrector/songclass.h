#pragma once
#include <string>
#include <boost/filesystem.hpp>
#include <iostream>

using namespace std;
namespace fs = boost::filesystem;

class Song
{
private:
	//pathes for the .mp3 corrector process
	fs::path path;
	fs::path path_out;

	//id3s
	string title;
	string artist;

public:
	//constructor
	Song(fs::path _path, fs::path _path_out);

	//getters
	fs::path get_path() { return path; }
	fs::path get_path_out() { return path_out; }
	string get_title() { return title; }
	string get_artist() { return artist; }

	//check if we can get id3s from the name
	bool is_suitable_name();

	//get id3s from the name of the file
	void get_id3s();
};

