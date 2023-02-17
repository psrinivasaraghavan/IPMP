#include <bits/stdc++.h>
using namespace std;


void computeLPSArray(char* pattern, int m, int* lps)
{
	int len = 0;
	lps[0] = 0; 
	int i = 1;
	while (i < m) 
    {
		if (pattern[i] == pattern[len])
        {
			len++;
			lps[i] = len;
			i++;
		}
		else 
		{
			if (len != 0) len = lps[len - 1];
			else 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}



void KMP(char* pattern, char* text)
{
	int m = strlen(pattern), n = strlen(text), lps[m];
	computeLPSArray(pattern, m, lps);
	int i = 0, j = 0; 
	while ((n - i) >= (m - j)) 
    {
		if (pattern[j] == text[i]) 
        {
			j++;
			i++;
		}
		if (j == m) 
        {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}
		else if (i < n && pattern[j] != text[i]) 
        {
			if (j != 0) j = lps[j - 1];
			else i += 1;
		}
	}
}


int main()
{
	char text[] = "ABDABACDABABCABAB";
	char pattern[] = "CDABA";
	KMP(pattern, text);
	return 0;
}
