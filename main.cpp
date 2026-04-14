

#include <iostream>
#include <iomanip>
#include <string>

using  namespace std;

class CaesarCipher {
    public:   
        void setShiftValue(int value) {
            shiftValue = value;
        }
        string decode(const string& message) {
            int originalShift = shiftValue;
            
            //reverses the shift to decode
            shiftValue = 26 - shiftValue;
            string result = encode(message);
            
            shiftValue = originalShift;
            
            return result;
        }

    private:
        int shiftValue;
    protected:
        string encode(const string& message) {
            string test = "";

            for (char ch : message) { //for each character in the message
        
                if (ch >= 97 && ch <= 122) {
                    int shifted = ch + shiftValue;
                    while (shifted > 122) {
                        int extra = shifted - 122;
                        shifted = 96 + extra;
                    }
                    test += shifted;
                }
        
                else if (ch >= 65 && ch <= 90) {
                    int shifted = ch + shiftValue;
                    if (shifted > 90) {
                        int extra = shifted - 90;
                        shifted = 64 + extra;
                    }
                    test += shifted;
                }
        
                else {
                    test += ch;
                }
            }

            return test;
        }

};

class Rot13Cipher : public CaesarCipher {
    public:
        Rot13Cipher() {
            setShiftValue(13);
        }
        
};

class Encryptor : public CaesarCipher {
    public:
        string encryptMessage(const string& message, int shift) {
            setShiftValue(shift);
            return encode(message);
        }
};

int main() {
    cout << "Hello, World!" << endl;

    int role = 0;

    cout << "======" << "Cryptography Quest" << "======" << endl;
    
    while (role != 3) {
        

        cout << endl;

        cout << "1. Encryptor Persona" << endl;
        cout << "2. Decryptor Persona" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose role: ";
        cin >> role;

        if (role == 1) {
            string plaintext;
            int shift;

            cout << "Enter message to encrypt: ";
            cin.ignore(); 
            getline(cin, plaintext);

            cout << plaintext << endl;

            Encryptor encryptor;
            string encryptedMessage;

            cout << "Enter shift value (1-13): ";
            cin >> shift;
            cin.ignore();

            CaesarCipher cipher;
            while (shift < 1 || shift > 13) {
                cout << "Invalid shift value. Please enter a value between 1 and 13:" << endl;
                cin >> shift;
            }
            if (shift == 13) {
                cipher = Rot13Cipher();
                encryptedMessage = encryptor.encryptMessage(plaintext, shift);
                cout << "Encrypted message: " << encryptedMessage << endl;
            }
            else {
                cipher.setShiftValue(shift);
                encryptedMessage = encryptor.encryptMessage(plaintext, shift);
                cout << "Encrypted message: " << encryptedMessage << endl;
            }

            // Decrypt the message to verify via user choice
            int role2 = 0;
            while (role2 != 2) {
                cout << "Do you want to decrypt the message? (1 for Yes, 2 for No): ";
                cin >> role2;
                if (role2 == 1) {
                    cout << "Enter shift:" << endl;
                    int decryptShift;
                    cin >> decryptShift;
                    cipher.setShiftValue(decryptShift);
                    string decryptedMessage = cipher.decode(encryptedMessage);
                    cout << "Decrypted message: " << decryptedMessage << endl;
                    cipher.setShiftValue(shift); // Reset shift
                }
                else if (role2 != 2) {
                    cout << "Invalid choice. Enter 1 or 2: " << endl;
                }
            }



            //cout << "Encrypted message: " << encryptedMessage << endl;
            
            
        }

        else if (role == 2) {
            string captured;
            cout << "Enter captured encrypted message: \n";
            cin.ignore();
            getline(cin, captured);

            CaesarCipher cipher;
            cout << "Enter shift value used for encryption (1-13): ";
            int shift;
            cin >> shift;
            while (shift < 1 || shift > 13) {
                cout << "Invalid shift value. Please enter a value between 1 and 13:" << endl;
                cin >> shift;
            }
            if (shift == 13) {
                cipher = Rot13Cipher();
            }
            else {
            cipher.setShiftValue(shift);
            }

            string decryptedMessage = cipher.decode(captured);
            cout << "Decrypted message: " << decryptedMessage << endl;
            int role2 = 0;
            while (role2 != 2) {
                cout << "Do you want to try again? (1 for Yes, 2 for No): ";
                cin >> role2;
                if (role2 == 1) {
                    cout << "New shift value (1-13): ";
                    int newShift;
                    cin >> newShift;
                    while (newShift < 1 || newShift > 13) {
                        cout << "Invalid shift value. Please enter a value between 1 and 13:" << endl;
                        cin >> newShift;
                    }
                    cipher.setShiftValue(newShift);
                    decryptedMessage = cipher.decode(captured);
                    cout << "Decrypted message: " << decryptedMessage << endl;


                }
                else if (role2 != 2) {
                    cout << "Invalid choice. Enter 1 or 2: " << endl;
                }
            }

        }

        else if (role != 3) {
            cout << "Invalid choice. Enter 1-3: " << endl;
        }


    }
    

    
    // comment
    return 0;
}
