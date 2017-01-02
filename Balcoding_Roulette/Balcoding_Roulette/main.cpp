#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>
#include <iomanip>
#include <windows.h>
using namespace std;

class List
{
public:
	List()
	{
		tempInitAll();
		tempInitDead();
		subtractList();
	}
	void tempInitAll()
	{
		all.emplace_back("�ʵ�");
		all.emplace_back("���");
		all.emplace_back("ȣ��");
		all.emplace_back("�����ú�");
		all.emplace_back("���ӽ�");
		all.emplace_back("���̳�");
		all.emplace_back("���");
	}
	void tempInitDead()
	{
	}
	void subtractList()
	{
		sort(all.begin(), all.end());
		sort(dead.begin(), dead.end());
		set_difference(all.begin(), all.end()
			, dead.begin(), dead.end()
			, back_inserter(alive));
	}
	vector<string> getAlived()
	{
		subtractList();
		return alive;
	}
private:
	vector<string> all;
	vector<string> dead;
	vector<string> alive;
};
class Roulette
{
public:
	Roulette()
	{
		List force;
		player = force.getAlived();
		size = player.size() - 1;
	}
	void start()
	{
		printResult();
	}
	string getRandomPlayer()
	{
		string result;

		random_device random;
		mt19937 generator;
		generator.seed(random());
		uniform_int_distribution<int> distribution(0, size);
		int choose = distribution(generator);
		result = player[choose];
		return result;
	}
	void printResult()
	{
		printRandom(42, 10);
		printRandom(21, 50);
		printRandom(10, 100);
		printRandom(5, 200);
		printRandom(2, 400);
		printRandom(1, 1);
		cout << "�ٽ� �ұ��?(Y/N)" << endl;
		string input;
		cin >> input;
		if (input == "Y" || input == "y") return printResult();
		if (input == "N" || input == "n") return;
	}

	void printRandom(int count, int millsec)
	{
		string result;
		for (int i = 0; i < count; i++)
		{
			system("cls");
			result = getRandomPlayer();
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << setw(42) << "��÷�� ��� : " << result << endl << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			Sleep(millsec);
		}
		if (count == 1)
			cout << "�̹� �� ���� �����̴� " << result << "��!" << endl;
	}
private:
	vector<string> player;
	int size;
};
int main()
{
	Roulette roulette;
	roulette.start();

	return 0;
}