#include <iostream>
#include <string>
#include <vector>
#include <map>
#define mapIter map<char, SuffixNode*>::iterator
using namespace std;

struct SuffixNode
{
	map<char, SuffixNode*> next;
	string nodeStr;
	int branchNum;
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
	// insert the string without compress
	insertStr(st, s);
	// compress the suffix tree
	if(zip)
		compress(st);

	return st;
}


void contrast(SuffixNode* sn, string t, bool& flag)
{
	// contrast if same with t
	if(sn->nodeStr.substr(0, t.size()) == t)
	{
		flag = true;	
		return;
	}
	if(sn->branchNum == 0 || flag)
	{
		return;
	}
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		contrast(i->second, t, flag);
	}
}

bool isContain(string s, string t)
{
	SuffixNode* st = creatSuffixTree(s);
	bool flag = false;
	contrast(st, t, flag);
	return flag;
}


void getLeafNum(SuffixNode* sn, int& num)
{
	if(sn->branchNum == 0)
	{
		num += 1;
		return;
	}
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		getLeafNum(i->second, num);
	}
}

void count(SuffixNode* sn, string t, int& num)
{ 
	if(sn->nodeStr == t)
	{
		getLeafNum(sn ,num);
		return;
	}
	if(sn->branchNum == 0)
	{
		return;
	}	
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		count(i->second, t, num);
	}
}

int findRepeatNum(string s, string t)
{
	// A suffix tree without compression
	SuffixNode* st = creatSuffixTree(s, false);
	int num = 0;
	count(st, t, num);
	return num;
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

void digForLongestNotLeaf(SuffixNode* sn, SuffixNode*& ln, int& longest)
{
	if(sn->nodeStr.size() > longest && sn->branchNum >=2)
	{
		longest = sn->nodeStr.size();
		ln = sn;
	}
	if(sn->branchNum == 0)
	{
		return;
	}
	for(mapIter i=sn->next.begin(); i!=sn->next.end(); i++)
	{
		digForLongestNotLeaf(i->second, ln, longest);
	}
}

string longestRepearSub(string s)
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
	int longest = 0;
	digForLongestNotLeaf(st, longestNodeNotLeaf, longest);
	return longestNodeNotLeaf->nodeStr;
}


int main(int argc, char const *argv[])
{
	string s = "banana";
	SuffixNode* st = creatSuffixTree(s);
	// SuffixNode* stnc = creatSuffixTree(s, false);
	// int num = 0;
	// getLeafNum(st, num);
	// cout << num << endl;
	// cout << "-------" << endl;
	// compress(st);
	// cout << st->next['b']->nodeStr << endl;
	// cout << st->next['n']->next['a']->nodeStr << endl;
	// cout << st->branchNum << endl;
	// cout << "test" << " " << st->next['b']->nodeStr << endl;
	// cout << isContain("anselishandsome", "sk") << endl;
	// cout << findRepeatNum("dsfvnjafgadchufgaucbagfbcvagffgfgfgcd", "fg") << endl;
	cout << longestRepearSub("cdfscacaxzcdasdfgsdfscascadaczdasdfgadasdfg") << endl;
	return 0;
}