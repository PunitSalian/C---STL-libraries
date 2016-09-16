
/*
string S represented by ABC
permute set S, we can select the first character A permute the remainder of the string to get a new list.
with that new list, we can push A into each possible position.
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;


string insert(string temp, int i, char firchar)
{
	return temp.substr(0, i) + firchar + temp.substr(i);

}

vector<string> permutes(string &x)
{


	vector<string> word;
	if (x.length() == 0)
	{
		word.push_back("");
		return word;
	}
	char firchar = x[0];
	string remain = x.substr(1);
	vector<string> tempword = permutes(remain);
	for (string str : tempword)
	{
		for (int i = 0; i <= str.length(); i++)
			word.push_back(insert(str, i, firchar));
	}

	return word;



}


void main()
{
	vector<string> x;

	string a("ABC");


	x = permutes(a);

	for (string str : x)
	{
		cout << str << "  ";
	}




}
