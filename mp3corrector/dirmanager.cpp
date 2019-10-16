#include "dirmanager.h"

extern Logger Log;	//form mp3corrector

//constructor
DirManager::DirManager( fs::path _path )
{
	folder = _path;
	folder_name = fs::basename(_path);
	twin_folder = create_twin_folder();
	twin_folder_name = fs::basename( twin_folder );

	Log.out("Created folder: '" + twin_folder_name + "'");

	find_files();
	create_subfolders();
	
}


//create twin directory
string DirManager::create_twin_folder()
{
	string twin_folder = fs::basename(folder) + "_corrected";

	bool ok = false;
	int num = 1;

	//try to create directory with different names
	fs::path mkdir_path = folder.parent_path();
	mkdir_path.append(twin_folder);
	while (!boost::filesystem::create_directory(mkdir_path))
	{
		mkdir_path = folder.parent_path();
		mkdir_path.append(twin_folder + to_string(++num));
	}
	return mkdir_path.string();
}

//create subfolders in the twin folder
void DirManager::create_subfolders()
{
	for ( const auto& path : folders )
	{
		string path_str = path.string();
		boost::replace_all(path_str, folder.string(), twin_folder.string());
		bool test = boost::filesystem::create_directory(path_str);
		
		if (!test)
			Log.out("Folder '" + path.string() + "' can't be created!");
	}
	cout << "subs" << endl;
}

//searches all .mp3s and subfolders in the folder
void DirManager::find_files()
{
	filelist files_and_folders{ fs::recursive_directory_iterator(folder),
		fs::recursive_directory_iterator() };

	//leave mp3s only
	for (const auto& path : files_and_folders)
	{
		if (fs::is_directory(path))
			folders.push_back(path);
		if (fs::extension(path) == ".mp3")
			mp3s.push_back(path);
	}
}