#include <iostream>
#include <stack>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	stack<int> st;
	int n;
	cout << "N = ";
	cin >> n;
	cout << "Введите " << n << " чисел: ";
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		st.push(a);
	}
	cout << "Вершина стека - " << st.top();
	return 0;
}
