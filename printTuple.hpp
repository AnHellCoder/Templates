#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>

using namespace std;

template <size_t I = 0, typename... Ts>
typename enable_if<I == sizeof...(Ts),
	void>::type
	print(tuple<Ts...> tup)
{
	// If iterated through all values
	// of tuple, then simply return.
	return;
}

template<size_t I = 0, typename... Args>
typename enable_if<(I < sizeof...(Args)), void>::type
print(tuple<Args...> t) {
	cout << get<I>(t) << ' ';
	print<I + 1>(t);
}

template <typename Ch, typename Tr, typename... Args>
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> t) {
	print(t);
	cout << endl;
}