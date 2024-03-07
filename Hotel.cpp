
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <map>

class Hotel {
private:
    struct Room {
        bool occupied;
        time_t checkInTime;
        double roomRate;
        std::string bedType; // Added to specify the type of bed in the room
    };

    std::vector<Room> rooms; // Represents the status, check-in time, and room rate of each room
    bool poolAvailable;
    bool barAvailable;
    bool breakfastCafeAvailable;

    std::map<std::string, double> breakfastMenu{
        {"Menu Item 1", 15.00}, // Price for Food A
        {"Menu Item 2", 12.00}, // Price for Food B
        {"Menu Item 3", 10.00}  // Price for Food C
    };

public:
    Hotel(int numSingleRooms, int numDoubleRooms)
        : rooms(numSingleRooms + numDoubleRooms, { false, 0, 0.0, "" }),
          poolAvailable(true), barAvailable(true), breakfastCafeAvailable(true) {

        // Initialize the first numSingleRooms as single beds and the rest as double beds
        for (int i = 0; i < numSingleRooms; ++i) {
            rooms[i].bedType = "Single Bed";
            rooms[i].roomRate = 80.0; // Adjust the rate for single beds
        }

        for (int i = numSingleRooms; i < numSingleRooms + numDoubleRooms; ++i) {
            rooms[i].bedType = "Double Bed";
            rooms[i].roomRate = 120.0; // Adjust the rate for double beds
        }
    }

    void displayAvailableRooms() const {
        std::cout << "Available rooms: \n";
        for (int i = 0; i < rooms.size(); ++i) {
            if (!rooms[i].occupied) {
                std::cout << "Room " << i + 1 << " (" << rooms[i].bedType << ") - $" << rooms[i].roomRate << "\n";
            }
        }
        std::cout << "\n";
    }

    void displayOccupiedRooms() const {
        std::cout << "Occupied rooms: ";
        for (int i = 0; i < rooms.size(); ++i) {
            if (rooms[i].occupied) {
                std::cout << "Room " << i + 1 << " (Check-in time: " << formatCheckInTime(rooms[i].checkInTime) << ") ";
            }
        }
        std::cout << "\n\n";
    }

    void displayFacilitiesStatus() const {
        std::cout << "Facilities status:\n"
            << "Pool: " << (poolAvailable ? "Available" : "Not available") << "\n"
            << "Bar: " << (barAvailable ? "Available" : "Not available") << "\n"
            << "Breakfast Cafe: " << (breakfastCafeAvailable ? "Available" : "Not available") << "\n";
    }

    bool bookRoom(int roomNumber) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            std::cout << "Invalid room number!" << "\n\n";
            return false;
        }

        if (rooms[roomNumber - 1].occupied) {
            std::cout << "Room " << roomNumber << " is already occupied." << "\n\n";
            return false;
        }

        rooms[roomNumber - 1] = { true, std::time(0), 100.0, "" }; // Set room rate to 100.0 (you can adjust this as needed)
        std::cout << "Room " << roomNumber << " booked successfully." << "\n\n";
        return true;
    }

    bool checkOutRoom(int roomNumber) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            std::cout << "Invalid room number!" << std::endl;
            return false;
        }

        if (!rooms[roomNumber - 1].occupied) {
            std::cout << "Room " << roomNumber << " is not occupied." << std::endl;
            return false;
        }

        double totalAmount = rooms[roomNumber - 1].roomRate;
        std::cout << "Checking out from Room " << roomNumber << " successful.\n";
        std::cout << "Room Charge: $" << totalAmount << std::endl;

        // Offer breakfast options and calculate total amount including breakfast
        totalAmount += handleBreakfastSelection();

        std::cout << "Total Amount: $" << totalAmount << std::endl;

        // Clear the room details after checkout
        rooms[roomNumber - 1] = { false, 0, 0.0, "" };
        return true;
    }

    void reservePool() {
        if (poolAvailable) {
            std::cout << "Pool reserved successfully." << std::endl;
            poolAvailable = false;
        }
        else {
            std::cout << "Pool is not available at the moment." << std::endl;
        }
    }

    void reserveBar() {
        if (barAvailable) {
            std::cout << "Bar reserved successfully." << std::endl;
            barAvailable = false;
        }
        else {
            std::cout << "Bar is not available at the moment." << std::endl;
        }
    }

    void reserveBreakfastCafe() {
        if (breakfastCafeAvailable) {
            std::cout << "Breakfast Cafe reserved successfully." << std::endl;
            breakfastCafeAvailable = false;
        }
        else {
            std::cout << "Breakfast Cafe is not available at the moment." << std::endl;
        }
    }

    double handleBreakfastSelection() {
        std::cout << "Breakfast Menu:\n"
            << "1. Menu Item 1 (3 eggs, hashbrowns, 2 pancakes) - $15.00\n"
            << "2. Menu Item 2 (Sandwich with egg, cheese, and bacon or sausage) - $12.00\n"
            << "3. Menu Item 3 (Oatmeal with blueberries and strawberries) - $10.00\n"
            << "Choose your breakfast (enter 0 if you don't want breakfast): ";

        int choice;
        std::cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            std::string foodSelection;
            switch (choice) {
            case 1:
                foodSelection = "Menu Item 1";
                break;
            case 2:
                foodSelection = "Menu Item 2";
                break;
            case 3:
                foodSelection = "Menu Item 3";
                break;
            }

            double breakfastCost = breakfastMenu[foodSelection];
            std::cout << "Selected Breakfast: " << foodSelection << " - $" << breakfastCost << std::endl;
            return breakfastCost;
        }
        else {
            return 0.0; // User opted not to have breakfast
        }
    }

    static std::string formatCheckInTime(time_t checkInTime) {
        std::tm timeStruct;
        localtime_s(&timeStruct, &checkInTime);
        std::stringstream ss;
        ss << std::put_time(&timeStruct, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
};

int main() {
    const int numSingleRooms = 5;
    const int numDoubleRooms = 5;
    Hotel hotel(numSingleRooms, numDoubleRooms);

    while (true) {
        std::cout << "1. Display available rooms\n"
            << "2. Display occupied rooms\n"
            << "3. Book a room\n"
            << "4. Check out\n"
            << "5. Reserve Pool\n"
            << "6. Reserve Bar\n"
            << "7. Reserve Breakfast Cafe\n"
            << "8. Display facilities status\n"
            << "9. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            hotel.displayAvailableRooms();
            break;
        case 2:
            hotel.displayOccupiedRooms();
            break;
        case 3:
            int bookRoomNumber;
            std::cout << "Enter the room number to book: ";
            std::cin >> bookRoomNumber;
            hotel.bookRoom(bookRoomNumber);
            break;
        case 4:
            int checkOutRoomNumber;
            std::cout << "Enter the room number to check out: ";
            std::cin >> checkOutRoomNumber;
            hotel.checkOutRoom(checkOutRoomNumber);
            break;
        case 5:
            hotel.reservePool();
            break;
        case 6:
            hotel.reserveBar();
            break;
        case 7:
            hotel.reserveBreakfastCafe();
            break;
        case 8:
            hotel.displayFacilitiesStatus();
            break;
        case 9:
            std::cout << "Exiting the program. Thank you!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
