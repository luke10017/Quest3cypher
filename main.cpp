

#include <iostream>
#include <iomanip>

using  namespace std;

class CaesarCipher {
    public:   
        void setShiftValue(int value) {
            shiftValue = value;
        }
        string decode(const string& message) {
            return "test";
        }

    private:
        int shiftValue;
    protected:
        string encode(const string& message) {
            string test = "";

            for (char ch : message) { //for each character in the message
        
                if (ch >= 97 && ch <= 122) {
                    int shifted = ch + shiftValue;
                    if (shifted > 122) {
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

int main() {
    cout << "Hello, World!" << endl;

    // comment
    return 0;
}
