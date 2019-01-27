// Introductuion to Algorithm Chapter 15.1

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cutRod_Native(const vector<int> price, const int len) {
	if (len == 0)
		return 0;
	int result = -1;
	for (int i = 1; i <= len; i++)
		result = std::max(result, price.at(i) + cutRod_Native(price, len - i));

	return result;
}

int cutRod_memoized_aux(const vector<int> price, const int len, vector<int> &r) {
	if (r.at(len) >= 0)
		return r.at(len);
	int q = -2;
	if (len == 0)
		q = 0;
	else {
		for (int i = 1; i <= len; ++i)
			q = std::max(q, price.at(i)+cutRod_memoized_aux(price, len - i, r));
	}
	r.at(len) = q;
	return q;
}
int cutRod_memoized(const vector<int> price, const int len) {
	vector<int> r(len+1, -1);
	return cutRod_memoized_aux(price, len, r);
}

int cutRod_BottomUp(const vector<int> price, const int len) {
	vector<int> r(len + 1, 0);
	for (int j = 1; j <= len; ++j) {
		int q = -1;
		for (int i = 1; i <= j; ++i) {
			q = std::max(q, price.at(i) + r[j - i]);
		}
		r.at(j) = q;
	}
	return r.at(len);
}

int main(){
    vector<int> price{0,1,5,8,9,10,17,17,20,24,30};
    int length = 4;
    int result = cutRod_BottomUp(price, length);
    cout << result << endl;
    return 0;
}