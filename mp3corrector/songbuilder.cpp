#include "songbuilder.h"

using namespace std;

SongBuilder::SongBuilder()
{
	iterator = 0;
}

Song * SongBuilder::get_song()
{
	return iterator < songs.size() ? songs.at(iterator++) : nullptr;
}

void SongBuilder::create_song(fs::path _path, fs::path path_out ) 
{
	songs.push_back(new Song(_path, path_out ) );
}

void SongBuilder::create_songlist( filelist mp3s, fs::path folder, fs::path twin_folder )
{
	for ( auto& path : mp3s) {
		string path_out = path.string();
		boost::replace_all( path_out, folder.string(), twin_folder.string());
		create_song(path, path_out);
	}
}