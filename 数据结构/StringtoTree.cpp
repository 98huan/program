#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;    //类型名也可以是string等等
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
把去掉中括号'[]'后的字符串转换成vector<string>向量，去掉逗号','
传入："1,2,3,null,null,4,5"
返回：{1,2,3,null,null,4,5}
*/
vector<string> StringtoVector(string str, string delim) {
    vector<string> vec;
    int i = 0, j = 0, len = str.length();   //i字符串的首地址，j字符串的尾地址加1即逗号的地址
    while (i < len) {
        while (j < len && str[j] != ',')
            j++;
        // 退出while时j存储的是逗号的地址
        vec.push_back(str.substr(i, j - i));
        i = ++j;
    }
    return vec;
}

//序列化：将一个二叉树按层序输出成一个字符串
string serialize(TreeNode* root) {
    if(root == nullptr) return "[]";
    string res = "[";
    queue<TreeNode*> que;
    que.emplace(root);
    while(!que.empty())
    {
        TreeNode* node = que.front();
        que.pop();
        if(node != nullptr) {
            res += (to_string(node->val) + ",");
            que.emplace(node->left);
            que.emplace(node->right);
        }
        else res += "null,";
    }
    res.pop_back(); //删掉字符串最后一个字符
    res += "]";
    return res;
}

/* 字符串数组转成一个满二叉树*/
TreeNode* deserialize(string data) {
    if (data == "[]")
        return nullptr;

    //data.substr(1, data.length() - 2) 取从首地址1开始长为length()-2的子串，即把首尾的'[]'去掉
    vector<string> list = StringtoVector(data.substr(1, data.length() - 2), ",");
    
    // stoi()字符串转int
    queue<TreeNode*> que;
    TreeNode *root = new TreeNode(std::stoi(list[0]));  //创建根节点
    que.emplace(root);  //和push效果一样从队列尾部插入
    int i = 1;
    while(!que.empty()) {
        TreeNode *node = que.front();
        que.pop();
        if(list[i] != "null")
        {
            node->left = new TreeNode(std::stoi(list[i]));  //创建新节点的方式：new TreeNode(int x)
            que.emplace(node->left);
        }
        if(i == list.size() - 1)
            return root;
        i++;
        if(list[i] != "null") {
            node->right = new TreeNode(std::stoi(list[i]));
            que.emplace(node->right);
        }
        if(i == list.size() - 1)
            return root;
        i++;
    }
    return root;
}

int main(){
    string str;
    cin >> str;
    TreeNode* root = deserialize(str);
    string s = serialize(root);
    cout << "s:" << s << endl;
    return 0;
}