#include <iostream>
#include <string>
#include <deque>

int tree_height(std::string s){
    int max_height = -1;
    int height = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'd'){
            height++;
        }
        else if(s[i] == 'u'){
            max_height = std::max(max_height, height);
            height--;
        }
    }
    return max_height;
}

int main(){
    std::string s;
    bool hh = 0;
    int t = 0;
    while(getline(std::cin, s)){
        if(s[0] == '#') break;
        if(hh) std::cout << std::endl;
        hh = 1;
        std::cout << "Tree " << ++t << ": " << tree_height(s) << " => ";
        int height = 0;
        int max_height = -1;
        bool u = 0;
        std::deque <int> stack;
        stack.push_back(0);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'd'){
                if(u){
                    height = stack.back();
                    stack.pop_back();
                }
                stack.push_back(++height);
                u = 0;
            }else if(s[i] == 'u'){
                height = stack.back();
                max_height = std::max(max_height, height);
                if(u){
                    stack.pop_back();
                }
                height--;
                u = 1;
            }
        }
        std::cout << max_height;
    }
    return 0;
}