/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       Node* temp=head;
       int value;
       int count=0;
       while(temp){
        count++;
        temp=temp->next;
       }
       if(n>count){
           return -1;
       }
       int run=count-(n-1);
       for(int i=0;i<run-1;i++){
           head=head->next;
       }
       value=head->data;
       return value;
}
