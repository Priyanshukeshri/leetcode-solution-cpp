/**
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
**/

//Runtime: 52 ms, faster than 37.54% of C++ online submissions for Contains Duplicate.
//Memory Usage: 18.1 MB, less than 5.12% of C++ online submissions for Contains Duplicate.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset(nums.begin(), nums.end());
        return myset.size() < nums.size();
    }
};

//Naive Linear Search
/**
Complexity Analysis

Time complexity : O(n^2). In the worst case, there are \frac{n(n+1)}{2} 2n(n+1) pairs of integers to check. 
Therefore, the time complexity is O(n^2).

Space complexity : O(1). We only used constant extra space.
**/
//Sorting
/**
Complexity Analysis

Time complexity : O(nlogn). Sorting is O(nlogn) and the sweeping is O(n). 
The entire algorithm is dominated by the sorting step, which is O(nlogn).

Space complexity : O(1). Space depends on the sorting implementation which, usually, costs O(1) auxiliary space if heapsort is used.
**/
//Hash Table
/**
Intuition

Utilize a dynamic data structure that supports fast search and insert operations.

Algorithm

From Approach #1 we know that search operations is O(n)O(n) in an unsorted array and we did so repeatedly. Utilizing a data structure with faster search time will speed up the entire algorithm.

There are many data structures commonly used as dynamic sets such as Binary Search Tree and Hash Table. The operations we need to support here are search() and insert(). For a self-balancing Binary Search Tree (TreeSet or TreeMap in Java), search() and insert() are both O(\log n)O(logn) time. For a Hash Table (HashSet or HashMap in Java), search() and insert() are both O(1)O(1) on average. Therefore, by using hash table, we can achieve linear time complexity for finding the duplicate in an unsorted array.
**/
/**
Complexity Analysis

Time complexity : O(n)O(n). We do search() and insert() for nn times and each operation takes constant time.

Space complexity : O(n)O(n). The space used by a hash table is linear with the number of elements in it.
**/
