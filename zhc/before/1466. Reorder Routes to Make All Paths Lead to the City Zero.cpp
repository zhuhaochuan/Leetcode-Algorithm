class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m!=n-1) return -1;
        //每一个节点最多只有两条相关的边，要么出要么入
        //只可以改变方向，那么0节点只能是入，边界节点只能是出
        //bfs
        vector<vector<pair<int,int>>> table(n,vector<pair<int,int>>());
        for(int i=0;i<m;++i) {
            table[connections[i][0]].push_back(pair<int,int>{connections[i][1],1});
            table[connections[i][1]].push_back(pair<int,int>{connections[i][0],-1});
        }
        unordered_set<int> set;
        int res = 0;
        queue<int> q;
        q.push(0);
        set.insert(0);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            auto next_list = table[cur];
            for(auto next:next_list){
                if(next.second==1&&!set.count(next.first)){
                    res++;
                }
                if(!set.count(next.first)) {
                    q.push(next.first);
                    set.insert(next.first);
                }
            }
        }
        return res;
    }
};