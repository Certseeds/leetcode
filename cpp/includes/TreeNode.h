/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-12 20:27:58
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-10 16:24:40
*/
#ifndef LEETCODE_CPP_INCLUDES_TREENODE_H
#define LEETCODE_CPP_INCLUDES_TREENODE_H

#include <utility>
#include <vector>
#include <queue>
namespace TREENODE {
using std::queue;
using std::vector;
static constexpr const int32_t No{-100000};
static size_t alloc_delete_count{0};
class TreeNode {
public:
    int32_t val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x, TreeNode *le, TreeNode *rig) : val(x), left(le), right(rig) {
        alloc_delete_count++;
    };

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

class TreeNodeLink {

public:
    vector<TreeNode *> list{};

    TreeNodeLink(std::initializer_list<int32_t> list_) : list(TreeNode::numToTree(list_)) {}

    explicit TreeNodeLink(vector<TreeNode *> list_) : list(std::move(list_)) {}

    explicit TreeNodeLink(TreeNode *li) {
        list.push_back(li);
    }

    virtual ~TreeNodeLink() {
        for (auto &i:list) {
            delete i;
        }
    }

    TreeNode *operator[](size_t i) {
        if (i >= list.size()) {
            return nullptr;
        }
        return list[i];
    }
};

inline TreeNode::~TreeNode() {
    alloc_delete_count--;
    if (this->left != nullptr) {
        delete this->left;
        this->left = nullptr;
    }
    if (this->right != nullptr) {
        delete this->right;
        this->right = nullptr;
    }
    this->val = 0;
}

vector<TreeNode *> TreeNode::numToTree(const vector<int> &nums) {

    vector<TreeNode *> will_return(nums.size(), nullptr);
    for (int32_t i{0}; i < static_cast<int32_t>(nums.size()); i++) {
        will_return[i] =
                (nums[i] != No) ?
                new TreeNode(nums[i]) : nullptr;
    }
    TreeNode::organize(will_return);
    return will_return;
}

void TreeNode::organize(vector<TreeNode *> Tree) {
    int32_t tree_size = Tree.size();
    for (int32_t i{0}; i < tree_size; i++) {
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
    for (int32_t i{0}; i < static_cast<int32_t>(nums.size()); i++) {
        will_return = will_return && (nums[i] == vec[i]);
    }
    return will_return;
}
}

#endif // LEETCODE_CPP_INCLUDES_TREENODE_H