/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-01 10:36:37
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-01 13:36:58
 */
#ifndef _LEETCODE_1366_H_
#define _LEETCODE_1366_H_
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
/*
In a special ranking system, 
each voter gives a rank from highest to lowest to all teams participated in the competition.
The ordering of teams is decided by 
who received the most position-one votes. 
If two or more teams tie in the first position, 
we consider the second position to resolve the conflict, 
if they tie again, we continue this process until the ties are resolved. 
If two or more teams are still tied after considering all positions, 
we rank them alphabetically based on their team letter.
Given an array of strings votes which is the votes of all voters in the ranking systems. 
Sort all teams according to the ranking system described above.
Return a string of all teams sorted by the ranking system.

Example 1:
Input: votes = ["ABC","ACB","ABC","ACB","ACB"]
Output: "ACB"
Explanation: Team A was ranked first place by 5 voters. No other team was voted as first place so team A is the first team.
Team B was ranked second by 2 voters and was ranked third by 3 voters.
Team C was ranked second by 3 voters and was ranked third by 2 voters.
As most of the voters ranked C second, team C is the second team and team B is the third.

Example 2:
Input: votes = ["WXYZ","XYZW"]
Output: "XWYZ"
Explanation: X is the winner due to tie-breaking rule. X has same votes as W for the first position but X has one vote as second position while W doesn't have any votes as second position.

Example 3:
Input: votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
Output: "ZMNAGUEDSJYLBOPHRQICWFXTVK"
Explanation: Only one voter so his votes are used for the ranking.

Example 4:
Input: votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]
Output: "ABC"
Explanation:
Team A was ranked first by 2 voters, second by 2 voters and third by 2 voters.
Team B was ranked first by 2 voters, second by 2 voters and third by 2 voters.
Team C was ranked first by 2 voters, second by 2 voters and third by 2 voters.
There is a tie and we rank teams ascending by their IDs.

Example 5:
Input: votes = ["M","M","M","M"]
Output: "M"
Explanation: Only team M in the competition so it has the first rank.

Constraints:
1 <= votes.length <= 1000
1 <= votes[i].length <= 26
votes[i].length == votes[j].length for 0 <= i, j < votes.length.
votes[i][j] is an English upper-case letter.
All characters of votes[i] are unique.
All the characters that occur in votes[0] also occur in votes[j] where 1 <= j < votes.length
10:36-11:35,13:00-13:35
*/
//
class Solution1366 {
public:
    string rankTeams(vector<string>& votes) {
        unordered_set<char> zero;
        return rankTeams_rec(votes, zero,0);
    }
    string rankTeams_rec(vector<string>& votes,unordered_set<char> uses,const int length) {
        if (votes[0].size() == length || uses.size() == votes[0].size()) {
            return "";
        }
        unordered_map<char, int> firsts;
        for (auto i : votes) {
            if (uses.count(i[length]) == 0) {
                firsts[i[length]]++;
            }
        }
        vector<vector<int>> chars(firsts.size(), vector<int>(27, 0));
        int count = 0;
        for (auto i : firsts) {
            for (int j = 0; j < votes.size(); j++) {
                int posi = votes[j].find_first_of(i.first);
                chars[count][posi]++;
            }
            chars[count][26] = (128 - static_cast<int>(i.first));
            count++;
        }
        std::stable_sort(chars.begin(), chars.end(), std::greater<vector<int>>());
        string will_return = "";
        for (auto i : chars) {
            will_return += static_cast<char>(128 - i[26]);
        }
        for (auto i : firsts) {
            uses.insert(i.first);
        }
        return will_return + rankTeams_rec(votes,uses,length+1);
    }
    void test() {
        vector<string> str1 = { "ABC","ACB","ABC","ACB","ACB" };
        vector<string> str2 = { "WXYZ","XYZW" };
        vector<string> str3 = { "ZMNAGUEDSJYLBOPHRQICWFXTVK" };
        vector<string> str4 = { "BCA","CAB","CBA","ABC","ACB","BAC" };
        vector<string> str5 = { "M","M","M","M" };
        vector<string> str6 = { 
            "FVSHJIEMNGYPTQOURLWCZKAX",
            "AITFQORCEHPVJMXGKSLNZWUY",
            "OTERVXFZUMHNIYSCQAWGPKJL",
            "VMSERIJYLZNWCPQTOKFUHAXG",
            "VNHOZWKQCEFYPSGLAMXJIUTR",
            "ANPHQIJMXCWOSKTYGULFVERZ",
            "RFYUXJEWCKQOMGATHZVILNSP",
            "SCPYUMQJTVEXKRNLIOWGHAFZ",
            "VIKTSJCEYQGLOMPZWAHFXURN",
            "SVJICLXKHQZTFWNPYRGMEUAO",
            "JRCTHYKIGSXPOZLUQAVNEWFM",
            "NGMSWJITREHFZVQCUKXYAPOL",
            "WUXJOQKGNSYLHEZAFIPMRCVT",
            "PKYQIOLXFCRGHZNAMJVUTWES",
            "FERSGNMJVZXWAYLIKCPUQHTO",
            "HPLRIUQMTSGYJVAXWNOCZEKF",
            "JUVWPTEGCOFYSKXNRMHQALIZ",
            "MWPIAZCNSLEYRTHFKQXUOVGJ",
            "EZXLUNFVCMORSIWKTYHJAQPG",
            "HRQNLTKJFIEGMCSXAZPYOVUW",
            "LOHXVYGWRIJMCPSQENUAKTZF",
            "XKUTWPRGHOAQFLVYMJSNEIZC",
            "WTCRQMVKPHOSLGAXZUEFYNJI" };
        std::cout << "normal test 1" << std::endl;
        assert("ACB" == rankTeams(str1));
        std::cout << "normal test 2" << std::endl;
        assert("XWYZ" == rankTeams(str2));
        std::cout << "single element test" << std::endl;
        assert("ZMNAGUEDSJYLBOPHRQICWFXTVK" == rankTeams(str3));
        std::cout << "all character equal test" << std::endl;
        assert("ABC"  == rankTeams(str4));
        std::cout << "one character test" << std::endl;
        assert("M" == rankTeams(str5));
        std::cout << "complex test 1" << std::endl;
        assert("VWFHSJARNPEMOXLTUKICZGYQ" == rankTeams(str6));
    }
};
/*
Runtime: 16 ms,
Memory Usage: 11.8 MB,
92.86%,100%.
*/
#endif
