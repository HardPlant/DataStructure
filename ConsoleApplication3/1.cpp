#include <iostream>
#include <string>

using namespace std;

class Coffee {
public:
	Coffee()
	{
		cout << "<Ŀ��>" << endl;
	}
};
class Latte : public Coffee {
public:
	Latte()
	{
		print("��");
	}
	void print(string n) // ����� �κ��̹Ƿ� Coffee�� �ű�� �� �� ���� �� ����.
	{
		cout << n << " �Դϴ�." << endl;
	}
};
class Mocha : public Coffee {
public:
	Mocha()
	{
		print("��ī");
	}
	void print(string n)
	{
		cout << n << " �Դϴ�." << endl;
	}
};
class Cappuccino : public Coffee {
public:
	Cappuccino()
	{
		print("īǪġ��");
	}
	void print(string n)
	{
		cout << n << " �Դϴ�." << endl;
	}
};
class Americano : public Coffee {
public:
	Americano()
	{
		print("�Ƹ޸�ī��");
	}
	void print(string n)
	{
		cout << n << " �Դϴ�." << endl;
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
