// kadai01.cpp
#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

/* --------------------------------------------------------------- */
/*
* is_prime
*
* 与えられた正整数 x に対して、素数かどうかを判定する
*
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int x) {
	int flag = 0;
	if (x < 2) {
		return false;
	}else if (x == 2) {
		return true;
	}else if (x % 2 == 0) {
		return false;
	}

	double sqx = sqrt(x);
	for (int i = 3;i <=sqx; i += 2) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int num = a;
	int count = 0;//numが素数であれば1インクリメントする。
	while (num < 1000000) {
		if (is_prime(num) == true) {
			count++;
		}
		if (count == n) {
			return num;
		}
		num += d;
	}
}

int main() {
	std::cout << nth_prime(367 ,186 ,151) << std::endl;
	std::cout << nth_prime(179, 10, 203) << std::endl;
	std::cout << nth_prime(271, 37, 39) << std::endl;
	std::cout << nth_prime(103, 230, 1) << std::endl;
	std::cout << nth_prime(27, 104, 185) << std::endl;
	std::cout << nth_prime(253, 50, 85) << std::endl;
	std::cout << nth_prime(1, 1, 1) << std::endl;
	std::cout << nth_prime(9075 ,337 ,210) << std::endl;
	std::cout << nth_prime(307 ,24 ,79) << std::endl;
	std::cout << nth_prime(331 ,221 ,177) << std::endl;
	std::cout << nth_prime(259 ,170 ,40) << std::endl;
	std::cout << nth_prime(269 ,58 ,102) << std::endl;
	// 以下、同様に、入出力例通りになるか確認せよ。
	return 0;
}
