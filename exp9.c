/* Experiment 9
 * Subject : Data Structure Lab ( CSL303 )
 * Aim : Implement Binary Search Tree
 * Description : Binary Search Tree is a node-based binary tree data structure which has the
 * following properties: The left subtree of a node contains only nodes with keys lesser than
 * the node's key. The right subtree of a node contains only nodes with keys greater than the node's key.
 * Different Functions performs different tasks in this program showing Modular Approach.*/

 #include<stdio.h>
 #include<stdlib.h>

 struct bst
 {
	int data;
	struct bst *left,*right;
 };

 struct bst *insert(struct bst *root, int d)
 {
	 struct bst *p;
	 if(root==NULL)
	 {
	 p=(struct bst *)malloc(sizeof(struct bst));
	 p->data=d;
	 p->left=p->right=NULL;
	 root =p;
	 }
	 else
	 {
	 if(d<root->data)
	 root->left=insert(root->left,d);
	 }
	 return root;
 }

 struct bst *insertIter(struct bst *root,int d)
 {
	 struct bst *p, *cur, *prev;
	 p=(struct bst *)malloc(sizeof(struct bst));
	 p->data=d;
	 p->left=p->right=NULL;
	 if(root==NULL)
	 root =p;
	 else
	 {
	 cur=prev=root;
	 while(cur!=NULL)
	 {
	 prev=cur;
	 if(d<cur->data)
	 cur=cur->left;
	 else
	 cur=cur->right;
	 }
	 if(d<prev->data)
	 prev->left=p;
	 else
	 prev->right=p;
	 }
	 return root;
 }
 void inorder(struct bst *r)
 {
	 if(r!=NULL)
	 {
	 inorder(r->left);
	 printf("\n%d",r->data);
	 inorder(r->right);
	 }
 }

 void preorder(struct bst *r)
 {
	 if(r!=NULL)
	 {
	 printf("\n%d",r->data);
	 preorder(r->left);
	 preorder(r->right);
	 }
 }

 void postorder(struct bst *r)
 {
	 if(r!=NULL)
	 {
	 postorder(r->left);
	 postorder(r->right);
	 printf("\n%d",r->data);
	 }
 }

 struct bst *search(struct bst *root, int key)
 {
	 if(root!=NULL)
	 {
	 if(key==root->data)
	 return root;
	 else
	 {
	 if(key<root->data)
	 root->left=search(root->left,key);
	 else
	 root->right=search(root->right,key);
	 }
	 }
	 else
	 return NULL;
 }

 int main()
 {
	 int ch, d;
	 struct bst *p, *root=NULL;
	 while(1)
	 {
	 printf("\n\t\t\tMENU\n\t 1. Insert\n\t 2. Inorder\n\t 3. Preorder\n\t 4. Postorder\n\t 5. Search\n\t 6. Exit");
	 printf("\n\tEnter your choice : ");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		 case 1:
		 printf("\n\tEnter the data : ");
		 scanf("%d",&d);
		 root=insert(root,d);
		 break;
		 case 2:
		 printf("\n\tInorder Traversal");
		 inorder(root);
		 break;
		 case 3:
		 printf("\n\tPreorder Traversal");
		 preorder(root);
		 break;
		 case 4:
		 printf("\n\tPostorder Traversal");
		 postorder(root);
		 break;
		 case 5:
		 printf("\n\tEnter data : ");
		 scanf("%d",&d);
		 p=search (root,d);
		 if(p==NULL)
		 printf("\n\tGiven key does not exist");
		 else
		 printf("\n\tGiven key exist");
		 break;
		 case 6:
		 exit(0);
		 break;
		 }
	 }
	 return 0;
 }
