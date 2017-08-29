#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	ifstream file;
	file.open("Markov.txt");
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return -1;
	}
	string word;
	while (file >> word) {
		cout << word << " ";
	}
	file.close();
	map<string, vector<string>> chain;
	vector<string> options;
	string option;
	options.push_back("Testi 1");
	chain["testi"] = options;
	chain.at("testi").push_back("Testi 2");
	options.push_back("Testi 3");
	chain["testi 1"] = options;
	for (auto i: chain) {
		for (auto x : i.second) {
			cout << x << endl;
		}
	}
	system("pause");
	return 0;
}