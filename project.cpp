#include <iostream>
#include <string>

using namespace std;

// Структура  меню
struct MenuItem {
    string name;
    double price;
};


// Функция для вывода 
void printMenu(const MenuItem menu[], int size, const string& title) {
    cout << title << ":\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << menu[i].name << " - €" << menu[i].price << "\n";
    }
    cout << endl;
}


// Функция для  выбора чего то из меню
double takeOrder(const MenuItem menu[], int size, const string& prompt) {
    int choice;
    cout << prompt;
    cin >> choice;
    while (choice < 1 || choice > size) {
        cout << "Invalid choice. " << prompt;
        cin >> choice;
    }
    return menu[choice - 1].price;
}


int main() {
    cout << "Welcome to our restaurant!\n";


    //  алллергии
    string allergies[5] = { "nuts", "gluten", "dairy", "shellfish", "eggs" };
    bool allergyCheck[5] = { false, false, false, false, false };


    // инф о  наличии аллергии
    cout << "Do you have any allergies? (yes or no): ";
    string response;
    cin >> response;


    // Проверка аллергий
    if (response == "yes") {
        for (int i = 0; i < 5; ++i) {
            cout << "Are you allergic to " << allergies[i] << "? (yes or no): ";
            cin >> response;
            allergyCheck[i] = (response == "yes");
        }
    }


    //  основные блюда
    MenuItem mainDishes[3] = {
        {"Grilled Chicken", 12.50},
        {"Beef Steak", 15.00},
        {"Vegetarian Pasta", 10.00}
    };


    // напитки
    MenuItem drinks[3] = {
        {"Water", 1.50},
        {"Soda", 2.00},
        {"Wine", 5.00}
    };


    // десерты
    MenuItem desserts[3] = {
        {"Cheesecake", 4.50},
        {"Ice Cream", 3.00},
        {"Fruit Salad", 3.50}
    };


    // закуски 
    MenuItem appetizers[3] = {
        {"Bruschetta", 4.00},
        {"Garlic Bread", 3.50},
        {"Stuffed Mushrooms", 5.00}
    };


    double totalCost = 0.0;
    bool ordering = true;


    while (ordering) {
        // Вывод меню
        cout << "Here is our menu:\n";
        printMenu(mainDishes, 3, "Main Dishes");
        printMenu(drinks, 3, "Drinks");
        printMenu(desserts, 3, "Desserts");
        printMenu(appetizers, 3, "Appetizers");


        // инф о выборе пользователя
        cout << "Please make a selection from each category.\n";
        totalCost += takeOrder(mainDishes, 3, "Choose a main dish (1-3): ");
        totalCost += takeOrder(drinks, 3, "Choose a drink (1-3): ");
        totalCost += takeOrder(desserts, 3, "Choose a dessert (1-3): ");
        totalCost += takeOrder(appetizers, 3, "Choose an appetizer (1-3): ");


        // Проверка, хочет ли пользователь сделать еще один заказ
        cout << "Would you like to order anything else? (yes or no): ";
        cin >> response;
        if (response == "no") {
            ordering = false;
        }
    }


    // Вывод  стоимости заказа
    cout << "Thank you for your order. Your total is:  €" << totalCost << endl;
    return 0;
}
