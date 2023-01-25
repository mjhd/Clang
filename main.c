#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct scooper {
    char handle;
    char *scoops;
} scooper;

struct scooper *scooper_maker(char type[], char handle){
    struct scooper *shovel = (struct scooper *)malloc(sizeof(scooper));
    (*shovel).handle = (handle == 'y') ? 1 : 0;
    (*shovel).scoops = (char *)malloc(sizeof(char)*5);
    while(*type != '\0')
      *(*shovel).scoops++ = *type++;
    *(*shovel).scoops = '\0';
    return shovel;
}
/*
int main(){

    char splar = 'g';
    write(1,&splar,1);

    struct scooper *shovel_01 = scooper_maker("poop", 'y');
    write(1,(*shovel_01).scoops,1);

    return 0;
}
*/







int argcee = 3;
char *argvee[] = {"file.out", "0010", "1001", /*"1101", "0011"*/};

struct value {
  char value[4];
  struct value *link;
} value;

void add_value(char value[4], struct value **values){
  struct value *new_value = (struct value *)malloc(sizeof(struct value));
  int count = 4;

  while(count--)
    (*new_value).value[count] = value[count];
  (*new_value).link = *values;
  *values = new_value;
}

void print_list(struct value *values){
  while((long int)(*values).link != (long int)NULL){
    char count = 4;
    while(count--)
      write(1,&(*values).value[count],1);
    values = (*values).link;
  }
}
/*
int main(int argc, char **argv) {
  struct value *values = (struct value *)malloc(sizeof(struct value));
  struct value **values_pnt = &values;
  (*values).link = NULL;
  while(--argcee){
    char chars = 4;
    char count = 0;
    char *arg = (char *)memset(malloc(sizeof(char) * 5), '1', 4);
    arg[4] = '\0';
    while(*arg != '\0'){
      *arg = argvee[argcee][count++];
      arg+=1;
    }
    add_value(argvee[argcee], values_pnt);
  }
  
  print_list(values);
  
  return 0;
}
*/



struct my_data {
  int number;
  char active;
} my_data;
/*
int main() {
  //int arr[] = { 20,10,-80,10,10,15,35 };
  int arr[] = { 1,2,3,4,3,2,1 };

  int *ptr_i = malloc(sizeof(int));
  char *ptr_c = malloc(sizeof(int));

  ptr_c[2] = 'l';
  //ptr_i[2] = 'w';
  char *ptr_new = ptr_i;
  ptr_new[2] = 'w';
  write(1, &ptr_new[2], 1);

  struct my_data *data = malloc(sizeof(my_data));
  (*data).number = 42;
  (*data).active = 'Y';

  return 0;
}
*/








struct Base {
  int val;
  void (*printer)(struct test);
} Base;

struct test {
  //int val;
  //void (*printer)(struct test);
  struct Base test;
} test;

void print_test(struct test *tester){
  //printf("%d", (*tester).val);
  printf("%d", (*tester).test.val);
}

struct test *create_object(int val){
  struct test *current = (struct test *)malloc(sizeof(test));
  //(*current).val = val;
  (*current).test.val = val;
  //(*current).printer = print_test;
  (*current).test.printer = print_test;
  return current;
}

/*
int main() {
  struct test *tester = create_object(4);
  print_test(tester);

  return 0;
}
*/


int main(){ return 0; }