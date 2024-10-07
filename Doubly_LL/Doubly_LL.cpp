#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* nxt;
    node* prev;
    node(int data1){
        data=data1;
        nxt=prev=NULL;
    }
};

class doubly_LL{
    public:
    node* head=NULL;
    void add(int data){
        node* p = new node(data);
        if (head==NULL){
            head=p;
        }
        else{
            node* temp=head;
            while(temp->nxt!=NULL){
                temp=temp->nxt;
            }
            temp->nxt=p;
            p->prev=temp;
        }
    }

    void del(int data){
        node* temp= head;
        if(temp==NULL){
            cout<<"NULL"<<endl;
        }
        else if(temp->data==data){
            head=temp->nxt;
            head->prev=NULL;
            delete temp;
        }
        else{
            while(temp->data!=data && temp->nxt!=NULL){
                temp=temp->nxt;
            }
            if(temp->data==data){
                temp->prev->nxt=temp->nxt;
                if(temp->nxt!=NULL)
                    temp->nxt->prev=temp->prev;
                delete temp;
            }
            else
                cout<<"Element not found"<<endl;
        }
    }

    void display(){
        node* temp=head;
        if(temp==NULL){
            cout<<"NULL"<<endl;
        }
        else{
            while(temp->nxt!=NULL){
                cout<<temp->data<<" ";
                temp=temp->nxt;
            }
            cout<<temp->data<<endl;
        }
    }
};

int main(){
    doubly_LL dll;
    dll.add(1);
    dll.add(2);
    dll.add(3);
    dll.add(4);
    dll.display();
    dll.del(2);
    dll.display();
    return 0;
}