#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>

int zip(int x, int y, int z){
    return x*1000000+y*1000+z;
}

std::vector<int> unzip(int zip){
    std::vector<int> ans;
    ans.push_back(zip/1000000);
    zip = zip%1000000;
    ans.push_back(zip/1000);
    ans.push_back(zip%1000);
    return ans;
}

std::multimap<double, std::pair<int, int>> l;
std::vector<int> dot;

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int x, y, z;
        std::cin >> x >> y >> z;
        dot.push_back(zip(x, y, z));
    }
    int num = dot.size();
    for(int i = 0; i < num-1; i++){
        int x0, y0, z0;
        std::vector<int> temp0 = unzip(dot[i]);
        x0 = temp0[0];
        y0 = temp0[1];
        z0 = temp0[2];
        for(int j = i + 1; j < num; j++){
            int x, y, z;
            std::vector<int> temp = unzip(dot[j]);
            x = temp[0];
            y = temp[1];
            z = temp[2];
            double d = std::sqrt(std::pow((double)(x0-x), 2)
                +std::pow((double)(y0-y), 2)+std::pow((double)(z0-z), 2));
            l.insert(std::make_pair(-d, std::make_pair(dot[i], dot[j])));
        }
    }
    bool hh = 0;
    for (const auto& [key, value] : l) {
        if(hh) std::cout << std::endl;
        hh=1;
        auto [v1, v2] = value;
        std::vector<int> d1 = unzip(v1);
        std::vector<int> d2 = unzip(v2);
        std::cout << '(' << d1[0] << ',' << d1[1] << ',' << d1[2] << ')'
            << "-(" << d2[0] << ',' << d2[1] << ',' << d2[2] << ")="
                << std::fixed << std::setprecision(2) << -key;
    }
    // for(int i = 0; i < n*(n-1)/2; i++)
    return 0;
}