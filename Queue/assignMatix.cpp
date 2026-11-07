
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {

        // {weight, index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            available;

        // {freeTime, weight, index}
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            busy;

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Initially all servers are available
        for (int i = 0; i < n; i++)
        {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int i = 0; i < m; i++)
        {

            time = max(time, (long long)i);

            // Release servers that are free
            while (!busy.empty() && get<0>(busy.top()) <= time)
            {
                auto [t, w, idx] = busy.top();
                busy.pop();
                available.push({w, idx});
            }

            // If no server is available, wait
            if (available.empty())
            {

                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time)
                {
                    auto [t, w, idx] = busy.top();
                    busy.pop();
                    available.push({w, idx});
                }
            }

            // Assign task to the best server
            auto [weight, idx] = available.top();
            available.pop();

            ans[i] = idx;

            // Update server's free time
            busy.push({time + tasks[i],
                       weight,
                       idx});
        }

        return ans;
    }
};

int main()
{
    int n, m;

    cin >> n;

    vector<int> servers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> servers[i];
    }

    cin >> m;

    vector<int> tasks(m);
    for (int i = 0; i < m; i++)
    {
        cin >> tasks[i];
    }

    Solution obj;

    vector<int> ans = obj.assignTasks(servers, tasks);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
