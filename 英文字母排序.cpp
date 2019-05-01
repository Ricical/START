/*116.英文字母排序 (20分) 
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
编写一个程序，当输入英文字符串时，计算机将这个句子中的英文字母按字典字母顺序重新
排列，排列后的单词的长度要与原始句子中的长度相同，并且要求只对Ａ到Ｚ的字母重新排
列，其它字符保持原来的状态。
输入描述
一个字符串，包括大写英文字母，以及其他字符
输出描述
字符串的重新排列，只是大写字母按字典顺序，其他字母保持原位
输入样例
ＴＨＥ ＰＲＩＣＥ ＯＦＢＲＥＡＤ ＩＳ ￥１ ２５ ＰＥＲ ＰＯＵＮＤ
输出样例
ＡＢＣ ＤＤＥＥＥ ＥＦＨＩＩＮＯ ＯＰ ￥１ ２５ ＰＰＲ ＲＲＳＴＵ*/

#include <iostream>
#include <string>
#include <cstdio> 
using namespace std;

int a[1000];
int main(){
	string s;
	getline(cin,s);
	int length=s.length();
	s.c_str();
	for(int i=0;i<length;i++){
		++a[s[i]];
	}
//	printf("%d",'A');
	int ans=65;
	for(int i=0;i<length;i++){
		while(s[i]>=65 && s[i]<=90){
			if(a[ans]!=0){
				--a[ans];
				s[i]=ans;
				break;
			}
			else{
				++ans;
			}
		}
	}
	for(int i=0;i<length;i++){
		cout<<s[i];
	}
	return 0;
}
