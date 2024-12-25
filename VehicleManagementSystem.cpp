#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;
    int price;

public:
    Vehicle() : make(""), model(""), year(0), price(0) {}
    virtual ~Vehicle() {}
    void setMake(const string& ma) { make = ma; }
    void setModel(const string& mo) { model = mo; }
    void setYear(const int& y) { year = y; }
    void setPrice(const int& p) { price = p; }

    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    int getPrice() const { return price; }
    virtual void displayDetails() const {
        cout << "Make: " << make << "\nModel: " << model
             << "\nYear: " << year << "\nPrice: $" << price << endl;
    }
    virtual void calculateTax() const {
        cout << "Tax: $" << price * 0.10 << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car() : numDoors(4) {}
    void setNumDoors(const int& d) { numDoors = d; }
    int getNumDoors() const { return numDoors; }
    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class Truck : public Vehicle {
private:
    int payload;
    int towingCapacity;

public:
    Truck() : payload(0), towingCapacity(0) {}
    void setPayload(const int& p) { payload = p; }
    void setTowingCapacity(const int& t) { towingCapacity = t; }
    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Payload: " << payload << " lbs\nTowing Capacity: " << towingCapacity << " lbs" << endl;
    }
    void calculateTax() const override {
        cout << "Tax: $" << price * 0.12 << endl;
    }
};

void addVehicle(Vehicle* fleet[], int& count, int capacity) {
    if (count >= capacity) {
        cout << "Fleet is at maximum capacity. Cannot add more vehicles.\n";
        return;
    }

    int type;
    cout << "Enter vehicle type (1 for Car, 2 for Truck): ";
    cin >> type;

    Vehicle* vehicle = nullptr;
    if (type == 1) {
        vehicle = new Car();
        string make, model;
        int year, price, numDoors;
        cout << "Enter make: ";
        cin >> make;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter number of doors: ";
        cin >> numDoors;

        vehicle->setMake(make);
        vehicle->setModel(model);
        vehicle->setYear(year);
        vehicle->setPrice(price);
        dynamic_cast<Car*>(vehicle)->setNumDoors(numDoors);
    } else if (type == 2) {
        vehicle = new Truck();
        string make, model;
        int year, price, payload, towingCapacity;
        cout << "Enter make: ";
        cin >> make;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter payload (lbs): ";
        cin >> payload;
        cout << "Enter towing capacity (lbs): ";
        cin >> towingCapacity;

        vehicle->setMake(make);
        vehicle->setModel(model);
        vehicle->setYear(year);
        vehicle->setPrice(price);
        dynamic_cast<Truck*>(vehicle)->setPayload(payload);
        dynamic_cast<Truck*>(vehicle)->setTowingCapacity(towingCapacity);
    } else {
        cout << "Invalid vehicle type.\n";
        return;
    }

    fleet[count++] = vehicle;
    cout << "Vehicle added successfully.\n";
}

void filterVehicles(Vehicle* fleet[], int count) {
    if (count == 0) {
        cout << "No vehicles to filter.\n";
        return;
    }

    int choice;
    cout << "Filter by:\n";
    cout << "1. Make\n";
    cout << "2. Model\n";
    cout << "3. Year\n";
    cout << "4. Price\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string make;
            cout << "Enter make to filter by: ";
            cin >> make;
            cout << "Vehicles with make \"" << make << "\":\n";
            for (int i = 0; i < count; ++i) {
                if (fleet[i]->getMake() == make) {
                    fleet[i]->displayDetails();
                    cout << "---------------------\n";
                }
            }
            break;
        }
        case 2: {
            string model;
            cout << "Enter model to filter by: ";
            cin >> model;
            cout << "Vehicles with model \"" << model << "\":\n";
            for (int i = 0; i < count; ++i) {
                if (fleet[i]->getModel() == model) {
                    fleet[i]->displayDetails();
                    cout << "---------------------\n";
                }
            }
            break;
        }
        case 3: {
            int year;
            cout << "Enter year to filter by: ";
            cin >> year;
            cout << "Vehicles from year " << year << ":\n";
            for (int i = 0; i < count; ++i) {
                if (fleet[i]->getYear() == year) {
                    fleet[i]->displayDetails();
                    cout << "---------------------\n";
                }
            }
            break;
        }
        case 4: {
            int price;
            cout << "Enter maximum price to filter by: ";
            cin >> price;
            cout << "Vehicles with price <= $" << price << ":\n";
            for (int i = 0; i < count; ++i) {
                if (fleet[i]->getPrice() <= price) {
                    fleet[i]->displayDetails();
                    cout << "---------------------\n";
                }
            }
            break;
        }
        default:
            cout << "Invalid choice. Returning to main menu.\n";
    }
}

void removeVehicle(Vehicle* fleet[], int& count) {
    if (count == 0) {
        cout << "No vehicles to remove.\n";
        return;
    }

    string make, model;
    cout << "Enter make of vehicle to remove: ";
    cin >> make;
    cout << "Enter model of vehicle to remove: ";
    cin >> model;

    for (int i = 0; i < count; ++i) {
        if (fleet[i]->getMake() == make && fleet[i]->getModel() == model) {
            delete fleet[i];
            for (int j = i; j < count - 1; ++j) {
                fleet[j] = fleet[j + 1];
            }
            --count;
            cout << "Vehicle removed successfully.\n";
            return;
        }
    }
    cout << "Vehicle not found.\n";
}

void searchVehicle(Vehicle* fleet[], int count) {
    if (count == 0) {
        cout << "No vehicles to search.\n";
        return;
    }

    string make, model;
    cout << "Enter make of vehicle to search: ";
    cin >> make;
    cout << "Enter model of vehicle to search: ";
    cin >> model;

    for (int i = 0; i < count; ++i) {
        if (fleet[i]->getMake() == make && fleet[i]->getModel() == model) {
            cout << "Vehicle found:\n";
            fleet[i]->displayDetails();
            return;
        }
    }
    cout << "Vehicle not found.\n";
}

void viewSummary(Vehicle* fleet[], int count) {
  int totalPrice;
  int price;
  for (int i = 0; i < count; ++i) {
    price = fleet[i]->getPrice();
    totalPrice += price;
  }
  cout << "Total number of vehicles: " << count << endl;
  cout << "Average price per vehicle: $" << totalPrice / count << endl;
}

int main() {
    const int capacity = 100;
    Vehicle* fleet[capacity] = {nullptr};
    int count = 0;

    bool run = true;
    while (run) {
        cout << "\nMenu\n";
        cout << "1. Add vehicle\n";
        cout << "2. Remove vehicle\n";
        cout << "3. Search for vehicle\n";
        cout << "4. View summary\n";
        cout << "5. Filter vehicles\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addVehicle(fleet, count, capacity);
                break;
            case 2:
                removeVehicle(fleet, count);
                break;
            case 3:
                searchVehicle(fleet, count);
                break;
            case 4:
                viewSummary(fleet, count);
                break;
            case 5:
                filterVehicles(fleet, count);
                break;
            case 6:
                run = false;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    for (int i = 0; i < count; ++i) {
        delete fleet[i];
    }

    return 0;
}
