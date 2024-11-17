#include <iostream>

int find(int* tree, int t1){
    while(tree[t1] != 0 && tree[t1] != t1){
        if(tree[tree[t1]] != 0) tree[t1] = tree[tree[t1]];
        t1 = tree[t1];
    }
    return t1;
}

int main(){
    int n, m;
    int c = 0;
    std::cin >> n >> m;
    while(n > 0 && m > 0){
        int* tree = new int[n + 1]();
        for(int i = 0; i < m; i++){
            int t1, t2;
            std::cin >> t1 >> t2;
            int temp1 = find(tree, t1);
            int temp2 = find(tree, t2);
            if(temp1 < temp2) tree[temp2] = temp1;
            else tree[temp1] = temp2;
        }
        int* check = new int[n + 1]();
        int num = 0;
        for(int i = 0; i < n; i++){
            int temp = find(tree, i + 1);
            if(check[temp] == 0){
                check[temp] = 1;
                num++;
            }
        }
        free(tree);
        free(check);
        if(c) std::cout << std::endl;
        std::cout << "Case " << ++c << ": " << num;
        std::cin >> n >> m;
    }
    
}