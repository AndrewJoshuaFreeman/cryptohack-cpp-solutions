//convert numbers to corresponding ASCII characters
#include <vector>
#include <iostream>//for cin, cout

void printASCII( const std::vector<int>& vec ){
    //prints out ASCII characters(int->char == ASCII)
    for( const auto& element : vec ){
        std::cout << static_cast<char>(element) << " ";
    }
    std::cout << '\n';
}

int main(){

    std::vector<int> userNumberVector;

    std::cout << "Enter in your numbers to convert to ASCII(enter '*' to stop, or 'x' to delete last entry): ";
    int input{};
    while( std::cin >> input ){

        if( input == '*' ) break;

        userNumberVector.push_back(input);
        std::cout << "Logged: " << input << '\n';
    }

    printASCII(userNumberVector);

return 0;
}
