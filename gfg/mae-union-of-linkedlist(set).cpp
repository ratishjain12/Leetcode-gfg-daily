struct Node* makeUnion(struct Node* head1, struct Node* head2){
    // code here
    set<int>st;
    while(head1){
        st.insert(head1->data);
        head1=head1->next;
    }
    
    while(head2){
        st.insert(head2->data);
        head2=head2->next;
    }
    
    
    Node *head = NULL;
    Node *tail = NULL;
    
    for(auto it : st){
        Node *temp = new Node(it);
        
        if(head == NULL){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    
    return head;
}