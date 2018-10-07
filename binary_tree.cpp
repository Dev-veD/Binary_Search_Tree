//Successful Binary_Tree Implementation.
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<fstream>
#define elif else if
clock_t z;
using namespace std;
struct node{
int d;
node *left=NULL;
node *right=NULL;
}
;
node *td;
vector <int> vec;
vector <int> :: iterator i;
int inorder(node* x){
stack <node*> s;
node* crr=x;
while(1){
    if(crr!=NULL){
            s.push(crr);
            crr=crr->left;
    }
    else if(s.empty()==false){
        cout<<s.top()->d;
        crr=s.top()->right;
        s.pop();
    }
    else
        break;
}
return 0;
}
int balance(int *beg,int *ovr,node **x){//---------------------------Tree Balancing Function
    int s=(ovr-beg)/2;
    *x=new node ;
    (*x)->d=*(beg+s);

        if(beg<=beg+s-1)
        {//cout<<"\nleft"<<(*x)->d;
        balance(beg,beg+s-1,&((*x)->left));}
        if(beg+s+1<=ovr)
        {//cout<<"\nRight"<<(*x)->d;
        balance(beg+s+1,ovr,&((*x)->right));
        }
    //cout<<"\nback";
    return 0;
}

int bfs(node* x,int r){//------------------------------BFS
queue <node*> p;
p.push(x);
bool found=false;
while(p.empty()==false){
    if(p.front()->d==r)
    {found=true;
    break;}
    if(p.front()->left!=NULL)
        p.push(p.front()->left);
    if(p.front()->right!=NULL)
        p.push(p.front()->right);
    p.pop();
}
if(found==true)
cout<<"Found at : "<<p.front()<<endl;
else
cout<<"\nNot Found\n";
return 0;
}

int in(int a,node **x){//---------------------------- insertion function
    if(*x==NULL)
    {
        *x=new node;
        (*x)->d=a;
    }
    else if(a>(*x)->d)
        {
            in(a,&((*x)->right));
        }
    else if(a<=(*x)->d)
        {
            in(a,&((*x)->left));
        }
    return 0;
}
int del(node *x,node* pr,int c){

    node *l=x->left;
    node *r=x->right;
if(r!=NULL)
{
    x->d=r->d;
    del(r,x,1);
}
else if(l!=NULL)
{
    x->d=l->d;
    del(l,x,-1);
}
else
{
    if(c==0)
        x=NULL;
    else if(c==1)
    pr->right=NULL;
    else
        pr->left=NULL;
//
   delete x;
}
return 0;
}
int access(int i,node *x){//-----------------------Traversal function

    if(i==1)
    cout<<(x)->d<<endl;

    if((x)->left!=NULL){
       // cout<<"\nLeft ";
        access(i,((x)->left));}

    if(i==3)
    cout<<(x)->d<<endl;
    if(i==4)
        {
            vec.push_back(x->d);

        }

    if(((x)->right)!=NULL){//cout<<"\nRight ";
        access(i,((x)->right));}
    if(i==4)
        delete x;
    if(i==2)
    cout<<(x)->d<<endl;
    //cout<<"back\n";
    if(i==0)
        return x->d;
    return 0;
}

int lookfor(node *x,int a,int v){//---------------------Searching Function

 if(x!=NULL)
 {
     if(a==x->d)
    {
        cout<<endl<<a<<" Was Found At Address : "<<x<<endl;
       // if(v==1)
            td=x;
    }
    else if(a>x->d)
        lookfor(x->right,a,v);
    else if(a<x->d)
        lookfor(x->left,a,v);
}
else
    cout<<"\nElement Not Present.\n";

return 0;

}

int main(){

    long long n;
int y,dta,o;
node *root=NULL;
    while(y!=0)
    {
        cout<<"For insertion enter (1) \nFor accessing Your Tree enter (2)\nTo Search enter (3)\n";
        cout<<"For Balancing the input Tree enter (4)\nFor in order traversal without recursion enter (5)\n";
        cout<<"To save tree to disk enter (9)";
        cout<<"WARNING : Delete Function is not working properly so its option is removed for now .\n";
        cout<<"\nTo EXIT enter (0)\n";
    cin>>y;
    srand(clock());
        switch (y)
        {
        case 0:
            access(4,root);
            break;
        case 1:
            cout<<"How Many Nodes Do You Want :\n";
            cin>>n;
         z=clock();
            while(n--)
            {
                dta=rand()%100;
                in(dta,&root);
            }
           z=clock()-z;
           cout<<"\nTime took : "<<z;
            break;
        case 2:
            if(root!=NULL)
            {
                cout<<"\nFor Pre-Order traversal enter (1)\nFor Post-Order traversal enter (2)\nFor In-Order traversal enter (3)\n";
                cin>>o;
                access(o,root);
            }
            else
                {
                    cout<<"\nYou must first create a tree\n";
            system("pause");
                }
                break;
        case 3:

            if(root!=NULL)
                {
                    cout<<"\nEnter The Element To Search : ";
                    int e;
                    cin>>e;
                    int m;
                    cout<<"Select Mode for searching\nEnter (1) for DFS\nEnter (2) for BFS\n";
                    cin>>m;
                    if(m==1){
                            int v=0;
                        lookfor(root,e,v);}
                    else if(m==2)
                        bfs(root,e);
                }
            else
            {cout<<"\nYou must first create a tree\n";
            system("pause");}
            break;
        case 4:
            if(root!=NULL){
            access(4,root);
            for(int h=0;h<10;h++)
                cout<<vec[h]<<" ";
                root=new node;
            balance(&vec[0],&vec[vec.size()-1],&root);
            vec.erase(vec.begin(),vec.end());}
            else
            {cout<<"\nYou must first create a tree\n";
            system("pause");
            }
            break;
        case 5:
            if(root==NULL)
                {
                cout<<"\nYou must first create a tree\n";
            system("pause");
            }
            else
            inorder(root);
            break;
        case 6:
            td=NULL;
            cout<<"\nEnter element to delete\n";
            int p;
            cin>>p;
            lookfor(root,p,1);
            if(td!=NULL)
                del(td,NULL,0);
            break;

        default:
            system("cls");
            cout<<"\nNot a Valid entry \n";
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}
//Now will be saving data of tree into disk.

//______________________Divyanshu_______________________

//Tried adding delete function but is not working right now.
//deleted previously created tree for balancing
//added new function for in-order traversal without recursion
//BFS ADDed Converted from BF Traversal.
//BF Traversal Removed .
//BF Traversal (Not exactly traversal but you know it Right.... ;)...)added
//Balancing tree achieved successful.
//Accessing tree in  /inorder , pre-order, post-order/ done.
//Searching operation done ie DFS.
//Inserting function included Successfully.
