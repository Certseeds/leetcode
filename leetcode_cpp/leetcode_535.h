#pragma once
#ifndef _LEETCODE_535_H_
#define _LEETCODE_535_H_
#include <vector>
#include <string>
using namespace std;
/*
Note: This is a companion problem to the System Design problem:
Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as 
https://leetcode.com/problems/design-tinyurl 
and it returns a short URL such as http://tinyurl.com/4e9iAk.
Design the encode and decode methods for the TinyURL service. 
There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/
class Solution535 {
public:
	unordered_map<string, string> transfer;
	hash<string> h;
	string encode(string longUrl) {
		transfer[to_string(h(longUrl))] = longUrl;
		return to_string(h(longUrl));
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return transfer[shortUrl];
	}
	void test(){
		string test = "Just fucking google it";
		cout << test._Equal(decode(encode(test))) << endl;
	}
};

#endif
