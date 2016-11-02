#include <iostream>
#include <string>

using namespace std;

class Coffee {
public:
	Coffee()
	{
		cout << "<커피>" << endl;
	}
};
class Latte : public Coffee {
public:
	Latte()
	{
		print("라떼");
	}
	void print(string n) // 공통된 부분이므로 Coffee로 옮기는 게 더 나을 것 같음.
	{
		cout << n << " 입니다." << endl;
	}
};
class Mocha : public Coffee {
public:
	Mocha()
	{
		print("모카");
	}
	void print(string n)
	{
		cout << n << " 입니다." << endl;
	}
};
class Cappuccino : public Coffee {
public:
	Cappuccino()
	{
		print("카푸치노");
	}
	void print(string n)
	{
		cout << n << " 입니다." << endl;
	}
};
class Americano : public Coffee {
public:
	Americano()
	{
		print("아메리카노");
	}
	void print(string n)
	{
		cout << n << " 입니다." << endl;
	}
};
int main()
{
	Americano a;
	Cappuccino c;
	Latte l;
	Mocha m;
	return 0;
}
