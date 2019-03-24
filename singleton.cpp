#include"DxLib.h"
#include"singleton.h"
Singleton* Singleton::instance = nullptr;

int Singleton::LoadTextrue(std::string file_name) {

	// すでに管理マップに登録されているかチェックして
	// 登録済みであればそのハンドルを返す
	if (map_graphic_handle.find(file_name)
		!= map_graphic_handle.end()) {
		return map_graphic_handle[file_name];
	}

	// 新規のロードであればロードしたデータと
	// 画像のファイル名を管理マップに登録し
	// ロードしたデータを返す
	int handle = LoadGraph(file_name.c_str());
	map_graphic_handle.insert(
		std::make_pair(file_name, handle));

	return handle;
}