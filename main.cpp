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
        cout<<"Deleting front node"<<endl;
        struct node* ptr,*temp;
        temp=root;
        ptr=temp->next;
        root=ptr;
        free(temp);
        return root;
    }
}
struct node* deleteend(struct node* root)
{
   if(root==NULL)
   {
       return NULL;
   }
    else
    {
        cout<<"Deleting last node"<<endl;
        struct node* temp,*ptr;
        temp=root;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        ptr=temp->next;
        temp->next=NULL;
        free(ptr);
        return root;
    }
}
void search(struct node* root)
{
    if(root==NULL)
    {
        cout<<"Linked is empty"<<endl;
    }
    else
    {
        int value;
        cout<<"Enter value to searched in the list"<<endl;
        cin>>value;
        struct node* temp;
        temp=root;
        while(temp!=NULL)
        {
            if(temp->data==value)
            {
                cout<<"Found"<<endl;
            }
            else
            {
                temp=temp->next;
            }
        }
        if(temp==NULL)
        {
            cout<<"Not found"<<endl;
        }
    }
}
struct node* deleteany(struct node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        int pos;
        cout<<"Enter position of node to be deleted"<<endl;
        cin>>pos;
        if(pos>size)
        {
            return root;
        }
        else
        {
            struct node* temp,*ptr;
            temp=ptr=root;
            for(int i=0;i<pos-1;i++)
            {
                ptr=temp;
                temp=temp->next;
            }
            if(pos==1)
            {
                root=temp->next;
                free(temp);
            }
            else
            {
                ptr->next=temp->next;
                temp->next=NULL;
                free(temp);
            }
            return root;
        }
    } 
}
struct node* removeDuplicates(struct node* head)
{
    struct node* temp=head,*ptr;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            ptr=temp->next;
            temp->next=ptr->next;
            free(ptr);
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}
int main()
{
    struct node* root=NULL;
    root=create();
//     traverse(root);
//     root=deletefront(root);
//     root=deleteend(root);
//     root=deleteany(root);
//     root=removeDuplicates(root)
    search(root);
    
    return 0;
