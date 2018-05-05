#include <stdio.h>

int main()
{
  int amount = 700;
  char a, b, c;
  scanf("%c%c%c", &a, &b, &c);

  if (a == 'o') {
    amount += 100;
  }
  if (b == 'o') {
    amount += 100;
  }
  if (c == 'o') {
    amount += 100;
  }

  printf("%d\n", amount);

  return 0;
}
