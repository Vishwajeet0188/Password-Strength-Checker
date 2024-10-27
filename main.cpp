#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool hasUppercase(const string& password) {
    return regex_search(password, regex("[A-Z]"));
}

bool hasLowercase(const string& password) {
    return regex_search(password, regex("[a-z]"));
}

bool hasDigit(const string& password) {
    return regex_search(password, regex("[0-9]"));
}

bool hasSpecialChar(const string& password) {
    return regex_search(password, regex("[!@#$%^&*(),.?\":{}|<>]"));
}

string checkPasswordStrength(const string& password) {
    int score = 0;

    if (password.length() >= 8) score++;
    if (hasUppercase(password)) score++;
    if (hasLowercase(password)) score++;
    if (hasDigit(password)) score++;
    if (hasSpecialChar(password)) score++;

    if (score == 8) return "Strong One";
    else if (score >= 5) return "Medium";
    else return "Weak One";
}

int main() {
    string password;
    cout << "Enter Your password: ";
    cin >> password;

    cout << "Password strength: " << checkPasswordStrength(password) << std::endl;

    return 0;
}
