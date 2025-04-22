// Euler's Totient Function
// calculate phi(1) to phi(n) in O(nloglogn)
// calculate coprime from 1 to n

const int N = 1e6;
vector<int> phi(N+1);
void phi_1_to_n() {

  int n = N;
  
  for (int i = 0; i <= n; i++)
      phi[i] = i;

  for (int i = 2; i <= n; i++) {
      if (phi[i] == i) {
          for (int j = i; j <= n; j += i)
              phi[j] -= phi[j] / i;
      }
  }
}