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

bool parseInput( const std::string& input, int& result ){
    //attempts to convert string to int: returns true iff success
    try{
        result = std::stoi(input);
        return true;
    }catch( const std::invalid_argument& ){
        std::cout << "Invalid input, enter a number, 'x', or '*'\n";
        return false;
    }catch( const std::out_of_range& ){
        std::cout << "Number out of range\n";
        return false;
    }
}

void handleDelete( std::vector<int>& vec ){
    //delete last element from vector if not empty
    if( !vec.empty() ){
        std::cout << "Deleted: " << vec.back() << '\n';
        vec.pop_back();
    }else{
        std::cout << "Nothing to delete\n";
    }
}

void handleNumericInput( const std::string& input, std::vector<int>& vec ){
    //parse input and add to vector if valid
    int num;
    if( parseInput(input, num) ){
        vec.push_back(num);
        std::cout << "Logged: " << num << '\n';
    }
}

void collectNumbers( std::vector<int>& vec ){
    //main input loop for collecting numbers
    std::cout << "Enter in your numbers to convert to ASCII(enter '*' to stop, or 'x' to delete last entry): ";
    std::string input;
    while( std::cin >> input ){
        if( input == "*" ) break;
        
        if( input == "x" ){
            handleDelete(vec);
            continue;
        }
        
        handleNumericInput(input, vec);
    }
}

int main(){

    std::vector<int> userNumberVector;
    collectNumbers(userNumberVector);
    printASCII(userNumberVector);

return 0;
}
