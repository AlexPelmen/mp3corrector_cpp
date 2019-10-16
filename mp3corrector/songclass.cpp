#include "songclass.h"

Song::Song(fs::path _path, fs::path _path_out )
{
	path = _path;
	path_out = _path_out;

	if (is_suitable_name()) {
		get_id3s();
	}
}

//checks if the name is suitable for mp3corrector
bool Song::is_suitable_name()
{	
	string basename = fs::basename(path);
	return strstr(basename.c_str(), " - ") ? true : false;
}

void Song::get_id3s()
{
	vector<char> title_v;
	vector<char> artist_v;

	string basename = fs::basename(path);
	bool flag = false;

	for (int i = 0; basename[i] != '\0'; i++)
	{
		char c = basename[i];
		if (c == '-' && !flag) {
			flag = true;
			continue;
		}
		if (!flag)
			artist_v.push_back(c);
		else
			title_v.push_back(c);
	}
	title = string(title_v.begin(), title_v.end());
	artist = string(artist_v.begin(), artist_v.end());
}
