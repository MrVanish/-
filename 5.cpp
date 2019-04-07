#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <set>

using namespace std;

long long long_input()
{
	long long input;
	cin >> input;
	return input;
}

vector<vector<pair<long long, long long>>> graph_input(long long n, long long m)
{
	vector<vector<pair<long long, long long>>> graph(n);

	for (long long i = 0; i < n; i++)
		graph.push_back(vector<pair<long long, long long>>());

	for (long long i = 0; i < m; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(b - 1, c));
		graph[b - 1].push_back(make_pair(a - 1, c));
	}

	return graph;
}

int main()
{
	const long long N = long_input();
	const long long M = long_input();
	const vector<vector<pair<long long, long long>>> graph = graph_input(N, M);
	const long long A = long_input() - 1;
	const long long B = long_input() - 1;

	vector<long long> d(N, 10e12);
	d[A] = 0;
	set<pair<long long, long long>> q;
	q.insert(make_pair(d[A], A));
	while (!q.empty())
	{
		long long v = q.begin()->second;
		q.erase(q.begin());

		for (long long j = 0; j < graph[v].size(); j++)
		{
			long long to = graph[v][j].first, len = graph[v][j].second;
			if (d[v] + len < d[to])
			{
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				q.insert(make_pair(d[to], to));
			}
		}
	}

	cout << d[B] << endl;
}
