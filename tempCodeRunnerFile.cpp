#include <iostream>
#include <vector>
using namespace std;

vector<int> mergsort(vector<int> a, vector<int> b)
{
	vector<int> res;
	int i = 0;
	int j = b.size() - 1;
	while (i < a.size() && j >= 0)
	{
		if (a[i] <= b[j])
			res.push_back(a[i++]);
		else
			res.push_back(b[j--]);
	}

	while (i < a.size())
	{
		res.push_back(a[i++]);
	}
	while (j >= 0)
	{
		res.push_back(b[j--]);
	}
	return res;
}

int main()
{
	vector<int> a;
	int item;
	while (cin >> item)
	{
		a.push_back(item);
	}
	cin.clear();
	cin.ignore();
	vector<int> b;
	while (cin >> item)
	{
		b.push_back(item);
	}

	vector<int> res = mergsort(a, b);
	for (auto r : res)
	{
		cout << r << " ";
	}
	return 0;
}