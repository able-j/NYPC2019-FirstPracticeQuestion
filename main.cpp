#include <iostream>
#include <string>

using namespace std;

void passwordValidate(string& password) {
	int length = password.length();

	bool lowercase = false;
	bool uppercase = false;
	bool numbers = false;
	bool specialChars = false;

	string englishChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < length; i++) {
		if (islower(password[i])) {
			lowercase = true;
		}
		if (isupper(password[i])) {
			uppercase = true;
		}
		if (isdigit(password[i])) {
			numbers = true;
		}

		size_t special = password.find_first_not_of(englishChars);

		if (special != string::npos) {
			specialChars = true;
		}
	}

	if (lowercase && uppercase && numbers && specialChars && length >= 8 && length <= 15) {
		cout << "valid" << endl;
	}
	else {
		cout << "invalid" << endl;
	}
}

int main() {
	string password;
	cin >> password;
	passwordValidate(password);

	return 0;
}
