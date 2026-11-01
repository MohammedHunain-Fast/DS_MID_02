#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSubsetswithdup(vector<int>&arr, vector<int>&ans, int i) {
    if(i == arr.size()) {
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[i]);
    printSubsetswithdup(arr, ans, i + 1);
    ans.pop_back();
    int idx = i + 1;
    while(idx < arr.size() && arr[idx] == arr[idx - 1]) idx++;
    printSubsetswithdup(arr, ans, idx);
}


int main() {
    vector<int> arr = {1, 2, 2};
    vector<int> ans;
    printSubsetswithdup(arr, ans, 0);
    return 0;
}