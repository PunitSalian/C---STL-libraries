#include "iostream"
#include "map"
#include "string"
#include "vector"
using namespace std;
map<string, int> result;


/*
	This function uses dynamic programming  to calculate the number of employees

*/
int employeecount(map < string, vector<string>>dependency, string temp)

{

	if (result.find(temp) != result.end()) {

		return result[temp];

	}
	int count = 0;
	if (dependency.find(temp) == dependency.end()) {


		return 0;

	}


	vector<string> tempstring = dependency[temp];
	count = tempstring.size();
	for (vector<string>::iterator it = tempstring.begin(); it != tempstring.end(); it++) {

		count += employeecount(dependency, *it);

	}
	result[temp] = count;
	return count;
}

/*
This function makes a dictionary of dependency list as value and each manager as a key

*/
void Employeeundermanager(map<string, string> data)
{
	map < string, vector<string>> dependencyofmanager;

	for (map<string, string>::iterator it = data.begin(); it != data.end(); it++) {
		string manager = it->second;
		string employee = it->first;
		if (!employee.compare(manager)) continue;
		vector<string>employeelist;

		if (dependencyofmanager.end() != dependencyofmanager.find(manager)) {
			employeelist = dependencyofmanager[manager];
		}

		employeelist.push_back(employee);
		dependencyofmanager[manager] = employeelist;

	}


	for (map<string, string>::iterator it = data.begin(); it != data.end(); it++) {

		int count = 0;
		count = employeecount(dependencyofmanager, it->first);
		cout << it->first << "  :  " << count << endl;

	}
}





void main()
{
	map<string, string> dataset;
	dataset["F"] = "F";
	dataset["A"] = "C";
	dataset["B"] = "C";
	dataset["C"] = "F";
	dataset["D"] = "E";
	dataset["E"] = "F";
	Employeeundermanager(dataset);

}
