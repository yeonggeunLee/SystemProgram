#include <iostream>
#include <vector>

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrixA(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> matrixB(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> matrixC(rows, std::vector<int>(cols));

    std::cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrixA[i][j];
        }
    }

    std::cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrixB[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    std::cout << "Resulting matrix C:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrixC[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

