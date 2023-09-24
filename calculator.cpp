#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <vector>
#include <unistd.h>

using namespace std;

class Calculator {
public:
    vector<pair<string, double>> calculations;  // Vector to store calculations
    Calculator();
    double evaluateExpression(const string& expression);

private:
    double calculate(double a, char op, double b);
    bool isOperator(char c);
};

class PersistenceManager {
public:
    PersistenceManager(Calculator& calc) : calculator(calc) {}

    void saveCalculationsToFile(const string& filename);
    vector<pair<string, double>> loadCalculationsFromFile(const string& filename);

private:
    Calculator& calculator;
};

Calculator::Calculator() {
    // Initialize calculations vector from the file "calculations.txt"
    PersistenceManager persistenceManager(*this);
    calculations = persistenceManager.loadCalculationsFromFile("calculations.txt");
}

double Calculator::calculate(double a, char op, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        // Add other operators as needed
        default: throw invalid_argument("Invalid operator");
    }
}

bool Calculator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double Calculator::evaluateExpression(const string& expression) {
    stack<double> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (c == ' ') continue;  // Ignore whitespace

        if (isdigit(c)) {
            double value = 0;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                value = value * 10 + (expression[i] - '0');
                ++i;
            }
            --i;  // Move back one position to account for the last character read
            values.push(value);
        } else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' &&
                   ((c == '+' || c == '-') && (operators.top() == '*' || operators.top() == '/'))) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(calculate(a, op, b));
            }
            operators.push(c);
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(calculate(a, op, b));
            }
            operators.pop();  // Remove the '('
        }
    }

    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(calculate(a, op, b));
    }

    double result = values.top();
    calculations.push_back(make_pair(expression, result));  // Store the calculation
    return result;
}

void PersistenceManager::saveCalculationsToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& calculation : calculator.calculations) {
            file << calculation.first << " = " << calculation.second << '\n';
        }
        file.close();
    }
}

vector<pair<string, double>> PersistenceManager::loadCalculationsFromFile(const string& filename) {
    vector<pair<string, double>> calculations;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return calculations; // Return an empty vector on file open failure
    }
    
    string line;
    while (getline(file, line)) {
        size_t equalsPos = line.find('=');
        if (equalsPos != string::npos) {
            string expression = line.substr(0, equalsPos);
            string resultStr = line.substr(equalsPos + 1);
            
            try {
                double result = stod(resultStr);
                calculations.push_back(make_pair(expression, result));
            } catch (const std::invalid_argument& e) {
                cerr << "Error parsing result in line: " << line << endl;
            } catch (const std::out_of_range& e) {
                cerr << "Result is out of range in line: " << line << endl;
            }
        }
    }
    
    file.close();
    return calculations;
}




int main() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        std::cerr << "Error getting current working directory" << std::endl;
    }
    // Create a Calculator instance
    Calculator calculator;
    PersistenceManager persistenceManager(calculator);  // Associate with the Calculator instance
    cout<<"Recently evaluated calculations"<<endl;
    for(auto& history:calculator.calculations) cout<<history.first<<" "<<history.second<<endl;

    // Enter a loop to continuously take user input until "exit" is entered
    while (true) {
        string expression;
        cout << "Enter an expression (or 'exit' to quit): ";
        getline(cin, expression);

        if (expression == "exit") {
            break;  // Exit the loop if "exit" is entered
        } else if (expression == "show") {
            vector<pair<string, double>> prevCalculations = persistenceManager.loadCalculationsFromFile("calculations.txt");
            for (auto& calc : prevCalculations) {
                cout << calc.first << " : " << calc.second << endl;
            }
        }

        double result = calculator.evaluateExpression(expression);
        cout << "Result of expression: " << expression << " = " << result << endl;
        persistenceManager.saveCalculationsToFile("calculations.txt");
    }
    return 0;
}


