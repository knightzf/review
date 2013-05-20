#include <iostream>

using namespace std;

struct node{
    int value;
    node* next;
};

node* reverse_list(node* head)
{
    if(head == NULL)
        return NULL;

    node* p1 = NULL;
    node* p2 = head;
    node* p3 = p2->next;

    while(true)
    {
        p2->next = p1;

        if(p3 == NULL)
            break;

        p1 = p2;
        p2 = p3;
        p3 = p2->next;
    }

    return p2;

}

int main()
{
    node a1 = {1, NULL};
    node a2 = {2, NULL};
    node a3 = {3, NULL};
    node a4 = {4, NULL};
    node a5 = {5, NULL};

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;

    node* new_head = reverse_list(&a1);

    while(new_head != NULL)
    {
        std::cout<<new_head->value<<"-";
        new_head = new_head->next;
    }
    std::cout<<endl;

    return 0;
}
