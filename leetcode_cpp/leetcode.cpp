#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <string>
#include <fstream>
#include <iostream>
#include "assert.h"
//1-99 begin
/*
#include "leetcode_1.h"
#include "leetcode_2.h"
#include "leetcode_3.h"
#include "leetcode_4.h"
#include "leetcode_5.h"
#include "leetcode_6.h"
#include "leetcode_7.h"
#include "leetcode_8.h"
#include "leetcode_9.h"
#include "leetcode_10.h"
#include "leetcode_11.h"
#include "leetcode_12.h"
#include "leetcode_13.h"
#include "leetcode_14.h"
#include "leetcode_15.h"
#include "leetcode_16.h"
#include "leetcode_17.h"
#include "leetcode_18.h"
#include "leetcode_19.h"
#include "leetcode_20.h"
#include "leetcode_21.h"
#include "leetcode_22.h"
#include "leetcode_23.h"
#include "leetcode_24.h"
#include "leetcode_25.h"
#include "leetcode_26.h"
#include "leetcode_27.h"
#include "leetcode_28.h"
#include "leetcode_29.h"
#include "leetcode_30.h"
#include "leetcode_31.h"
#include "leetcode_32.h"
#include "leetcode_33.h"
#include "leetcode_34.h"
#include "leetcode_35.h"
#include "leetcode_36.h"
#include "leetcode_37.h"
#include "leetcode_38.h"
#include "leetcode_39.h"
#include "leetcode_40.h"
#include "leetcode_41.h"
#include "leetcode_42.h"
#include "leetcode_43.h"
#include "leetcode_44.h"
#include "leetcode_45.h"
#include "leetcode_46.h"
#include "leetcode_47.h"
#include "leetcode_48.h"
#include "leetcode_49.h"
#include "leetcode_50.h"
#include "leetcode_51.h"
#include "leetcode_52.h"
#include "leetcode_53.h"
#include "leetcode_54.h"
#include "leetcode_55.h"
#include "leetcode_56.h"
#include "leetcode_57.h"
#include "leetcode_58.h"
#include "leetcode_59.h"
#include "leetcode_60.h"
#include "leetcode_61.h"
#include "leetcode_62.h"
#include "leetcode_63.h"
#include "leetcode_64.h"
#include "leetcode_65.h"
#include "leetcode_66.h"
#include "leetcode_67.h"
#include "leetcode_68.h"
#include "leetcode_69.h"
#include "leetcode_70.h"
#include "leetcode_71.h"
#include "leetcode_72.h"
#include "leetcode_73.h"
#include "leetcode_74.h"
#include "leetcode_75.h"
#include "leetcode_76.h"
#include "leetcode_77.h"
#include "leetcode_78.h"
#include "leetcode_79.h"
#include "leetcode_80.h"
#include "leetcode_81.h"
#include "leetcode_82.h"
#include "leetcode_83.h"
#include "leetcode_84.h"
#include "leetcode_85.h"
#include "leetcode_86.h"
#include "leetcode_87.h"
#include "leetcode_88.h"
#include "leetcode_89.h"
#include "leetcode_90.h"
#include "leetcode_91.h"
#include "leetcode_92.h"
#include "leetcode_93.h"
#include "leetcode_94.h"
#include "leetcode_95.h"
#include "leetcode_96.h"
#include "leetcode_97.h"
#include "leetcode_98.h"
#include "leetcode_99.h"
//1-99 end
#include "leetcode_1108.h"
#include "leetcode_771.h"
#include "leetcode_938.h"
#include "leetcode_709.h"
#include "leetcode_1021.h"
#include "leetcode_804.h"
#include "leetcode_832.h"
#include "leetcode_905.h"
#include "leetcode_977.h"
#include "leetcode_657.h"
#include "leetcode_728.h"
#include "leetcode_617.h"
#include "leetcode_461.h"
#include "leetcode_852.h"
#include "leetcode_942.h"
#include "leetcode_929.h"
#include "leetcode_922.h"
#include "leetcode_965.h"
#include "leetcode_509.h"
#include "leetcode_1122.h"
#include "leetcode_1160.h"
#include "leetcode_944.h"
#include "leetcode_961.h"
#include "leetcode_811.h"
#include "leetcode_559.h"
#include "leetcode_999.h"
#include "leetcode_897.h"
#include "leetcode_1002.h"
#include "leetcode_1295.h"
#include "leetcode_1281.h"
#include "leetcode_1290.h"
#include "leetcode_1221.h"
#include "leetcode_1266.h"

#include "leetcode_1252.h"
#include "leetcode_1299.h"
#include "leetcode_1207.h"
#include "leetcode_1237.h"
#include "leetcode_1200.h"
#include "leetcode_1047.h"
#include "leetcode_344.h"
#include "leetcode_872.h"
#include "leetcode_893.h"
#include "leetcode_1030.h"
#include "leetcode_1185.h"
#include "leetcode_806.h"
#include "leetcode_1217.h"
#include "leetcode_867.h"
#include "leetcode_1022.h"
#include "leetcode_104.h"
#include "leetcode_500.h"
#include "leetcode_1302.h"
#include "leetcode_1282.h"
#include "leetcode_807.h"
#include "leetcode_1038.h"
#include "leetcode_1315.h"
#include "leetcode_535.h"
#include "leetcode_701.h"
#include "leetcode_654.h"
#include "leetcode_1008.h"
#include "leetcode_1078.h"
#include "leetcode_1305.h"
#include "leetcode_763.h"
#include "leetcode_797.h"
#include "leetcode_814.h"
#include "leetcode_1261.h"
#include "leetcode_890.h"
#include "leetcode_894.h"
#include "leetcode_1314.h"
#include "leetcode_304.h"
#include "leetcode_307.h"
#include "leetcode_123.h"
#include "leetcode_1313.h"
#include "leetcode_766.h"
#include "leetcode_985.h"
#include "leetcode_1287.h"
#include "leetcode_1260.h"
#include "leetcode_566.h"
#include "leetcode_1089.h"
#include "leetcode_1170.h"
#include "leetcode_888.h"
#include "leetcode_1013.h"
#include "leetcode_896.h"
#include "leetcode_283.h"
#include "leetcode_485.h"
#include "leetcode_169.h"
#include "leetcode_1184.h"
#include "leetcode_448.h"
#include "leetcode_217.h"
#include "leetcode_122.h"
#include "leetcode_697.h"
#include "leetcode_661.h"
#include "leetcode_268.h"
#include "leetcode_118.h"
#include "leetcode_121.h"
#include "leetcode_717.h"
#include "leetcode_830.h"
#include "leetcode_1232.h"
#include "leetcode_1018.h"
#include "leetcode_1010.h"
*/
#define function_head() function_head1(leetcode_NUM)
#define function_head1(EXP) function_head2(EXP)
//#define function_head2(EXP) main_##EXP()
#define function_head2(EXP)  sums_of_three(main_,EXP,())


#define Solution_head Solution_head1(leetcode_NUM)
#define Solution_head1(EXP) Solution_head2(EXP)
//#define Solution_head2(EXP) Solution##EXP
#define Solution_head2(EXP)  sums_of_two(Solution,EXP)


#define Solution_object Solution_object1(leetcode_NUM)
#define Solution_object1(EXP) Solution_object2(EXP)
//#define Solution_object2(EXP) Solution##EXP
#define Solution_object2(EXP)  sums_of_two(sol,EXP)


#define leetcode_include leetcode_include2(leetcode_NUM)
#define leetcode_include2(EXP) leetcode_include3(EXP)
//#define leetcode_include3(EXP) leetcode_##EXP.h
#define leetcode_include3(EXP)  sums_of_three(leetcode_,EXP,.h)

#define sums_of_three(x,y,z) x##y##z
#define sums_of_two(x,y) x##y

#define TO_STRING(str) _TO_STRING(str)
#define _TO_STRING(str) #str
#define leetcode_NUM 1325
#include TO_STRING(leetcode_include)


/*
void main_1108();
void main_771();
void main_938();
void main_709();
void main_1021();
void main_804();
void main_832();
void main_905();
void main_977(); 
void main_657();
void main_728();
void main_617();
void main_461();
void main_852();
void main_942();
void main_929();
void main_922();
void main_965();
void main_509();
void main_1122();
void main_1160();
void main_944();
void main_961();
void main_811();
void main_559();
void main_999();
void main_897();
void main_1002();
void main_1295();
void main_1281();
void main_1290();
void main_1221();
void main_1266();
void main_1252();
void main_1299();
void main_1207();
void main_1237();
void main_1200();
void main_1047();
void main_344();
void main_872();
void main_893();
void main_1030();
void main_1185();
void main_806();
void main_1217();
void main_867();
void main_1022();
void main_104();
void main_500();
void main_1302();
void main_1282();
void main_807();
void main_1038();
void main_1315();
void main_535();
void main_701();
void main_654();
void main_1008();
void main_1078();
void main_1305();
void main_763();
void main_797();
void main_814();
void main_1261();
void main_890();
void main_894();
void main_1314();
void main_304();
void main_307();
void main_123();
// 1- 99 begin
void main_1();
//1-99 end
void main_1313();
void main_766();
void main_985();
void main_1287();
void main_1260();
void main_566();
void main_1089();
void main_1170();
void main_888();
void main_1013();
void main_896();
void main_283();
void main_485();
void main_169();
void main_1184();
void main_448();
void main_217();
void main_122();
void main_697();
void main_661();
void main_268();
void main_118();
void main_121();
void main_717();
void main_830();
void main_1232();
void main_1018();
void main_1010();
*/
using namespace std;
void function_head();
static int faster_streams = []() {
	std::ios::sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();
int main() {
	cout << leetcode_NUM << " begin" << endl;
	function_head();
	cout << leetcode_NUM << " end"<<endl;
	cin.get();
	cin.get();
	
return 0;
}
void function_head() {
	Solution_head Solution_object;
	Solution_object.test();
}/*

void main_108() {
	string  temp = "1.1.1.1";
	Solution1108 sol1108 = Solution1108();
	cout << sol1108.defangIPaddr(temp);
	cin.get();
	cin.get();
}

void main_771() {
	unordered_map<char, bool> map;
	map.insert(make_pair('a', true));
	bool b = map.at('a');
	cout << b << endl;
	map.erase('a');
	map.insert(make_pair('a', false));
	cout << map.at('a') << endl;
	string j;
	string s;
	cin >> j;
	cin >> s;
	Solution771 sol771 = Solution771();
	cout << sol771.numJewelsInStones(j, s);
	cin.get();
	cin.get();
}
void main_938() {
	TreeNode938 * root = new TreeNode938(10);
	root->left = new TreeNode938(5);
	root->right = new TreeNode938(15);
	root->left->left = new TreeNode938(3);
	root->left->right = new TreeNode938(7);
	root->right->left = nullptr;
	root->right->right= new TreeNode938(18);
	Solution938 sol938;
	cout << sol938.rangeSumBST(root, 7, 15) << endl;
	cout << (int)'A' << " " << (int)'a' << endl;
	cin.get();
	cin.get();

}
void main_709() {
	Solution709 sol709;
	string hello = "HEllo";
	cout << sol709.toLowerCase(hello) << endl;
}
void main_1021() {
	Solution1021 sol1021;
	string s = "(()())(())(()(()))";
	cout << sol1021.removeOuterParentheses(s);

}
void main_804() {
	Solution804 sol804;
	vector<string> words = {"gin", "zen", "gig", "msg"};
	cout << sol804.uniqueMorseRepresentations(words);
}
void main_832() {
	Solution832 sol832;
	vector<vector<int>> matrixs = { {1, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 }};
	sol832.flipAndInvertImage_1(matrixs);
	sol832.flipAndInvertImage_2(matrixs);
	for (int i = 0; i < matrixs.size(); i++)
	{
		for (int j = 0; j < matrixs[0].size(); j++)
		{
			cout << matrixs[i][j] << " ";
		}
		cout << endl;
	}

}
void main_905() {
	Solution905 sol905;
	vector<int> parity = { 3,1,2,4 };
	for (int i = 0; i < parity.size(); i++)
	{
		cout << parity[i] << " ";
	}
	sol905.sortArrayByParity(parity);
	cout << "?" << endl;
	for (int i = 0; i < parity.size(); i++)
	{
		cout << parity[i] << " ";
	}

}
void main_977() {
	Solution977 sol977;
	vector<int> temp = { -1000,-998,-996,-995,-988,-985,-985,-985,-984,-977,-976,-973,-971,-969,-968,-967,-967,-963,-958,-956,-955,-954,-954,-953,-950,-950,-948,-947,-947,-945,-940,-938,-936,-936,-936,-935,-934,-930,-929,-926,-925,-924,-924,-923,-921,-915,-914,-913,-907,-903,-903,-899,-897,-892,-891,-890,-888,-886,-885,-884,-883,-882,-881,-876,-874,-874,-872,-870,-870,-869,-867,-865,-864,-862,-859,-857,-847,-847,-843,-839,-839,-838,-837,-829,-825,-825,-822,-821,-819,-819,-815,-814,-813,-811,-810,-809,-809,-808,-808,-807,-807,-806,-803,-801,-801,-800,-797,-796,-794,-789,-787,-786,-786,-785,-782,-780,-776,-774,-770,-770,-769,-769,-769,-767,-767,-762,-758,-758,-755,-749,-745,-743,-741,-740,-739,-737,-736,-735,-732,-727,-727,-726,-724,-724,-723,-722,-720,-718,-714,-713,-712,-711,-711,-710,-710,-695,-693,-692,-692,-691,-688,-687,-681,-680,-677,-676,-675,-673,-673,-669,-665,-661,-660,-659,-658,-658,-656,-656,-652,-649,-648,-646,-642,-640,-636,-633,-632,-630,-624,-624,-622,-621,-617,-616,-614,-611,-609,-606,-604,-604,-602,-600,-594,-589,-577,-574,-572,-572,-571,-568,-566,-561,-553,-547,-547,-547,-533,-532,-527,-526,-525,-519,-517,-516,-514,-510,-509,-504,-500,-499,-498,-495,-494,-493,-489,-487,-487,-486,-485,-484,-480,-472,-469,-468,-467,-461,-460,-460,-459,-457,-456,-455,-442,-441,-440,-439,-438,-435,-434,-434,-434,-433,-430,-430,-426,-421,-417,-413,-411,-410,-408,-407,-404,-403,-397,-397,-397,-396,-391,-388,-384,-381,-381,-380,-377,-375,-370,-369,-368,-367,-365,-364,-361,-356,-353,-353,-352,-351,-344,-341,-341,-341,-341,-340,-339,-338,-337,-337,-337,-336,-334,-331,-329,-329,-326,-325,-322,-316,-313,-313,-308,-308,-302,-301,-296,-295,-294,-292,-289,-288,-287,-285,-281,-280,-279,-273,-271,-270,-270,-268,-264,-264,-264,-262,-261,-259,-255,-255,-253,-251,-248,-247,-244,-242,-242,-240,-238,-237,-234,-232,-230,-227,-219,-216,-215,-213,-212,-212,-211,-209,-207,-199,-197,-193,-193,-191,-191,-190,-190,-184,-180,-177,-175,-173,-173,-172,-172,-171,-170,-170,-170,-165,-163,-163,-162,-160,-158,-158,-158,-158,-156,-152,-152,-151,-149,-143,-142,-139,-137,-137,-134,-133,-132,-126,-124,-122,-120,-120,-119,-118,-118,-117,-114,-113,-112,-111,-111,-111,-110,-110,-109,-109,-101,-100,-95,-94,-94,-92,-85,-83,-78,-77,-74,-72,-72,-70,-66,-66,-64,-64,-61,-61,-58,-58,-57,-54,-53,-51,-50,-50,-50,-46,-45,-43,-42,-40,-38,-37,-32,-30,-27,-23,-22,-21,-18,-15,-14,-14,-13,-11,-6,-6,-5,-1,3,4,8,9,13,21,23,26,26,27,31,33,35,38,38,39,39,40,42,43,50,54,57,57,60,60,62,68,70,71,73,76,77,80,91,92,93,93,93,94,95,96,97,97,103,108,115,115,116,116,120,121,121,121,124,126,126,126,126,128,134,134,138,138,139,142,146,147,150,153,157,161,162,168,172,173,174,178,178,180,180,182,185,187,189,192,192,194,194,196,201,202,203,205,211,214,214,215,216,217,218,223,225,233,233,238,241,241,244,244,244,246,249,250,251,253,256,256,258,260,261,261,263,264,267,268,271,272,272,273,274,275,275,279,282,283,286,286,287,287,290,292,293,294,295,296,297,298,299,299,302,302,305,309,309,309,311,312,313,314,315,317,317,318,320,321,323,326,327,335,339,339,341,342,347,349,351,351,356,356,357,357,357,368,375,386,387,387,387,390,394,398,402,403,406,406,407,408,409,410,414,417,417,418,419,421,422,425,426,427,427,429,432,433,435,436,438,445,445,446,447,447,449,450,450,453,459,459,462,464,468,468,469,471,474,474,474,475,475,476,476,477,479,480,481,481,485,488,488,488,493,496,497,498,503,506,506,509,514,515,517,518,523,523,523,524,527,528,529,531,532,539,540,541,543,543,546,550,551,551,553,554,555,555,557,559,560,565,577,577,582,583,584,585,587,587,589,591,592,594,596,597,599,600,605,607,613,613,615,618,620,620,621,621,622,623,624,626,626,627,627,627,630,633,633,635,637,637,638,639,640,642,643,644,644,646,647,648,652,654,655,656,658,659,664,667,668,670,674,675,675,680,682,682,688,690,691,692,698,700,703,706,710,710,712,713,713,721,722,722,728,728,731,732,734,736,738,739,739,740,741,741,743,743,745,746,747,748,750,750,753,753,758,759,762,764,768,770,772,774,774,776,778,780,782,782,784,786,789,789,790,790,791,792,792,793,793,801,802,803,803,805,806,807,808,809,811,815,815,818,818,819,823,825,827,832,837,840,841,842,847,848,848,850,852,853,854,854,859,863,865,866,866,867,868,868,869,874,875,876,880,881,882,882,887,888,894,895,897,900,901,903,903,904,905,907,909,915,916,919,926,931,932,933,934,935,938,941,941,941,944,948,952,957,959,959,962,971,971,973,976,977,977,981,983,984,984,984,985,990,992,993,996,998,999,1000 };
	sol977.sortedSquares(temp);
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << " " << endl;
	}
}
void main_657() {
	Solution657 sol657;
	string str657 = "UD";
	cout << sol657.judgeCircle(str657);

}
void main_728() {
	Solution728 sol728;
	vector<int> selfdivides = sol728.selfDividingNumbers(1, 22);
	for (size_t i = 0; i < selfdivides.size(); i++)
	{
		cout << selfdivides[i] << endl;
	}
}
void main_617() {
	Solution617 sol617;
	Solution617::TreeNode617 * x1 = new Solution617::TreeNode617(1);
	Solution617::TreeNode617 * x2 = new Solution617::TreeNode617(2);
	Solution617::TreeNode617 * x3 = new Solution617::TreeNode617(3);
	Solution617::TreeNode617 * x4 = new Solution617::TreeNode617(5);
	Solution617::TreeNode617 * y1 = new Solution617::TreeNode617(2);
	Solution617::TreeNode617 * y2 = new Solution617::TreeNode617(1);
	Solution617::TreeNode617 * y3 = new Solution617::TreeNode617(3);
	Solution617::TreeNode617 * y4 = new Solution617::TreeNode617(4);
	Solution617::TreeNode617 * y5 = new Solution617::TreeNode617(7);
	x1->left = x3;
	x1->right = x2;
	x3->left = x4;

	y1->left = y2;
	y1->right = y3;
	y2->right = y4;
	y3->right = y5;

	Solution617::TreeNode617 * sum = new Solution617::TreeNode617(0);
	sum = sol617.mergeTrees(x1, y1);
	cout << sum->val << endl;
	cout << sum->left->val << endl;
	cout << sum->right->val << endl;
	cout << sum->left->left->val << endl;
	cout << sum->left->right->val << endl;
	cout << sum->right->right->val << endl;




}
void main_461() {
	Solution461 sol461;
	cout << sol461.hammingDistance(1, 4) << endl;
}
void main_852() {
	Solution852 sol852;
	vector <int> vec852 = { 0,2,1,0 };
	cout << sol852.peakIndexInMountainArray(vec852) << endl;
	cout << "finish 852" << endl;
}
void main_942() {
	Solution942 sol942;
	cout << (int)('I') << endl;
	string str942 = "DDI";
	vector <int> temp942 = sol942.diStringMatch(str942);
	for (int i = 0; i < temp942.size(); i++)
	{
		cout << temp942[i] << endl;
	}
	cout << "finish 942" << endl;
}
void main_929() {
	Solution929 sol929;
	vector<string> emails =
	{ "fzk@ownxv.fvxas.com",
"fzk@ownxv.fvxas.com",
"fzk@ownxv.fvxas.com",
"h@r.oy.com",
"fzk@ownxv.fvxas.com",
"fzk@ownxv.fvxas.com" };
	cout << sol929.numUniqueEmails(emails) << endl;
}
void main_922() {

	cout << "922 begin" << endl;
	Solution922 sol922;
	vector<int> vec922 = { 4,2,5,7 };
	sol922.sortArrayByParityII_2(vec922);
	for ( int i = 0; i < vec922.size(); i++)
	{
		cout << vec922[i] << endl;
	}
	cout << "922 finish" << endl;
}
void main_965() {
	cout << "965 begin" << endl;
	Solution965 sol965;
	Solution965::TreeNode965  x1 = Solution965::TreeNode965(2);
	Solution965::TreeNode965  x2 = Solution965::TreeNode965(2);
	Solution965::TreeNode965  x3 = Solution965::TreeNode965(2);
	Solution965::TreeNode965  x4 = Solution965::TreeNode965(5);
	Solution965::TreeNode965  x5 = Solution965::TreeNode965(2);
	(x1.left) = &x2;
	(x1.right) = &x3;
	(x2.left) = &x4;
	(x2.right) = &x5;
	cout << (bool)sol965.isUnivalTree(&x1) << endl ;
	cout << "965 finish" << endl;
	

}
void main_509() {
	int a = 0;
	int b = 1;
	int temp;
	for (int i = 0; i < 30; i++)
	{
		temp = a;
		a = b;
		b = temp + a;
		cout << a << endl;
	}
}
void main_1122() {
	Solution1122 sol1122;
	vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
	vector <int> arr2 = { 2,1,4,3,9,6 };
	vector <int> arr3 = sol1122.relativeSortArray(arr1,arr2);
	for ( int i = 0; i < arr3.size(); i++)
	{
		cout << arr3[i] << endl;
	}
}
void main_1160() {
	Solution1160 sol1160;
	vector<string> words;
	cout << 1 << endl;
	words.push_back("hello");
	cout << 2 << endl;
	words.push_back("world");
	cout << 3 << endl;
	words.push_back("leetcode");
	cout << 4 << endl;
	string chars = "welldonehoneyr";
	cout << 6 << endl;
	cout << sol1160.countCharacters(words,chars);
	//printf("%s","fuck");
}
void main_944() {
	Solution944 sol944;
	vector<string> array2 = { "rrjk","furt","guzm"};
	cout << sol944.minDeletionSize(array2);

}
void main_961() {
	Solution961 sol961;
	vector<int> A = { 5,1,5,2,5,3,5,4 };
	cout << sol961.repeatedNTimes(A) << endl;

}
void main_811() {
	Solution811 sol811;
	string str1 = "9001 www.baidu.com";
	cout << str1.find(" ") << endl;
	cout << std::stoi(str1.substr(0, str1.find(" "))) << endl;
	string str2 = "www.microsoft.com.cn";
	vector<string> vec2 = sol811.getDomains(str1);
	for (int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << endl;
	}
	cout << "?" << endl;
	vector<string> vec = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
	vector<string> vec3 = sol811.subdomainVisits(vec);
	for (int i = 0; i < vec3.size(); i++)
	{
		cout << vec3[i] << endl;
	}
}
void main_559(){
	Solution559 sol559;
	Node559 * one = new Node559();
	Node559 * two = new Node559();
	Node559 * three = new Node559();
	Node559 * four =  new Node559();
	Node559 * five = new Node559();
	Node559 * six = new Node559();
	one->val = 1;
	two->val = 2;
	three->val = 3;
	four->val = 4;
	five->val = 5;
	six->val = 6;
	one->children.push_back(three);
	one->children.push_back(two);
	one->children.push_back(four);
	three->children.push_back(five);
	three->children.push_back(six);
	cout << sol559.maxDepth(one) << endl;

}
void main_1002();
void main_999() {
	Solution999 sol999;
	vector<vector<char>> vecvec = {
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', 'p', '.', '.', '.', '.'},
		{'.', '.', '.', 'R', '.', '.', '.', 'p'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', 'p', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'} 
	};
	vector<vector<char>> vecvec2 = { 
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
		{'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
		{'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
	    {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
		{'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'} }
	;
	cout << sol999.numRookCaptures(vecvec) << endl;
	cout << sol999.numRookCaptures(vecvec2) << endl;
}
void main_897() {
	TreeNode897 * one = new TreeNode897(1);
	TreeNode897 * two = new TreeNode897(2);
	TreeNode897 * three = new TreeNode897(3);
	TreeNode897 * four = new TreeNode897(4);
	TreeNode897 * five = new TreeNode897(5);
	TreeNode897 * six = new TreeNode897(6);
	TreeNode897 * seven = new TreeNode897(7);
	TreeNode897 * eight = new TreeNode897(8);
	TreeNode897 * nine = new TreeNode897(9);
	TreeNode897 * ten = new TreeNode897(10);
	five->left = three;
	five->right = six;
	three->left = two;
	three->right = four;
	six->right = eight;
	two -> left = one;
	eight->left = seven;
	eight->right = nine;
	Solution897 sol897;
	TreeNode897 * outputs = sol897.increasingBST(five);
	cout << outputs->val << " " << outputs->right->val << endl;

}
void main_1002() {
	Solution1002 sol1002;
	vector<string> vec = {"bella","label","roller" };
	vector<string> vec2 = sol1002.commonChars(vec);
	for ( int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << endl;
	}
	int x = 3;
	string str= "";
	str += to_string(char('a' + 3));
	cout << str;
}
void main_1295() {
	Solution1295 sol1295;
	vector <int> nums1 = { 12, 345, 2, 6, 7896 };
	vector <int> nums2 = { 555, 901, 482, 1771 };
	cout << sol1295.findNumbers(nums1) << endl;
	cout << sol1295.findNumbers(nums2) << endl;
}
void main_1281() {
	Solution1281 sol1281;
	int num1 = 234;
	int num2 = 4421;
	assert(sol1281.subtractProductAndSum(num1) == 15);
	assert(sol1281.subtractProductAndSum(num2) == 21);
}
void main_1290() {
	Solution1290 sol1290;
	ListNode  node1 = ListNode(1);
	ListNode  node2 = ListNode(0);
	ListNode  node3 = ListNode(1);
	node1.next = &node2;
	node2.next = &node3;
	cout << sol1290.getDecimalValue(&node1) << endl;
}
void main_1221() {
	Solution1221 sol1221;
	string str1 = "RLRRLLRLRL";
	string str2 = "RLLLLRRRLR";
	string str3 = "LLLLRRRR";
	string str4 = "RLRRRLLRLL";
	cout << sol1221.balancedStringSplit(str1) <<endl;
	cout << sol1221.balancedStringSplit(str2) << endl;
	cout << sol1221.balancedStringSplit(str3) << endl;
	cout << sol1221.balancedStringSplit(str4) << endl;
	assert(sol1221.balancedStringSplit(str1) == 4);
	assert(sol1221.balancedStringSplit(str2) == 3);
	assert(sol1221.balancedStringSplit(str3) == 1);
	assert(sol1221.balancedStringSplit(str4) == 2);
}
void main_1266() {
	Solution1266 sol1266;
	vector<vector<int>> nums1 = { {1,1},{3,4},{-1,0} };
	vector<vector<int>> nums2 = { {3, 2},{-2, 2} };
	cout << sol1266.minTimeToVisitAllPoints(nums1) << endl;
	cout << sol1266.minTimeToVisitAllPoints(nums2) << endl;
	assert(sol1266.minTimeToVisitAllPoints(nums1) == 7);
	assert(sol1266.minTimeToVisitAllPoints(nums2) == 5);


}
*/