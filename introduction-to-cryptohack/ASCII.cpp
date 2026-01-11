//convert numbers to corresponding ASCII characters
#include <vector>
#include <iostream>//for cin, cout
#include <string>//for input

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
    std::string input;
    while(std::cin >> input){
        if( input == "*" ) break;
        
        if( input == "x" ){
            if( !userNumberVector.empty() ){
                std::cout << "Deleted: " << userNumberVector.back() << '\n';
                userNumberVector.pop_back();
            }else{
                std::cout << "Nothing to delete\n";
            }
            continue;
        }
        
        try{
            int num = std::stoi(input);
            userNumberVector.push_back(num);
            std::cout << "Logged: " << num << '\n';
        }catch( const std::invalid_argument& ){
            std::cout << "Invalid input, enter a number, 'x', or '*'\n";
        }catch( const std::out_of_range& ){
            std::cout << "Number out of range\n";
        }
    }
    printASCII(userNumberVector);

return 0;
}
