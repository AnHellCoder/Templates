#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>

using namespace std;

template <typename T> tuple<T> parse(istream& is) {
	T t;
	is >> t;
	return tuple<T>(move(t));
}

template <typename T, typename Arg, typename... Args>
tuple<T, Arg, Args...> parse(istream& is) {
	T t; is >> t;
	return tuple_cat(tuple<T>(move(t)), parse<Arg, Args...>(is));
}

template <typename... Args>
tuple<Args...> parse(const string& str) {
	istringstream is(str);
	return parse<Args...>(is);
}