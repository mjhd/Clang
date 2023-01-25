void list_sort_from_back(int *list, int length){
  char has_changed = 0;
  int list_remaining = length - 1;
  while(--length){
    if(list[length] < list[length - 1]){
      int current_val = list[length];
      list[length] = list[length - 1];
      list[length - 1] = current_val;
      has_changed = 1;
    }
  }
  *list++;
  if(list_remaining && has_changed)
    list_sort_from_back(list, list_remaining);
}



void list_sort_from_front(int *list, int length){
  char has_changed = 0;
  int list_remaining = length - 1;
  for(int i = 0; i < list_remaining; i++){
    if(list[i] > list[i + 1]){
      int current_val = list[i];
      list[i] = list[i + 1];
      list[i + 1] = current_val;
      has_changed = 1;
    }
  }
  if(list_remaining && has_changed)
    list_sort_from_front(list, list_remaining);
}

void list_sort_from_front_and_back(int *list, int length){
  char has_changed = 0;
  int list_remaining = length - 1;
  char from_front = (length % 2) ? 1 : 0;
  if(!from_front){
    while(--length){
      if(list[length] < list[length - 1]){
        int current_val = list[length];
        list[length] = list[length - 1];
        list[length - 1] = current_val;
        has_changed = 1;
      }
    }
    *list++;
  }
  else {
    for(int i = 0; i < list_remaining; i++){
      if(list[i] > list[i + 1]){
        int current_val = list[i];
        list[i] = list[i + 1];
        list[i + 1] = current_val;
        has_changed = 1;
      }
    }
  }
  if(list_remaining && has_changed)
    list_sort_from_front_and_back(list, list_remaining);
}


int main() {
  int values = 10;
  int *list = (int *)malloc(sizeof(int) * values);

  list[0] = 2;
  list[1] = 4;
  list[2] = 10;
  list[3] = 5;
  list[4] = 7;
  list[5] = 3;
  list[6] = 9;
  list[7] = 1;
  list[8] = 8;
  list[9] = 6;
  
  //list_sort_from_front(list, values); // 246 steps
  //list_sort_from_back(list, values); // 254 steps
  list_sort_from_front_and_back(list, values); // 217 steps

  
  /*
  list[0] = 2;
  list[1] = 1;
  list[2] = 3;
  list[3] = 5;
  list[4] = 7;
  list[5] = 4;
  list[6] = 6;
  list[7] = 9;
  list[8] = 10;
  list[9] = 8;
  
  //list_sort_from_front(list, values); // 110 steps
  //list_sort_from_back(list, values); // 113 steps
  list_sort_from_front_and_back(list, values); // 118 steps
  */

  /*
  list[0] = 10;
  list[1] = 9;
  list[2] = 8;
  list[3] = 7;
  list[4] = 6;
  list[5] = 5;
  list[6] = 4;
  list[7] = 3;
  list[8] = 2;
  list[9] = 1;
  
  //list_sort_from_front(list, values); // 364 steps
  //list_sort_from_back(list, values); // 374 steps
  list_sort_from_front_and_back(list, values); // 389 steps
  */

  return 0;
}