#pragma once
#ifndef _LEETCODE_797_H_
#define _LEETCODE_797_H_

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
Given a directed, acyclic graph of N nodes.  
Find all possible paths from node 0 to node N-1, 
and return them in any order.
The graph is given as follows:  
the nodes are 0, 1, ..., graph.length - 1.  
graph[i] is a list of all nodes j for which the edge (i, j) exists.
-->
find all paths in directed, acyclic graph from A to B.
*/
class Solution797 {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> willreturn;
        set<vector<int>> reorganzation;
        vector<vector<int>> temp;
        temp.push_back(vector<int>{0});
        int aim = graph.size() - 1;
        cout << "aim is " << aim << endl;
        for (int i = 0; i < aim; i++) {
            vector<vector<int>> replace;
            for (int j = 0; j < temp.size(); j++) {
                vector<int> added(temp[j]);
                added.push_back(0);
                int where = temp[j].back();
                for (int k = 0; k < graph[where].size(); k++) {
                    added[temp[j].size()] = graph[where][k];
                    if (graph[where][k] == aim) {
                        reorganzation.insert(added);
                    } else {
                        replace.push_back(added);
                    }
                }
            }
            if (replace.empty()) {
                break;
            }
            temp = replace;
        }
        for (auto iter = reorganzation.begin(); iter != reorganzation.end(); iter++) {
            willreturn.push_back(*iter);
        }
        return willreturn;
    }

    vector<vector<int>> allPathsSourceTarget2(vector<vector<int>> &graph) {
        vector<vector<int>> willreturn;
        vector<vector<int>> temp;
        temp.push_back(vector<int>{0});
        int aim = graph.size() - 1;
        cout << "aim is " << aim << endl;
        for (int i = 0; i < aim; i++) {
            vector<vector<int>> replace;
            for (int j = 0; j < temp.size(); j++) {
                vector<int> added(temp[j]);
                added.push_back(0);
                int where = temp[j].back();
                for (int k = 0; k < graph[where].size(); k++) {
                    added[temp[j].size()] = graph[where][k];
                    if (graph[where][k] == aim) {
                        willreturn.push_back(added);
                    } else {
                        replace.push_back(added);
                    }
                }
            }
            if (replace.empty()) {
                break;
            }
            temp = replace;
        }
        return willreturn;
    }

    void test() {
        vector<vector<int>> input1 = {{1, 2},
                                      {3},
                                      {3},
                                      {}};
        vector<vector<int>> output1 = allPathsSourceTarget(input1);
        for (auto i : output1) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
/*
my own:
Runtime: 96 ms,
Memory Usage: 20.8 MB
25.52%,10%.
if ingnore the knock of paths, it will be 
Runtime: 88 ms,
Memory Usage: 18.5 MB,
43.83%,10%.
others way use recurrence
*/
#endif
