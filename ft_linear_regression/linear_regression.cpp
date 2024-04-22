#include <iostream>

float estimate_price(int mileage) {
    float theta0 = 0;
    float theta1 = 0;
    return theta0 + theta1 * mileage;
}

int main() {
    int mileage ;
    std::cin >> mileage;

    std::cout << estimate_price(mileage) << std::endl;
}

