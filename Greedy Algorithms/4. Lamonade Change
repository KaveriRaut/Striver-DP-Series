#include <bits/stdc++.h>
using namespace std;

// Intution: Time:O(n)  Space:O(1)
// greedy approach:
// for each note case of Rs5, Rs10, Rs20 =>handle in different condition
// for Rs5 => add to mycash only
// for Rs10 => check if Rs5 have&add Rs10 to mycash => else if dont have Rs5 return false;
// for Rs20 => if you have then return (Rs10+Rs5) chi 2 notes or return (Rs5+Rs5+Rs5) chi 3 notes => else return false

class Solution
{
public:
    bool lemonadeChange(int n, vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5) // Rs.5 got from customer...add to our cash only=>dont return any change
            {
                five++;
            }
            else if (bills[i] == 10) // Rs.10 got from customer...add to our cash=> have to return Rs5 as change
            {
                if (five > 0) // Rs5 chi 1 note change
                {
                    ten++;  // take that Rs10 chi note
                    five--; // give back Rs5 cha change
                }
                else
                {
                    return false; // Rs5 cha change nasel tr
                }
            }
            else if (bills[i] == 20) // Rs.15 have to return as change
            {
                if (ten > 0 && five > 0) // change return => Rs10+Rs5
                {
                    ten--;
                    five--;
                }
                else if (five > 2) // change return => Rs5+Rs5+Rs5
                {
                    five--;
                    five--;
                    five--;
                }
                else // dont have enough change
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// Driver Code Starts.

int main()
{
    int N;
    cin >> N;
    vector<int> bills(N);
    for (int i = 0; i < N; i++)
        cin >> bills[i];
    Solution obj;
    int ans = obj.lemonadeChange(N, bills);
    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

// Input:
// N = 5
// bills [ ] = {5, 5, 5, 10, 20}
// Output: True
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change we return true.


// Input:
// N = 5
// bills [ ] = {5, 5, 10, 10, 20}
// Output: False
// Explanation: 
// From the first two customers in order, we collect two $5 bills.
// For the next two customers in order, we collect a $10 bill and give back a $5 bill.
// For the last customer, we can not give the change of $15 back because we only have two $10 bills.
// Since not every customer received the correct change, the answer is false.
