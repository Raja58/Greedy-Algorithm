// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Jul 2021
//  @Detail  :        Double Helix (Greedy)
//  ============================
//  -->
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(true)
    {
        int n, m;
        cin>>n;
        if(!n)
            break;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin>>a[i];
        cin>>m;
        vector<int> b(m);
        for(int i = 0; i < m; i++)
            cin>>b[i];
        int i = 0, j = 0, k = 0;
        vector<pair<int, int>> cache;
        while(i < n && j < m)
        {
            if(a[i] == b[j])
            {
                cache.push_back(pair<int, int>{i, j});
                i++;
            }
            else if(a[i] < b[j])
                i++;
            else
                j++;
        }
        if(cache.empty())
        {
            cout<<max(accumulate(a.begin(), a.end(), 0), accumulate(b.begin(), b.end(), 0))<<"\n";
            continue;
        }
        int result = 0, aIdx, bIdx, prev_aIdx = 0, prev_bIdx = 0;
        while(k < cache.size())
        {
            aIdx = cache[k].first, bIdx = cache[k].second;
            result += max(accumulate(a.begin() + prev_aIdx, a.begin() + aIdx + 1, 0), 
                            accumulate(b.begin() + prev_bIdx, b.begin() + bIdx + 1, 0));
            prev_aIdx = aIdx + 1;
            prev_bIdx = bIdx + 1;
            k++;
        }
        result += max(accumulate(a.begin() + prev_aIdx, a.end(), 0), 
                        accumulate(b.begin() + prev_bIdx, b.end(), 0));
        cout<<result<<"\n";
    }
	return 0;
}