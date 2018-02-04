/*
 * 连续子数组的最大和
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#连续子数组的最大和-42
 *
 * @author PLM
 * @date 2018-02-04
 */

#include <vector>
#include <algorithm>

using namespace std;


/*
 * 连续子数组的最大和
 */ 
int maxsum_subarray(const vector<int>& a) {
    if (a.empty()) {
        return 0;
    }
    
    int cursum = a[0];
    int bestsum = a[0];

    for (int i = 1; i < a.size(); i++) {
        if (cursum <= 0) {
            cursum = a[i];
        } else {
            cursum += a[i];
        }

        if (cursum > bestsum) {
            bestsum = cursum;
        }
    }
    return bestsum;
}


int maxsum_subarray_dp(const vector<int>& a) {
    if (a.empty()) {
        return 0;
    }
    // p[i]=k，以i结尾的所有连续子数组中的最大值为k
    vector<int> p(a.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        if (i == 0 || p[i-1] <= 0) {
            p[i] = a[i];
        } else if (p[i-1] > 0) {
            p[i] = p[i-1] + a[i];
        }
    }
    return *std::max_element(p.begin(), p.end());
}


int main() {
    vector<int> p(10, 0);

    return 0;
}
