#include "songbuilder.h"

using namespace std;

//constructor
SongBuilder::SongBuilder()
{
	iterator = 0;
}


//getter. Get song from vector 'songs'
Song * SongBuilder::get_song()
{
	return iterator < songs.size() ? songs.at(iterator++) : nullptr;
}


//add songclass object 
void SongBuilder::create_song(fs::path _path, fs::path path_out ) 
{
	songs.push_back(new Song(_path, path_out ) );
}


//call create song for every file in 'files'
void SongBuilder::create_songlist( filelist mp3s, fs::path folder, fs::path twin_folder )
{
	for ( auto& path : mp3s) {
		string path_out = path.string();
		boost::replace_all( path_out, folder.string(), twin_folder.string());
		create_song(path, path_out);
	}
}