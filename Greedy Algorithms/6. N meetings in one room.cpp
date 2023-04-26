#include <bits/stdc++.h>
using namespace std;

//approach: Time:O(NlogN)    Space:O(N)
//1.Store {start,end} time of all meetings in vector as pairs
//2.sort the vector by the end[] timing of meetings => using comparator method
//3.maintain the last meeting ka end time that was performed in variable. and maintain the count of meet can hold
//4.iterate on this new sorted vector of pairs => 
// if(startTime of next meeting > last_meeting_endTime) => count++ , update last_meeting_endTime = currMeet ka endTime
// else do nothing 
// at end return count;

class Solution
{
    public:
    static bool myComparator(pair<int,int> p1, pair<int,int>p2)
    {
        if(p1.second<p2.second)
        {
            return true;
        }
        return false;
    }
    //Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({start[i],end[i]});
        }
        sort(vec.begin(),vec.end(),myComparator);
        int count = 0;
        int lastEndTime = 0;
        for(int i=0;i<n;i++)
        {
            if(lastEndTime < vec[i].first)
            {
                count++;
                lastEndTime = vec[i].second;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    
    return 0;
}

/*
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/
