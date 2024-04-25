#include <iostream>
#include <fstream>

float estimate_price(int mileage) {
    float theta0 = 0;
    float theta1 = 0;
    std::string line;
    std::ifstream datasetFile("theta.txt");
    if (!datasetFile) {
        std::cerr << "Failed to open dataset file." << std::endl;
        return 1;
    }
    std::getline(datasetFile, line);
    sscanf(line.c_str(), "%f,%f", &theta0, &theta1);
    datasetFile.close();
    return theta0 + theta1 * mileage;
}

int main() {
    int mileage ;
    std::cout << "Enter mileage : ";
    std::cin >> mileage;

    std::cout << "Estimated price : " << estimate_price(mileage) << std::endl;
}

