#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Item {
private:
    std::string name;
    int quantity;
    float price;

public:
    Item(std::string name, int quantity, float price)
        : name{std::move(name)}, quantity{quantity}, price{price} {}

    std::string get_name() const { return name; }
    int get_quantity() const { return quantity; }
    void set_quantity(int new_quantity) { quantity = new_quantity; }
    float get_price() const { return price; }
    bool is_match(const std::string& other) const { return name == other; }
};

class Inventory {
private:
    std::vector<Item*> items;
    float total_money = 0;

    static void display_data(const Item& item) {
        std::cout << "\nItem name: " << item.get_name();
        std::cout << "\nQuantity: " << item.get_quantity();
        std::cout << "\nPrice: " << item.get_price();
    }

public:
    ~Inventory() {
        for (auto item : items) {
            delete item;
        }
    }

    void add_item() {
        std::string name;
        int quantity;
        float price;

        std::cin.ignore();
        std::cout << "\nEnter item name: ";
        std::cin >> name;
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        std::cout << "Enter price: ";
        std::cin >> price;

        items.push_back(new Item(name, quantity, price));
    }

    void sell_item() {
        std::string item_to_check;
        std::cin.ignore();
        std::cout << "\nEnter item name: ";
        std::cin >> item_to_check;

        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i]->is_match(item_to_check)) {
                remove_item(i);
                return;
            }
        }
        std::cout << "\nThis item is not in your Inventory";
    }

    void remove_item(size_t index) {
        Item* item = items[index];
        int input_quantity;

        std::cout << "\nEnter number of items to sell: ";
        std::cin >> input_quantity;

        int quantity = item->get_quantity();

        if (input_quantity <= quantity) {
            float earned = input_quantity * item->get_price();
            total_money += earned;

            int new_quantity = quantity - input_quantity;
            item->set_quantity(new_quantity);

            std::cout << "\nItems sold";
            std::cout << "\nMoney received: " << earned;

            if (new_quantity == 0) {
                delete item;
                items.erase(items.begin() + index);
                std::cout << "\nItem removed from inventory.";
            }
        } else {
            std::cout << "\nCannot sell more items than you have.";
        }
    }

    void list_items() const {
        if (items.empty()) {
            std::cout << "\nInventory empty.";
            return;
        }

        for (auto item : items) {
            display_data(*item);
            std::cout << "\n";
        }
    }
};
