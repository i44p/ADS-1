// Copyright 2022 NNTU-CS

#include "alg.h"

#include <cmath>
#include <cstdint>

bool checkPrime(uint64_t value) {
  if (value == 1) return false;

  if (value <= 3) return true;

  if (value % 2 == 0) return false;

  for (uint64_t divisor = 3; divisor <= sqrt(value); divisor += 2) {
    if (value % divisor == 0) return false;
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t index = 0;
  uint64_t value = -1;

  do {
    value++;
    if (checkPrime(value)) {
      index++;
    }
  } while (index <= n);

  return value;
}

uint64_t nextPrime(uint64_t value) {
  do {
    value++;
  } while (!checkPrime(value));

  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  for (uint64_t i = 0; i < hbound; i++) sum += checkPrime(i) ? i : 0;

  return sum;
}
