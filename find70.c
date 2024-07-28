#include <stdio.h>

const int digits[] = {1,2,3,4,5,6,7,8,9};
const char ops[] = {'+','-','*'};

int main (int argc, char argv[]) {
  int digits_len = sizeof(digits)/sizeof(int);
  int ops_len = sizeof(ops)/sizeof(char);
  for (int i1 = 0; i1 < digits_len; i1++) {
    for (int j1 = 0; j1 < ops_len; j1++) {
      for (int i2 = 0; i2 < digits_len; i2++) {
        for (int j2 = 0; j2 < ops_len; j2++) {
          for (int i3 = 0; i3 < digits_len; i3++) {
            int d1 = digits[i1];
            int o1 = ops[j1];
            int d2 = digits[i2];
            int o2 = ops[j2];
            int d3 = digits[i3];
            //printf("(%d %c %d) %c %d\n",d1,o1,d2,o2,d3);
            int r;
            if (o1 == '*' && o2 != '*') {
              int a = d1 * d2;
              int x = a;
              switch(o2) {
              case '+': x += d3; break;
              case '-': x -= d3; break;
              }
              r = x;
            } else if (o1 != '*' && o2 == '*') {
              int x = d1;
              int b = d2 * d3;
              switch(o1) {
              case '+': x += b; break;
              case '-': x -= b; break;
              }
              r = x;
            } else {
              r = d1;
              switch(o1) {
              case '+': r += d2; break;
              case '-': r -= d2; break;
              case '*': r *= d2; break;
              }
              switch(o2) {
              case '+': r += d3; break;
              case '-': r -= d3; break;
              case '*': r *= d3; break;
              }
            }
            if (r == 70) {
              printf("%d %c %d %c %d = %d\n",d1,o1,d2,o2,d3,r);
            }
          }
        }
      }
    }
  }
}
