#include <iostream>
#include <string>

using namespace std;

const int MAX_VISAS = 10;

class Passport {
protected:
    string firstName;
    string lastName;
    string nationality;
    int passportNumber;

public:
    Passport(const string& first, const string& last, const string& nation, int number)
        : firstName(first), lastName(last), nationality(nation), passportNumber(number) {}

    void Display() {
        cout << "Passport Information:" << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Passport Number: " << passportNumber << endl;
    }
};

class Visa {
public:
    string country;
    string type;

    Visa() : country(""), type("") {}

    Visa(const string& c, const string& t) : country(c), type(t) {}
};

class ForeignPassport : public Passport {
private:
    string foreignPassportNumber;
    Visa visas[MAX_VISAS];
    int visaCount;

public:
    ForeignPassport(const string& first, const string& last, const string& nation, int number, const string& foreignNumber)
        : Passport(first, last, nation, number), foreignPassportNumber(foreignNumber), visaCount(0) {}

    void AddVisa(const Visa& visa) {
        if (visaCount < MAX_VISAS) {
            visas[visaCount++] = visa;
        }
        else {
            cout << "Cannot add more visas. Maximum limit reached." << endl;
        }
    }

    void Display() {
        Passport::Display();
        cout << "Foreign Passport Number: " << foreignPassportNumber << endl;
        cout << "Visas:" << endl;
        for (int i = 0; i < visaCount; ++i) {
            cout << "Country: " << visas[i].country << ", Type: " << visas[i].type << endl;
        }
    }
};

int main() {
    Passport ukrainianPassport("Max", "Sar", "Ukrainian", 123456);
    ukrainianPassport.Display();

    ForeignPassport foreignPassport("Max", "Sar", "Ukrainian", 789012, "ABC123");
    foreignPassport.AddVisa(Visa("USA", "Tourist"));
    foreignPassport.AddVisa(Visa("Canada", "Business"));
    foreignPassport.Display();


}
