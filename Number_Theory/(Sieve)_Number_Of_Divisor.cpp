int M = 1e7 + 1;
vector<bool> is_prime(M + 1, true);
vector<int> prime;
int s = 0;

void sievePrime() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= M; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= M; j += i)
        is_prime[j] = false;
    }
  }
  for (int i = 2; i <= M; i++) {
    if (is_prime[i])
      prime.push_back(i);
  }
  s = prime.size();
}

int numberOfDivisors(int num) {
  int total = 1;

  for (int i = 0; i < s && prime[i] * prime[i] <= num; i++) {
    if (num % prime[i] == 0) {
      int e = 0;
      do {
        e++;
        num /= prime[i];
      } while (num % prime[i] == 0);
      total *= e + 1;
    }
  }
  if (num > 1) {
    total *= 2;
  }
  return total;
}