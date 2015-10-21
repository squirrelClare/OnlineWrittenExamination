#include<iostream>
#include<string>
using namespace std;

//去掉非字母
string removeNotChar(string str){
	int k=0;
	while(k<str.size()){
		if(str.at(k)>'z' ||  str.at(k)<'A' || (str.at(k)>'Z'&& str.at(k)<'a')){
			str.erase(k,1);
			k--;
		}
		k++;
	}
	return str;
}

//获取结果
string getResult(string str){
	int n=str.length();
	if(n<=0)
		return "";

	int j=0,i=0,count=0;
	char* ch=new char[4];

	while(i<n)
	{
		j=i;
		while(str.at(j)==str.at(i)){
			count++;
			j++;
			if(j>=n)
				break;
		}

		if(count==1){

			str.insert(i+1,1,'1');
			i=i+2;
		}else{

			sprintf(ch,"%d",count);
			str.replace(i+1,count-1,ch);
			if(count<10)
				i=i+2;
			else if(count>=10 && count<100)
				i=i+3;
			else if(count>=100 && count<1000)
				i=i+4;
			else
				i=i+5;
		}

		count=0;
		n=str.length();
	}
	return str;
}
string reverseString(string &str) {
	int n=str.length();
	if(n<0 || n>1024)
		return 0;
	str=removeNotChar(str);
	return getResult(str);

}


int main()
{
	string s="aafdsfa&&&&";
//    int a,b;
//    cin>>a>>b;
//    cout<<a<<endl;

//    cout<<b<<endl;
//    //cout<<s<<endl;
	string s2=reverseString(s);
	cout<<s2;
	return 0;
}
