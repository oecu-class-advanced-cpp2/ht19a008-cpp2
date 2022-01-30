#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	「数字が連続で入力されている場合、mcxiの順番が違う場合、mcxiと数字以外の文字が入力されている場合」
	この3つの不適切な入力が合った場合には例外処理を適用し、またvalue_の値を-1を返すようにしている。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		int value_;
		int unit(char c) {
			switch (c) {
			case 'm': return 1000; break;
			case 'c': return 100; break;
			case 'x': return 10; break;
			case 'i': return 1; break;
			}
		}
	public:
		mcxi(const std::string& s) : value_(0) {
			int num = 0;
			int ch = 1001;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					if (*(pos + 1) >= '0' && *(pos + 1) <= '9') {
						std::cout << "数字が連続で入力されています" << std::endl;
						value_ = -1;
						break;
					}else {
						num = (int)(*pos - '0');
					}
				}else if(*pos == 'm'|| *pos == 'c' || *pos == 'x' || *pos == 'i'){
					int u = unit(*pos);
					if (ch > u) {
						value_ += std::max(num, 1) * u;
						ch = u;
						num = 0;
					}else {
						value_ = -1;
						num = 0;
						std::cout << "mcxiの順番が違います" << std::endl;
						break;
					}
				}else {
					value_ = -1;
					std::cout << "不適切な文字が入力されています" << std::endl;
					break;
				}
			}
		}
		/* --------------------------------------------------------------------- */
		/*
		operator +
		2つのオブジェクトの加算結果を取得します。
		*/
		/* --------------------------------------------------------------------- */
		mcxi operator + (mcxi& rhs)
		{
			mcxi nm("");
			nm.value_ = this->value_ + rhs.value_;
			return nm;
		}
		/* --------------------------------------------------------------------- */
		/*
		to_string()
		現在の値をmcxi記述に変換します。
		*/
		/* --------------------------------------------------------------------- */
		std::string mcxi::to_string()
		{
			std::stringstream ss;
			for (int i = 3; i >= 0; i--) {
				char c;
				switch (i) {
				case 3: c = 'm'; break;
				case 2: c = 'c'; break;
				case 1: c = 'x'; break;
				case 0: c = 'i'; break;
				}
				int q = value_ / std::pow(10, i);
				if (q == 1) {
					ss << c;
					value_ = value_ - std::pow(10, i);
				}
				if (q > 1) {
					ss << q;
					ss << c;
					value_ = value_ - std::pow(10, i)*q;
				}
			}
			return ss.str();
		}
	};
	/* --------------------------------------------------------------------- */
	/*
	check
	与えられた回答と計算結果を比較し実装が正しいことを確認する。
	*/
	/* --------------------------------------------------------------------- */
	void check(std::string a, std::string b, std::string answer) {
		cpp2::mcxi mcxi_a(a);
		cpp2::mcxi mcxi_b(b);
		cpp2::mcxi result = mcxi_a + mcxi_b;
		if (result.to_string() == answer) {
			std::cout << a << "+" << b << "は与えられた回答" << answer << "と等しいため正解" << std::endl;
		}else {
			std::cout << a << "+" << b << "は与えられた回答と異なるため不正解" << std::endl;
		}
	}
} // namespace cpp2
int main() {
	cpp2::mcxi c0("ix");//発展課題1のテスト用
	cpp2::mcxi c1("aa");//発展課題1のテスト用
	cpp2::mcxi c2("m2x33i");//発展課題1のテスト用
	cpp2::check("i", "9i", "2x");//発展課題2のテスト用
	cpp2::check("xi", "x9i", "3x");
	cpp2::check("i", "9i", "x");
	cpp2::check("c2x2i", "4c8x8i", "6cx");
	cpp2::check("m2ci", "4m7c9x8i", "5m9c9x9i");
	cpp2::check("9c9x9i", "i", "m");
	cpp2::check("i", "9m9c9x8i", "9m9c9x9i");
	cpp2::check("m", "i", "mi");
	cpp2::check("i", "m", "mi");
	cpp2::check("m9i", "i", "mx");
	cpp2::check("9m8c7xi", "c2x8i", "9m9c9x9i");
}

