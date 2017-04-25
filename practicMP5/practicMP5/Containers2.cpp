#include <queue>
#include <vector>
#include <algorithm>    
#include <iostream>
#include <Windows.h>
using namespace std;
struct let {
		int n;
		char s;
	};
int main()
{
	setlocale(LC_ALL, "Russian");
	queue <let> q1;
	vector <let> v1;
	vector <let> v;
	vector <let>::iterator Iter;
	for (int i = 0; i <= 5; i++)
	{
		let element; element.n = 2 * i + 1; element.s = (char)((-1)*i);
		q1.push(element);
	}
	size_t size_q1 = q1.size(); let *a = new let[size_q1];
	while (!q1.empty())
	{
		let element = q1.front(); v.push_back(q1.front());
		cout << element.n << " " << element.s << endl;
		q1.pop();
	}
	sort(v.begin(), v.end(), [](const let& a, const let& b)
	{
		return a.n > b.n; });
	cout << "Sorted vector v = ( ";

	for_each(v.begin(), v.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!v.empty())
	{
		q1.push(v.front());
		v.erase(v.begin());
	}
}
