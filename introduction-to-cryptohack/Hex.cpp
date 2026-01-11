#include <iostream>
#include <string>

void decimalToHex( int number ){
    if( number == 0 ){
        std::cout << "0\n";
        return;
    }
    
    std::string hexNumber{};
    
    while( number > 0 ){
        int remainder{ number % 16 };
        char hexDigit;
        
        if( remainder < 10 ){
            hexDigit = '0' + remainder;//convert to char '0'-'9'
        }
        else{
            hexDigit = 'A' + (remainder - 10);//convert to char 'A'-'F'
        }
        
        hexNumber = hexDigit + hexNumber;
        number /= 16;
    }
    
    std::cout << hexNumber << std::endl;
}

void asciiToHex( const std::string& text ){
    //convert ascii to hex
    for( const auto& ch : text ){
        int asciiValue{ static_cast<int>(ch) };
        decimalToHex(asciiValue);
    }
}

int hexCharToDecimal( char hexChar ){
    //convert single hex char to decimal
    if( hexChar >= '0' && hexChar <= '9' ){
        return hexChar - '0';
    }
    else if( hexChar >= 'A' && hexChar <= 'F' ){
        return hexChar - 'A' + 10;
    }
    else if( hexChar >= 'a' && hexChar <= 'f' ){
        return hexChar - 'a' + 10;
    }
    return -1;//invalid hex
}

void hexToAscii( const std::string& hexString ){
    //convert hex to ascii char
    if( hexString.length() % 2 != 0 ){
        std::cout << "Invalid hex string (must have even number of characters)\n";
        return;
    }
    
    for( size_t i{0}; i < hexString.length(); i += 2 ){
        int highNibble{ hexCharToDecimal(hexString[i]) };
        int lowNibble{ hexCharToDecimal(hexString[i + 1]) };
        
        if( highNibble == -1 || lowNibble == -1 ){
            std::cout << "Invalid hex character in string\n";
            return;
        }
        
        int asciiValue{ highNibble * 16 + lowNibble };
        std::cout << static_cast<char>(asciiValue);
    }
    std::cout << std::endl;
}

int main(){
    int choice{};
    std::cout << "Choose conversion:\n";
    std::cout << "1. Decimal to Hex\n";
    std::cout << "2. ASCII string to Hex\n";
    std::cout << "3. Hex to ASCII\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore();
    
    if( choice == 1 ){
        int number{};
        std::cout << "Enter decimal number: ";
        std::cin >> number;
        decimalToHex(number);
    }
    else if( choice == 2 ){
        std::string text{};
        std::cout << "Enter ASCII string: ";
        std::getline(std::cin, text);
        asciiToHex(text);
    }
    else if( choice == 3 ){
        std::string hexString{};
        std::cout << "Enter hex string: ";
        std::getline(std::cin, hexString);
        hexToAscii(hexString);
    }
    else{
        std::cout << "Invalid choice\n";
    }
    
return 0;
}
