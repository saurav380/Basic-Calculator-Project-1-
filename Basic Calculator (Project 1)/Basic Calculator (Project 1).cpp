#include<iostream>
#include<cmath> 
#include<sstream>
#include<string>
#include<vector>

using namespace std;

// Function to store calculation history
vector <string> history;


// Function to perform addition
double add(double a, double b) {
	return a + b;

}

// Function to perform subtraction
double subtract(double a, double b) {
	return a - b;

}

// Function to perform multiplication
double multiply(double a, double b) {
	return a * b;

}

// Function to perform Division
double divide(double a, double b) {
	if (b != 0) {
		return a / b;
	}
	else {
		cout << "Error: Division by zero is undefined." << endl;
		return 0;

	}
}

// Function to perform exponentiation
double exponentiation(double a, double b) {
	return pow(a, b);
}

// Function to calculate square root
double squarerRoot(double a) {
	if (a >= 0) {
		return sqrt(a);
	}
	else {
		cout << " Error: Square root of a negative number is undefined." << endl;
		return 0;

	}
}

// Function to calculate cube root
double cubeRoot(double a) {
		return cbrt(a);
	
}

// Function to perform evaluate mathematical operations
double evaluateExpression(const string& expression) {
	stringstream ss(expression);
	double result;
	ss >> result;

	char op;
	double next;
	while (ss >> op >> next) {
		switch (op) {
		case '+':
			result += next;
			break;
		case'-':
			result -= next;
			break;
		case'*':
			result *= next;
			break;
		case'/':
			if (next != 0) {
				result /= next;
			}
			else {
				throw invalid_argument("Division by zero.");
			}
			break;
		default:
			throw invalid_argument("Invalid operator.");

		}
	}

	return result;
}

// Function for temperature conversion: Fahrenheit to Celsius

double fahrenheitToCelsius(double fahrenheit) {
	return (fahrenheit - 32) * 5 / 9;
}

// Function for distance conversion: Kilometers to Miles
double kilometersToMiles(double km) {
	return km * 0.621371;
}

// Function to display the calculation history
void displayHistory() {
	if (history.empty()) {
		cout << "No calculations Performed yet." << endl;
	}
	else {
		cout << "Calculation History:" << endl;
		for (const string& record : history) {
			cout << record << endl;
		}
	}
}
// Function to display the menu
void showMenu() {
	cout << "\n****** Basic Calculator ******" << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << "5. Exponentiation" << endl;
	cout << "6. Square Root" << endl;
	cout << "7. Cube Root" << endl;
	cout << "8. Evaluate Expression" << endl;
	cout << "9. View Calculation History" << endl;
	cout << "10. Unit Conversion" << endl;
	cout << "11. Exit" << endl;
	cout << "******************************" << endl;
	cout << "Enter your choice:";

}
// Function to display the unit conversion menu
void showConversionMenu() {
	cout << "\n****** Unit Conversion ******" << endl;
	cout << "1. Fahrenheit to Celsius" << endl;
	cout << "2. Kilometers to miles" << endl;
	cout << "3. Back to Main Menu" << endl;
	cout << "**********************************" << endl;
	cout << "Enter your choice:";
}

int main() {
	int choice;
	double num1, num2;

	do {
		showMenu();
		cin >> choice;

		switch (choice) {
		case 1: // Addition
			cout << "Enter two numbers:";
			cin >> num1 >> num2;
			cout << "Result:" << add(num1, num2) << endl;
			history.push_back(to_string(num1) + "+" + to_string(num2) + "=" + to_string(add(num1, num2)));
			break;

		case 2: // Subtraction
			cout << "Enter two numbers:";
			cin >> num1 >> num2;
			cout << "Result:" << subtract(num1, num2) << endl;
			history.push_back(to_string(num1) + " - " + to_string(num2) + " = " + to_string(subtract(num1, num2)));
			break;

		case 3: // Multiplication
			cout << "Enter two numbers:";
			cin >> num1 >> num2;
			cout << "Result:" << multiply(num1, num2) << endl;
			history.push_back(to_string(num1) + " * " + to_string(multiply(num1, num2)));
			break;

		case 4: // Division
			cout << "Enter two numbers:";
			cin >> num1 >> num2;
			cout << "Result:" << divide(num1, num2) << endl;
			history.push_back(to_string(num1) + " / " + to_string(num2) + " = " + to_string(divide(num1, num2)));
			break;

		case 5: // Exponentiation
			cout << "Enter base and exponent:";
			cin >> num1 >> num2;
			cout << "Result:" << exponentiation(num1, num2) << endl;
			history.push_back(to_string(num1) + " ^ " + to_string(num2) + "=" + to_string(exponentiation(num1, num2)));
			break;

		case 6: //Square Root
			cout << "Enter a number:";
			cin >> num1;
			cout << "Result:" << squarerRoot(num1) << endl;
			history.push_back("sqrt(" + to_string(num1) + ") = " + to_string(squarerRoot(num1)));
			break;

		case 7: // Cube Root
			cout << "Enter a number:";
			cin >> num1;
			cout << "Result:" << cubeRoot(num1) << endl;
			history.push_back("cbrt(" + to_string(num1) + ") = " + to_string(cubeRoot(num1)));
			break;

		case 8: {// Evaluate Expression
			cout << "Enter an expression:";
			cin.ignore(); //To clear the newline character from input buffer
			string expression;
			getline(cin, expression);
			try {
				double result = evaluateExpression(expression);
				cout << "Result:" << result << endl;
				history.push_back(expression + " = " + to_string(result));
			}
			catch (const invalid_argument& e) {
				cout << "Error:" << e.what() << endl;

			}
			break;
		}
		case 9: // View History
			displayHistory();
			break;

		case 10: {// Unit Conversion
			int conversionChoice;
			showConversionMenu();
			cin >> conversionChoice;
			switch (conversionChoice) {

				case 1: // Fahrenheit to Celsius
					cout << "Enter distance in kilometers:";
					cin >> num1;
					cout << "Result:" << fahrenheitToCelsius(num1) << "°C" << endl;
					history.push_back(to_string(num1) + " °F to °C =" + to_string(fahrenheitToCelsius(num1)));
					break;

				case 2:// Kilometers to Miles
					cout << "Enter distance in kilometers: ";
					cin >> num1;
					cout << "Result: " << kilometersToMiles(num1) << "miles" << endl;
					history.push_back(to_string(num1) + "km to miles = " + to_string(kilometersToMiles(num1)));
					break;

				case 3: // Back to Main Menu
					break;

				default:
					cout << "Invalid choice. " << endl;
			}
			break;
			}

		case 11: // Exit
			cout << "Exiting the calculator. Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;

		}
	} while (choice != 11); // Loop until the user choose to exit

	return 0;

}