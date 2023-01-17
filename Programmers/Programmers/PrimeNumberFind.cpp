#include <string>
#include <vector>
#include <cmath>
#include <memory>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    
    unique_ptr<bool[]> primePtr = make_unique<bool[]>(static_cast<unsigned long long>(n) + 1);

    for (size_t i = 2; i <= sqrt(n); ++i)
    {
        for (size_t j = 2; i * j <= n; ++j)
        {
            primePtr[i * j] = true;
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        if (!primePtr[i])
            ++answer;
    }


    return answer;
}



// O(n^2);
int solution2(int n)
{
    int answer = 0;

    bool isPrime = true;

    for (int i = 2; i <= n; ++i)
    {
        isPrime = true;
        for (int j = 2; j < i; ++j)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            ++answer;
    }
}


bool isPrime(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}


bool isPrime2(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution3(int n)
{
    int answer = 0;
    bool isPrime = true;

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (isPrime2(i))
            ++answer;
    }


    return answer;
}
