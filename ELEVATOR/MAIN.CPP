#include <iostream>
#include <bitset>

#define MAX_FLOORS 10

// Function to shift the floor unit based on direction
void shiftFloorUnit(int &floorUnit, bool goingUp) {
    if (goingUp) {
        floorUnit <<= 1;
    }
    else {
        floorUnit >>= 1;
    }
}

// Function to perform AND operation between floor units
int performANDOperation(int floorUnit, int callUnit) {
    return floorUnit & callUnit;
}

int main() {
    int currentFloor, destinationFloor, elevatorPosition;
    char direction, continueChoice;
    int floorUnit = 1;
    int upCallUnit = 0, downCallUnit = 0;

    std::cout << "Enter the initial elevator position (1-" << MAX_FLOORS << "): ";
    std::cin >> elevatorPosition;

    while (true) {
        std::cout << "\nEnter your current floor (1-" << MAX_FLOORS << "): ";
        std::cin >> currentFloor;
        std::cout << "Enter 'u' for up or 'd' for down: ";
        std::cin >> direction;
        std::cout << "Enter your destination floor (1-" << MAX_FLOORS << "): ";
        std::cin >> destinationFloor;

        if (direction == 'u' || direction == 'U') {
            upCallUnit = 1 << (destinationFloor - 1);
        }
        else if (direction == 'd' || direction == 'D') {
            downCallUnit = 1 << (destinationFloor - 1);
        }
        else {
            std::cerr << "Invalid direction input. Please enter 'u' or 'd'.\n";
            continue;
        }

        floorUnit = 1 << (elevatorPosition - 1);

        std::cout << "\nElevator movement:\n";
        std::cout << "Elevator is currently at floor: " << elevatorPosition << "\n";
        std::cout << "User is at floor: " << currentFloor << "\n";

        // Move elevator to the user's current floor
        while (elevatorPosition != currentFloor) {
            bool goingUp = currentFloor > elevatorPosition;
            if (goingUp) {
                std::cout << "Elevator goes up\n";
                elevatorPosition++;
            }
            else {
                std::cout << "Elevator goes down\n";
                elevatorPosition--;
            }
            shiftFloorUnit(floorUnit, goingUp);
        }

        std::cout << "Elevator arrives at user's floor: " << currentFloor << "\n";

        // Move elevator to the destination floor
        while (currentFloor != destinationFloor) {
            bool goingUp = destinationFloor > currentFloor;
            if (goingUp) {
                std::cout << "Elevator goes up\n";
                currentFloor++;
                elevatorPosition++;
                shiftFloorUnit(floorUnit, true);
                if (performANDOperation(floorUnit, upCallUnit) > 0) {
                    std::cout << "Elevator stops at floor " << currentFloor << "\n";
                }
            }
            else {
                std::cout << "Elevator goes down\n";
                currentFloor--;
                elevatorPosition--;
                shiftFloorUnit(floorUnit, false);
                if (performANDOperation(floorUnit, downCallUnit) > 0) {
                    std::cout << "Elevator stops at floor " << currentFloor << "\n";
                }
            }
        }

        std::cout << "Elevator stops and eliminates response signal\n";
        std::cout << "You have reached your destination: Floor " << destinationFloor << "\n";
        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> continueChoice;

        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
    }

    std::cout << "Elevator program terminated.\n";
    return 0;
}