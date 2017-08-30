#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;
bool isValidChar(char c) {
	switch (c) {
	case '"':
	case ',':
	case '.':
	case ':':
	case '?':
	case '-':
		return true;
	default:
		return false;
	}
}

int main() {
	ifstream file;
	file.imbue(locale());
	file.open("Markov.txt");
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return -1;
	}
	map<string, vector<string>> chain;
	string word;
	vector<string> wordlist;
	while (file >> word) {
		word.erase(remove_if(word.begin(), word.end(), &isValidChar), word.end());
		wordlist.push_back(word);
	}
	file.close();
	int x = 0;
	for (auto const &i : wordlist) { //Only need to read values and create key entry
		if (chain.count(i) == 0) {
			chain[i];
			chain.at(i).push_back(wordlist[x+1]);
		}
		x++;
	}

	for (auto i: chain) {
		cout << i.first << ":";
		for (auto x : i.second) {
			cout << x << endl;
		}
	}
	system("pause");
	return 0;
}
