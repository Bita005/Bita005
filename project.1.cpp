#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return;
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void scalarMultiply(int matrix[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int rows, int cols, int scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = matrix[i][j] * scalar;
        }
    }
}

bool searchInMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == value) {
                return true;
            }
        }
    }
    return false;
}

void editElement(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int rowIndex, int colIndex, int newValue) {
    if (rowIndex >= 0 && rowIndex < rows && colIndex >= 0 && colIndex < cols) {
        matrix[rowIndex][colIndex] = newValue;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void sumRows(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << sum << endl;
    }
}

void sumColumns(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << sum << endl;
    }
}

int sumMainDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int countZeroElements(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) count++;
        }
    }
    return count;
}

string determineMatrixType(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    bool upperTriangular = true;
    bool lowerTriangular = true;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < j && matrix[i][j] != 0) lowerTriangular = false;
            if (i > j && matrix[i][j] != 0) upperTriangular = false;
        }
    }

    if (upperTriangular) return "Upper Triangular Matrix";
    if (lowerTriangular) return "Lower Triangular Matrix";

    return "Neither Upper nor Lower Triangular Matrix";
}

bool binarySearch(int arr[], int size, int value) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value)
            return true;
        else if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    inputMatrix(matrix, rows, cols);

    cout << "Matrix:\n";
    printMatrix(matrix, rows, cols);

    int matrix2[MAX_SIZE][MAX_SIZE];
    inputMatrix(matrix2, rows, cols);

    cout << "Sum of Matrices:\n";
    int sumResult[MAX_SIZE][MAX_SIZE];
    addMatrices(matrix, matrix2, sumResult, rows, cols);
    printMatrix(sumResult, rows, cols);

    cout << "Difference of Matrices:\n";
    int subResult[MAX_SIZE][MAX_SIZE];
    subtractMatrices(matrix, matrix2, subResult, rows, cols);
    printMatrix(subResult, rows, cols);

    cout << "Enter a scalar to multiply the matrix: ";
    int scalar;
    cin >> scalar;

    cout << "Scalar Multiplication Result:\n";
    int scalarResult[MAX_SIZE][MAX_SIZE];
    scalarMultiply(matrix, scalarResult, rows, cols, scalar);
    printMatrix(scalarResult, rows, cols);

    cout << "Enter a value to search in the matrix: ";
    int searchValue;
    cin >> searchValue;

    if (searchInMatrix(matrix, rows, cols, searchValue)) {
        cout << searchValue << " found in the matrix." << endl;
    } else {
        cout << searchValue << " not found in the matrix." << endl;
    }

    cout << "Enter row and column to edit: ";
    int editRow, editCol, newValue;
    cin >> editRow >> editCol;

    cout << "Enter new value: ";
    cin >> newValue;

    editElement(matrix, rows, cols, editRow - 1, editCol - 1, newValue);

    cout << "Matrix after editing:\n";
    printMatrix(matrix, rows, cols);

    sumRows(matrix, rows, cols);
    sumColumns(matrix, rows, cols);

    cout << "Sum of main diagonal: " << sumMainDiagonal(matrix, min(rows, cols)) << endl;

    cout << "Number of zero elements in the matrix: " << countZeroElements(matrix, rows, cols) << endl;

    cout << determineMatrixType(matrix, rows, cols) << endl;

   int flatArray[MAX_SIZE * MAX_SIZE];
   int k = 0;

   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           flatArray[k++] = matrix[i][j];
       }
   }

   bubbleSort(flatArray, k);

   cout << "Sorted array from the matrix:\n";
   for (int i = 0; i < k; i++) {
       cout << flatArray[i] << " ";
   }
   cout << endl;

   cout << "Enter a value to search in the sorted array: ";
   cin >> searchValue;

   if (binarySearch(flatArray, k, searchValue)) {
       cout << searchValue << " found in the sorted array." << endl;
   } else {
       cout << searchValue << " not found in the sorted array." << endl;
   }

   return 0;
}

