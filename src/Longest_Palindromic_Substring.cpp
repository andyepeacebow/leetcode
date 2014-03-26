class Solution {
public:
	int p[3000]; //表示以i为中心的回文半径
	string oldstr;
	char str[3000];

	string Manacher(int n){
 
		int mx=0; //记录前面回文串最长影响到的地方。不一定是最长回文串造成的。
		int id; //最长影响串的位置;
		p[0]=0;
		
		int big = -1;
		int idx = -1;

		for(int i = 1; i < n; i++){
			p[i]=1;//至少是1
			if(mx>i){
				//i受到影响即，id+p[id]-1>=i;
				p[i] = p[2 * id - i];//2*id-i是i关于id的对称点相当于是id-(i-id);
				if(mx - i < p[i]) p[i] = mx - i;
				//由于对称点的回文半径可能超过mx-i,因为mx后面的还没有配过
				//所以要取小的。
			}
 
			//向两端配匹
			while(str[i - p[i]] == str[i + p[i]]) p[i]++;
 
			if(i + p[i] > mx){
				mx = i + p[i];
				id = i;
			}

			if (p[i] > big) {
				big = p[i];
				idx = i;
			}

			//printf("i=%d  str=%c  p=%d\n",i,str[i],p[i]);
		}

		int len = p[idx] - 1;
		int r = len / 2;
		int f, t;
		string res;
		if (len % 2 == 0) {
			f = idx - 1, t = idx + 1;
			for (int i = 0; i < r; i ++) {
				res = str[f] + res + str[t];
				f -= 2, t += 2;
			}
		} else {
			res = str[idx];
			f = idx - 2, t = idx + 2;
			for (int i = 0; i < r; i ++) {
				res = str[f] + res + str[t];
				f -= 2, t += 2;
			}
		}
		return res;
	}
 
	/*
	预处理字符串
	*/
	int pre(char head='$', char middle='#', char end = '?'){
		int n=0;
		memset(str, 0, sizeof(str));
		
		str[n++]=head;
		str[n++]=middle;
 
		for(int i = 0; i < oldstr.length(); i++){
			str[n++] = oldstr[i];
			str[n++] = middle;
		}
 
		str[n]=end;
 
		return n;
	}

    string longestPalindrome(string s) {
		oldstr = s;
		int n = pre();
		string res = Manacher(n);
		return res;
    }
};