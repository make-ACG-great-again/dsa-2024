#include <iostream>
#include <deque>
#include <string>

// std::deque<int> num;
// std::deque<char> op;

int calculate(std::string t){
    std::deque<int> num;
    std::deque<char> op;
    int len = t.length();
    for(int i = 0; i < len; ){
        if(t[i] == '('){
            std::string temp;
            int count = 0;
            for(int j = i + 1; j < len; i = ++j){
                if(t[j] != ')'){
                    if(t[j] == '(') count++;
                    temp += t[j];
                }else if(count == 0){
                    i = j + 1;
                    break;
                }else{
                    count--;
                    temp += t[j];
                }
            }
            int inside = calculate(temp);
            num.push_back(inside);
        }else if(t[i] == '+' || t[i] == '-'){
            op.push_back(t[i]);
            i++;
        }else if(t[i] == '*'){
            int front, back = 1;
            if(!num.empty()) {
                front = num.back();
                num.pop_back();
            }
            if(t[i + 1] == '('){
                std::string temp;
                int count = 0;
                for(int j = i + 2; j < len; i = ++j){
                    if(t[j] != ')'){
                        if(t[j] == '(') count++;
                        temp += t[j];
                    }else if(count == 0){
                        i = j + 1;
                        break;
                    }else{
                        count--;
                        temp += t[j];
                    }
                }
                back = calculate(temp);
            }else{
                char temp[30];
                int p = 0;
                for(int j = i + 1; j < len; i = ++j){
                    if(t[j] >= '0' && t[j] <= '9'){
                        temp[p] = t[j];
                        p++;
                    }else {
                        temp[p] = 0;
                        i = j;
                        break;
                    }
                }
                temp[p] = 0;
                back = atoi(temp);
            }
            num.push_back(front * back);
        }else if(t[i] == '/'){
            int front, back = 1;
            if(!num.empty()) {
                front = num.back();
                num.pop_back();
            }
            if(t[i + 1] == '('){
                std::string temp;
                int count = 0;
                for(int j = i + 2; j < len; i = ++j){
                    if(t[j] != ')'){
                        if(t[j] == '(') count++;
                        temp += t[j];
                    }else if(count == 0){
                        i = j + 1;
                        break;
                    }else{
                        count--;
                        temp += t[j];
                    }
                }
                back = calculate(temp);
            }else{
                char temp[30];
                int p = 0;
                for(int j = i + 1; j < len; i = ++j){
                    if(t[j] >= '0' && t[j] <= '9'){
                        temp[p] = t[j];
                        p++;
                    }else {
                        temp[p] = 0;
                        i = j;
                        break;
                    }
                }
                temp[p] = 0;
                back = atoi(temp);
            }
            num.push_back(front / back);
        }else{
            char temp[30];
            int p = 0;
            for(int j = i; j < len; i = ++j){
                if(t[j] >= '0' && t[j] <= '9'){
                    temp[p] = t[j];
                    p++;
                }else {
                    temp[p] = 0;
                    i = j;
                    break;
                }
            }
            temp[p] = 0;
            num.push_back(atoi(temp));
        }
    }
    int n_len = num.size();
    int op_len = op.size();
    if(n_len != op_len + 1) while(1);
    else{
        int sum = 0;
        for(int i = 0; i < op_len; i++){
            char oper = op.back();
            int temp = num.back();
            op.pop_back();
            num.pop_back();
            if(oper == '+') sum += temp;
            else if(oper == '-') sum -= temp;
            else while(1);
        }
        if(num.size() != 1) while(1);
        else sum += num.back();
        return sum;
    }
}

int main(){
    int n;
    std::cin >> n;
    bool hh = 0;
    std::string t;
    for(int i = 0; i < n; i++){
        std::cin >> t;
        if(hh) std::cout << std::endl;
        hh = 1;
        std::cout << calculate(t);
    }
    return 0;
}