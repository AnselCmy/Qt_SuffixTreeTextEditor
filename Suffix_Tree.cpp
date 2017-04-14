#include <iostream>
#include <string>
#include <vector>
#include <map>
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


void insertStr(SuffixNode* st, string s)
{
	// Get the suffix of the string, and insert into suffix tree
	s = s + "$";
	string str = s;
	SuffixNode* tempNode;
	for(int start=0; start<s.size(); start++)
	{
		str = s.substr(start);
		tempNode = st;
		for(int i=0; i<str.size(); i++)
		{
			// If no node is the same as this charactor
			if((tempNode->next).find(str[i]) == (tempNode->next).end())
			{
				// Copy the string in current node to next node
				SuffixNode* newNode = new SuffixNode;
				newNode->branchNum = 0;
				newNode->nodeStr = tempNode->nodeStr;
				tempNode->next[str[i]] = newNode;
				// Add the new character into next node string
				char addStr[2];
				addStr[0] = str[i];
				addStr[1] = '\0';
				newNode->nodeStr += addStr;
				// Add the branch number of this node
				tempNode->branchNum++;
			}
			tempNode = tempNode->next[str[i]];
		}
		tempNode->subSrc = start;
	}
}

void compress(SuffixNode* sn)
{
	// cout << sn->nodeStr << " " << sn->branchNum << endl;
	SuffixNode* delNode;
	// shit up the node which has only one branch by loop
	while(sn->branchNum == 1)
	{
		// Get the only next node of current node as the delNode
		delNode = (sn->next.begin())->second;
		// update the sn
		sn->next = delNode->next;
		sn->nodeStr = delNode->nodeStr;
		sn->branchNum = delNode->branchNum;
		sn->subSrc = delNode->subSrc;
		delete delNode;
	}
	if(sn->branchNum == 0)
	{
		return;
	}
	// recursively travel all the node
	else
	{
		for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
		{
			compress(i->second);
		}
	}
}

SuffixNode* creatSuffixTree(string s, bool zip = true)
{
	// allocate the storage for a new pointer
	SuffixNode* st = new SuffixNode();
	st->nodeStr = "\0";
	st->branchNum = 0;
	st->subSrc = -1;
	// insert the string without compress
	insertStr(st, s);
	// compress the suffix tree
	if(zip)
		compress(st);

	return st;
}


void contrast(SuffixNode* sn, string t, bool& flag, int& start)
{
	// contrast if same with t
	if(sn->branchNum == 0 && sn->nodeStr.substr(0, t.size()) == t)
	{
		flag = true;
		start = sn->subSrc;
		return;
	}
	if(sn->branchNum == 0 || flag)
	{
		return;
	}
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		contrast(i->second, t, flag, start);
	}
}

int isContain(string s, string t)
{
	SuffixNode* st = creatSuffixTree(s);
	bool flag = false;
	int start = -1;
	contrast(st, t, flag, start);
	return start;
}


void getLeafNum(SuffixNode* sn, vector<int>& start)
{
	if(sn->branchNum == 0)
	{
		start.push_back(sn->subSrc);
		return;
	}
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		getLeafNum(i->second, start);
	}
}

void count(SuffixNode* sn, string t, int& num, vector<int>& start)
{ 
	if(sn->nodeStr.substr(0, t.size()) == t)
	{
		getLeafNum(sn, start);
		return;
	}
	if(sn->branchNum == 0)
	{
		return;
	}	
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		count(i->second, t, num, start);
	}
}

vector<int> findRepeatNum(string s, string t)
{
	// A suffix tree without compression
	SuffixNode* st = creatSuffixTree(s);
	int num = 0;
	vector<int> start;
	count(st, t, num, start);
	for(vecIter a=start.begin(); a!=start.end(); a++)
	{
		cout << *a << " ";
	}
	return start;
}


void digForDeepestNotLeaf(SuffixNode* sn, int currentDepth, SuffixNode*& dn, int& maxDepth)
{
	// cout << sn->nodeStr << " " << currentDepth << " " << sn->branchNum << endl;
	if(currentDepth > maxDepth & sn->branchNum >=2)
	{
		maxDepth = currentDepth;
		dn = sn;
	}
	if(sn->branchNum == 0)
	{
		return;
	}
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		digForDeepestNotLeaf(i->second, currentDepth+1, dn, maxDepth);
	}
}

void digForLongestNotLeaf(SuffixNode* sn, SuffixNode*& ln, int& longest, vector<int>& start)
{
	if(sn->nodeStr.size() > longest && sn->branchNum >=2)
	{
		longest = sn->nodeStr.size();
		// To get the subSrc in leaf node
		start.clear();
		getLeafNum(sn, start);
		ln = sn;
	}
	if(sn->branchNum == 0)
	{
		return;
	}
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		digForLongestNotLeaf(i->second, ln, longest, start);
	}
}

void longestRepeatSub(string s, int& longest, vector<int>& start)
{
	// Cost more by using suffix tree without compression
	// SuffixNode* st = creatSuffixTree(s, false);
	// SuffixNode* deepestNotLeaf;
	// int maxDepth = 0;
	// digForDeepestNotLeaf(st, 0, deepestNotLeaf, maxDepth);
	// return deepestNotLeaf->nodeStr;

	// Using the compressed tree is more sufficient
	SuffixNode* st = creatSuffixTree(s);
	SuffixNode* longestNodeNotLeaf;
	digForLongestNotLeaf(st, longestNodeNotLeaf, longest, start);
}

void HighLight(string* sPtr, int pos, int len)
{
    string s = *sPtr;
    *sPtr = s.substr(0, pos) + string("/") + s.substr(pos, len) + string("/") + s.substr(pos+len, s.size());
}

int main(int argc, char const *argv[])
{
	// string s = "banana";
	// SuffixNode* st = creatSuffixTree(s);
	// SuffixNode* stnc = creatSuffixTree(s, false);
	// int num = 0;
	// getLeafNum(st, num);
	// cout << num << endl;
	// cout << "-------" << endl;
	// compress(st);
	// cout << st->next['$']->subSrc << endl;
	// cout << st->next['n']->next['a']->nodeStr << endl;
	// cout << st->branchNum << endl;
	// cout << "test" << " " << st->next['b']->nodeStr << endl;
	string s = "asdfvmkdmvsdmkjdfvgkjnjfnbnbkjfdkfvkjdnvjkdnfjkvmjdfnmvzkcmiemrfmdsfkmsfmskmfkmsvmisfmmvjadfdfvdfvvdvgfddfdfdfd";
	string t = "df";
	string rst = s;
	// int rst = isContain(s, t);
	// cout << rst << endl;
	// cout << s.substr(0, rst) + string("<b>") + s.substr(rst, t.size()) + string("<b>") + s.substr(rst+t.size(), s.size()) << endl;
	
	// vector<int> repeatVec = findRepeatNum(s, t);
	// sort(repeatVec.begin(), repeatVec.end(),greater<int>());
	// for(vecIter i=repeatVec.begin(); i!=repeatVec.end(); i++)
	// {
	// 	HighLight(&rst, *i, t.size());
	// }
	// cout << rst << endl;
	int longest = 0;
	vector<int> start;
	string str = "cdfscacaxzcdasdfgsdfscascadaczdasdfgadasdfg";
	longestRepeatSub(str, longest, start);
	sort(start.begin(), start.end(),greater<int>());
	for(vecIter i=start.begin(); i!=start.end(); i++)
	{
		HighLight(&str, *i, longest);
		cout << *i << " ";
	}
	cout << str;
	// cout <<  << endl;
	return 0;
}