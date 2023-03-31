#include <bits/stdc++.h>
using namespace std;

// Intutition : Time -> max(O(NlogN,MlogM))     Space -> O(1)
// 1) sort both arrays
// 2) if condition satisfied => count++ and move both in greed[] and sz[] both arrays i++, j++
// 3) else if not satisfied  => move only in sz[] array j++
// return that count

class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) 
    {
        
        int i=0,j=0,count=0;
        
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        
        while(i<N && j<M)
        {
            if(sz[j]>=greed[i])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};

// Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
