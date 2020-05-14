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