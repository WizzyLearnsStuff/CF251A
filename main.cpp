#include<iostream>
#include<queue>

using namespace std;

#define lli long long int

lli num_pair(lli n) {
	if (n < 2) return 0l;
	else return (n * (n - 1)) / 2;
}

int main() {
	int n, d;
	cin >> n >> d;

	lli s = 0;
	vector<int> v(n);

	for (int &e : v) {
		cin >> e;
	}

	for (int i = 0; i < n; i++) {
		int t = v[i] + d;
		int lo = i;
		int hi = n-1;

		int mid = (lo + hi) / 2;
		while (lo <= hi) {
			if (v[mid] > t) hi = mid - 1;
			else if (v[mid] < t) lo = mid + 1;
			else {
				hi = mid;
				break;
			};
			mid = (lo + hi) / 2;
		}

		int k = hi;
		for (; k < n && v[k] == v[hi]; k++);
		--k;
		// cerr << "DEBUG: k=" << k << " i=" << i << " hi=" << hi << " ret="  << num_pair(k - i) << '\n';
		s += num_pair(k - i);		
	}

	cout << s;
}
