#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string str;
	long Q, X, Y;
	cin >> str >> Q;
	vector<pair<long, long>> Z(str.size());
	for (long i = 0; i < Q; ++i)
	{
		cin >> X >> Y;
		if (X > Y)
			swap(X, Y);
		Z[--X].first++;
		Z[--Y].second++;
	}
	for (unsigned long i = 0; i <str.size(); ++i)
	{
		if (Z[i].first & 1)
			if (islower(str.at(i))) 
				str.at(i) = toupper(str.at(i));
			else
				str.at(i) = tolower(str.at(i));
		if (i < str.size()-1)
			Z[i + 1].first += Z[i].first - Z[i].second;
	}
	cout << str;
	return 0;
}