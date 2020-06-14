class Solution {
public:
    int digitSum(int m, int n){
        int rst1 = m%10 + (m-m%10)/10;
        int rst2 = n%10 + (n-n%10)/10;
        return rst1 + rst2;
    }

    int movingCount(int m, int n, int k) {
        if(k < 0) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 1;
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        visited[0][0] = true;
        while(!q.empty()){
            pair<int,int> top = q.front();
            q.pop();
            if(top.second+1<n && digitSum(top.first, top.second+1) <= k && visited[top.first][top.second + 1] == false){
                q.push(make_pair(top.first, top.second+1));
                visited[top.first][top.second + 1] = true;
                ++count;
            }
            if(top.first+1 < m && digitSum(top.first+1, top.second) <= k && visited[top.first+1][top.second] == false){
                q.push(make_pair(top.first+1, top.second));
                visited[top.first+1][top.second] = true;
                ++count;
            }
        }
        return count;
    }
};
