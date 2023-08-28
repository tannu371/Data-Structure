#include <iostream>
#include <string>

struct Employee {
    std::string employeeID;
    std::string employeeName;
    int mobileNumber;
    std::string dateOfJoining;
    double salary;
};

void displayMenu() {
    std::cout << "Main Menu " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "1. Add Employee" << std::endl;
    std::cout << "2. Delete Employee by Employee ID" << std::endl;
    std::cout << "3. View Details" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}

void addEmployee (Employee*&database, int&size, int&capacity) {
    if(size >= capacity) {
        capacity *= 2;
        Employee* newDatabase = new Employee[capacity];
        for(int i=0; i<size; i++) {
            newDatabase[i] = database[i];
        }
        delete[] database;
        database = newDatabase;
    }

    std::cout << "Enter Employee details: " << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Enter ID: ";
    std::cin >> database[size].employeeID;
    std::cout << "Enter name: ";
    std::cin >> database[size].employeeName;
    std::cout << "Enter mobile number: ";
    std::cin >> database[size].mobileNumber;
    std::cout << "Enter DOJ: ";
    std::cin >> database[size].dateOfJoining;
    std::cout << "Enter salary: ";
    std::cin >> database[size].salary;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout  << "Employee Details added successfully";

    ++size;
}

void deleteEmployee(Employee* database, int &size, std::string employeeID) {
    int foundIndex = -1;
    for(int i=0; i<size; i++) {
        if(database[i].employeeID == employeeID) {
            foundIndex = i;
            break;
        }
    }

    if(foundIndex != -1) {
        for (int i=foundIndex; i< size-1; i++) {
            database[i] = database[i+1];
        }
        --size;
        std::cout << "Record of employee id " << employeeID << " has been deleted" << std::endl;
    } else {
        std::cout << "Record of employee id " << employeeID << " not found" << std::endl;
    }
}

void viewEmployeeDetail(Employee ) {
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "1. View employee by Employee ID" << std::endl;
    std::cout << "2. List all employee " << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    int choice;
    std::cout << "Enter the choice: ";
    std::cin >> choice;
    if(choice == 1) {
        std::cout << "Enter the employee ID";
    }
}


int main () {
    int capacity = 0;
    int size = 0;

    std::cout << "Enter how many employees' record need to be stored: ";
    std::cin >> capacity;
    Employee* database = new Employee[capacity];
    std::cout << "Database created with the capacity to hold the details of " << capacity << " employees" << std::endl;

    int choice;
    do {
        displayMenu();

        std::cout << "Enter the choice: " << std::endl;
        std::cin >> choice;
        

        switch (choice) {
            case 1:
                char c;
                do{
                    addEmployee(database, size, capacity); 
                    std::cout << "Press Y to add more employee and N to go back to main menu (Y/N): ";
                    std::cin >> c;
                } while(c=='Y'||c=='y');
                displayMenu();
                break;
            case 2:
                std::string id;
                std::cout << "Enter the employee id to delete the record: ";
                std::cin >> id;
                deleteEmployee(database, size, id);
                break;
            case 3:
                
        }



    } while ();


    
    
    
    

    return 0;
}