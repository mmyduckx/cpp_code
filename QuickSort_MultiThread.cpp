#include<iostream>
#include<vector>
#include<thread>
using namespace std;

void q_sort(vector<int>& v1, int i, int j);

int main()
{
	thread t1, t2;
	vector<int> v(100);
	for (int w = 0; w < 100; w++) v[w] = rand() % 50;
	cout << endl;
	for (auto i : v) { cout << i << " "; }
	cout << endl;


	int l = 0, u = 99;
	int b1 = 0, e1 = 99;
	int temp1 = v[0], temp2;
	for (int k = 1; k <= e1; k++)
	{
		if (v[k] < temp1) { v[l] = v[k]; l++; }
		else { temp2 = v[u]; v[u] = v[k]; v[k] = temp2; u--; k--; e1--; }
	}
	v[l] = temp1;
	if ((l - 1 > 0)) t1 = thread(q_sort, ref(v), 0, l - 1);

	if ((99 > u + 1)) t2 = thread(q_sort, ref(v), u + 1, 99);

	if (t1.joinable()) t1.join();
	if (t2.joinable()) t2.join();

	for (int w = 0; w < 100; w++) cout << v[w] << "   ";

	cout << "\n\n";
	return 0;

}

void q_sort(vector<int>& v1, int b, int e)
{
	if (b == e) return;
	int temp;

	int l = b, u = e;
	int b1 = b, e1 = e;
	int temp1 = v1[b], temp2;
	for (int k = b1 + 1; k <= e1; k++)
	{
		if (v1[k] < temp1) { v1[l] = v1[k]; l++; }
		else { temp2 = v1[u]; v1[u] = v1[k]; v1[k] = temp2; u--; k--; e1--; }
	}
	v1[l] = temp1;

	if ((l - 1 > b)) q_sort(v1, b, l - 1);
	if ((e > u + 1)) q_sort(v1, u + 1, e);
	return;
}
