#ifndef SUFFIXTREE_H
#define SUFFIXTREE_H

#include <string>
#include <map>
#define mapIter map<char, SuffixNode*>::iterator
using namespace std;

struct SuffixNode
{
    map<char, SuffixNode*> next;
    string nodeStr;
    int branchNum;
};

void insertStr(SuffixNode* st, string s);
void compress(SuffixNode* sn);
SuffixNode* creatSuffixTree(string s, bool zip = true);
void contrast(SuffixNode* sn, string t, bool& flag);
bool isContain(string s, string t);
void getLeafNum(SuffixNode* sn, int& num);
void count(SuffixNode* sn, string t, int& num);
int findRepeatNum(string s, string t);
void digForDeepestNotLeaf(SuffixNode* sn, int currentDepth, SuffixNode*& dn, int& maxDepth);
void digForLongestNotLeaf(SuffixNode* sn, SuffixNode*& ln, int& longest);
string longestRepearSub(string s);

#endif // SUFFIXTREE_H
