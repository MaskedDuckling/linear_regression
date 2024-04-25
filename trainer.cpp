#include <iostream>
#include <fstream>
#include <vector>

// Function to estimate the price based on mileage and theta values
double estimatePrice(double mileage, double theta0, double theta1) {
    return theta0 + (theta1 * mileage);
}

int main() {
    // Load the dataset file
    std::ifstream datasetFile("data.csv");
    if (!datasetFile) {
        std::cerr << "Failed to open dataset file." << std::endl;
        return 1;
    }

    // Read the dataset into vectors
    std::vector<double> mileage;
    std::vector<double> price;
    std::string line;
    double mileageValue, priceValue;
    std::getline(datasetFile, line); // Skip the header line
    while (std::getline(datasetFile, line)) {

        sscanf(line.c_str(), "%lf,%lf", &mileageValue, &priceValue);
        mileage.push_back(mileageValue);
        price.push_back(priceValue);
    }

    // Print the dataset
    // for (auto i = 0; i < mileage.size(); i++) { 
    //     std::cout << mileage[i] << " " << price[i] << std::endl;
    // } 

    // Close the dataset file
    datasetFile.close();

    // Perform linear regression
    double learningRate = 0.01; // Adjust the learning rate as needed
    double theta0 = 0.0;
    double theta1 = 0.0;
    int m = mileage.size();

    double tmpTheta0 = 0.0;
    double tmpTheta1 = 0.0;

    for (int i = 0; i < m; i++) {
        double estimatedPrice = estimatePrice(mileage[i], theta0, theta1);
        double error = estimatedPrice - price[i];
        tmpTheta0 += error;
        tmpTheta1 += error * mileage[i];
    }

    tmpTheta0 = (learningRate * tmpTheta0) / m;
    tmpTheta1 = (learningRate * tmpTheta1) / m;

    theta0 = tmpTheta0;
        theta1 = tmpTheta1;

    // Save the theta values for use in the first program
    std::ofstream thetaFile("theta.txt");
    if (!thetaFile) {
        std::cerr << "Failed to open theta file." << std::endl;
        return 1;
    }

    thetaFile << theta0 << " " << theta1;

    // Close the theta file
    thetaFile.close();

    return 0;
}
