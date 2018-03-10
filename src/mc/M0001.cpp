
#include <string>
#include <iostream>
#include <vector>

using namespace std;
namespace M0001 {


    int main() {
        int n = 4;
        int count = 0;
        char str[] = "abc";
        void func(char *str, int len, int n, int cen, vector<int> &array, int &count);
        vector<int> array;
        func(str, 3, n, 1, array, count);
        cout << '\n' << count;
        return 0;
    }

    void func(char *str, int len, int n, int cen, vector<int> &array, int &count) {
        if (cen == n + 1) {
            for (int i = 0; i < array.size(); i++) {
                cout << str[array[i]];
            }
            cout << "  ";
            count++;
            array.pop_back();
            return;
        }
        for (int i = 0; i < len; i++) {
            array.push_back(i);
            func(str, len, n, cen + 1, array, count);
        }
        if (!array.empty()) {
            array.pop_back();
        }

    }
};
