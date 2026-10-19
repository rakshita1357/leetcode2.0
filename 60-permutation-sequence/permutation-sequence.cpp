class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int factorial = 1;
        // Prepare list of numbers and factorial of (n-1)
        for (int i = 1; i < n; i++) {
            numbers.push_back(i);
            factorial *= i;
        }
        numbers.push_back(n);

        k = k - 1; // zero-based index
        string result;

        // Construct the k-th permutation
        while (!numbers.empty()) {
            int index = k / factorial;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            if (numbers.empty()) break;

            k %= factorial;
            factorial /= (int)numbers.size();
        }
        return result;
    }
};