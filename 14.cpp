#include <iostream>
#include <vector>

int n;
std::vector<std::vector<long long> > identity;

std::vector<std::vector<long long> > mul(std::vector<std::vector<long long> > a, std::vector<std::vector<long long> > b) {
    std::vector<std::vector<long long> > c(n, std::vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % 1000000007) % 1000000007;
            }
        }
    }
    return c;
}

std::vector<std::vector<long long> > pow(std::vector<std::vector<long long> > m, int n)
{
    if (n == 0)
        return identity;
    else if (n == 1)
        return m;
    else if (n % 2 == 1)
        return mul(pow(m, n - 1), m);
    else
    {
        std::vector<std::vector<long long> > b = pow(m, n / 2);
        return mul(b, b);
    }
}

int main()
{
    int m, u, v, l;
    std::cin >> n >> m >> u >> v >> l;
    u--;
    v--;

    for (int i = 0; i < n; i++) {
        identity.push_back(std::vector<long long>(n));
        identity[i][i] = 1;
    }

    std::vector<std::vector<long long> > matrix(n, std::vector<long long>(n));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        matrix[a][b]++;
        matrix[b][a]++;
    }

    std::vector<std::vector<long long> > res = pow(matrix, l);
    std::cout << res[u][v] % 1000000007 << std::endl;
}
