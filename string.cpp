//String 类
//用到了strlen、strcpy函数
#include<iostream>
#include<string>
using namespace std;
 
class String
{
public:
    String(const char *str=NULL);//构造普通函数
    String(const String &other);//拷贝构造函数
    ~String(void);
    String &operator=(const String &other);//重载=
    friend bool operator==(const String &s1,const String &s2);//重载==
    friend bool operator>(const String &s1,const String &s2);//重载>
    friend bool operator<(const String &s1,const String &s2);//重载<
    friend ostream &operator<<(ostream &,const String &other);//重载<<
    friend istream &operator>>(istream &,String &other);//重载>>
private:
    char *m_data;
};
 
String::String(const char *str)
{
    if(str==NULL)
    {
        m_data=new char[1];
        m_data='\0';
    }
    else
    {
        int length=strlen(str);
        m_data=new char[length+1];
        strcpy(m_data,str);
    }
}
 
String::~String(void)
{
    delete []m_data;
}
 
String::String(const String &other)
{
    int length=strlen(other.m_data);
    m_data=new char[length+1];
    strcpy(m_data,other.m_data);
}
 
String & String::operator=(const String &other)
{
    if(&other==this)
        return *this;
    delete []m_data;
    int length=strlen(other.m_data);
    m_data=new char[length+1];
    strcpy(m_data,other.m_data);
    return *this;
}
 
ostream& operator<<(ostream&output,const String &other)
{
    output<<other.m_data; 
    return output; 
}
 
 istream& operator>>(istream&input,String &other)
{
    char p[256];
    input>>p;
    int length=strlen(p);
    other.m_data=new char [length+1];
    strcpy(other.m_data,p);
    return input;
}
 
bool operator==(const String&s1,const String&s2)
{
    int len_s1=strlen(s1.m_data);
    int len_s2=strlen(s2.m_data);
    if(len_s1!=len_s2)
        return false;
    int i=0;
    while(s1.m_data[i]==s2.m_data[i])
    {
        i++;
        if(i==len_s1)
            return true;
    }
    return false;
}
 
bool operator>(const String&s1,const String&s2)
{
    int len=strlen(s1.m_data)>strlen(s2.m_data)?strlen(s2.m_data):strlen(s1.m_data);
    for(int i=0;i<len;i++) 
	{ 
		if(s1.m_data[i]>s2.m_data[i])
        {
            return true;
        }
        else if(s1.m_data[i]==s2.m_data[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    if(strlen(s1.m_data)>strlen(s2.m_data))
        return true;
    else
        return false;
}
 
bool operator<(const String&s1,const String&s2)
{
    int len=strlen(s1.m_data)>strlen(s2.m_data)?strlen(s2.m_data):strlen(s1.m_data);
    for(int i=0;i<len;i++) 
	{ 
		if(s1.m_data[i]>s2.m_data[i])
        {
            return false;
        }
        else if(s1.m_data[i]==s2.m_data[i])
        {
            continue;
        }
        else
        {
            return true;
        }
    }
    if(strlen(s1.m_data)<strlen(s2.m_data)) 
    	return true; 
	else false; 
} 

int main() 
{ 
    //测试string的输入与输出 
	string s; 
	cin>>s;
    cout<<"s:"<<s; cout<<endl;
	//测试构造函数与‘="’" 
	string a="1234" ; 
	b(a); 
	//拷贝构造函数初始化 c; 
	c="a;" 
	//赋值语句 “="”" 
	cout<<"a:"<' '<' 
    if(s>b)
        cout<<"s>b"<<endl; 
	else if(s<b) 
		cout<<"s<b"<<endl; 
	cout<<"s="=b"<<endl;" 
	system("pause"); 
	return 0; 
}