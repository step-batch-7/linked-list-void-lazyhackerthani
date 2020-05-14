#include"linkedlist.h"

List_ptr create_list(void){
  List_ptr new_list = calloc(1, sizeof(LinkedList));
  return new_list;
}

Node_ptr create_node(Element element){
  Node_ptr new_node = calloc(1, sizeof(Node));
  new_node->element = element;
  new_node->next = NULL;
  return new_node;
}

Status insert_at(List_ptr list, Element element, int position){
  Status operation_status;
  Node_ptr node = create_node(element);
    operation_status = node == NULL ? Failure : Success;
    operation_status = position < 0 || position > list->length ? Failure : operation_status;
    if (operation_status == Failure)
    {
      return operation_status;
    }
    if(list->length==0){
      list->first = list->last = element;
  list->length=1;
      return operation_status;
    }
    if (position==0)
    {
      node->next= list->first;
      list->first = node;
      list->length++;
       return operation_status;
    }
    if (position==list->length)
    {
      list->last->next = node;
      list->last = node;
      list->length++;
       return operation_status;
    }
    Node_ptr curr_node = list->first;
    for (int i = 0; i < position-1; i++)
    {
      curr_node = curr_node->next;
    }
    node->next=curr_node->next;
    curr_node->next = node;
    list->length++;
    return operation_status;
}

Status add_to_list(List_ptr list, Element element){
Status operation_status;
operation_status = insert_at(List_ptr list, Element element, int list->length);
return operation_status;
}