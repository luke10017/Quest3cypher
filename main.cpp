

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

            return "test";
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
    return 0;
}