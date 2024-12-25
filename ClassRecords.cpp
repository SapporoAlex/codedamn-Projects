#include <string>
#include <iostream>

// Creating a struct that will act like an object with attributes of each record
struct Record {
    int RollNo;
    std::string Name;
    std::string FathersName;
    std::string DOB;
    std::string Branch;
    int YearOfAdmission;
    int TentativeYearOfPassing;
    std::string State;
    std::string PIN;
    std::string Country;
};

// Function to add a new record
int addNewRecord(Record records[], int size) {
    for (int i = 0; i < size; i++) {
        if (records[i].RollNo == 0) { // 0 means uninitialized record
            // Add a new record
            std::cout << "Enter Roll Number: ";
            std::cin >> records[i].RollNo;
            std::cin.ignore();
            std::cout << "Enter Name: ";
            std::getline(std::cin, records[i].Name);
            std::cout << "Enter Father's Name: ";
            std::getline(std::cin, records[i].FathersName);
            std::cout << "Enter Date of Birth (YYYY-MM-DD): ";
            std::getline(std::cin, records[i].DOB);
            std::cout << "Enter Branch: ";
            std::getline(std::cin, records[i].Branch);
            std::cout << "Enter Year of Admission: ";
            std::cin >> records[i].YearOfAdmission;
            std::cout << "Enter Tentative Year of Passing: ";
            std::cin >> records[i].TentativeYearOfPassing;
            std::cin.ignore();
            std::cout << "Enter State: ";
            std::getline(std::cin, records[i].State);
            std::cout << "Enter PIN: ";
            std::getline(std::cin, records[i].PIN);
            std::cout << "Enter Country: ";
            std::getline(std::cin, records[i].Country);
            std::cout << "Record added successfully!" << std::endl;
            return 1; // Success
        }
    }
    // If we get here, the array is full
    std::cout << "Records full. Cannot add a new record." << std::endl;
    return 0; // Failure
}

// Function to update a record
int updateRecord(Record records[], int rollNo, int size) {
    for (int i = 0; i < size; i++) {
        if (records[i].RollNo == rollNo) {
            bool recordFound = true;
            while (recordFound) {
                int choice;
                std::cout << "Select field to update" << std::endl;
                std::cout << "1. Roll number" << std::endl;
                std::cout << "2. Name" << std::endl;
                std::cout << "3. Father's Name" << std::endl;
                std::cout << "4. DOB" << std::endl;
                std::cout << "5. Branch" << std::endl;
                std::cout << "6. Year Of Admission" << std::endl;
                std::cout << "7. Tentative Year Of Passing" << std::endl;
                std::cout << "8. State" << std::endl;
                std::cout << "9. PIN" << std::endl;
                std::cout << "10. Country" << std::endl;
                std::cout << "Enter your choice (or 0 to exit): ";
                std::cin >> choice;
                std::cin.ignore();
                switch (choice) {
                    case 1: {
                        std::cout << "Enter new Roll number: ";
                        std::cin >> records[i].RollNo;
                        std::cin.ignore();
                        break;
                    }
                    case 2: {
                        std::cout << "Enter new Name: ";
                        std::getline(std::cin, records[i].Name);
                        break;
                    }
                    case 3: {
                        std::cout << "Enter new Father's Name: ";
                        std::getline(std::cin, records[i].FathersName);
                        break;
                    }
                    case 4: {
                        std::cout << "Enter new DOB: ";
                        std::getline(std::cin, records[i].DOB);
                        break;
                    }
                    case 5: {
                        std::cout << "Enter new Branch: ";
                        std::getline(std::cin, records[i].Branch);
                        break;
                    }
                    case 6: {
                        std::cout << "Enter new Year Of Admission: ";
                        std::cin >> records[i].YearOfAdmission;
                        std::cin.ignore();
                        break;
                    }
                    case 7: {
                        std::cout << "Enter new Tentative Year Of Passing: ";
                        std::cin >> records[i].TentativeYearOfPassing;
                        std::cin.ignore();
                        break;
                    }
                    case 8: {
                        std::cout << "Enter new State: ";
                        std::getline(std::cin, records[i].State);
                        break;
                    }
                    case 9: {
                        std::cout << "Enter new PIN: ";
                        std::getline(std::cin, records[i].PIN);
                        break;
                    }
                    case 10: {
                        std::cout << "Enter new Country: ";
                        std::getline(std::cin, records[i].Country);
                        break;
                    }
                    case 0: {
                        std::cout << "Exiting update menu." << std::endl;
                        recordFound = false;
                        break;
                    }
                    default: {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                        break;
                    }
                }
            }
            return 1; // Successfully updated the record
        }
    }
    // If we reach here, the roll number wasn't found
    std::cout << "Record with RollNo " << rollNo << " not found." << std::endl;
    return 0; // Record not found
}

// Function to delete a record
int deleteRecord(Record records[], int rollNo, int &size) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (records[i].RollNo == rollNo) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Record with Roll Number " << rollNo << " not found." << std::endl;
        return 0;
    }

    // Shift subsequent records to the left
    for (int i = index; i < size - 1; i++) {
        records[i] = records[i + 1];
    }

    // Reduce the size of the array
    size--;
    std::cout << "Record with RollNo " << rollNo << " has been deleted." << std::endl;
    return 1; // Deletion successful
}

// Function to generate a report of all records
void generateReport(Record records[], int size) {
    std::cout << "\n---- Student Records Report ----\n";
    for (int i = 0; i < size; i++) {
        if (records[i].RollNo != 0) {
            std::cout << "Roll No: " << records[i].RollNo << "\n";
            std::cout << "Name: " << records[i].Name << "\n";
            std::cout << "Father's Name: " << records[i].FathersName << "\n";
            std::cout << "DOB: " << records[i].DOB << "\n";
            std::cout << "Branch: " << records[i].Branch << "\n";
            std::cout << "Year of Admission: " << records[i].YearOfAdmission << "\n";
            std::cout << "Tentative Year of Passing: " << records[i].TentativeYearOfPassing << "\n";
            std::cout << "State: " << records[i].State << "\n";
            std::cout << "PIN: " << records[i].PIN << "\n";
            std::cout << "Country: " << records[i].Country << "\n\n";
        }
    }
}

void searchByName(Record records[], std::string name, int size) {
    bool found = false;
    std::cout << "\n---- Students named " << name << " ----\n";
    for (int i = 0; i < size; i++) {
        if (records[i].Name == name) {
            found = true;
            std::cout << "Roll No: " << records[i].RollNo << "\n";
            std::cout << "Name: " << records[i].Name << "\n";
            std::cout << "Father's Name: " << records[i].FathersName << "\n";
            std::cout << "DOB: " << records[i].DOB << "\n";
            std::cout << "Branch: " << records[i].Branch << "\n";
            std::cout << "Year of Admission: " << records[i].YearOfAdmission << "\n";
            std::cout << "Tentative Year of Passing: " << records[i].TentativeYearOfPassing << "\n";
            std::cout << "State: " << records[i].State << "\n";
            std::cout << "PIN: " << records[i].PIN << "\n";
            std::cout << "Country: " << records[i].Country << "\n\n";
        }
    }
    if (!found) {
    std::cout << "No record found for Name: " << name << std::endl;
    }
}


void searchByState(Record records[], std::string state, int size) {
    bool found = false;
    std::cout << "\n---- Students from " << state << " ----\n";
    for (int i = 0; i < size; i++) {
        if (records[i].State == state) {
            found = true;
            std::cout << "Roll No: " << records[i].RollNo << "\n";
            std::cout << "Name: " << records[i].Name << "\n";
            std::cout << "Father's Name: " << records[i].FathersName << "\n";
            std::cout << "DOB: " << records[i].DOB << "\n";
            std::cout << "Branch: " << records[i].Branch << "\n";
            std::cout << "Year of Admission: " << records[i].YearOfAdmission << "\n";
            std::cout << "Tentative Year of Passing: " << records[i].TentativeYearOfPassing << "\n";
            std::cout << "State: " << records[i].State << "\n";
            std::cout << "PIN: " << records[i].PIN << "\n";
            std::cout << "Country: " << records[i].Country << "\n\n";
        }
    }
    if (!found) {
    std::cout << "No record found for State: " << state << std::endl;
    }
}


void searchByCountry(Record records[], std::string country, int size) {
    bool found = false;
    std::cout << "\n---- Students from " << country << " ----\n";
    for (int i = 0; i < size; i++) {
        if (records[i].Country == country) {
            found = true;
            std::cout << "Roll No: " << records[i].RollNo << "\n";
            std::cout << "Name: " << records[i].Name << "\n";
            std::cout << "Father's Name: " << records[i].FathersName << "\n";
            std::cout << "DOB: " << records[i].DOB << "\n";
            std::cout << "Branch: " << records[i].Branch << "\n";
            std::cout << "Year of Admission: " << records[i].YearOfAdmission << "\n";
            std::cout << "Tentative Year of Passing: " << records[i].TentativeYearOfPassing << "\n";
            std::cout << "State: " << records[i].State << "\n";
            std::cout << "PIN: " << records[i].PIN << "\n";
            std::cout << "Country: " << records[i].Country << "\n\n";
        }
    }
    if (!found) {
    std::cout << "No record found for Country: " << country << std::endl;
    }
}


int main() {
    Record records[100] = {}; // Array of 100 records (can be expanded as needed)
    int size = 0;  // To keep track of the number of records

    // Creating 20 sample records
    records[0] = {101, "Alice Johnson", "John Johnson", "2000-03-12", "Computer Science", 2018, 2022, "California", "90001", "USA"};
    size++;
    records[1] = {102, "Bob Smith", "James Smith", "1999-05-15", "Mechanical Engineering", 2017, 2021, "Texas", "75001", "USA"};
    size++;
    records[2] = {103, "Charlie Brown", "David Brown", "2001-06-20", "Electrical Engineering", 2019, 2023, "Seoul", "10001", "KOR"};
    size++;
    records[3] = {104, "Diana Green", "George Green", "1998-08-30", "Civil Engineering", 2016, 2020, "Hokkaido", "33101", "JPN"};
    size++;
    records[4] = {105, "Eve White", "Michael White", "2000-11-10", "Chemical Engineering", 2018, 2022, "New York", "10001", "USA"};
    size++;

    bool running = true; // Keep the program running
    while (running) {
        // Display menu
        std::cout << "\n---- Menu ----\n";
        std::cout << "1. Add New Record\n";
        std::cout << "2. Update Record\n";
        std::cout << "3. Delete Record\n";
        std::cout << "4. Generate Report\n";
        std::cout << "5. Search by Name\n";
        std::cout << "6. Search by State\n";
        std::cout << "7. Search by Country\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();  // Clear the newline character left by std::cin

        switch (choice) {
            case 1: {
                addNewRecord(records, 100); // Add new record
                break;
            }
            case 2: {
                int rollNo;
                std::cout << "Enter Roll Number to update: ";
                std::cin >> rollNo;
                updateRecord(records, rollNo, 100); // Update a record
                break;
            }
            case 3: {
                int rollNo;
                std::cout << "Enter Roll Number to delete: ";
                std::cin >> rollNo;
                deleteRecord(records, rollNo, size); // Delete a record
                break;
            }
            case 4: {
                generateReport(records, size); // Generate a report of all records
                break;
            }
            case 5: {
                std::string name;
                std::cout << "Enter Name to search: ";
                std::getline(std::cin, name);
                searchByName(records, name, size); // Search by name
                break;
            }
            case 6: {
                std::string state;
                std::cout << "Enter State to search: ";
                std::getline(std::cin, state);
                searchByState(records, state, size); // Search by state
                break;
            }
            case 7: {
                std::string country;
                std::cout << "Enter Country to search: ";
                std::getline(std::cin, country);
                searchByCountry(records, country, size); // Search by country
                break;
            }
            case 0: {
                std::cout << "Exiting program.\n";
                running = false; // Exit the loop and terminate the program
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

    return 0; // Return 0 to indicate successful execution
}