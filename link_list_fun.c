#include <unistd.h>
#include <stdlib.h>

struct plorp {
  char status;
  int val;
  struct plorp *next;
} plorp;

void ft_putchar(char p){
  write(1, &p, 1);
}

void ft_putnum(int num){
  while(num > 0){
    int digit = num % 10;
    num -= digit;
    num /= 10;
    ft_putchar(digit + '0');
  }
}

void ft_putstr(char str[]){
  while(*str != '\0')
    ft_putchar(*str++);
}

void plorp_list_spitter(struct plorp *plorp_list){
  if((*plorp_list).status == 'C')
    ft_putstr("00");
  ft_putnum((*plorp_list).val);
  if((*plorp_list).status == 'B')
    ft_putstr(".0");
  ft_putchar('\n');
  
  if((*plorp_list).next != NULL){
    plorp_list_spitter((*plorp_list).next);
  }
}

struct plorp *plorp_lister(char argv[]){
  struct plorp *blorp = (struct plorp *)malloc(sizeof(struct plorp));

  int val = 0;
  int base = 1;

  while(*(argv + 1) != ',' && *(argv + 1) != '\0'){
    val += ((*argv - '0') * base);
    base *= 10;
    argv++;
  }

  (*blorp).val = val;
  (*blorp).status = *argv;
  (*blorp).next = NULL;

  if (*(argv + 1) == ','){
    (*blorp).next = plorp_lister(argv + 2);
  }

  return blorp;
}

int main(int argc, char **argv) {
  struct plorp *plorp_list;
  if(argv[1])
    plorp_list = plorp_lister(argv[1]);
  else{
    char argv[] = "1A,6A,2B,3A,2B,5C,11A,3C";
    plorp_list = plorp_lister(argv);
  }
    
  plorp_list_spitter(plorp_list);

  return 0;
}