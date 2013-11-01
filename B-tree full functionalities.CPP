#include<conio.h>
#include<string.h>
#include<iostream.h>
#include<process.h>
class tree{
     public:
	   long ID;
	   int sib;
	   char NAME[10];
	   tree* parent;
	   tree* Lchild;
	   tree* sibling;
	   tree* Rchild;
	   tree();
	   void AtoB();
	   void add();
	   void move();
	   };


struct tmptree{
	   long ID;
	   char NAME[10];
	   int C;
	   int S;
	   tmptree* nxt;
	   void show();
	   void convert();
	   tmptree* push(tree*,int);
	    };

class btree{
	 public:
	   long ID;
	   char NAME[10];
	   int C;
	   int S;
	   btree* Lchild;
	   btree* Rsiblng;
	   btree* parent;
	   btree(tmptree*);
	   void move();
	   };

void decrypt();

btree* Bnode = NULL;
tmptree* navi=NULL;
tree* crnt=NULL;
btree* ctnode=NULL;

void main()
     {
     clrscr();
     tree* root;
     root = new tree();
     crnt =root;
     int x;
     while(1)
	  {
	  cout<<"*************************************"<<endl;
	    if(x!=3)
	      {
	       cout<<"current ID   is   : "<<crnt->ID<<endl;
	       cout<<"current Name is   : "<<crnt->NAME<<endl;
	       }
	    else
	      {
	       cout<<"new tree has strated"<<endl;
	       }
	  cout<<"1. add child  2.move 3.to B-tree 4.see B-tree 5.decrypt 6.exit"<<endl;
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
			root->AtoB();
			ctnode=NULL;
			navi->convert();
			break;
		 case 4:
			Bnode->move();
			break;
		 case 5:
			exit(0);
		default:
			cout<<"enter valid command"<<endl;
			break;
		  }
	     }
 }


tree::tree()
	  {
	  cout<<"enter the ID"<<endl;
	  cin>>this->ID;
	  cout<<"enter the name"<<endl;
	  cin>>this->NAME;
	  this->sib=0;
	  this->parent=crnt;
	  this->sibling=NULL;
	  this->Lchild=NULL;
	  this->Rchild=NULL;
	  }

void tree:: add()
	  {
	  tree* tmp;
	  tmp = new tree();
	  if(crnt->Lchild==NULL)
	    (crnt->Lchild)=tmp;

	  (crnt->Rchild)->sib=1;
	  (crnt->Rchild)->sibling=tmp;
	   crnt->Rchild=tmp;
	   }

void tree:: move()
	  {
	   crnt=this;
	   int x,n=1;
	   while(n)
		{
		cout<<"current ID   is   : "<<crnt->ID<<endl;
		cout<<"current Name is   : "<<crnt->NAME<<endl;

		cout<<"*******************************************"<<endl;
		cout<<"1. next sibling"<<endl;
		cout<<"2. to child    "<<endl;
		cout<<"3. to parent   "<<endl;
		cout<<"4. done        "<<endl;
		cin>>x;
		switch(x)
		      {
		      case 1:
			    if(crnt->sibling==NULL)
			    cout<<"no sibling"<<endl;
			    else
			    crnt=crnt->sibling;
			    break;
		      case 2:
			    if(crnt->Lchild==NULL)
			    cout<<"no child here"<<endl;
			    else
			    crnt=crnt->Lchild;
			    break;
		      case 3:
			    if(crnt->parent==NULL)
			    cout<<"u have reached the root"<<endl;
			    else
			    crnt=crnt->parent;
			    break;
		      case 4:
			    n=0;
			    break;
		       }
		}
	    return;
	  }

tmptree* tmptree::push(tree* node,int c)
		 {
		  tmptree* temp;
		  temp = new tmptree();
		  temp->ID=node->ID;
		  strcpy(temp->NAME,node->NAME);
		  temp->S=node->sib;
		  temp->C=c;
		  temp->nxt=this;
		  return temp;
		  }

void tree::AtoB()
	 {
	 crnt=this;
	 int c=0;
	 while(crnt!=NULL)
	       {
	      if(crnt->Rchild!=NULL)
		{
		crnt=crnt->Rchild;
		cout<<"shift"<<endl;
		 }
	      else
		{
	  tree* tmp;
	  navi=navi->push(crnt,c);
	  cout<<"copied"<<endl;
	  c=0;
	  if(crnt==this)
	     {
	      delete crnt;
	      break;
	       }
	  else
	     {
	     tmp=(crnt->parent)->Lchild;
	     if(tmp==crnt)
	       {
	       crnt=crnt->parent;
	       crnt->Lchild=NULL;
	       delete crnt->Rchild;
	       crnt->Rchild=NULL;
	       c=1;
		}
	     else
		{
	       while(tmp->sibling!=crnt)
		    {
		     tmp=tmp->sibling;
		     }
		 tmp->sibling=NULL;
		 (crnt->parent)->Rchild=tmp;
		 tmp=crnt;
		 crnt=crnt->parent;
		 delete tmp;
		}
	    }
	  }
	}
       tmptree* temp = navi;
	if(temp==NULL)
	cout<<"tree not avilable"<<endl;
	else
	   {
	   while(temp!=NULL)
	    {
	     cout<<"ID   :  "<<temp->ID<<"  name  : "<<temp->NAME<<" S : "<<temp->S<<" C : "<<temp->C<<endl;
	     temp=temp->nxt;
	     }
	    }
	 }
btree::btree(tmptree* tmp)
{
this->ID=tmp->ID;
strcpy(this->NAME,tmp->NAME);
this->C=tmp->C;
this->S=tmp->S;
this->Lchild=NULL;
this->Rsiblng=NULL;
this->parent=ctnode;
}

void tmptree::convert()
	    {
	    tmptree* stack=this;
	    while(stack!=NULL)
	     {
	      btree* tmp;
	      tmp=new btree(stack);
	      tmp->parent=ctnode;

	      if(Bnode==NULL)
		 {
		   ctnode=tmp;
		   Bnode=ctnode;
		   stack=stack->nxt;
		   cout<<"root done"<<endl;
		   }

	  else{
		if(ctnode->C!=0)
		{
		 ctnode->C=0;
		 ctnode->Lchild=tmp;
		 ctnode=ctnode->Lchild;
		 stack=stack->nxt;
		 cout<<"left child done"<<endl;
		 }
	     else if(ctnode->S!=0)
		{
		 ctnode->S=0;
		 ctnode->Rsiblng=tmp;
		 ctnode=ctnode->Rsiblng;
		 stack=stack->nxt;
		 cout<<"right sibling done"<<endl;
		 }
	   else{
	       ctnode=ctnode->parent;
	      // cout<<"going to parent"<<endl;
		}
	       }
	      }
	    cout<<"donreeeeeeeeeeeeeeeee"<<endl;
	     }
void btree::move()
     {
       ctnode=Bnode;
	int x=1,t=0;
	while(x)
	    {
	    cout<<"current node is "<<ctnode->ID<<endl;
	    cout<<"current name is "<<ctnode->NAME<<endl;
	    cout<<"**************************"<<endl;
	    cout<<"1.to child  2.to sibling 3.to parent 4.done"<<endl;
	    cin>>t;
	    switch(t)
		{
		case 1:
		      if(ctnode->Lchild!=NULL)
			  ctnode=ctnode->Lchild;
		      else
			 cout<<"no left child"<<endl;
			break;
		case 2:
		      if(ctnode->Rsiblng!=NULL)
			 ctnode=ctnode->Rsiblng;
		      else
			cout<<"no right sibling"<<endl;
			break;
		case 3:
		      if(ctnode->parent!=NULL)
			 ctnode=ctnode->parent;
		      else
			 cout<<"no parent present"<<endl;
			 break;
		case 4:
		      x=0;
		      break;
		}

	     }
      }