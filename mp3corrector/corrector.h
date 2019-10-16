#pragma once
#include <boost/filesystem.hpp>
#include "songclass.h"
#include "songbuilder.h"

using namespace std;
namespace fs = boost::filesystem;
typedef std::vector<Song*> songlist;

class Corrector
{
private:
	fs::path ffmpeg_path;
public:
	//constructor
	Corrector( fs::path _path_to_ffmpeg);

	//executes cmd command for song object
	void process(Song* song);

	//call process for every song in songbuilder
	void process(SongBuilder songbuilder);
};

