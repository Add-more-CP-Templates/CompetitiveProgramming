#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int a[n];
	int numbers[3002]={0};
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		numbers[a[i]]=1;
	}
	for (int i=1;i<3002;++i)
	{
		if (numbers[i]==0)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}