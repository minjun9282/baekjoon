#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for(auto iter = a.begin(); iter != a.end(); iter++){
        ans += *iter;
    }
	return ans;
}
