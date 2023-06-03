#include<iostream>
#include<vector>
#include <cmath>
#include <unordered_map>
#include<algorithm>
using namespace std;
float pie=22/7;
//addition function

// Function to calculate the exponential function (e^x)
double exponential(double x) {
    return exp(x);
}
// Function to calculate the sine of an angle in radians
double sine(double angle) {
    return sin(angle);
}

// Function to calculate the cosine of an angle in radians
double cosine(double angle) {
    return cos(angle);
}

// Function to calculate the tangent of an angle in radians
double tangent(double angle) {
    return tan(angle);
}
// Function to perform row interchange between two rows of a matrix
void rowInterchange(vector<vector<double>>& matrix, int row1, int row2) {
    vector<double> temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

// Function to perform row scaling (multiplication by a non-zero constant) on a row of a matrix
void rowScale(vector<vector<double>>& matrix, int row, double scalar) {
    for (int j = 0; j < matrix[row].size(); j++) {
        matrix[row][j] *= scalar;
    }
}

// Function to perform row replacement (addition/subtraction of a row multiplied by a scalar) on two rows of a matrix
void rowReplace(vector<vector<double>>& matrix, int row1, int row2, double scalar) {
    for (int j = 0; j < matrix[row1].size(); j++) {
        matrix[row1][j] += scalar * matrix[row2][j];
    }
}

// Function to convert a matrix to echelon form
void echelonForm() {
    int rows, cols;
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    vector<vector<double>> matrix(rows, vector<double>(cols));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }

    int lead = 0;  // Tracks the leading entry column

    for (int r = 0; r < rows; r++) {
        if (lead >= cols) {
            break;
        }

        int i = r;
        while (matrix[i][lead] == 0) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols) {
                    return;
                }
            }
        }

        rowInterchange(matrix, i, r);
        if (matrix[r][lead] != 0) {
            rowScale(matrix, r, 1.0 / matrix[r][lead]);
        }

        for (i = 0; i < rows; i++) {
            if (i != r) {
                rowReplace(matrix, i, r, -matrix[i][lead]);
            }
        }

        lead++;
    }

    cout << "Echelon Form:" << endl;
    for (const auto& row : matrix) {
        for (double element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}
// Function to perform matrix addition
vector<vector<double>> matrixAddition(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}
void inputMatrix(int matrix[][10], int row, int col) {
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
}


void displayMatrix(int matrix[][10], int row, int col) {
    cout << "Matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrix(int matrix1[][10], int matrix2[][10], int result[][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrix(int matrix1[][10], int matrix2[][10], int result[][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[][10], int matrix2[][10], int result[][10], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][10], int transpose[][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}
const double EPSILON = 1e-10; // A small value used for comparison to zero

void inputMatrix(double matrix[][10], int n) {
    cout << "Enter the elements of the " << n << "x" << n << " matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(double matrix[][10], int n) {
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void swapRows(double matrix[][10], int row1, int row2, int n) {
    for (int i = 0; i < n; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

void multiplyRow(double matrix[][10], int row, double scalar, int n) {
    for (int i = 0; i < n; i++) {
        matrix[row][i] *= scalar;
    }
}

void addRows(double matrix[][10], int row1, int row2, double scalar, int n) {
    for (int i = 0; i < n; i++) {
        matrix[row1][i] += scalar * matrix[row2][i];
    }
}

bool isZero(double value) {
    return (value) < EPSILON;
}

bool invertMatrix(double matrix[][10], double inverse[][10], int n) {
    // Augment the matrix with the identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                inverse[i][j] = 1.0;
            } else {
                inverse[i][j] = 0.0;
            }
            matrix[i][j + n] = inverse[i][j];
        }
    }

    // Perform Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        if (isZero(matrix[i][i])) {
            // Find a row below with non-zero value in the current column
            int swapRow = -1;
            for (int j = i + 1; j < n; j++) {
                if (!isZero(matrix[j][i])) {
                    swapRow = j;
                    break;
                }
            }
            if (swapRow == -1) {
                // The matrix is not invertible
                return false;
            }
            swapRows(matrix, i, swapRow, 2 * n);
        }

        double pivot = matrix[i][i];
        multiplyRow(matrix, i, 1.0 / pivot, 2 * n);

        for (int j = 0; j < n; j++) {
            if (j != i) {
                double scalar = -matrix[j][i];
                addRows(matrix, j, i, scalar, 2 * n);
            }
        }
    }

    // Divide each row by the diagonal values to get the inverse
    for (int i = 0; i < n; i++) {
        double pivot = matrix[i][i];
        multiplyRow(matrix, i, 1.0 / pivot, 2 * n);
        for (int j = 0; j < n; j++) {
            inverse[i][j] = matrix[i][j + n];
        }
    }

    return true;
}

// Function to perform matrix subtraction








// Function to calculate the inverse of a square matrix

 

// Function to calculate the eigenvalues and eigenvectors of a square matrix


// Function to calculate the power of a square matrix


// Function to calculate the trace of a square matrix



// Function to calculate the cotangent of an angle in radians
double cotangent(double angle) {
    return 1 / tan(angle);
}

// Function to calculate the secant of an angle in radians
double secant(double angle) {
    return 1 / cos(angle);
}

// Function to calculate the cosecant of an angle in radians
double cosecant(double angle) {
    return 1 / sin(angle);
}
int factorial(int n) {
    if (n < 0) {
        cout << "Error: Factorial can only be calculated for non-negative integers!" << endl;
        return -1;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
// Function to calculate the logarithm with base 'base' of a number 'x'
double logarithm(double x, double base) {
    if (x <= 0 || base <= 0 || base == 1) {
        cout << "Error: Invalid input for logarithm!" << endl;
        return NAN;  // Return NaN (Not-a-Number) as an indicator of an error
    } else {
        return log(x) / log(base);
    }
}


// Function to solve a system of linear equations





int ADDition(int x,int y){
    
    return x+y;
}
int subtraction(int x,int y){
    
    return x-y;
}
int multiplication(int x,int y){
    
    return x*y;
}
int Division(int x,int y){
    
    return x/y;
}
int remainder(int x,int y){
    
    return x%y;
}
int power(int x,int y){
    return (pow(x,y));
}
float AreaRectangle(float x,int y){
    return x*y;
}
float AreaSquare(int x){
    return x*x;
}
float AreaTriangle(int x,int y){
    return 1/2*x*y;
}
float AreaCircle(int x){
    return pie*x*x;
}
float AreaRhombus(int x,int y){
    return 0.5*x*y;
}
float AreaParallelogram(int x,int y){
    return 0.5*x*y;
}
float AreaTrapezium(int x,int y,int z){
    float n=(x+y)*z/2;
    return n;
}
float AreaRing(int x,int y){
    float n=(x*x-y*y)*pie;
    return n;
}
float Areasemicircle(int x){
    float n=(pie*x*x)/2;
    return n;
}
float CSACube(int x){
    return 4*x*x;
}
float CSACuboid(int x , int y , int z){
    return (x+y)*2*z;
}
float CSACone(int x, int y){
    return pie*x*y;
}
float CSASphere(float x){
    return 4*pie*x*x;
}
float CSAHemisphere(float x){
    return 2*pie*x*x;
}
float CSACYLINDER(float x,float y){
    float n=2*pie*x*y;
    return n;
}
float TSACube(float x){
  return 6*x*x;
}
float TSACuboid(float x, float y,float z){
    return (x*z+y*z+x*y)*2;
}
float TSACylinder(float x,float y){
    return (x+y)*2*pie*x;
}
float TSACone(float y,float z){
    float l=sqrt(y*y+z*z);
    float n=pie*z*(l+z);
    return n;

}
float TSASphere(float x){
    return 4*pie*x*x;
}
float TSAHemisphere(float x){
    return 3*pie*x*x;
}
float VOLCube(float x){
    return x*x*x;
}
float VOLCuboid(float x,float y,float z){
    return x*y*z;
}
float VOLCylinder(float x,float y){
    return (pie*x*x*y);
}
float VOLCone(float x,float y){
    return (1/3*pie*x*x*y);
}
float VOLSphere(float x){
    
    return (1.3333*pie*x*x*x);
}
float VOLhemisphere(float x){
    float z=0.6666*pie*x*x*x;
    return (z);
}
// Function to convert Kilometers to Meters
double kilometersToMeters(double kilometers) {
    return kilometers * 1000;
}

// Function to convert Meters to Kilometers
double metersToKilometers(double meters) {
    return meters / 1000;
}

// Function to convert Centimeters to Meters
double centimetersToMeters(double centimeters) {
    return centimeters / 100;
}

// Function to convert Meters to Centimeters
double metersToCentimeters(double meters) {
    return meters * 100;
}

// Function to convert Feet to Meters
double feetToMeters(double feet) {
    return feet * 0.3048;
}

// Function to convert Meters to Feet
double metersToFeet(double meters) {
    return meters / 0.3048;
}

// Function to convert Inches to Centimeters
double inchesToCentimeters(double inches) {
    return inches * 2.54;
}

// Function to convert Centimeters to Inches
double centimetersToInches(double centimeters) {
    return centimeters / 2.54;
}

// Function to convert Square Kilometers to Square Meters
double squareKilometersToSquareMeters(double squareKilometers) {
    return squareKilometers * 1000000;
}

// Function to convert Square Meters to Square Kilometers
double squareMetersToSquareKilometers(double squareMeters) {
    return squareMeters / 1000000;
}

// Function to convert Square Feet to Square Meters
double squareFeetToSquareMeters(double squareFeet) {
    return squareFeet * 0.092903;
}

// Function to convert Square Meters to Square Feet
double squareMetersToSquareFeet(double squareMeters) {
    return squareMeters / 0.092903;
}

// Function to convert Hectares to Acres
double hectaresToAcres(double hectares) {
    return hectares * 2.47105;
}

// Function to convert Acres to Hectares
double acresToHectares(double acres) {
    return acres / 2.47105;
}

// Function to convert Kilograms to Grams
double kilogramsToGrams(double kilograms) {
    return kilograms * 1000;
}

// Function to convert Grams to Kilograms
double gramsToKilograms(double grams) {
    return grams / 1000;
}

// Function to convert Milligrams to Grams
double milligramsToGrams(double milligrams) {
    return milligrams / 1000;
}

// Function to convert Grams to Milligrams
double gramsToMilligrams(double grams) {
    return grams * 1000;
}

// Function to convert Pounds to Kilograms
double poundsToKilograms(double pounds) {
    return pounds * 0.453592;
}

// Function to convert Kilograms to Pounds
double kilogramsToPounds(double kilograms) {
    return kilograms / 0.453592;
}

// Function to convert Ounces to Grams
double ouncesToGrams(double ounces) {
    return ounces * 28.3495;
}

// Function to convert Grams to Ounces
double gramsToOunces(double grams) {
    return grams / 28.3495;
}

// Function to convert Kilometers per Hour to Miles per Hour
double kilometersPerHourToMilesPerHour(double kilometersPerHour) {
    return kilometersPerHour * 0.621371;
}

// Function to convert Miles per Hour to Kilometers per Hour
double milesPerHourToKilometersPerHour(double milesPerHour) {
    return milesPerHour / 0.621371;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Seconds to Minutes
double secondsToMinutes(double seconds) {
    return seconds / 60;
}

// Function to convert Minutes to Seconds
double minutesToSeconds(double minutes) {
    return minutes * 60;
}

// Function to convert Hours to Minutes
double hoursToMinutes(double hours) {
    return hours * 60;
}

// Function to convert Minutes to Hours
double minutesToHours(double minutes) {
    return minutes / 60;
}

// Function to perform unit conversions based on user input
void performConversions() {
    int choice;
    double value;

    cout << "Conversion Calculator" << endl;
    cout << "1. Length" << endl;
    cout << "2. Area" << endl;
    cout << "3. Mass" << endl;
    cout << "4. Speed" << endl;
    cout << "5. Temperature" << endl;
    cout << "6. Time" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    cout << "Enter the value to convert: ";
    cin >> value;

    double result;

    switch (choice) {
        case 1: // Length conversions
            cout << "Select the conversion type:" << endl;
            cout << "1. Kilometers to Meters" << endl;
            cout << "2. Meters to Kilometers" << endl;
            cout << "3. Centimeters to Meters" << endl;
            cout << "4. Meters to Centimeters" << endl;
            cout << "5. Feet to Meters" << endl;
            cout << "6. Meters to Feet" << endl;
            cout << "7. Inches to Centimeters" << endl;
            cout << "8. Centimeters to Inches" << endl;
            cout << "Enter your choice (1-8): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    result = kilometersToMeters(value);
                    cout << value << " Kilometers = " << result << " Meters" << endl;
                    break;
                case 2:
                    result = metersToKilometers(value);
                    cout << value << " Meters = " << result << " Kilometers" << endl;
                    break;
                case 3:
                    result = centimetersToMeters(value);
                    cout << value << " Centimeters = " << result << " Meters" << endl;
                    break;
                case 4:
                    result = metersToCentimeters(value);
                    cout << value << " Meters = " << result << " Centimeters" << endl;
                    break;
                case 5:
                    result = feetToMeters(value);
                    cout << value << " Feet = " << result << " Meters" << endl;
                    break;
                case 6:
                    result = metersToFeet(value);
                    cout << value << " Meters = " << result << " Feet" << endl;
                    break;
                case 7:
                    result = inchesToCentimeters(value);
                    cout << value << " Inches = " << result << " Centimeters" << endl;
                    break;
                case 8:
                    result = centimetersToInches(value);
                    cout << value << " Centimeters = " << result << " Inches" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            break;

        case 2: // Area conversions
            cout << "Select the conversion type:" << endl;
            cout << "1. Square Kilometers to Square Meters" << endl;
            cout << "2. Square Meters to Square Kilometers" << endl;
            cout << "3. Square Feet to Square Meters" << endl;
            cout << "4. Square Meters to Square Feet" << endl;
            cout << "5. Hectares to Acres" << endl;
            cout << "6. Acres to Hectares" << endl;
            cout << "Enter your choice (1-6): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    result = squareKilometersToSquareMeters(value);
                    cout << value << " Square Kilometers = " << result << " Square Meters" << endl;
                    break;
                case 2:
                    result = squareMetersToSquareKilometers(value);
                    cout << value << " Square Meters = " << result << " Square Kilometers" << endl;
                    break;
                case 3:
                    result = squareFeetToSquareMeters(value);
                    cout << value << " Square Feet = " << result << " Square Meters" << endl;
                    break;
                case 4:
                    result = squareMetersToSquareFeet(value);
                    cout << value << " Square Meters = " << result << " Square Feet" << endl;
                    break;
                case 5:
                    result = hectaresToAcres(value);
                    cout << value << " Hectares = " << result << " Acres" << endl;
                    break;
                case 6:
                    result = acresToHectares(value);
                    cout << value << " Acres = " << result << " Hectares" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            break;

        case 3: // Mass conversions
            cout << "Select the conversion type:" << endl;
            cout << "1. Kilograms to Grams" << endl;
            cout << "2. Grams to Kilograms" << endl;
            cout << "3. Milligrams to Grams" << endl;
            cout << "4. Grams to Milligrams" << endl;
            cout << "5. Pounds to Kilograms" << endl;
            cout << "6. Kilograms to Pounds" << endl;
            cout << "7. Ounces to Grams" << endl;
            cout << "8. Grams to Ounces" << endl;
            cout << "Enter your choice (1-8): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    result = kilogramsToGrams(value);
                    cout << value << " Kilograms = " << result << " Grams" << endl;
                    break;
                case 2:
                    result = gramsToKilograms(value);
                    cout << value << " Grams = " << result << " Kilograms" << endl;
                    break;
                case 3:
                    result = milligramsToGrams(value);
                    cout << value << " Milligrams = " << result << " Grams" << endl;
                    break;
                case 4:
                    result = gramsToMilligrams(value);
                    cout << value << " Grams = " << result << " Milligrams" << endl;
                    break;
                case 5:
                    result = poundsToKilograms(value);
                    cout << value << " Pounds = " << result << " Kilograms" << endl;
                    break;
                case 6:
                    result = kilogramsToPounds(value);
                    cout << value << " Kilograms = " << result << " Pounds" << endl;
                    break;
                case 7:
                    result = ouncesToGrams(value);
                    cout << value << " Ounces = " << result << " Grams" << endl;
                    break;
                case 8:
                    result = gramsToOunces(value);
                    cout << value << " Grams = " << result << " Ounces" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            break;

        case 4: // Speed conversions
            cout << "Select the conversion type:" << endl;
            cout << "1. Kilometers per Hour to Miles per Hour" << endl;
            cout << "2. Miles per Hour to Kilometers per Hour" << endl;
            cout << "Enter your choice (1-2): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    result = kilometersPerHourToMilesPerHour(value);
                    cout << value << " Kilometers per Hour = " << result << " Miles per Hour" << endl;
                    break;
                case 2:
                    result = milesPerHourToKilometersPerHour(value);
                    cout << value << " Miles per Hour = " << result << " Kilometers per Hour" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            break;

        case 5: // Temperature conversions
            cout << "Select the conversion type:" << endl;
            cout << "1. Celsius to Fahrenheit" << endl;
            cout << "2. Fahrenheit to Celsius" << endl;
            cout << "3. Celsius to Kelvin" << endl;
            cout << "4. Kelvin to Celsius" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    result = celsiusToFahrenheit(value);
                    cout << value << " Celsius = " << result << " Fahrenheit" << endl;
                    break;
                case 2:
                    result = fahrenheitToCelsius(value);
                    cout << value << " Fahrenheit = " << result << " Celsius" << endl;
                    break;
                case 3:
                    result = celsiusToKelvin(value);
                    cout << value << " Celsius = " << result << " Kelvin" << endl;
                    break;
                case 4:
                    result = kelvinToCelsius(value);
                    cout << value << " Kelvin = " << result << " Celsius" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            break;

        case 6: // Time conversions
            cout << "Select the conversion type:" << endl;
            cout << "1. Seconds to Minutes" << endl;
            cout << "2. Minutes to Seconds" << endl;
            cout << "3. Hours to Minutes" << endl;
            cout << "4. Minutes to Hours" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    result = secondsToMinutes(value);
                    cout << value << " Seconds = " << result << " Minutes" << endl;
                    break;
                case 2:
                    result = minutesToSeconds(value);
                    cout << value << " Minutes = " << result << " Seconds" << endl;
                    break;
                case 3:
                    result = hoursToMinutes(value);
                    cout << value << " Hours = " << result << " Minutes" << endl;
                    break;
                case 4:
                    result = minutesToHours(value);
                    cout << value << " Minutes = " << result << " Hours" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            break;

        default:
            cout << "Invalid choice!" << endl;
    }
}


int main(){
    
    cout<<"1 is for Basic maths"<<endl;
    cout<<"2 is for Advanced maths like trignometry matrix factorial logrithm exponential "<<endl;
    cout<<"3 for Conversions"<<endl;
    cout<<"4 for AREA (CSA & TSA)"<<endl;
    cout<<"5 for Volume"<<endl;
    cout<<"6 for EXIT"<<endl;
    cout<<"Enter your choice (1-6)"<<endl;
    int button;
    cin>>button;
    int x,y,z;
    int saiyan;//3 program
    int super;//2 program
    int Basic;
    int area;
    int volume;
    int champu;//general program
    switch (button)
    {
    case 1:
            cout<<"1 is for addition "<<endl;
            cout<<"2 is for subtraction "<<endl;
            cout<<"3 is for multiplication "<<endl;
            cout<<"4 is for division "<<endl;
            cout<<"5 is for power "<<endl;
            cout<<"Enter your choice (1-5) "<<endl;        
            cin>>Basic;
        switch(Basic){
            case 1:
                cout<<"Enter values of two numbers ";
                cin>>x>>y;
                cout<<ADDition(x,y)<<endl;
                break;
            case 2:
                cout<<"Enter values of two numbers ";
                cin>>x>>y;
                cout<<subtraction(x,y)<<endl;
                break;
            case 3:
                cout<<"Enter values of two numbers ";
                cin>>x>>y;
                cout<<multiplication(x,y)<<endl;
                break;
            case 4:
                cout<<"Enter values of dividend and divisior ";
                cin>>x>>y;
                cout<<Division(x,y)<<endl;
                break;
            case 5:
                cout<<"Enter values of base and power ";
                cin>>x>>y;
                cout<<pow(x,y)<<endl;
                break;
            default :
                cout<<"Pls see the statements first ";
                break;
        }
        
       
    case 2:
        cout<<"1 is for trigometric function"<<endl;
        cout<<"2 is for logarithm "<<endl;
        cout<<"3 is exponential"<<endl;
        cout<<"4 is for factorial of a number"<<endl;
        cout<<"5 is for matrix"<<endl;
        cout<<"Enter your choice (1-5) "<<endl;
        cin>>super;
        switch(super){
            case 1 :
            cout<<"1 is to convert sin"<<endl;
            cout<<"2 is to convert cos"<<endl;
            cout<<"3 is to convert tan"<<endl;
            cout<<"4 is to convert sec"<<endl;
            cout<<"5 is to convert cosec"<<endl;
            cout<<"6 is to convert cot"<<endl;
            cout<<"Enter your choice (1-6) "<<endl;
            cout<<"Note :- Enter the value in radians only";
            cin>>saiyan;
            switch(saiyan){
                case 1:
                cout<<" Enter the angle ";
                cin>>x;
                cout<<sine(x)<<endl;
                break;
                case 2:
                cout<<" Enter the angle ";
                cin>>x;
                cout<<cosine(x)<<endl;
                break;
                case 3:
                cout<<" Enter the angle ";
                cin>>x;
                cout<<tangent(x)<<endl;
                break;
                case 4:
                cout<<" Enter the angle ";
                cin>>x;
                cout<<secant(x)<<endl;
                break;
                case 5:
                cout<<" Enter the angle ";
                cin>>x;
                cout<<cosecant(x)<<endl;
                break;
                case 6:
                cout<<" Enter the angle ";
                cin>>x;
                cout<<cotangent(x)<<endl;
                break;


            }
            case 2:
            cout<<"Enter value for x and base ";
            cin>>x>>y;
            cout<<logarithm(x,y)<<endl;
            break;
            case 3:
            cout<<"Enter value for exponential ";
            cin>>x;
            cout<<exponential(x)<<endl;
            break;
            case 4: 
            cout<<"Enter the number to find factorial ";
            cin>>x;
            cout<<factorial(x);
            break;
            case 5:
            int matrix1[10][10], matrix2[10][10], result[10][10], transpose[10][10];
    int row1, col1, row2, col2;
    int choice;

    cout << "Enter the dimensions of the first matrix (row column): ";
    cin >> row1 >> col1;
    inputMatrix(matrix1, row1, col1);

    cout << "Enter the dimensions of the second matrix (row column): ";
    cin >> row2 >> col2;
    inputMatrix(matrix2, row2, col2);

    cout << "Choose an operation:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Transpose\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            if (row1 == row2 && col1 == col2) {
                addMatrix(matrix1, matrix2, result, row1, col1);
                displayMatrix(result, row1, col1);
            } else {
                cout << "Error: The matrices must have the same dimensions for addition.\n";
            }
            break;
        case 2:
            if (row1 == row2 && col1 == col2) {
                subtractMatrix(matrix1, matrix2, result, row1, col1);
                displayMatrix(result, row1, col1);
            } else {
                cout << "Error: The matrices must have the same dimensions for subtraction.\n";
            }
            break;
        case 3:
            if (col1 == row2) {
                multiplyMatrix(matrix1, matrix2, result, row1, col1, col2);
                displayMatrix(result, row1, col2);
            } else {
                cout << "Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.\n";
            }
            break;
        case 4:
            transposeMatrix(matrix1, transpose, row1, col1);
            displayMatrix(transpose, col1, row1);
            break;
        case 5:
            double matrix[10][10], inverse[10][10];
    int n;

    cout << "Enter the dimension of the matrix: ";
    cin >> n;

    inputMatrix(matrix, n);

    if (invertMatrix(matrix, inverse, n)) {
        cout << "Inverse of the matrix:\n";
        displayMatrix(inverse, n);
    } else {
        cout << "The matrix is not invertible.\n";
    }
        
        default:
            cout << "Invalid choice!\n";
            break;
    }


        }
        
        break;
    case 3:
        performConversions();
    
    case 4:
        cout<<"1 is for Area of 2d shapes"<<endl;
        cout<<"2 is for TSA(Total Suraface area) of 3D shapes"<<endl;
        cout<<"3 is for CSA(Curved surafce area) of 3D shapes"<<endl;
        cout<<"Enter your choice (1-3) "<<endl;
        cin>>area;
        switch(area){
            case 1 :
            cout<<"1 is for area of Square"<<endl;
            cout<<"2 is for area of Rectangle"<<endl;
            cout<<"3 is for area of Triangle"<<endl;
            cout<<"4 is for area of Circle"<<endl;
            cout<<"5 is for area of Rhombus"<<endl;
            cout<<"6 is for area of Parallelogram"<<endl;
            cout<<"7 is for area of Trapezium"<<endl;
            cout<<"8 is for area of Ring"<<endl;
            cout<<"9 is for area of Semicircle"<<endl;
            cout<<"Enter your choice (1-9) "<<endl;
            cin>>area;
            switch (area){
                case 1:
                    cout<<"Enter value of side";
                    cin>>x;
                    cout<<AreaSquare(x)<<endl;
                break;
                case 2:
                cout<<"Enter value of length and breath";
                cin>>x>>y;
                cout<<AreaRectangle(x,y)<<endl;
                break;
                case 3:
                cout<<"Enter value of base and height";
                cin>>x>>y;
                cout<<AreaTriangle(x,y)<<endl;
                break;
                case 4:
                cout<<"Enter value of Radius";
                cin>>x;
                cout<<AreaCircle(x)<<endl;
                break;
                case 5:
                cout<<"Enter value of 1st diagonal and 2nd diagonal";
                cin>>x>>y;
                cout<<AreaRhombus(x,y)<<endl;
                break;
                case 6:
                cout<<"Enter value of base and height";
                cin>>x>>y;
                cout<<AreaParallelogram(x,y)<<endl;
                break;
                case 7:
                cout<<"Enter value of base1 ,base 2 and height";
                cin>>x>>y>>z;
                cout<<AreaTrapezium(x,y,z)<<endl;
                break;
                case 8:
                cout<<"Enter value of outer radius and inner radius";
                cin>>x>>y;
                cout<<AreaRing(x,y)<<endl;
                break;
                case 9:
                cout<<"Enter value of Radius";
                cin>>x;
                cout<<Areasemicircle(x)<<endl;
                break;
                default :
                cout<<"Pls see the statements first ";
                break;
            }
            
            case 2 :
            cout<<"1 is for TSA of Cube"<<endl;
            cout<<"2 is for TSA of Cuboid"<<endl;
            cout<<"3 is for TSA of Cylinder"<<endl;
            cout<<"4 is for TSA of Cone"<<endl;
            cout<<"5 is for TSA of Sphere"<<endl;
            cout<<"6 is for TSA of Hemisphere"<<endl;
            cout<<"Enter your choice (1-6) "<<endl;
            cin>>area;
            switch(area){
                case 1:
                cout<<"Enter value of side";
                cin>>x;
                cout<<TSACube(x)<<endl;
                break;
                case 2:
                cout<<"Enter value of length breadth and height";
                cin>>x>>y>>z;
                cout<<TSACuboid(x,y,z)<<endl;
                break;
                case 3:
                cout<<"Enter value of radius and height";
                cin>>x>>y;
                cout<<TSACylinder(x,y)<<endl;
                break;
                case 4:
                cout<<"Enter value of radius and height";
                cin>>x>>y;
                cout<<TSACone(x,y)<<endl;
                break;
                case 5:
                cout<<"Enter value of radius";
                cin>>x;
                cout<<TSASphere(x)<<endl;
                break;
                case 6:
                cout<<"Enter value of radius";
                cin>>x;
                cout<<TSAHemisphere(x)<<endl;
                break;
                default :
                cout<<"Pls see the statements first ";
                break;
            }
            

            case 3 :
            cout<<"1 is for CSA of Cube"<<endl;
            cout<<"2 is for CSA of Cuboid"<<endl;
            cout<<"3 is for CSA of Cylinder"<<endl;
            cout<<"4 is for CSA of Cone"<<endl;
            cout<<"5 is for CSA of Sphere"<<endl;
            cout<<"6 is for CSA of Hemisphere"<<endl;
            cout<<"Enter your choice (1-6) "<<endl;
            cin>>area;
            switch(area){
                case 1:
                cout<<"Enter value of side";
                cin>>x;
                cout<<CSACube(x)<<endl;
                break;
                case 2:
                cout<<"Enter value of length breadth and height";
                cin>>x>>y>>z;
                cout<<CSACuboid(x,y,z)<<endl;
                break;
                case 3:
                cout<<"Enter value of radius and height";
                cin>>x>>y;
                cout<<CSACYLINDER(x,y)<<endl;
                break;
                case 4:
                cout<<"Enter value of radius and height";
                cin>>x>>y;
                cout<<CSACone(x,y)<<endl;
                break;
                case 5:
                cout<<"Enter value of radius";
                cin>>x;
                cout<<CSASphere(x)<<endl;
                break;
                case 6:
                cout<<"Enter value of radius";
                cin>>x;
                cout<<CSAHemisphere(x)<<endl;
                break;
                default :
                cout<<"Pls see the statements first ";
                break;
            }
        }

        
    case 5:
        cout<<"1 is for volume of Cube"<<endl;
        cout<<"2 is for volume of Cuboid"<<endl;
        cout<<"3 is for volume of Cylinder"<<endl;
        cout<<"4 is for volume of Cone"<<endl;
        cout<<"5 is for volume of Sphere"<<endl;
        cout<<"6 is for volume of Hemisphere"<<endl;
        cout<<"Enter your choice (1-6)"<<endl;
        cin>>volume;
        switch(volume){
            case 1:
                cout<<"Enter value of side "<<endl;
                cin>>x;
                cout<<VOLCube(x)<<endl<<endl;
                break;
            case 2:
                cout<<"Enter value of length base height "<<endl;
                cin>>x>>y>>z;
                cout<<VOLCuboid(x,y,z)<<endl<<endl;
                break;
            case 3:
                cout<<"Enter value of length and height "<<endl;
                cin>>x>>y;
                cout<<VOLCylinder(x,y)<<endl;
                break;
            case 4:
                cout<<"Enter value of length and base "<<endl;
                cin>>x>>y;
                cout<<VOLCone(x,y)<<endl;
                break;
            case 5:
                cout<<"Enter value of radius "<<endl;
                cin>>x;
                cout<<VOLSphere(x)<<endl;
                break;
            case 6:
                cout<<"Enter value of radius "<<endl;
                cin>>x;
                cout<<VOLhemisphere(x)<<endl;
                break;
            default :
                cout<<"Pls see the statements first "<<endl;
                break;
        }
        

    case 6:
        cout<<"Thank you for choosing our calculator"<<endl;
        break;
    default:
        cout<<"Pls see the statements first";
        break;
    }

}