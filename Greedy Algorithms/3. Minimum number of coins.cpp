#include <bits/stdc++.h>
using namespace std;

// Intution:     //Time:O(n)     //Space:O(n)
// 1)make the coin supply arr[] in descending order
// 2)if (coin<target) => add coin in vector and reduce target by coin amount => stay at same index in arr[] ,dont move
// 3)else if (coin>target) => dont add to vector => only move i++ in arr[]

class Solution
{
public:
    vector<int> minPartition(int target)
    {
        vector<int> vec;
        // 1)make the coin supply arr[] in descending order
        int coins[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        // 2)iterate over the coins arr[] and choose greedyly
        int i = 0;
        while (i < 10)
        {
            // if (coin<target) => add coin in vector and reduce target by coin amount => stay at same index in arr[] ,dont move
            if (coins[i] <= target)
            {
                vec.push_back(coins[i]);
                target = target - coins[i];
            }
            else // else if (coin>target) => dont add to vector => only move i++ in arr[]
            {
                i++;
            }
        }
        return vec;
    }
};

int main()
{
    int N;
    cin >> N;
    Solution ob;
    vector<int> numbers = ob.minPartition(N);
    for (auto u : numbers)
        cout << u << " ";
    cout << "\n";
    return 0;
}

// Input: N = 43
// Output: 20 20 2 1
// Explaination: Minimum number of coins and notes needed to make 43. 
