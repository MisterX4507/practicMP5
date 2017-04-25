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
	vector <let>::iterator Iter; int i;
	for (i = 0; i <= 9; i++)   //заполнение очереди
	{
		let element; element.n = 2 * i + 1; element.s = (char)(-i);
		q1.push(element);
	}
	size_t size_q1 = q1.size();
	while (!q1.empty())  //работа с очередью
	{
		v.push_back(q1.front());
		q1.pop();
	}
	sort(v.begin(), v.end(), [](const let& a, const let& b)
	{
		return a.n > b.n; });
	cout << "Sorted queue = ( ";
	for_each(v.begin(), v.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!v.empty())
	{
		q1.push(v.front());
		v.erase(v.begin());
	}
	for (i = size_q1; i > 0; i--) {    // работа с вектором
		let element = q1.front(); q1.pop();
		if ((int)element.s < -5) v1.push_back(element); else
			q1.push(element);
	}
	sort(v1.begin(), v1.end(), [](const let& a, const let& b)
	{
		return a.n > b.n; });
	cout << "Sorted vector v1 = ( ";
	for_each(v1.begin(), v1.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!q1.empty())  //снова работа с очередью
	{
		v.push_back(q1.front());
		q1.pop();
	}
	sort(v.begin(), v.end(), [](const let& a, const let& b)
	{
		return a.n < b.n; });
	cout << "Sorted queue = ( ";
	for_each(v.begin(), v.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!v.empty())
	{
		q1.push(v.front());
		v.erase(v.begin());
	}
	sort(v1.begin(), v1.end(), [](const let& a, const let& b) //сортировка вектора
	{
		return a.n < b.n; });
	cout << "Sorted vector v1 = ( ";
	for_each(v1.begin(), v1.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
}