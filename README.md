# Top K Frequent Elements in C++

This project contains a C++ solution for the **Top K Frequent Elements** problem using:

* Sorting
* Frequency counting
* STL `pair`
* Custom sorting with `greater<pair<int,int>>()`

---

# Problem Statement

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

Example:

```cpp
Input:
nums = [1,1,1,2,2,3]
k = 2

Output:
[1,2]
```

---

# Approach

## Step 1 — Sort the Array

The array is first sorted so that equal elements become adjacent.

```cpp
sort(nums.begin(), nums.end());
```

---

## Step 2 — Count Frequencies

Traverse the sorted array and count occurrences of each element.

Store them as:

```cpp
{frequency, element}
```

inside a vector of pairs.

Example:

```cpp
{3,1}
{2,2}
{1,3}
```

---

## Step 3 — Sort by Frequency

Sort the frequency vector in descending order.

```cpp
sort(freq.begin(), freq.end(), greater<pair<int,int>>());
```

This sorts:

* Higher frequency first
* If frequency is same, larger element first

---

## Step 4 — Extract Top K Elements

Take the first `k` elements from the sorted frequency vector.

---

# Code

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> top_k_frequent_elements(vector<int>& nums, int k) {

    sort(nums.begin(), nums.end());

    vector<pair<int,int>> freq;

    int count = 1;

    for(int i = 1; i < nums.size(); i++) {

        if(nums[i] == nums[i-1]) {
            count++;
        }
        else {
            freq.push_back({count, nums[i-1]});
            count = 1;
        }
    }

    freq.push_back({count, nums[nums.size()-1]});

    sort(freq.begin(), freq.end(), greater<pair<int,int>>());

    vector<int> ans;

    for(int i = 0; i < k; i++) {
        ans.push_back(freq[i].second);
    }

    return ans;
}

int main() {

    vector<int> nums = {1,1,1,2,2,3};

    int k = 2;

    vector<int> ans = top_k_frequent_elements(nums, k);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
```

---

# Dry Run

Input:

```cpp
nums = [1,1,1,2,2,3]
k = 2
```

After sorting:

```cpp
[1,1,1,2,2,3]
```

Frequency vector:

```cpp
{3,1}
{2,2}
{1,3}
```

After descending sort:

```cpp
{3,1}
{2,2}
{1,3}
```

Top 2 frequent elements:

```cpp
[1,2]
```

---

# Time Complexity

## Sorting Array

```cpp
O(n log n)
```

## Frequency Counting

```cpp
O(n)
```

## Sorting Frequency Vector

```cpp
O(m log m)
```

Where:

* `n` = size of array
* `m` = number of unique elements

### Overall Complexity

```cpp
O(n log n)
```

---

# Space Complexity

```cpp
O(m)
```

Where `m` is the number of unique elements.

---

# STL Concepts Used

* `vector`
* `pair`
* `sort()`
* `greater<pair<int,int>>()`

---

# Learning Outcome

By solving this problem, you learn:

* Frequency counting
* Pair sorting
* STL sorting techniques
* Custom sorting logic
* Problem-solving using sorting

---

# Author

Ritik Rai
