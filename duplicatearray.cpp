#include<iostream>
#include <array>
#include <unordered_map>
using namespace std;



std::array<int, 9> inp = { 2, 3, 4, 4, 1, 2, 3, 3,6 };
unordered_map<int, int> hashtable;

//form a hashtable from the array only unique keys are stored thus achieving our goal
void formhashtable(array<int, 9>& tempinp)
{

	for (int a : tempinp) {
		hashtable.emplace(a, NULL);
	}


}

void main()
{
	unsigned loopcnt = 0;
	formhashtable(inp);
	inp.fill(0);

	for (auto &itr : hashtable)
	{
		inp[loopcnt] = itr.first;
		++loopcnt;
	}

	for (int i : inp)
	{
		cout << i << endl;
	}


}
