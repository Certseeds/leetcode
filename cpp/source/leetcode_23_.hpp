#pragma once
#ifndef _LEETCODE_23_H_
#define _LEETCODE_23_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-06 20:16:25
 */
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

#ifdef __LOCAL__

#include "ListNode.h"

#endif


/*
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
namespace Solution23 {
using std::vector;
using std::min;
using std::cout;
using std::endl;
using std::multiset;
using std::priority_queue;

class Solution23 {

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode will_return(0);
        ListNode *head = &will_return;
        mergeKLists_helper1(lists);
        while (!lists.empty()) {
            head->next = mergeKLists_helper2(lists);
            mergeKLists_helper1(lists);
            head = head->next;
        }
        return will_return.next;
    }

    void mergeKLists_helper1(vector<ListNode *> &vec) {
        vec.erase(std::remove(vec.begin(), vec.end(), nullptr), vec.end());
    }

    ListNode *mergeKLists_helper2(vector<ListNode *> &vec) {
        int32_t minv = std::numeric_limits<int32_t>::max();
        for (auto i : vec) {
            minv = min(minv, i->val);
        }
        for (auto &i : vec) {
            if (minv == i->val) {
                auto *const will_return = i;
                i = i->next;
                return will_return;
            }
        }
        return nullptr;// can not reach there
    }

    ListNode *mergeKLists2(vector<ListNode *> &lists) {
        ListNode will_return{0};
        ListNode *head = &will_return;
        auto cmp = [](const ListNode *l1, const ListNode *l2) {
            return l1->val < l2->val;
        };
        multiset<ListNode *, decltype(cmp)> node_set(cmp);
        for (auto i : lists) {
            if (i != nullptr) {
                //cout << i->val << endl;
                node_set.insert(i);
            }
        }
        //cout << "?" << endl;
        vector<ListNode *> outs;
        while (!node_set.empty()) {
            //cout << node_set.size() << " ";
            for (auto iter = node_set.begin(); iter != node_set.end(); iter++) {
                if ((*iter)->val != (*node_set.begin())->val) {
                    break;
                }
                outs.push_back(*iter);
            }
            ListNode *pre = outs[0];
            head->next = pre;
            node_set.erase(pre);
            //cout << pre->val << " " << (pre->next == nullptr) << endl;
            outs[0] = outs[0]->next;
            //cout << (pre==nullptr) << endl;
            for (auto i : outs) {
                if (i != nullptr) {
                    node_set.insert(i);
                }
            }
            outs.clear();
            //cout << node_set.size() << endl;
            //node_set.erase(node_set.find(nullptr));
            head = head->next;
        }
        return will_return.next;
    }

    ListNode *mergeKLists3(vector<ListNode *> &lists) {
        if (lists.size() == 1) {
            return lists[0];
        }
        ListNode will_return(0);
        ListNode *head = &will_return;
        for (int32_t i = lists.size() - 1; i > 0; i--) {
            lists[i - 1] = mergeTwoLists(lists[i], lists[i - 1]);
            head->next = lists[i - 1];
        }
        return will_return.next;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // from leetcode 21
        ListNode will_return(0);
        ListNode *head = &will_return;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = (l1 == nullptr) ? l2 : l1;
        return will_return.next;
    }

    ListNode *mergeKLists4(vector<ListNode *> &lists) {
        ListNode will_return{0};
        ListNode *head = &will_return;
        const auto cmp = [](const ListNode *l1, const ListNode *l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (auto i : lists) {
            if (i != nullptr) {
                pq.push(i);
            }
        }
        while (!pq.empty()) {
            auto * const root = pq.top();
            pq.pop();
            head->next = root;
            if (root->next != nullptr) {
                pq.push(root->next);
            }
            head = head->next;
        }
        return will_return.next;
    }
};

}
/*
brute force merge:
Runtime: 304 ms,
Memory Usage: 12.3 MB,
18%,6%.
merge use min heap:
Runtime: 208 ms,
Memory Usage: 55.2 MB,
20%,3%.
merge them two by two use iteration:
Runtime: 168 ms,
Memory Usage: 12.5 MB,
22.46%,5.95%.
merge them two by two use recursion:
Runtime: 228 ms,
Memory Usage: 12.7 MB,
18.42%,5.95%.
use priority_queue:
Runtime: 32 ms,
Memory Usage: 12.8 MB,
60.15%,5.95%.
*/
#endif //_LEETCODE_23_H_