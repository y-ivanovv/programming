#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<string> deq;

void enqueue(string s)
{
	deq.push_back(s);
}

void dequeue()
{
	deq.pop_front();
}

void print()
{
	int n = deq.size();
	for (int i = 0; i < n; i++)
	{
		cout << deq[i] << " ";
	}
	cout << endl;
}

int count()
{
	int count = 0;
	while (!deq.empty())
	{
		string current = deq.front();
		deq.pop_front();
		if (current[0] == 'f' or current[0] == 't')
		{
			count++;
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "RU");
	enqueue("one");
	enqueue("two");
	enqueue("three");
	enqueue("four");
	enqueue("five");
	enqueue("six");
	print();
	dequeue();
	dequeue();
	enqueue("seven");
	print();
	cout << "\nКоличество строк начинающихся с букв «f» или «t» - " << count();
	return 0;
}