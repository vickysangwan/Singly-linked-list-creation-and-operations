#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* create()
{
    struct node* root;
    root=NULL;
    int size;
    cout<<"Enter size of linked list"<<endl;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int data;
        cout<<"Enter data in linked  list"<<endl;
        cin>>data;
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            struct node* ptr;
            ptr=root;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    return root;
}
void traverse(struct node* root)
{
    if(root==NULL)
    {
        cout<<"Nothing to show"<<endl;
    }
    else
    {
        while(root!=NULL)
        {
            cout<<"Linked list data is "<<root->data<<endl;
            root=root->next;
        }
    }
}
struct node* deletefront(struct node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        struct node* ptr,*temp;
        temp=root;
        ptr=temp->next;
        root=ptr;
        free(temp);
        return root;
    }
}
int main()
{
    struct node* root=NULL;
    root=create();
    traverse(root);
    root=deletefront(root);
    return 0;
}
