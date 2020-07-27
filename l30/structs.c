#include <stdio.h>
#include <string.h>

enum transactiontypes { PURCHASE, CREDIT, FEE };

typedef struct cardtransaction_t {
  int date;
  enum transactiontypes type;
  int mcc;
  char merchantName[26];
  char location[16];
  int amount; /* cents */
  int flags;
} cardTransaction;

int main() {
  cardTransaction t;
  t.date = 20200723;
  t.type = PURCHASE;
  t.mcc = 5812;
  strcpy(t.merchantName, "MANOLO'S PIZZA AND EMPANA");
  strcpy(t.location, "URBANA , IL");
  t.amount = 500;
  t.flags = 0;
}
