// kadai01.cpp
#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B

/* --------------------------------------------------------------- */
/*
* is_prime
*
* �^����ꂽ������ x �ɑ΂��āA�f�����ǂ����𔻒肷��
*
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int x) {
	int flag = 0;
	//2����x-1�܂ł̐���x������邩�`�F�b�N����B
	for (int i = 2; i<x; i++) {
		if (x%i == 0) {
			return false;	
		}
		else {
			return true;
		}
	}
}
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int num = a;
	int count = 0;//num���f���ł����1�C���N�������g����B
	while (num < 100000) {
		if (is_prime(num) == true) {
			count++;
		}
		num += d;
		if (count == n) {
			return num;
		}
	}
}




int main() {
	std::cout << nth_prime(179 ,10 ,203) << std::endl;
	//std::cout << nth_prime(367, 186, 151) << std::endl;
	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
	return 0;
}
