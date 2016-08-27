#include <iostream>
#include <map>
#include <string>
using namespace std;

void print(map<string, string> data){
	// To store reverse of given map to-from format
	map<string, string> reversemap;
	map<string, string>::iterator it;

	// form a reverse map
	for (it = data.begin(); it != data.end(); it++)
		reversemap[it->second] = it->first;

	// Find the starting point of itinerary
	string start;

	for (it = data.begin(); it != data.end(); it++){
		if (reversemap.find(it->first) == reversemap.end()){
			start = it->first;
			break;
		}
	}



	// as we get the starting point we just need to iterate 
	it = data.find(start);
	while (it != data.end()){
		cout << it->first << "to" << it->second << endl;
		it = data.find(it->second);
	}

}

int main(){
	map<string, string> data;
	data["LAX"] = "SFO";
	data["DCA"] = "LAX";
	data["SEA"] = "DCA";
	data["SFO"] = "JFK";

	print(data);

	return 0;
}
