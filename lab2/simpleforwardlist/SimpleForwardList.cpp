//
// Created by damian on 12.03.18.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value) {
    
    ForwardList *new_node = new ForwardList;
    new_node->value = value;
    
    return new_node;
}

void DestroyList(ForwardList *list) {
    
    if(list)
    {
        ForwardList *nextToDelete = list->next;
        delete list;
        DestroyList(nextToDelete);
    }
    
    
    

}
