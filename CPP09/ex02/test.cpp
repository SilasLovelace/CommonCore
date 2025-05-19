#include <iostream>
#include <vector>


std::vector<int> generateJacobsthalPattern(int N) {
    N++;
    std::vector<int> jacobsthal = {0, 1};

    // Generate Jacobsthal numbers up to < N
    while (true) {
        int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= N)
            break;
        jacobsthal.push_back(next);
    }
    
    std::vector<int> result;
    if (N > 2) {
        jacobsthal.erase(jacobsthal.begin(), jacobsthal.begin() + 2);
    }

    std::cout << "Jacobsthal numbers: ";
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        std::cout << jacobsthal[i] << " ";
    }
    std::cout << std::endl;

      for (size_t i = 0; i < jacobsthal.size(); ++i) {
        int start = jacobsthal[i];
        int end = jacobsthal[i - 1];

        // Print descending from start down to end+1
        for (int num = start; num > end; --num) {
            result.push_back(num);
            std::cout << num << " ";
        }

    }
    if (jacobsthal.back() < N) {
        for (int num = jacobsthal.back() + 1; num < N; ++num) {
            result.push_back(num);
            std::cout << num << " ";
        }
    }
    for (size_t i = 0; i < result.size(); ++i) 
        result[i] = result[i] - 1;
    std::cout << std::endl;
    return result;
}


int main(int argc, char* argv[]) {
    int N = std::stoi(argv[1]);
    std::vector<int> pattern = generateJacobsthalPattern(N);
    std::cout << "Generated pattern: ";
    for (int val : pattern)
        std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}