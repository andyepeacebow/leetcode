class Solution {
public:
	int len1, len2;
	vector<int> P;

    char *strStr(char *haystack, char *needle) {
		len1 = strlen(haystack);    
		len2 = strlen(needle);
		if (!len2) return haystack;
		else if (!len1) return nullptr;

		P.resize(len2 + 1);
		P[1] = 0;
		int j = 0;
		for (int i = 2; i <= len2; i ++) {
		   while ( (j > 0) && (needle[j] != needle[i - 1])) {
				j = P[j];
		   }
		   if (needle[j] == needle[i - 1]) {
			   j = j+1;
		   }
	 	   P[i] = j;
		}

		j = 0;
		for (int i = 1; i <= len1; i ++) {
		   while ((j>0) && (needle[j] != haystack[i - 1])) {
				j = P[j];
		   }
		   if (needle[j] == haystack[i - 1]) {
			   j = j + 1;
		   }
		   if (j == len2) {
			   return haystack + i - len2;
		   }
		}
		return nullptr;
	}
};