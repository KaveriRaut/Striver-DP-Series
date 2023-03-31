#include <bits/stdc++.h>
using namespace std;

// Time : O(NlogN)   Space:O(1)
// Intutition: we have to consider the maximum of (value per weight) ki amount => to solve problem
// 1) sort the array as per (value per weight) number in descending order  --> O(NlogN)
// 2) if (curr_item_wt) is valid to pick as that (curr_item_wt <= capacity) =>
// add entire curr_item_value and reduce capacity by curr_item_wt
// 3) else if (curr_item_wt) is not_valid to pick as (curr_item_wt > remaining capacity) =>
// for the remaining weight adding value as => " capacity * (curr_item_value/curr_item_wt) " and break it.

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    // sort by (value per weight) -> in decreasing order
    static bool compare(Item p1, Item p2)
    {
        // first-> value     //second-> weight
        double val1 = (double)p1.value / (double)p1.weight;
        double val2 = (double)p2.value / (double)p2.weight;

        return val1 > val2;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // sort by (value per weight) -> using comparator
        sort(arr, arr + n, compare);
        // greedy approach => array has pairs as //first-> value     //second-> weight
        double ans = 0; // total value stored
        for (int i = 0; i < n; i++)
        {
            // if curr_item_wt can be picked => if(curr_item_wt <= capacity W) => add entire curr_item_value to total_value, reduce capacity by curr_item_wt picked
            if (arr[i].weight <= W)
            {
                W = W - arr[i].weight;    // capacity of sack reduced by curr_item_wt
                ans = ans + arr[i].value; // entire curr_item_value added
            }
            // else if curr_item_wt can not picked entirely => if(curr_item_wt > capacity W) => add fraction part of curr_item_value to total_value, and break
            else
            {
                // remaining weight that we can pickup => now 'W' remain => so according to that pick up the value
                double fraction_value = W * ((double)arr[i].value / (double)arr[i].weight);
                ans = ans + fraction_value;
                break; /// V.V.IMP
            }
        }
        return ans;
    }
};

// Driver Code Starts.
int main()
{
    // size of array and weight
    int n, W;
    cin >> n >> W;

    Item arr[n];
    // value and weight of each item
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }
    // function call
    Solution ob;
    cout << ob.fractionalKnapsack(W, arr, n) << endl;
    return 0;
}

// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output: 240.00
// Explanation:Total maximum value of item we can have is 240.00 from the given capacity of sack. 
