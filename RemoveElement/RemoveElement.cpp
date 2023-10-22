#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {

    int numSize = nums.size();
    int count = 0;

    for (int i = 0; i < numSize; i++) {
        if (nums[i] != val) {
            nums[count] = nums[i];
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> nums = { 3, 2, 2, 3, 4 };
    int val = 3;

    cout << "Original vector: ";
    for (int num : nums) {
        std::cout << num << " ";
    }

    int result = removeElement(nums, val);

    cout << "\nModified vector: ";
    for (int i = 0; i < result; i++) {
        std::cout << nums[i] << " ";
    }

    cout << "\nNew size of vector: " << result << std::endl;

    return 0;

}