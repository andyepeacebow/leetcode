class Solution {
public:
	int p[3000]; //��ʾ��iΪ���ĵĻ��İ뾶
	string oldstr;
	char str[3000];

	string Manacher(int n){
 
		int mx=0; //��¼ǰ����Ĵ��Ӱ�쵽�ĵط�����һ��������Ĵ���ɵġ�
		int id; //�Ӱ�촮��λ��;
		p[0]=0;
		
		int big = -1;
		int idx = -1;

		for(int i = 1; i < n; i++){
			p[i]=1;//������1
			if(mx>i){
				//i�ܵ�Ӱ�켴��id+p[id]-1>=i;
				p[i] = p[2 * id - i];//2*id-i��i����id�ĶԳƵ��൱����id-(i-id);
				if(mx - i < p[i]) p[i] = mx - i;
				//���ڶԳƵ�Ļ��İ뾶���ܳ���mx-i,��Ϊmx����Ļ�û�����
				//����ҪȡС�ġ�
			}
 
			//��������ƥ
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
	Ԥ�����ַ���
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