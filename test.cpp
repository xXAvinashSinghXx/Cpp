#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

long long convertToNumber(string numStr) {
    char suffix = numStr.back();
    long long multiplier = 1;

    if (suffix == 'k' || suffix == 'K') multiplier = 1000;
    else if (suffix == 'm' || suffix == 'M') multiplier = 1000000;
    else if (suffix == 'b' || suffix == 'B') multiplier = 1000000000;
    else if (suffix == 't' || suffix == 'T') multiplier = 1000000000000LL;
    else return stoll(numStr); 

    numStr.pop_back();
    return stoll(numStr) * multiplier;
}

string formatWithCommas(long long num) {
    string numStr = to_string(num);
    int n = numStr.length();

    string result;
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        result = numStr[i] + result;
        count++;
        if (count % 3 == 0 && i != 0) {
            result = ',' + result;
        }
    }
    return result;
}

int main() {
    vector<long long> nums;
    string input;

    cout << "Enter numbers separated by spaces (use k, m, b, t for large numbers): ";
    getline(cin, input);

    stringstream ss(input);
    string numStr;

    while (ss >> numStr) {
        nums.push_back(convertToNumber(numStr));
    }

    long long sum = 0;
    for (long long i : nums) {
        sum += i;
    }

    cout << "Sum: " << formatWithCommas(sum) << endl;

    return 0;
}
