#include <iostream>
#include <deque>
#include <numeric>

int combination(int n, int k) {
    // 检查边界情况
    if (k > n) return 0;          // 当 k > n 时组合数为 0
    if (k == 0 || k == n) return 1; // 当 k = 0 或 k = n 时组合数为 1

    // 利用对称性 C(n, k) == C(n, n - k)，以减少计算量
    if (k > n - k) k = n - k;

    long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }

    return result;
}

int main(){
    int k;
    bool hh = 0;
    while(std::cin >> k){
        if(k == 0) return 0;
        if(hh) std::cout << std::endl;
        hh = 1;
        std::string pre;
        std::string post;
        std::cin >> pre >> post;
        int len = pre.length();
        int j = 0;
        std::deque<char> s;
        std::deque<int> num;
        int ans = 1;
        bool lx = 0;
        for(int i = 0; i < len || j < len; ){
            if(i >= len){
                if(!s.empty() && s.back() == post[j]){
                    int temp = num.back();
                    num.pop_back();
                    s.pop_back();
                    ans *= combination(k, temp);
                    j++;
                    continue;
                }
                ans = 114514;
            }
            if(pre[i] != post[j]){
                if(!s.empty() && s.back() == post[j]){
                    int temp = num.back();
                    num.pop_back();
                    s.pop_back();
                    ans *= combination(k, temp);
                    j++;
                    lx = 1;
                }else{
                    if(lx){
                        s.push_back(pre[i]);
                        int temp = num.back();
                        num.pop_back();
                        num.push_back(temp + 1);
                        i++;
                        lx = 0;
                        continue;
                    }
                    s.push_back(pre[i]);
                    num.push_back(1);
                    i++;
                    lx = 0;
                }
            }
            else{
                if(!lx){
                    num.push_back(1);
                    i++;
                    j++;
                    lx = 1;
                    continue;
                }
                lx = 1;
                int temp = num.back();
                num.pop_back();
                num.push_back(temp + 1);
                i++;
                j++;
            }
        }
        std::cout << ans;
    }
    return 0;
}