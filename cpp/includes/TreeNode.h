/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-12 20:27:58
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-10 16:24:40
*/
#ifndef LEETCODE_SOURCE_TREENODE_H
#define LEETCODE_SOURCE_TREENODE_H

#include <vector>
#include <queue>

using std::queue;
using std::vector;
static constexpr const int32_t No{-100000};

class TreeNode {
public:
    int32_t val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x, TreeNode *le, TreeNode *rig) : val(x), left(le), right(rig) {};

    explicit TreeNode(int x = 0) : TreeNode(x, nullptr, nullptr) {};

    TreeNode(const TreeNode &obj) : TreeNode(obj.val, obj.left, obj.right) {};

    TreeNode &operator=(const TreeNode &timer) = delete;

    TreeNode(TreeNode &&timer) = delete;

    TreeNode &operator=(TreeNode &&mat) = delete;

    ~TreeNode();

    static vector<TreeNode *> numToTree(const vector<int> &nums);

    static void organize(vector<TreeNode *> Tree);

    static bool judge_equal(TreeNode *root, const vector<int> &vec);
};

inline TreeNode::~TreeNode() {
    this->val = 0;
    this->left = nullptr;
    this->right = nullptr;
}

vector<TreeNode *> TreeNode::numToTree(const vector<int> &nums) {

    vector<TreeNode *> will_return(nums.size(), nullptr);
    for (int i = 0; i < static_cast<int32_t>(nums.size()); i++) {
        will_return[i] =
                (nums[i] != No) ?
                new TreeNode(nums[i]) : nullptr;
    }
    TreeNode::organize(will_return);
    return will_return;
}

void TreeNode::organize(vector<TreeNode *> Tree) {
    int32_t tree_size = Tree.size();
    for (int i = 0; i < tree_size; i++) {
        if (Tree[i] != nullptr) {
            Tree[i]->left = (2 * i + 1 < tree_size) ? Tree[2 * i + 1] : nullptr;
            Tree[i]->right = (2 * i + 2 < tree_size) ? Tree[2 * i + 2] : nullptr;
        }
    }
}

bool TreeNode::judge_equal(TreeNode *root, const vector<int> &vec) {
    queue<TreeNode *> que{};
    vector<int> nums{};
    que.push(root);
    while (!que.empty()) {
        TreeNode *head = que.front();
        que.pop();
        if (head == nullptr) {
            nums.push_back(No);
            continue;
        }
        nums.push_back(head->val);
        que.push(head->left);
        que.push(head->right);
    }
    bool will_return{true};
    for (int i = 0; i < static_cast<int32_t>(nums.size()); i++) {
        will_return = will_return && (nums[i] == vec[i]);
    }
    return will_return;
}


#endif //LEETCODE_SOURCE_TREENODE_H