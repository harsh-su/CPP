#include <iostream>
#include <vector>
#include <cmath> 




int main() {
    // Using the vector library from the C++ Standard Template Library (STL)
    std::vector<int> myVector;
    std::vector<float> twovec;
    

    // Adding elements to the vector
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    // Displaying the elements of the vector
    std::cout << "Vector elements: ";
    for (const auto& element : myVector) {
        std::cout << sqrt(element) << " ";
    }
    std::cout << std::endl;

    return 0;
}
