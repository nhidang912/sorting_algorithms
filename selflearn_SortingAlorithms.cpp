#include <iostream>
#include <vector>
#include <ctime>
#include <tuple>
#include <random>
#include <algorithm>
#include "myFunctions.h"
using namespace std;
int cnt = 0;
class Solution {
private:
    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr;
        int i = 0;
        int j = 0;
        int n = arr1.size() + arr2.size();
        for (int k = 0; k < n ; k++) {
            if ((i < arr1.size()) && (j < arr2.size()) && (arr1[i] < arr2[j])) {
                arr.push_back(arr1[i]);
                i++;
                cnt++;
            } else if ((i < arr1.size()) && (j < arr2.size())) {
                arr.push_back(arr2[j]);
                j++;
                cnt++;
            } else if ((i < arr1.size())) {
                arr.push_back(arr1[i]);
                i++;
            } else {
                arr.push_back(arr2[j]);
                j++;
            }            
        }
        return arr;
    }

    void quick(vector<int>& nums, int left, int right) {
        int id_pivot = right;
        int id_marker = left;
        if (right <= left) return;
        for (int i = left; i < right; i++) {
            if (nums[i] <= nums[id_pivot]) {
                if (i > id_marker) swap(nums[i],nums[id_marker]);
                id_marker++;
                cnt++;
            }
        }
        swap(nums[id_marker], nums[id_pivot]);
        id_pivot = id_marker;
        quick(nums, left, id_pivot-1);
        quick(nums, id_pivot+1, right);
    }
    

    bool isHeapNode (vector<int>& nums, int node_id, int right, int& max_id) {
        int child_a = 2*node_id + 1;
        int child_b = 2*node_id + 2;
        if ((child_a > right)) return true;
        cnt++;
        if (child_b > right) {
            if (nums[node_id] >= nums[child_a]) return true;
            else {
                max_id = child_a;
                return false;
            }
        }
        cnt = cnt++;
        if ((nums[node_id] < nums[child_b]) || (nums[node_id] < nums[child_a])) {
            cnt = cnt++;
            if (nums[child_a] >= nums[child_b]) max_id = child_a;
            else max_id = child_b;
            return false;
        }
        else {
            return true;
        }
    }

    void maxheap_rebuild (vector<int>& nums, int left, int right) {
        int i = left;
        while ( i < right ) {
            int max_id;
            if (isHeapNode(nums, i, right, max_id)) break;
            else {
                swap(nums[i], nums[max_id]);
                i = max_id;
            }
        }
    }


public:
    vector<int> maxheap_build (vector<int>& nums, int left, int right) {
        if(right <= left) return nums;
        int mid = (right + left) / 2;
        for (int i = mid; i >= left; i--) {
            int max_id;
            if (isHeapNode(nums, i, right, max_id)) continue;
            else swap(nums[i], nums[max_id]);            
            int j = max_id;
            while (j <= mid) {
                if (isHeapNode(nums, j, right, max_id)) break;
                else swap(nums[j], nums[max_id]);
                j = max_id;
            }
        }
        return nums;
    }

    vector<int> selection_Sort(vector<int>& nums) {
        /* 
            For each loop, this algorithm will search for the max value and move it to the end of the array
        */
        int n = nums.size();
        for (int i = n-1; i > -1; i--) {
            int max_id = i;
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[max_id]) max_id = j;
                cnt++;
            }
            swap(nums[max_id], nums[i]);
        }
        return nums;
    }

    vector<int> merge_Sort(vector<int>& nums) {
        int mid = (nums.size())/2;
        if (nums.size() <= 1 )  return nums;
        vector<int> arr1(nums.begin(), nums.begin() + mid);
        vector<int> arr2(nums.begin() + mid, nums.end());
        arr1 = merge_Sort(arr1);
        arr2 = merge_Sort(arr2);
        
        return merge(arr1, arr2);
    }

    vector<int> quick_Sort(vector<int>& nums) {
        quick(nums, 0, nums.size()-1);
        return nums;
    }

    vector<int> heap_Sort(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n == 1) return nums;
        nums = maxheap_build(nums,0,n);
        int i;
        for (i = 0; i < n - 1; i++) {
            swap(nums[0], nums[n-i]);
            maxheap_rebuild(nums,0,n-i-1);
        }
        swap(nums[0], nums[1]);
        return nums;
    }
};

class Testing {
private:
    Solution sl;
    vector<int> sortingType(vector<int> nums_in){
        vector<int> nums_out = sl.heap_Sort(nums_in);
        return nums_out;
    }

    void evaluateSorting(vector<int> input, int testid) {
        cnt = 0;    
        // printf("\n\nTEST%d\nINPUT:\n", testid);
        // print_vector(input);
        vector<int> output = sortingType(input);
        sort(input.begin(), input.end());
        if (input == output) printf(GREEN_COLOR "TEST%d -> PASS\n", testid);
        else {
            printf(RED_COLOR "%s -> FAIL\n");
        }
        // print_vector(output);
        printf("Counter of TEST%d: %d\n" RESET_COLOR, testid, cnt);
    }

public:
    void sorting_random() {
        vector<int> input_1 = random_vector(10, 0, 20);
        evaluateSorting(input_1, 1);

        vector<int> input_2 = random_vector(100, 0, 10000);
        evaluateSorting(input_2, 2);

        vector<int> input_3 = random_vector(1000, 0, 100000);
        evaluateSorting(input_3, 3);

        vector<int> input_4 = random_vector(10000, 0, 1000000);
        evaluateSorting(input_4, 4);

        vector<int> input_5 = random_vector(100000, 0, 10000000);
        evaluateSorting(input_5, 5);
    }

    
    void sorting_someUnique() {
        vector<int> input_1 = random_vector(10, 0, 2);
        evaluateSorting(input_1, 1);

        vector<int> input_2 = random_vector(10, 10, 15);
        evaluateSorting(input_2, 2);

        vector<int> input_3 = random_vector(10000, 0, 50);
        evaluateSorting(input_3, 3);
    }

    
    void sorting_alreadySort() {
        vector<int> input_1 = {1,2,3,4,5,6,7,8,9,10};
        evaluateSorting(input_1, 1);

        vector<int> input_2 = {10,9,8,7,6,5,4,3,2,1};
        evaluateSorting(input_2, 2);

        vector<int> input_3 = {1,2,3,4,5,7,6,8,9,10};
        evaluateSorting(input_3, 3);

        vector<int> input_4 = {10,9,8,7,5,6,4,3,2,1};
        evaluateSorting(input_4, 4);
    }
};

int main() {
    Solution sl;
    Testing test;
    // vector<int> numbers = {4,19,8,14,20,5,12,4,4,1}; 
    // vector<int> numbers = {13,17,0,8,19,17,1,15,14,2};
    // vector<int> numbers = {3,3,5,20,4,4,9,17,0,6};
    // vector<int> numbers = {0, 1, 2, 3};
    // numbers = sl.selection_Sort(numbers);
    // numbers = sl.merge_Sort(numbers);
    // numbers = sl.quick_Sort(numbers);
    // vector<int> nums = sl.maxheap_build(numbers, 0, numbers.size()-1);
    // vector<int> nums = sl.heap_Sort(numbers);
    // sort(numbers.begin(), numbers.end());
    // print_vector(nums);
    // printf("Number of elements: %d\n", numbers.size());
    // printf("Counter of comparation: %d\n", cnt);
    // return 0;
    // test.sorting_random();
    // test.sorting_someUnique();
    test.sorting_alreadySort();
}