#pragma once
#ifndef _LEETCODE_922_H
#define _LEETCODE_922_H

#include <vector>

using namespace std;


class Solution922 {
public:
    vector<int> sortArrayByParityII_1(vector<int> &A) {
        vector<int> odd;
        vector<int> even;
        int temp;
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 != i % 2) {
                count++;
                if (i % 2) {
                    even.push_back(i);
                } else {
                    odd.push_back(i);
                }
            }
        }
        for (int i = 0; i < count / 2; i++) {
            temp = A[even[i]];
            A[even[i]] = A[odd[i]];
            A[odd[i]] = temp;
        }
        odd.clear();
        even.clear();
        return A;
    }

    vector<int> sortArrayByParityII_2(vector<int> &A) {
        int *odd = new int[10001];
        int *even = new int[10001];
        odd[10000] = 0;
        even[10000] = 0;
        int *temp = new int;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 != i % 2) {
                even[even[10000]] = i;
                odd[odd[10000]] = i;
                even[10000] += i % 2;
                odd[10000] += !(i % 2);
            }
        }

        for (int i = 0; i < odd[10000]; i++) {
            (*temp) = A[even[i]];
            A[even[i]] = A[odd[i]];
            A[odd[i]] = (*temp);
        }
        delete[] odd;
        delete[] even;
        delete temp;
        return A;
    }

    vector<int> sortArrayByParityII_3(vector<int> &A) {
        vector<int> willreturn(A.size());
        int odd = 0;
        int even = 1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2) {
                willreturn[even] = A[i];
                even += 2;
            } else {
                willreturn[odd] = A[i];
                odd += 2;
            }
        }
        return willreturn;
    }

};

#endif
