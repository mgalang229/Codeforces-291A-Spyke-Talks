#include <bits/stdc++.h>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// create a vector that would store values that are
	// STRICTLY greater than 0
	vector<int> id;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			// store the value if and only if it's greater than 0
			id.emplace_back(x);
		}
	}
	// sort the vector in non-decreasing order
	sort(id.begin(), id.end());
	// create a 'prev' variable to store the previous element
	int prev = 0;
	// create a 'pairs' variable to count the number of pairs
	int pairs = 0;
	// create a 'cnt' to count the occurrences of each number
	int cnt = 0;
	for (int i = 0; i < (int) id.size(); i++) { 
		if (id[i] != prev) {
			// if the current is not equal to the previous, then reset the counter
			cnt = 1;
		} else if (id[i] == prev) {
			// otherwise, it means that it has a pair connected to it so increase the counter
			cnt++;
		}
		if (cnt > 2) {
			// if the counter is greater than 2, then it is not possible
			// so store -1 to the 'prev' variable and stop the loop
			pairs = -1;
			break;
		} else if (cnt == 2) {
			// otherwise, if the counter is exactly equal to 2,
			// then increment the 'pairs' variable
			pairs++;
		}
		// store the current element to be used in the next iteration
		prev = id[i];
	}
	cout << pairs << '\n';
}
