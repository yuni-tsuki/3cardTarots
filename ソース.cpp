#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std; 

string name_conversion(int symbolArcana)
{
	//��A���J�i�̔ԍ��ɉ������J�[�h����string�^�œn��
	if (symbolArcana >= 22) {
		return "error";
	}

	vector<string> arcanaName(22);
	arcanaName = { 
		          "����", "���p�t", "�����c", "����", "�c��", "�@��", 
				  "���l", "���", "��", "�B��", "�^���̗�", "���`", 
				  "�݂邵�l", "���_", "�ߐ�", "����", "��", "��", 
				  "��", "���z", "�R��", "���E" 
	             };
	
	return arcanaName.at(symbolArcana);
}

string position_conversion(int symbolPosition)
{
	if (symbolPosition == 0) {
		return "���ʒu";
	}
	else if (symbolPosition == 1) {
		return "�t�ʒu";
	}
	else {
		return "error";
	}
}

string symbol_output(int symbolArcana, int symbolPosition)
{
	if (symbolArcana >= 22 || symbolPosition >= 2) {
		return "error";
	}

	vector<vector<string>> vecSymbol(2, vector<string>(22));
	vecSymbol = { {"�������A���R�l", "�Ƒn���@�Z�p�́@�]�@",
		          "�v���[���@�w�͉�", "�ɉh�@�L�����@���n", 
		          "�D�ꂽ�w���́@�ӔC��", "�P�ǁ@����", 
		          "�j�����ꂽ���@�V��", "�R���g���[���@�����@�ړ�", 
	          	  "���₩�ȋ����@�ϋɐ�", "�v�����ʁ@�ǂ����k����", 
		          "�����̍D�]�@�^���I�ȏo����", "�o�����X�̎�ꂽ���f�@�펯�I", 
		          "���ȋ]����", "�I�~�@�����ω�", 
		          "�K���@���d", "�ϑz�ɂƂ����@�U�f", 
		          "�}�ȃg���u���@����", "��]�@����", 
		          "�s����@�R", "�����@��]������", 
		          "�����@����@�ϊv", "�����@����"
		         },
		         {"�v�搫�̖����A�񋦒��I", "�����]���̎����@�o���s��", 
	              "�����͂����@�C���", "�s����Ȉ��@���", 
	              "�コ�@�D�_�s�f", "�s���߂����s���@�M�S�̖���", 
	              "�Y�݁@�O�p�֌W", "����Ȃ������@�Ɛ�~", 
		          "�U�f�ɕ�����@���C��", "�s�M�@�l�t�����������", 
		          "�ǂ����̂������Ȃ�@�h�����瓦����Ȃ�", "�s���@�΂�", 
		          "���Ӗ��ȕ�d�@�S��", "�V���ȏo���@�ǂ��ω�", 
		          "�s�с@�E�ϗ̖͂���", "�X���@�ڂ��o�߂�", 
		          "�㎀�Ɉꐶ�𓾂�", "�ߊϓI�@�傫�����闝�z", 
		          "�R�ɋC�Â��@�������Ă��ފ댯�ȏo����", "���~�@�]�݂�����Ȃ�", 
		          "�������@�x��", "�ڍ��@����"
	             },
	            };

	return vecSymbol.at(symbolPosition).at(symbolArcana);
}

void play(int majorArcanaNum, int uprightReverseNum) {
	cout << majorArcanaNum << "�ԁA";
	cout << name_conversion(majorArcanaNum) << "��";
	cout << position_conversion(uprightReverseNum) << "�������܂����B" << endl;

	cout << symbol_output(majorArcanaNum, uprightReverseNum) << " �̏ے��ł��B" << endl;
}

int main()
{
	srand(time(NULL));

	int firstMajorArcanaNum = rand() % 22; //��A���J�i�̔ԍ�
	int firstUprightReverseNum = rand() % 2; //0�����ʒu�A1���t�ʒu

	cout << "�^���b�g�肢���n�߂܂��傤�B" << endl;
	cout << "�܂��ߋ���肢�܂��B";
	cout << "Enter�L�[�������Ă��������B" << endl;

	getchar();

	play(firstMajorArcanaNum, firstUprightReverseNum); //�ߋ����o��


	cout << "���Ɍ��݂�肢�܂��B";
	cout << "Enter�L�[�������Ă��������B" << endl;

	getchar();

	int secondMajorArcanaNum = firstMajorArcanaNum; //1��ڂ�rand���m���ɍs��

	while (1 == 1) {
		if (firstMajorArcanaNum == secondMajorArcanaNum) {
			secondMajorArcanaNum = rand() % 22; //��A���J�i
		}
		else {
			break; //���ڂƈႤ��A���J�i����������I��
		}
	}

	int secondUprightReverseNum = rand() % 2; //0�����ʒu�A1���t�ʒu

	play(secondMajorArcanaNum, secondUprightReverseNum); //���݂��o��


	cout << "�Ō�ɖ�����肢�܂��B";
	cout << "Enter�L�[�������Ă��������B" << endl;

	getchar();

	int finalMajorArcanaNum = firstMajorArcanaNum;

	while (1 == 1) {
		if (firstMajorArcanaNum == finalMajorArcanaNum || secondMajorArcanaNum == finalMajorArcanaNum) {
			finalMajorArcanaNum = rand() % 22; //��A���J�i
		}
		else {
			break; //1,2��ڂƈႤ��A���J�i����������I��
		}
	}

	int finalUprightReverseNum = rand() % 2; //0�����ʒu�A1���t�ʒu

	play(finalMajorArcanaNum, finalUprightReverseNum); //�������o��


	cout << "����Ń^���b�g�肢���I���܂��B�悢������B" << endl;
}