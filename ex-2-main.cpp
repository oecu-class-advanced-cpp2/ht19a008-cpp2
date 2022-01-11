#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
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
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				//*pos は、char ! char ってことが分かってたら、もっと簡単にできるのでは？？
				if (*pos >= '2' && *pos <= '9') {
					num = (int)(*pos - '0');
				}
				else {
					int u = unit(*pos);
					value_ += std::max(num, 1) * u;
					num = 0;
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
} // namespace cpp2
int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	cpp2::mcxi result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;
	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	cpp2::mcxi result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	cpp2::mcxi result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;
	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	cpp2::mcxi result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	cpp2::mcxi result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	cpp2::mcxi result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	cpp2::mcxi result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	cpp2::mcxi result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	cpp2::mcxi result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	cpp2::mcxi result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}

