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
operation_status = insert_at(list,element,list->length);
return operation_status;
}

Status add_to_start(List_ptr list, Element element){
  Status operation_status;
operation_status = insert_at(list,element,0);
return operation_status;
}

List_ptr reverse(List_ptr list){
  List_ptr reverse_list = create_list();
  Node_ptr curr_node = list->first;
  for(int i = 0; i < list->length; i++){
 add_to_start(reverse_list,curr_node->element);
 curr_node = curr_node->next;
  }
  return reverse_list;
}

List_ptr map(List_ptr list, Mapper map_function){
  Node_ptr curr_node = list->first;
  for (int i = 0; i < list->length; i++)
  {
    curr_node->element = map_function(curr_node->element);
    curr_node = curr_node->next;
}
return list;
}

List_ptr filter(List_ptr list, Predicate predicate_function){
  List_ptr filtered_list = create_list();
  Node_ptr curr_node = list->first;
  for (int i = 0; i < list->length; i++)
  {
    Status status = predicate_function(curr_node->element);
    if (status==Success)
    {
      add_to_list(filtered_list, curr_node->element);
    }
    curr_node = curr_node->next;
  }
  return filtered_list;
}

Element reduce(List_ptr list, Element element, Reducer reducer_function){
  Element element;
  Node_ptr curr_node = list->first;
  for (int i = 0; i < list->length; i++)
  {
    element = reducer_function(element,curr_node->element);
    curr_node = curr_node->next;
  }
  return element;
}

void forEach(List_ptr list, ElementProcessor processor){
  Node_ptr curr_node = list->first;
for (int i = 0; i < list->length; i++)
{
  processor(curr_node->element);
  curr_node = curr_node->next;
}
}

Element remove_at(List_ptr list, int position){
  Element removed_element =NULL;
    if (position < 0 || position >= list->length)
    {
      return removed_element;
    }
    if(list->length==1){
      removed_element = list->first->element;
      free(list->first);
      free(list->last);
      list->length--;
      return removed_element;
    }
    if (position==0)
    {
      Node_ptr node_to_clear = list->first;
      removed_element = node_to_clear->element;
      list->first=list->first->next;
      free(node_to_clear);
      list->length--;
      return removed_element;
    }
    Node_ptr curr_node = list->first;
    for (int i = 0; i < position-1; i++)
    {
      curr_node = curr_node->next;
    }
    Node_ptr node_to_clear = curr_node->next;
      removed_element = node_to_clear->element;
      if(position==list->length-1){
        list->last = curr_node;
        curr_node->next = NULL;
        free(node_to_clear);
      list->length--;
      return removed_element;
      }
      curr_node->next = curr_node->next->next;
      free(node_to_clear);
      list->length--;
      return removed_element;
}