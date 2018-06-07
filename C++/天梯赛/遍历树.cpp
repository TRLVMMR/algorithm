#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn=40;
int post[maxn];
int in[maxn];

struct node
{
    int data;
    node *lchild,*rchild;
};

node * creat(int postL,int postR,int inL,int inR)
{
    if(postL > postR)
		 return NULL;
		 
    node * root = new node;
    root->data = post[postR];
    
    int cur;
    for(cur = inL;cur <= inR;cur++)
    {
        if(in[cur] == post[postR])
        {
            break;
        }
    }
    int numLeft=cur-inL;
    root->lchild = creat(postL, postL+numLeft-1,inL,cur-1);
    root->rchild = creat(postL+numLeft, postR-1,cur+1,inR);
    return root;
}

int flag_1=0;

void LayerOrder(node * root)
{
    queue<node *> ans;
    ans.push(root);
    
    while(!ans.empty())
    {
        node * cur=ans.front();
        
        ans.pop();
        
        if(flag_1!=0)
        {
            cout<<" ";
        }
        
        cout << cur->data;
        flag_1 = 1;
        
        if(cur->lchild != NULL) ans.push(cur->lchild);
        if(cur->rchild != NULL) ans.push(cur->rchild);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        cin >> post[i];
    }
    for(int i = 0;i < n; i++)
    {
        cin >> in[i];
    }
    node * root = creat(0,n-1,0,n-1);
    
    LayerOrder(root);
    
    
    
    return 0;
}
