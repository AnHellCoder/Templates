#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include "parseTuple.hpp"
#include "printTuple.hpp"

using namespace std;

template<typename... Args>
class CSVParser {
private:
	string punctRemove(string s) {
		while (s.find(',') != string::npos) {
			int temp = s.find(',');

			s.replace(temp, 1, " ");
		}

		return s;
	}

public:
	vector<tuple<Args...>> t;

	CSVParser(ifstream& f, int skip) {
		string s;

		while (skip > 0) {
			getline(f, s);
			skip -= 1;
		}

		while (!f.eof()) {
			getline(f, s);
			s = punctRemove(s);
			t.push_back(parse<Args...>(s));
		}
	}

	void print() {
		for (int i = 0; i < t.size(); i++) operator<<(cout, t[i]);
	}
};

int main() {
	setlocale(LC_ALL, "Rus");
	ifstream f("input.txt");

	CSVParser<string, int, double> emp(f, 42000);

	emp.print();
}