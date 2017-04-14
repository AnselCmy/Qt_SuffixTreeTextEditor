#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node
{
	vector<Node*> next;
	string str;
};

int main(int argc, char const *argv[])
{
	map<char, int> a;
	string str = "asdfghxcv";
	a[str[0]] = 1;
	a[str[1]] = 2;
	char addStr[2];
	string s1 = "asdsda";
	string s2 = "adf";
	vector<int> b;
	b.push_back(1);
	b.push_back(2);
	// for(map<char, int>::iterator i=a.begin(); i!=a.end(); i++)
	// {
	// 	cout << i->first << " " << i->second << endl;
	// }
	cout << s1.substr(5, 3);
	return 0;
}

