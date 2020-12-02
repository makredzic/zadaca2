#include <math.h>
#include <functional>
#include <iostream>
#include <vector>

// Adds user input to `number` parameter passed by ref
// Returns user input
double add(double& number) {
  double input;
  std::cout << "Number to add: ";
  std::cin >> input;
  std::cin.ignore();
  number += input;
  return input;
}

int main(void) {
  double number = 0;
  std::vector<std::function<double()>> undoFunctions;
  std::vector<std::function<double()>> redoFunctions;
  int choice = -1;
  while (choice != 9) {
    std::cout << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << "New value: " << number << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Subtract" << std::endl;
    std::cout << "3. Multiply" << std::endl;
    std::cout << "4. Divide" << std::endl;
    std::cout << "5. Square" << std::endl;
    std::cout << "6. Square root" << std::endl;
    std::cout << "7. Undo" << std::endl;
    std::cout << "8. Redo" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();
    if (choice == 1) {
      auto input = add(number);
      undoFunctions.push_back([input, &number]() {
        auto oldNumber = number;
        number -= input;
        return oldNumber;
      });  // why is it necessary to copy `input` into the lambda? why is number
           // by reference okay?
    } else if (choice == 2) {
      //
      // Your code here...
      //
    } else if (choice == 3) {
      //
      // Your code here...
      //
    } else if (choice == 4) {
      //
      // Your code here...
      //
    } else if (choice == 5) {
      //
      // Your code here...
      //
    } else if (choice == 6) {
      //
      // Your code here...
      //
    } else if (choice == 7) {
      if (!undoFunctions.empty()) {
        std::cout << std::endl;
        std::cout << "Undoing..." << std::endl;
        std::cout << std::endl;
        auto& undoFunction = undoFunctions.back();
        // 
        // Your code here...
        //
        undoFunctions.pop_back();
      } else {
        std::cout << "Nothing to undo!" << std::endl;
      }
    } else if (choice == 8) {
      if (!redoFunctions.empty()) {
        std::cout << std::endl;
        std::cout << "Redoing..." << std::endl;
        std::cout << std::endl;
        //
        // Your code here...
        //
      } else {
        std::cout << "Nothing to redo" << std::endl;
      }
    }
  }

  return 0;
}
