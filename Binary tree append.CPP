#include<conio.h>
#include<iostream.h>
#include<process.h>
class btree{
	 public:
	     long key;
	     btree();
	     void add();
	     void move();
	     void print();
	     btree* Lchild;
	     btree* Rchild;
	     btree* parent;
	     };

void Find(btree*);
btree* crnt=NULL;
btree* find=NULL;

long id;

void main()
    {
     clrscr();
     btree* root;
     root=new btree;
     crnt=root;
     int x;
     while(1)
      {
       cout<<"1.add node  2.move 3.find 4.exit"<<endl;
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
	       cout<<"enter the ID"<<endl;
	       cin>>id;
	       Find(root);
	       find->print();
	       break;
	case 4:
	       exit(0);
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

void Find(btree* tmp)
     {
      if(tmp->key==id)
	find=tmp;
      if(tmp->Lchild!=NULL)
	   Find(tmp->Lchild);
      if(tmp->Rchild!=NULL)
	   Find(tmp->Rchild);
       }

void btree::print()
     {
     if(this==NULL)
       cout<<"no such element found"<<endl;
       else{
      if(this->parent!=NULL)
	 cout<<"the parent is     : "<<this->parent->key<<endl;
      if(this->Lchild!=NULL)
	 cout<<"the Left Child is : "<<this->Lchild->key<<endl;
      if(this->Rchild!=NULL)
	 cout<<"the Right Child is: "<<this->Rchild->key<<endl;
       }
      }