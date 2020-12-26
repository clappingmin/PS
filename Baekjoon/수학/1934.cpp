#include <iostream>
#include <algorithm>

using namespace std;
int gcd(int x,int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}
int lcm(int x,int y) {
	int res = x * y / gcd(x, y);

	return res;
}
int main() {
	int t;
	int x, y;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		cout << lcm(x, y) << endl;
	}

}