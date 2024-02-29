#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

class Hotel {
private:
    std::vector<std::pair<bool, time_t>> rooms; // Represents the status and check-in time of each room

public:
    Hotel(int numRooms) : rooms(numRooms, { false, 0 }) {}

    void displayAvailableRooms() const {
        std::cout << "Available rooms: ";
        for (int i = 0; i < rooms.size(); ++i) {
            if (!rooms[i].first) {
                std::cout << i + 1 << " ";
            }
        }
        std::cout << std::endl;
    }

    void displayOccupiedRooms() const {
        std::cout << "Occupied rooms: ";
        for (int i = 0; i < rooms.size(); ++i) {
            if (rooms[i].first) {
                std::cout << i + 1 << " (Check-in time: " << formatCheckInTime(rooms[i].second) << ") ";
            }
        }
        std::cout << std::endl;
    }

    bool bookRoom(int roomNumber) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            std::cout << "Invalid room number!" << std::endl;
            return false;
        }

        if (rooms[roomNumber - 1].first) {
            std::cout << "Room " << roomNumber << " is already occupied." << std::endl;
            return false;
        }

        rooms[roomNumber - 1] = { true, std::time(0) };
        std::cout << "Room " << roomNumber << " booked successfully." << std::endl;
        return true;
    }

    bool checkOutRoom(int roomNumber) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            std::cout << "Invalid room number!" << std::endl;
            return false;
        }

        if (!rooms[roomNumber - 1].first) {
            std::cout << "Room " << roomNumber << " is not occupied." << std::endl;
            return false;
        }

        rooms[roomNumber - 1] = { false, 0 };
        std::cout << "Check out from Room " << roomNumber << " successful." << std::endl;
        return true;
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
    const int numRooms = 10; // You can change the number of rooms as needed
    Hotel hotel(numRooms);

    while (true) {
        std::cout << "1. Display available rooms\n"
            << "2. Display occupied rooms\n"
            << "3. Book a room\n"
            << "4. Check out\n"
            << "5. Exit\n";

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
            std::cout << "Exiting the program. Thank you!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}