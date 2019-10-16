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
	Corrector( fs::path _path_to_ffmpeg);
	void process(Song* song);
	void process(SongBuilder songbuilder);
};

