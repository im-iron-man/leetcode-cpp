class Solution {
public:
    int countPrimes(int n) {
        bool* a = new bool[n]();
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (!a[i]) {
                cnt++;
                for (int j = 2; i * j < n; j++) {
                    a[i * j] = true;
                }
            }
        }
        delete[] a;
        return cnt;
    }
};
