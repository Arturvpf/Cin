#include <iostream>
#include <vector>

bool isSubsetSum(std::vector<int> set, int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);
    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main() {
    std::vector<int> set = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = set.size();
    if (isSubsetSum(set, n, sum) == true)
        std::cout << "Found a subset with given sum";
    else
        std::cout << "No subset with given sum";
    return 0;
}