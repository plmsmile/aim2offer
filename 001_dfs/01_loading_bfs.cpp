/*
 * BFS 装载问题
 *
 * @author PLM
 * @date 2017-12-31
 */

#include <iostream>
#include <vector>
#include <cstdio>

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

        //  回溯遍历搜索
        void backtrack(int i);
        
        // 构造函数
        Solution(const vector<int> &w, int c):w(w), c(c) {
            this->cw = 0;
            this->bestw = 0;
            this->n = w.size();
        }
};

/*
 * 无剪枝的bfs
 */
void Solution::backtrack(int i) {
    if (i == n) {
        if (cw > bestw) {
            bestw = cw;
        }
        return;
    }

    if (cw + w[i] <= c) {
        cw = cw + w[i];
        backtrack(i + 1);
        cw = cw - w[i];
    }
    backtrack(i + 1);
}


int max_loading(const vector<int> &w, int c) {
    Solution solu(w, c);
    solu.backtrack(0);
    return solu.bestw;
}


int main() {
    vector<int> w = {1, 2, 3, 4};
    int c = 9;
    int bestw = max_loading(w, c);
    cout << bestw << endl;
    //vector<int> v1(v2);
    //printf("v1=%p, v2=%p\n", &v1, &v2);
    //// v1 = v2;
    ////cout << v1.size() << endl;
    //printf("v1=%p, v2=%p\n", &v1, &v2);
}
