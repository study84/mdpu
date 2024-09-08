// Напишіть дві однойменні функції, які отримують на вхід матрицю (двовимірний масив) чисел з плаваючою комою і повертають її транспоненту і визначник відповідно


#include <iostream>

using namespace std; 
 
const int MAX_SIZE = 10; // maximum size of matrix 
 
// Function to calculate the transpose of a matrix 
void calculate(float matrix[][MAX_SIZE], float result[][MAX_SIZE], int rows, int cols) { 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            result[j][i] = matrix[i][j]; 
        } 
    } 
} 
 
// Function to calculate the determinant of a matrix 
float calculate(float matrix[][MAX_SIZE], int n) { 
    if (n == 1) { 
        return matrix[0][0]; 
    } 
    float det = 0; 
    int sign = 1; 
    float submatrix[MAX_SIZE][MAX_SIZE]; 
    for (int i = 0; i < n; i++) { 
        int sub_i = 0; 
        for (int j = 1; j < n; j++) { 
            int sub_j = 0; 
            for (int k = 0; k < n; k++) { 
                if (k != i) { 
                    submatrix[sub_i][sub_j] = matrix[j][k]; 
                    sub_j++; 
                } 
            } 
            sub_i++; 
        } 
        det += sign * matrix[0][i] * calculate(submatrix, n - 1); 
        sign = -sign; 
    } 
    return det; 
}

int main() { 
    float matrix[MAX_SIZE][MAX_SIZE] = { 
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 11} 
    };
    float transpose_matrix[MAX_SIZE][MAX_SIZE]; 
    
    calculate(matrix, transpose_matrix, 3, 3);
    
    float det = calculate(matrix, 3); 
    cout << "Original Matrix:" << endl; 
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            cout << matrix[i][j] << " "; 
        } 
        cout << endl; 
    } 
    cout << "Transpose Matrix:" << endl; 
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            cout << transpose_matrix[i][j] << " "; 
        } 
        cout << endl; 
    } 
    cout << "Determinant: " << det << endl; 
    return 0; 
}


