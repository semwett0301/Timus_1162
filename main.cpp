#include <iostream>
#include <vector>

using namespace std;

class Exchange {
public:
    int firstCurrency, secondCurrency;
    double exchangeRate, commission;

    Exchange(int a, int b, double r, double c) {
        firstCurrency = a;
        secondCurrency = b;
        exchangeRate = r;
        commission = c;
    }
};

int main() {
    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;

    vector<double> currencies(101);
    currencies[s] = v;
    vector<Exchange> exchanges;

    for (int i = 0; i < m; i++) {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b;
        cin >> rab >> cab >> rba >> cba;

        exchanges.emplace_back(a, b, rab, cab);
        exchanges.emplace_back(b, a, rba, cba);
    }

    for (int i = 0; i < n - 1; i++) {
        for (Exchange ex : exchanges) {
            if (currencies[ex.secondCurrency] < (currencies[ex.firstCurrency] - ex.commission) * ex.exchangeRate) {
                currencies[ex.secondCurrency] = (currencies[ex.firstCurrency] - ex.commission) * ex.exchangeRate;
            }
        }
    }

    for (Exchange ex : exchanges) {
        if (currencies[ex.secondCurrency] < (currencies[ex.firstCurrency] - ex.commission) * ex.exchangeRate) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
