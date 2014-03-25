class Solution {
public:
	vector<string> vec;
	string ans;

    void reverseWords(string &s) {
		char buf[100000];
		strcpy(buf, s.c_str());
		char* ptr = strtok(buf, " ");
		while (ptr) {
			int len = strlen(ptr);
			if (len > 0) {
				vec.push_back(string(ptr));
			}
			ptr = strtok(NULL, " ");
		}

		int n = vec.size();
		for (int i = n - 1; i >= 0; i --) {
			ans += vec[i];
			if (i > 0) {
				ans += " ";
			}
		}
		s = ans;
    }
};