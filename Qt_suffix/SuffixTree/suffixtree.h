#ifndef SUFFIXTREE_H
#define SUFFIXTREE_H

#include <string>
#include <map>
#include <vector>
#define mapIter map<char, SuffixNode*>::iterator
#define vecIter vector<int>::iterator
using namespace std;

struct SuffixNode
{
    map<char, SuffixNode*> next;
    string nodeStr;
    int branchNum;
    int subSrc;
};

void insertStr(SuffixNode* st, string s);
void compress(SuffixNode* sn);
SuffixNode* creatSuffixTree(string s, bool zip = true);
void contrast(SuffixNode* sn, string t, bool& flag);
int isContain(string s, string t);
void getLeafNum(SuffixNode* sn, int& num, vector<int>& start);
void count(SuffixNode* sn, string t, int& num, vector<int>& start);
vector<int> findRepeatNum(string s, string t);
void digForDeepestNotLeaf(SuffixNode* sn, int currentDepth, SuffixNode*& dn, int& maxDepth);
void digForLongestNotLeaf(SuffixNode* sn, SuffixNode*& ln, int& longest);
string longestRepearSub(string s);

#endif // SUFFIXTREE_H
