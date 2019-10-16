#include "corrector.h"

Corrector::Corrector(fs::path _path_to_ffmpeg)
{
	ffmpeg_path = _path_to_ffmpeg;
}

void Corrector::process(Song * song)
{
	string cmd = ffmpeg_path.string() + " -i ";	//ffmpeg
	cmd = cmd + '"' + song->get_path().string() + "\" -id3v2_version 3 ";	//file	
	cmd = cmd + " -metadata \"" + "title=" + song->get_title() + '"';	//	title
	cmd = cmd + " -metadata \"" + "artist=" + song->get_artist() + '"';	//	artist
	cmd = cmd + " \"" + song->get_path_out().string() + '"';	//path_out
	
	cout << cmd << endl;

	system( cmd.c_str() );	//exec
}


void Corrector::process( SongBuilder songbuilder )
{
	while (Song* song = songbuilder.get_song()) 
	{
		process(song);	
	}
}
