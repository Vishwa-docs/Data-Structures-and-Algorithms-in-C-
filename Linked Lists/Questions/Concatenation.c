void concatenate(struct Node *a,struct Node *b){
    if(a != NULL && b!= NULL){
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
    } else{
        printf("Either a or b is NULL\n");
    }
}