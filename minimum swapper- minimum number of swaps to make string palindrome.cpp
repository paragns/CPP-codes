#include <bits/stdc++.h>
using namespace std;

int convert_palindrome(string str)
{
	int n = str.length();
	
	if(n < 2)
		return 0;

	map<char, int> freq, first_occ, last_occ;
	
	for(int i = 0; i < n; i++)
		last_occ[str[i]] = i, freq[str[i]]++;

	for(int i = n - 1; i >= 0; i--)
		first_occ[str[i]] = i;

	int odd_count = 0;
	for(char ele = 'a'; ele <= 'z'; ele++)
		if(freq.count(ele) and freq[ele]%2 != 0)
			odd_count++;

	if(odd_count > 1)
		return -1;

	char to_be_replaced;
	int min_cost = INT_MAX;
	for(char ele = 'a'; ele <= 'z'; ele++)
	{
		int cost = abs(0 - first_occ[ele]);
		cost += abs(n - 1 - last_occ[ele]);

		if(min_cost > cost)
		{
			min_cost = cost;
			to_be_replaced = ele;
		}
	}

	string new_str = "";

	for(int i = 0; i < n; i++)
	{
		if(i == first_occ[to_be_replaced] or i == last_occ[to_be_replaced])
			continue;

		new_str += str[i];
	}

	int res = min_cost + convert_palindrome(new_str);
	return res;
}


/* ### READ-ONLY PART ### */
int minSwapper(char *input1)
/* ### READ-ONLY PART ### */
{
	int len = strlen(input1);

	string str = "";
	for(int i = 0; i < len; i++)
		str += input1[i];

	return convert_palindrome(str);
}

int main()
{
	const int max_string_size = 1e3 + 3;
	char input1[max_string_size + 1];

	scanf("%s", input1);

	int res = minSwapper(input1);

	printf("%d\n", res);

	return 0;
}

