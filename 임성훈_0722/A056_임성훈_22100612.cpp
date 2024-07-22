#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using std::vector;
using std::unordered_map;
using std::stack;

vector<int> nextGreaterElement(const vector<int>& nums1, const vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;

    // nums2 배열을 순회하며 다음 큰 요소를 계산합니다.
    for (int num : nums2) {
        while (!st.empty() && st.top() < num) {
            nextGreater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    // 스택에 남아 있는 요소는 다음 큰 요소가 없습니다.
    while (!st.empty()) {
        nextGreater[st.top()] = -1;
        st.pop();
    }

    // nums1 배열의 각 요소에 대해 다음 큰 요소를 찾습니다.
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater[num]);
    }

    return result;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = nextGreaterElement(nums1, nums2);
    
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
