#include<conio.h>
#include<iostream.h>
#include<process.h>
class btree{
	 public:
	     long key;
	     btree();
	     void add();
	     void move();
	     btree* Lchild;
	     btree* Rchild;
	     btree* parent;
	     };
btree* crnt=NULL;
struct stree{
	   long key;
	   stree* nxt;
	    };
stree* top=NULL;
void inorder(btree*);
void preorder(btree*);
void postorder(btree*);
 void main()
    {
     btree* root;
     root=new btree;
     crnt=root;
     int x;
     while(1)
      {
       cout<<"1.add node  2.move 3.exit 4.in-order 5.preorder 6.postorder"<<endl;
       cin>>x;
       switch(x)
	    {
	case 1:
	       root->add();
	       break;
	case 2:
	       root->move();
	       break;
	case 3:
	       exit(0);
	case 4:
	       top=NULL;
	       inorder(root);
		break;
	case 5:
	       top=NULL;
	       preorder(root);
		break;
	case 6:
	       top=NULL;
	       postorder(root);
	       break;
	default:
	       cout<<"enter valid command"<<endl;
		break;
      } }
     }
btree::btree()
      {
      cout<<"enter the value"<<endl;
      cin>>this->key;
      this->Rchild=NULL;
      this->Lchild=NULL;
      this->parent=crnt;
       }
void btree::add()
     {
      cout<<"current node key"<<crnt->key<<endl;
      btree* tmp;
      tmp=new btree();
      if(crnt->Lchild!=NULL&&crnt->Rchild!=NULL)
	 cout<<"invalid operation"<<endl;
      else if(crnt->Lchild!=NULL)
	      crnt->Rchild=tmp;
      else
	    crnt->Lchild=tmp;
       }
void btree::move()
       {
	crnt=this;
	int x=1,t=0;
	while(x)
	    {
	    cout<<"current node is "<<crnt->key<<endl;
	    cout<<"**************************"<<endl;
	    cout<<"1.to left child  2.to right child 3.to parent 4.done"<<endl;
	    cin>>t;
	    switch(t)
		{
		case 1:
		      if(crnt->Lchild!=NULL)
			  crnt=crnt->Lchild;
		      else
			 cout<<"no left child"<<endl;
			break;
		case 2:
		      if(crnt->Rchild!=NULL)
			 crnt=crnt->Rchild;
		      else
			cout<<"no right child"<<endl;
			break;
		case 3:
		      if(crnt->parent!=NULL)
			 crnt=crnt->parent;
		      else
			 cout<<"no parent present"<<endl;
			 break;
		case 4:
		      x=0;
		      break;
		}

	     }
	}
void inorder(btree* tmp)
     {
      if(tmp->Lchild!=NULL)
	   inorder(tmp->Lchild);
	 cout<<" the key"<<tmp->key<<endl;
      if(tmp->Rchild!=NULL)
	   inorder(tmp->Rchild);
       }
void preorder(btree* tmp)
      {
       cout<<"the key"<<tmp->key<<endl;
       if(tmp->Lchild!=NULL)
	  preorder(tmp->Lchild);
       if(tmp->Rchild!=NULL)
	  preorder(tmp->Rchild);
       }
void postorder(btree* tmp)
      {
       if(tmp->Lchild!=NULL)
	  postorder(tmp->Lchild);
       if(tmp->Rchild!=NULL)
	  postorder(tmp->Rchild);
	 cout<<"the key "<<tmp->key<<endl;
       }
void