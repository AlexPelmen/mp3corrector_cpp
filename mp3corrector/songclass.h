#pragma once
#include <string>
#include <boost/filesystem.hpp>
#include <iostream>

using namespace std;
namespace fs = boost::filesystem;

class Song
{
private:
	fs::path path;
	fs::path path_out;
	string title;
	string artist;
public:
	Song(fs::path _path, fs::path _path_out);

	//getters
	fs::path get_path() { return path; }
	fs::path get_path_out() { return path_out; }
	string get_title() { return title; }
	string get_artist() { return artist; }

	bool is_suitable_name();
	void get_id3s();
};

