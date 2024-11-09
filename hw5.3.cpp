#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <deque>
#include <algorithm>

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* rebuild(std::vector<int> in, std::vector<int>post){
    if(in.size() <= 1) return new TreeNode(in[0]);
    int root = post.back();
    post.pop_back();
    auto p = std::find(in.begin(), in.end(), root);
    if(p == in.end()) return NULL;
    TreeNode* parent = new TreeNode(root);
    if(p != in.begin()){
        std::vector<int> in_left(in.begin(), p);
        std::vector<int> post_left(post.begin(), post.begin() + in_left.size());
        TreeNode* left = rebuild(in_left, post_left);
        parent->left = left;
    }
    if(p != in.end() - 1){
        std::vector<int> in_right(++p, in.end());
        std::vector<int> post_right(post.end() - in_right.size(), post.end());
        TreeNode* right = rebuild(in_right, post_right);
        parent->right = right;
    }
    return parent;
}

void pre_visit(TreeNode* tree, std::deque<int> &output){
    if(tree == NULL) return;
    TreeNode* left = tree->left;
    TreeNode* right = tree->right;
    output.push_back(tree->val);
    pre_visit(left, output);
    pre_visit(right, output);
}

int main(){
    std::string inorderStr, postorderStr;
    std::getline(std::cin, inorderStr);
    std::getline(std::cin, postorderStr);

    // 读取中序序列
    std::vector<int> inorder;
    std::istringstream inStream(inorderStr);
    int num;
    while (inStream >> num) {
        inorder.push_back(num);
    }

    // 读取后序序列
    std::vector<int> postorder;
    std::istringstream postStream(postorderStr);
    while (postStream >> num) {
        postorder.push_back(num);
    }

    TreeNode* temp = rebuild(inorder, postorder);
    if(temp == NULL) return 0;
    
    std::deque<int> ans;
    pre_visit(temp, ans);

    for(int i = 0; i < ans.size(); i++){
        if(i) std::cout << ' ';
        std::cout << ans[i];
    }
}