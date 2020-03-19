#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

enum state {NEW, DURING, VISITED};

void visit(int cur, const vector<vector<int>> &less, vector<int> &state, bool &good)
{
	if (state[cur] == DURING)
	{
		good = false;
		return;
	}
	if (state[cur] == VISITED)
	{
		return;
	}
	assert(state[cur] == NEW);
	state[cur] = DURING;
	for (int next : less[cur]) {
		visit(next, less, state, good);
	}
	assert(state[cur] == DURING);
	state[cur] = VISITED;
}


int main()
{
	int numV;// количество вершин
	int numR;//  оличество ребер

	cin >> numV;
	cin >> numR;

	vector<vector<int>> less(1 + numV);

		for (int i = 0; i < numR; i++)
		{
			int v1;
			int v2;

			cin >> v1;
			cin >> v2;

			less[v1].push_back(v2);
		}

		vector<int> state(1 + numV, NEW);

		bool good = true;

	for (int i = 1; i <= numV; i++)
	{
		if (state[i] == NEW)
		{
			visit(i, less, state, good);
		}
	}
	if (good)
	{
		cout << "YES";

	}
	else
	{
		cout << "NO";
	}
	return 0;
}
