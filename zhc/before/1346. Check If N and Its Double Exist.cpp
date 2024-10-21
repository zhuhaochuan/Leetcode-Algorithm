class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> set;
        for(int i=0;i<n;++i) {
            if(set.count(arr[i]*2))
                return true;
            if(!(arr[i]&1)&&set.count(arr[i]/2))
                return true;
            set.insert(arr[i]);
        }
        return false;
    }
};