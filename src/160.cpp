#include <iostream>
#include <vector>
#include <iomanip>

// https://uva.onlinejudge.org/external/1/160.html

// n >= 2
std::vector<bool> prime_seives(int n) {
    std::vector<bool> primes;
    primes.assign(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            int j = 2;
            while ((i * j) <= n) {
                primes[i * j] = false;
                j++;
            }
        }
    }
    return primes;
}

// return the component of prime k in n!
int k_component(int n, int k) {
    int c = 0;
    int base = k;

    while (n / k != 0) {
        c += n / k;
        k *= base;
    }

    return c;
}

int main() {
    int n;
    std::vector<bool> primes = prime_seives(100);
    while (std::cin >> n && n != 0) {
        std::vector<int> components;
        for (int i = 0; i <= n; ++i) {
            if (primes[i]) {
                components.push_back(k_component(n, i));
            }
        }

        std::cout << std::setw(3) << std::right << n << "! =";
        for (int j = 0; j < components.size(); ++j) {
            if(j % 15 == 0 && j != 0){
                std::cout<<std::endl;
                std::cout<<std::setw(6)<<std::right<<" ";
            }
            std::cout << std::setw(3) << std::right << components[j];
        }
        std::cout<<std::endl;
    }

}