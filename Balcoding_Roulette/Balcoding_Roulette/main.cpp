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
		all.emplace_back("초동");
		all.emplace_back("상상");
		all.emplace_back("호준");
		all.emplace_back("나무늘보");
		all.emplace_back("제임스");
		all.emplace_back("도미노");
		all.emplace_back("뱁새");
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
		cout << "다시 할까요?(Y/N)" << endl;
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
			cout << setw(42) << "당첨된 사람 : " << result << endl << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			Sleep(millsec);
		}
		if (count == 1)
			cout << "이번 주 과제 나누미는 " << result << "님!" << endl;
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