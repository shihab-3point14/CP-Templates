bool is_set(int number, int x) {
    return (number >> x) & 1;
}

bool isDivisibleByPowerOf2(int n, int k) {
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}

bool isPowerOfTwo(int n) {
    
    return n && !(n & (n - 1));
}

// x is which bit i want to work with

void set_bit(int &n,int x){
    n = n | (1 << x);
}

void flip_bit(int &n,int x){
    n = n ^ (1 << x);
}

void clear_bit(int &n,int x){
    n = n & ~(1 << x);
}

// 110100 to 110000
void clear_right_most_bit(int &n){
    n = n & (n-1);
}

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int countSetBits_upto_n(int n) {
        int count = 0;
        while (n > 0) {
            int x = std::__bit_width(n) - 1;
            count += x << (x - 1);
            n -= 1 << x;
            count += n + 1;
        }
        return count;
}

// 110111 --> 110000
void clear_all_trailing_ones(int &n){
    n = n & (n+1);
}

// 110101 --> 110111
void set_the_last_cleared_bit(int &n){
    n = n | (n+1);
}

// 110100 --> 000100
void extracts_the_last_set_bit(int &n){
    n = n & (-n);
}
