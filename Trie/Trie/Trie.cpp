// Trie.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

template<int Size>
class trieNode
{
    public:
        trieNode() : terminableSize(0), nodeSize(0), wordSize(0) { for(int i = 0; i < Size; ++i) children[i] = NULL; }
        ~trieNode()
        {
            for(int i = 0; i < Size; ++i)
            {
                delete children[i];
                children[i] = NULL;
            }
        }
    public:
        int terminableSize;
        int nodeSize;
		int wordSize;
        trieNode* children[Size];
};

template<int Size, class Type>
class trie
{
    public:
        typedef trieNode<Size> Node;
        typedef trieNode<Size>* pNode;
        trie() : root(new Node) {}

        template<class Iterator>
        void insert(Iterator beg, Iterator end);
        void insert(const char *str);

        template<class Iterator>
        bool find(Iterator beg, Iterator end);
        bool find(const char *str);
		template<class Iterator>
        bool insert_find(Iterator beg, Iterator end);
        bool insert_find(const char *str);

        template<class Iterator>
        bool downNodeAlone(Iterator beg);

        template<class Iterator>
        bool erase(Iterator beg, Iterator end);
        bool erase(const char *str);
		bool erase_find(Iterator beg, Iterator end);
        bool erase_find(const char *str);

        int sizeAll(pNode);
        int sizeNoneRedundant(pNode);
    public:
        pNode root;
    private:
        Type index;
};

template<int Size, class Type>
template<class Iterator>
void trie<Size, Type>::insert(Iterator beg, Iterator end)
{
    pNode cur = root;
    pNode pre;
    for(; beg != end; ++beg)
    {
        if(!cur->children[index[*beg]])
        {
            cur->children[index[*beg]] = new(Node);
            ++cur->nodeSize;
        }
        pre = cur;
        cur = cur->children[index[*beg]];
    }
    ++pre->terminableSize;
}
template<int Size, class Type>
void trie<Size, Type>::insert(const char *str)
{
    return insert(str, str + strlen(str));
}

template<int Size, class Type>
template<class Iterator>
bool trie<Size, Type>::find(Iterator beg, Iterator end)
{
    pNode cur = root;
    pNode pre;
    for(; beg != end; ++beg)
    {
        if(!cur->children[index[*beg]])
        {
            return false;
            break;
        }
        pre = cur;
        cur = cur->children[index[*beg]];
    }
    if(pre->terminableSize > 0)
        return true;
    return false;
}

template<int Size, class Type>
bool trie<Size, Type>::find(const char *str)
{
    return find(str, str + strlen(str));
}
template<int Size, class Type>
template<class Iterator>
bool trie<Size, Type>::insert_find(Iterator beg, Iterator end)
{
    pNode cur = root;
    pNode pre;
    for(; beg != end; ++beg)
    {
        if(!cur->children[index[*beg]])
        {
            return false;
            break;
        }
        pre = cur;
		cur->wordSize ++;
        cur = cur->children[index[*beg]];
    }
    if(pre->terminableSize > 0)
        return true;
    return false;
}

template<int Size, class Type>
bool trie<Size, Type>::insert_find(const char *str)
{
    return insert_find(str, str + strlen(str));
}

template<int Size, class Type>
template<class Iterator>
bool trie<Size, Type>::downNodeAlone(Iterator beg)
{
    pNode cur = root;
    int terminableSum = 0;
    while(cur->nodeSize != 0)
    {
        terminableSum += cur->terminableSize;
        if(cur->nodeSize > 1)
            return false;
        else          //cur->nodeSize = 1
        {
            for(int i = 0; i < Size; ++i)
            {
                if(cur->children[i])
                    cur = cur->children[i];
            }
        }
    }
    if(terminableSum == 1)
        return true;
    return false;
}
template<int Size, class Type>
template<class Iterator>
bool trie<Size, Type>::erase(Iterator beg, Iterator end)
{
    if(find(beg, end))
    {
        pNode cur = root;
        pNode pre;
        for(; beg != end; ++beg)
        {
            if(downNodeAlone(cur))
            {
                delete cur;
                return true;
            }
            pre = cur;
            cur = cur->children[index[*beg]];
        }
        if(pre->terminableSize > 0)
            --pre->terminableSize;
        return true;
    }
    return false;
}

template<int Size, class Type>
bool trie<Size, Type>::erase(const char *str)
{
    if(find(str))
    {
        erase(str, str + strlen(str));
        return true;
    }
    return false;
}

template<int Size, class Type>
int trie<Size, Type>::sizeAll(pNode ptr)
{
    if(ptr == NULL)
        return 0;
    int rev = ptr->terminableSize;
    for(int i = 0; i < Size; ++i)
        rev += sizeAll(ptr->children[i]);
    return rev;
}

template<int Size, class Type>
int trie<Size, Type>::sizeNoneRedundant(pNode ptr)
{
    if(ptr == NULL)
        return 0;
    int rev = 0;
    if(ptr->terminableSize > 0)
        rev = 1;
    if(ptr->nodeSize != 0)
    {
        for(int i = 0; i < Size; ++i)
            rev += sizeNoneRedundant(ptr->children[i]);
    }
    return rev;
}

template<int Size>
class Index
{
    public:
        int operator[](char vchar) 
        { return vchar % Size; }
};

int main()
{
    trie<26, Index<26> > t;
    t.insert("abc");
	t.insert("abc");
	t.insert("abd");
    t.insert("hello");
    t.insert("h");
    t.insert("h");
    t.insert("he");
    t.insert("hel");
	t.insert("abc");
	t.insert("abd");
    cout << "SizeALL:" << t.sizeAll(t.root) << endl;
    cout << "SizeALL:" << t.sizeNoneRedundant(t.root) << endl;
    t.erase("abc");
    cout << "SizeALL:" << t.sizeAll(t.root) << endl;
    cout << "SizeALL:" << t.sizeNoneRedundant(t.root) << endl;
	t.erase("abc");
    cout << "SizeALL:" << t.sizeAll(t.root) << endl;
    cout << "SizeALL:" << t.sizeNoneRedundant(t.root) << endl;
}*/

#include<iostream>  
#include<string>  
using namespace std;  
  
struct TrieNode{  
    bool isword;// �Ƿ���һ�����ʵ��ս��  
    unsigned int count;  
    TrieNode *next[26];//����ָ��  
    TrieNode():isword(false),count(0){  
        for(int i=0;i<26;i++)  
        next[i]=NULL;  
    }  
};  
  
class TrieTree{  
public:  
    TrieTree()  
    {  
        root=new TrieNode();  
    }  
    ~TrieTree()  
    {  
        destroy(root);  
    }  
    void insert(const char *s);//����  
    unsigned int  find(const char *s);//����  
    void destroy(TrieNode *r);  
private:  
    TrieNode *root;  
      
};  
//sָ���ַ���  
void TrieTree::insert(const char *s)  
{  
    TrieNode *r=root;  
    while(*s)  
    {  
        if(!r->next[*s-'a'])//����ָ��Ϊ��  
        {  
            TrieNode *t=new TrieNode();//�����������  
            r->next[*s-'a']=t;  
        }  
        r->count++;  
        r=r->next[*s-'a'];  
        s++;  
    }  
    r->isword=true;//��ӦΪ��ɫ  
    r->count++;  
}  
    //�Ƿ���ڵ���s  
unsigned int  TrieTree::find(const char *s)  
{  
    TrieNode *r=root;  
    while(*s)  
    {  
        if(!r->next[*s-'a'])  
        return 0;  
        r=r->next[*s-'a'];  
        s++;  
    }  
    return r->count;  
}  
void TrieTree::destroy(TrieNode *r)  
{  
    for(int i=0;i<26;i++)  
    {  
        if(r->next[i]!=NULL)  
            destroy(r->next[i]);  
    }  
    delete r;  
}  
  
int main()  
{  
    string s;//����  
    unsigned int n;//���ٸ�����  
    unsigned int m;//���ٸ�ƥ�䵥��  
    TrieTree T;  
    cin>>n;  
    for(unsigned int i=0;i<n;i++)  
    {  
        cin>>s;//  
        T.insert(s.c_str());  
    }  
    cin>>m;  
    for(unsigned int i=0;i<m;i++)  
    {  
        cin>>s;  
        cout<<T.find(s.c_str())<<endl;  
    }  
    return 0;  
}  