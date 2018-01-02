/*
 * DFS 装载问题
 *
 * @author PLM
 * @date 2017-12-31
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <numeric>

using namespace std;

class Solution {
    public:
        // 集装箱数量
        int n;
        // 集装箱的重量
        vector<int> w;
        // 船的载重
        int c;
        // 当前重量
        int cw;
        // 最优重量
        int bestw;
        // 剩余重量
        int r;

        // 无剪枝的dfs
        void backtrack(int i);
        
        // 剪枝的dfs
        void dfs(int i);
        
        // 构造函数
        Solution(const vector<int> &w, int c):w(w), c(c) {
            this->cw = 0;
            this->bestw = 0;
            this->n = w.size();
            this->r = accumulate(w.begin(), w.end(), 0); 
        }
};


/*
 * 无剪枝的dfs
 */
void Solution::backtrack(int i) {
    if (i == n) {
        if (cw > bestw) {
            bestw = cw;
        }
        return;
    }
    // 选择i
    if (cw + w[i] <= c) {
        cw = cw + w[i];
        backtrack(i + 1);
        cw = cw - w[i];
    }
    // 不选择i
    backtrack(i + 1);
}


/*
 * 剪枝的dfs
 */
void Solution::dfs(int i) {
    if (i == n) {
        if (cw > bestw) {
            bestw = cw;
        }
        return;
    }
    // 剩余
    r = r - w[i];
    // 选择i
    if (cw + w[i] <= c) {
        cw += w[i];
        // 剪枝
        if (cw + r > bestw) {
            dfs(i + 1);
        }
        cw -= w[i];
    }

    // 不选择i，剪枝
    if (cw + r > bestw) {
        dfs(i + 1);
    }
    r = r + w[i];
}

int max_loading(const vector<int> &w, int c) {
    Solution solu(w, c);
    cout << "r=" << solu.r << endl;
    solu.dfs(0);
    return solu.bestw;
}


int main() {
    vector<int> w = {2, 3, 9, 4};
    int c = 8;
    int bestw = max_loading(w, c);
    cout << bestw << endl;
    //vector<int> v1(v2);
    //printf("v1=%p, v2=%p\n", &v1, &v2);
    //// v1 = v2;
    ////cout << v1.size() << endl;
    //printf("v1=%p, v2=%p\n", &v1, &v2);
}
