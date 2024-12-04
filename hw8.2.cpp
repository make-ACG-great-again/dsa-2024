#include <iostream>
#include <string>
#include <map>

int phoneMap[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

std::map<int, int> note;

int to_num(std::string s){
    int len = s.length();
    int ans = 0;
    for(int j = 0; j < len; j++){
        if(s[j] == '-' || s[j] == 'Q' || s[j] == 'Z' || s[j] == 'q' || s[j] == 'z') continue;
        ans*=10;
        if(s[j] >= 'A' && s[j] <= 'Z') ans+=phoneMap[s[j]-'A'];
        else if(s[j] >= 'a' && s[j] <= 'z') ans+=phoneMap[s[j]-'a'];
        else ans+=(s[j]-'0');
    }
    return ans;
}

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        int number = to_num(s);
        note[number] += 1;
    }
    bool hh = 0;
    // 输出方式有问题，若以0开头会被忽略！
    for (auto it = note.begin(); it != note.end(); ++it) {
        if(it->second <= 1) continue;
        if(hh) std::cout << std::endl;
        hh = 1;
        int head = it->first/10000;
        if(head < 100) std::cout << '0';
        if(head < 10) std::cout << '0';
        std::cout << head << '-';
        int tail = it->first%10000;
        if(tail < 1000) std::cout << '0';
        if(tail < 100) std::cout << '0';
        if(tail < 10) std::cout << '0';
        std::cout << tail << ' ' << it->second;
    }
    if(!hh) std::cout << "No duplicates.";
    return 0;
}