#include "stdafx.h"
#include "userdata.h"

using namespace std;

//Check path to ffmpeg 
void UserData::get_ffmpeg_from_user()
{
	string path;
	try {
		cout << "Input path to 'ffmpeg.exe': " << endl;
		getline(cin, path);	//get data from user

		string cmd = path + " -version";
		cout << endl;
		int code = system(cmd.c_str());
		cout << endl;
		if (code) {				//can't start ffmpeg
			Log.stop("Error with ffmpeg, code - " + std::to_string(code));
			exit(0);
		}

		ffmpeg = path;	//set path to ffmpeg
	}
	catch (int err) {			//smth wrong with opening
		Log.stop("Wrong ffmpeg path! Use -h fro help");
		exit(0);
	}
}



//get user input with folder
void UserData::get_folder_from_user()
{
	string path;
	try {
		cout << "Input path to folder with mp3 filse: " << endl;
		getline(cin, path);	//get data from user
		bool test = boost::filesystem::is_directory(path);	//check
		if (!test)
			throw 1;

		folder = path;	//set the path ot folder
	}
	catch (int err) {
		Log.stop("Wrong path to folder!");
		exit(0);
	}
}



//function to get all args and check it
void UserData::set_data_from_args(int argc, char *argv[]) {
	try {
		if (argc == 1)
			throw 1;
		ffmpeg = argv[1];
		folder = argv[2];
	}
	catch (int a) {
		Log.out("Cant't get args form user");
		get_ffmpeg_from_user();
		get_folder_from_user();
	}
}
