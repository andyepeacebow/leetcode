class Solution {
public:
	char buf[100000];
	bool fromRoot;
	vector<string> vec;

    string simplifyPath(string path) {
		if (path.length() == 0) return "";

        strcpy(buf, path.c_str());
		fromRoot = path[0] == '/';
		char* ptr = strtok(buf, "/");
		do {
			if (ptr == nullptr) break;
			if (strlen(ptr) == 0) continue;

			if (!strcmp(ptr, ".")) {
			} else if (!strcmp(ptr, "..")) {
				if (vec.size()) {
					vec.pop_back();
				}
			} else {
				vec.push_back(string(ptr));
			}
		} while (ptr = strtok(NULL, "/"));

		string ans = fromRoot ? "/" : "";
		for (int i = 0; i < vec.size(); i ++) {
			ans += vec[i];
			if (i < vec.size() - 1) {
				ans += "/";
			}
		}

		return ans;
    }
};