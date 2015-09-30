// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>    
#include<cstring>   
#include<string>  
#include<math.h>
#include <algorithm>
using namespace std;    
/*int Next[10001];  
//求KMP的Next数组    
void GetNext(const string& p)    
{    
    int len=p.size();    
    int i=0;    
    int j=-1;    
    Next[i]=j;    
    while(i<len)    
    {    
        if(j==-1||p.at(i)==p.at(j))    
        {    
            i++;    
            j++;    
            if(i==len||p.at(i)!=p.at(j))//不允许出现P[i]==P[next[i]]    
                Next[i]=j;    
            else    
                Next[i]=Next[j];    
        }    
        else    
        {    
            j=Next[j];    
        }    
    }    
        
}   
  
  
//S为母串，p为匹配子串，如果匹配返回匹配位置，否则返回-1    
int KMPSearch(const string& s,const string& p)    
{    
    unsigned int Slen=s.size();    
    unsigned int Plen=p.size();  
    //int *Next=new int[Plen];//Next数组存储位置    
    
    GetNext(p);//求得Next数组    
    
    unsigned int i=0;//在S串中的下标    
    unsigned int j=0;//在P串中的下标    
    unsigned int count=0;//匹配串出现的次数  
	while(i<Slen && j < Plen)    
    {    
        if(j==-1||s.at(i)==p.at(j))    
        {    
            i++;    
            j++;    
        }    
        else  if(j<Plen)  
            j=Next[j];    
        if(j==Plen)  
        {  
            count++;  
            j=Next[Plen];  
        }  
    }     
	return count;  
}  
  
int main()    
{    
    string str1;    
    string str2;    
    int n;  
    cin>>n;  
    for(int i=0;i<n;i++)  
    {  
        cin>>str2;  
        cin>>str1;   
           
        int pos=KMPSearch(str1,str2);    
        cout<<pos<<endl;   
      
    }  
     
    return 0;    
}   */

//KMP
int * buildNext(string & p)
{
	int size = p.size(), j = 0;
	int *N = new int[size];
	int t = N[0] = -1;
	while(j < size - 1)
	{
		if(0 > t || p[j] == p[t])
		{
			j ++; t ++; N[j] = p[j] != p[t] ? t : N[t];
		}
		else
			t = N[t];
	}
	return N;
}
int KMPsearch(string &s, string &p)
{
	int * Next = buildNext(p);
	int n = s.size(), i = 0;
	int m = p.size(), j = 0;
	while(j < m && j < n)
	{
		if(0 > j || s[i] == p[j])
		{
			i ++; j ++;
		}
		else j = Next[j];
	}
	delete[] Next;
	return i - j;
}
//BC
int *  buildBC(string &p)
{
	int *bc  =new int[256];
	for(int i = 0; i < 256; i ++)bc[i] = -1;
	for(int i = 0, m = p.size(); i < m; i ++)
	{
		bc[p[i]] = i;
	}
	return bc;
}
int BMMatch(char* pSrc, int nSrcSize, char* pSubSrc, int nSubSrcSize)
 {
 
     //1.坏字符数组
     int bcSkip[256];
     for( int i = 0; i < 256; i++)  
     {
         bcSkip[i] = nSubSrcSize;
     }
     for (int i = 0; i < nSubSrcSize - 1; i++)
     {
         bcSkip[pSubSrc[i]] = nSubSrcSize - i - 1;
     }
 
     //2.好后缀数组
     int* suffix = new int [nSubSrcSize];
     suffix[nSubSrcSize - 1] = nSubSrcSize;
     for (int i = nSubSrcSize - 2; i >= 0; i--)
     {
         
         int k = i;
         while( k >= 0 && pSubSrc[k] == pSubSrc[nSubSrcSize-1-i+k] )
         {
             k--;
         }
         suffix[i] = i - k; 
     }
     
     int* gsSkip = new int [nSubSrcSize];
     for (int i = 0; i < nSubSrcSize; i++) 
     {
         gsSkip[i] = nSubSrcSize;
     }  
     for (int i = nSubSrcSize - 1; i >= 0; i--) 
     {
         if (suffix[i] == i + 1)          
         {
             for (int j = 0; j < nSubSrcSize - 1 - i; ++j)             
             {
                 if (gsSkip[j] == nSubSrcSize)                
                     gsSkip[j] = nSubSrcSize - 1 - i;  
             }
         }
     }
     for (int i = 0; i <= nSubSrcSize - 2; ++i)       
     {
         gsSkip[nSubSrcSize - 1 - suffix[i]] = nSubSrcSize - 1 - i; 
     }
 
     int nPos = 0;
     while (nPos <= nSrcSize - nSubSrcSize) 
     {    
         int j = nSubSrcSize - 1;
         while(j >= 0 && pSubSrc[j] == pSrc[j + nPos])
         {
             j--;
         }
         if (j < 0)       
             break;  
         else      
         {
			 nPos += max(gsSkip[j], bcSkip[pSrc[j + nPos]]-(nSubSrcSize - 1 -  j));
         }
     }
     delete[] gsSkip;
     return (nPos > nSrcSize - nSubSrcSize)? -1 : nPos;        
 }


 int BMMatchEx(char* pSrc, int nSrcSize, char* pSubSrc, int nSubSrcSize)
 {
 
     //1.坏字符数组
     int bcSkip[256];
     for( int i = 0; i < 256; i++)  
     {
         bcSkip[i] = nSubSrcSize;
     }
     for (int i = 0; i < nSubSrcSize - 1; i++)
     {
         bcSkip[pSubSrc[i]] = nSubSrcSize - i - 1;
     }
 
     //2.好后缀数组
     int* suffix = new int [nSubSrcSize];
     suffix[nSubSrcSize - 1] = nSubSrcSize;
     int g = nSubSrcSize - 1;
     int f = 0;
     for (int i = nSubSrcSize - 2; i >= 0; i--)
     {
         if(i > g && suffix[i + nSubSrcSize - 1 - f] < i - g)
         {
             suffix[i] = suffix[i + nSubSrcSize - 1 - f];
         }
         else
         {
             if (i < g)
             {
                 g = i;
             }
             f = i; 
             while( g >= 0 && pSubSrc[g] == pSubSrc[nSubSrcSize-1-f+g] )
             {
                 g--;
             }
             suffix[i] = f - g; 
         }        
     }
 
     int* gsSkip = new int [nSubSrcSize];
     for (int i = 0; i < nSubSrcSize; i++) 
     {
         gsSkip[i] = nSubSrcSize;
     }  
     for (int i = nSubSrcSize - 1; i >= 0; i--) 
     {
         if (suffix[i] == i + 1)          
         {
             for (int j = 0; j < nSubSrcSize - 1 - i; ++j)             
             {
                 if (gsSkip[j] == nSubSrcSize)                
                     gsSkip[j] = nSubSrcSize - 1 - i;  
             }
         }
     }
     for (int i = 0; i <= nSubSrcSize - 2; ++i)       
     {
         gsSkip[nSubSrcSize - 1 - suffix[i]] = nSubSrcSize - 1 - i; 
     }
 
     int nPos = 0;
     while (nPos <= nSrcSize - nSubSrcSize) 
     {    
         int j = nSubSrcSize - 1;
         while(j >= 0 && pSubSrc[j] == pSrc[j + nPos])
         {
             j--;
         }
         if (j < 0)       
             break;  
         else      
         {
             nPos += max(gsSkip[j], (bcSkip[pSrc[j + nPos]]-(nSubSrcSize - 1 -  j)));
         }
     }
     delete[] gsSkip;
     return (nPos > nSrcSize - nSubSrcSize)? -1 : nPos;        
 }