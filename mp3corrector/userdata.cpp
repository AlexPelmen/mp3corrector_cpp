#include "stdafx.h"
#include "userdata.h"

using namespace std;

//Check path to ffmpeg 
void UserData::get_ffmpeg_from_user()
{
	try {
		cout << "Input path to 'ffmpeg.exe': " << endl;
		getline(cin, ffmpeg);	//get data from user

		string cmd = ffmpeg + " -version";
		cout << endl;
		int code = system(cmd.c_str());
		cout << endl;
		if (code) {				//can't start ffmpeg
			Log.stop("Error with ffmpeg, code - " + std::to_string(code));
			exit(0);
		}
	}
	catch (int err) {			//smth wrong with opening
		Log.stop("Wrong ffmpeg path! Use -h fro help");
		exit(0);
	}
}



//Foo to convert string to wstring
std::wstring ConvertStringToWstring(const std::string &str)
{
	if (str.empty())
	{
		return std::wstring();
	}
	int num_chars = MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, str.c_str(), str.length(), NULL, 0);
	std::wstring wstrTo;
	if (num_chars)
	{
		wstrTo.resize(num_chars);
		if (MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, str.c_str(), str.length(), &wstrTo[0], num_chars))
		{
			return wstrTo;
		}
	}
	return std::wstring();
}



//get user input with folder
void UserData::get_folder_from_user()
{
	try {
		cout << "Input path to folder with mp3 filse: " << endl;
		getline(cin, folder);	//get data from user
		bool test = is_dir(folder);	//check
		if (!test)
			throw 1;
	}
	catch (int err) {
		Log.stop("Wrong path to folder!");
		exit(0);
	}
}



//checks if the path is directory
bool UserData::is_dir(string filename)
{
	wstring filename_w = ConvertStringToWstring(filename);
	DWORD dwFileAttributes = GetFileAttributes(filename_w.c_str());
	if (dwFileAttributes == 0xFFFFFFFF)
		return false;
	return dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
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
