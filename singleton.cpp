#include"DxLib.h"
#include"singleton.h"
Singleton* Singleton::instance = nullptr;

int Singleton::LoadTextrue(std::string file_name) {

	// ���łɊǗ��}�b�v�ɓo�^����Ă��邩�`�F�b�N����
	// �o�^�ς݂ł���΂��̃n���h����Ԃ�
	if (map_graphic_handle.find(file_name)
		!= map_graphic_handle.end()) {
		return map_graphic_handle[file_name];
	}

	// �V�K�̃��[�h�ł���΃��[�h�����f�[�^��
	// �摜�̃t�@�C�������Ǘ��}�b�v�ɓo�^��
	// ���[�h�����f�[�^��Ԃ�
	int handle = LoadGraph(file_name.c_str());
	map_graphic_handle.insert(
		std::make_pair(file_name, handle));

	return handle;
}