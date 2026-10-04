#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ================= PRODUCT CLASS =================
class Product
{
private:
    int productId;
    string name;
    double price;
    int stock;

public:
    Product(int id, string n, double p, int s)
    {
        productId = id;
        name = n;
        price = p;
        stock = s;
    }

    int getId()
    {
        return productId;
    }

    string getName()
    {
        return name;
    }

    double getPrice()
    {
        return price;
    }

    int getStock()
    {
        return stock;
    }

    void reduceStock(int quantity)
    {
        stock -= quantity;
    }

    void displayProduct()
    {
        cout << left
             << setw(10) << productId
             << setw(25) << name
             << setw(12) << price
             << setw(10) << stock << endl;
    }
};

// ================= CUSTOMER CLASS =================
class Customer
{
private:
    int customerId;
    string name;
    string phone;
    string address;

public:
    Customer(int id, string n, string p, string a)
    {
        customerId = id;
        name = n;
        phone = p;
        address = a;
    }

    int getId()
    {
        return customerId;
    }

    string getName()
    {
        return name;
    }

    void displayCustomer()
    {
        cout << "\nCustomer ID : " << customerId;
        cout << "\nName        : " << name;
        cout << "\nPhone       : " << phone;
        cout << "\nAddress     : " << address << endl;
    }
};

// ================= CART ITEM CLASS =================
class CartItem
{
private:
    Product* product;
    int quantity;

public:
    CartItem(Product* p, int q)
    {
        product = p;
        quantity = q;
    }

    Product* getProduct()
    {
        return product;
    }

    int getQuantity()
    {
        return quantity;
    }

    double getTotal()
    {
        return product->getPrice() * quantity;
    }

    void increaseQuantity(int q)
    {
        quantity += q;
    }

    void displayItem()
    {
        cout << left
             << setw(25) << product->getName()
             << setw(10) << quantity
             << setw(12) << product->getPrice()
             << setw(12) << getTotal() << endl;
    }
};

// ================= CART CLASS =================
class Cart
{
private:
    vector<CartItem> items;

public:

    void addProduct(Product* product, int quantity)
    {
        if (quantity <= 0)
        {
            cout << "Invalid quantity!\n";
            return;
        }

        if (quantity > product->getStock())
        {
            cout << "Not enough stock available!\n";
            return;
        }

        // Check if product already exists in cart
        for (auto &item : items)
        {
            if (item.getProduct()->getId() == product->getId())
            {
                if (item.getQuantity() + quantity > product->getStock())
                {
                    cout << "Quantity exceeds available stock!\n";
                    return;
                }

                item.increaseQuantity(quantity);
                cout << "Product quantity updated in cart.\n";
                return;
            }
        }

        items.push_back(CartItem(product, quantity));

        cout << "Product added to cart successfully!\n";
    }

    void removeProduct(int productId)
    {
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            if (it->getProduct()->getId() == productId)
            {
                items.erase(it);
                cout << "Product removed from cart.\n";
                return;
            }
        }

        cout << "Product not found in cart.\n";
    }

    void displayCart()
    {
        if (items.empty())
        {
            cout << "\nCart is empty!\n";
            return;
        }

        cout << "\n================ YOUR CART ================\n";

        cout << left
             << setw(25) << "Product"
             << setw(10) << "Quantity"
             << setw(12) << "Price"
             << setw(12) << "Total" << endl;

        cout << "---------------------------------------------------------\n";

        for (auto &item : items)
        {
            item.displayItem();
        }

        cout << "---------------------------------------------------------\n";
        cout << "Cart Total: Rs. " << fixed << setprecision(2)
             << getTotal() << endl;
    }

    double getTotal()
    {
        double total = 0;

        for (auto &item : items)
        {
            total += item.getTotal();
        }

        return total;
    }

    bool isEmpty()
    {
        return items.empty();
    }

    vector<CartItem>& getItems()
    {
        return items;
    }

    void clearCart()
    {
        items.clear();
    }
};

// ================= ORDER CLASS =================
class Order
{
private:
    int orderId;
    double amount;
    string status;

public:
    Order(int id, double a)
    {
        orderId = id;
        amount = a;
        status = "Confirmed";
    }

    void displayOrder()
    {
        cout << left
             << setw(12) << orderId
             << setw(15) << amount
             << setw(15) << status << endl;
    }
};

// ================= SHOPPING SYSTEM CLASS =================
class ShoppingSystem
{
private:
    vector<Product> products;
    vector<Customer> customers;
    vector<Order> orders;

    int nextCustomerId;
    int nextOrderId;

public:

    ShoppingSystem()
    {
        nextCustomerId = 101;
        nextOrderId = 1001;

        // Default Products
        products.push_back(Product(1, "Laptop", 55000, 10));
        products.push_back(Product(2, "Smartphone", 25000, 15));
        products.push_back(Product(3, "Headphones", 2000, 20));
        products.push_back(Product(4, "Keyboard", 1200, 25));
        products.push_back(Product(5, "Mouse", 700, 30));
        products.push_back(Product(6, "Smart Watch", 3500, 12));
    }

    // ---------- PRODUCT CATALOGUE ----------
    void displayProducts()
    {
        cout << "\n=============== PRODUCT CATALOGUE ===============\n";

        cout << left
             << setw(10) << "ID"
             << setw(25) << "Product"
             << setw(12) << "Price"
             << setw(10) << "Stock" << endl;

        cout << "---------------------------------------------------------\n";

        for (auto &product : products)
        {
            product.displayProduct();
        }
    }

    // ---------- CUSTOMER REGISTRATION ----------
    Customer* registerCustomer()
    {
        string name, phone, address;

        cin.ignore();

        cout << "\nEnter Customer Name: ";
        getline(cin, name);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Address: ";
        getline(cin, address);

        customers.push_back(
            Customer(nextCustomerId, name, phone, address)
        );

        cout << "\nCustomer registered successfully!\n";
        cout << "Your Customer ID is: " << nextCustomerId << endl;

        nextCustomerId++;

        return &customers.back();
    }

    // ---------- DISPLAY CUSTOMERS ----------
    void displayCustomers()
    {
        if (customers.empty())
        {
            cout << "\nNo customer records found.\n";
            return;
        }

        cout << "\n=============== CUSTOMER RECORDS ===============\n";

        for (auto &customer : customers)
        {
            customer.displayCustomer();
            cout << "--------------------------------------\n";
        }
    }

    // ---------- FIND PRODUCT ----------
    Product* findProduct(int id)
    {
        for (auto &product : products)
        {
            if (product.getId() == id)
            {
                return &product;
            }
        }

        return nullptr;
    }

    // ---------- PLACE ORDER ----------
    void placeOrder(Customer* customer, Cart &cart)
    {
        if (cart.isEmpty())
        {
            cout << "\nCart is empty. Add products first.\n";
            return;
        }

        double subtotal = cart.getTotal();

        double gst = subtotal * 0.18;

        double delivery = 50;

        double finalAmount = subtotal + gst + delivery;

        // Reduce stock
        for (auto &item : cart.getItems())
        {
            item.getProduct()->reduceStock(
                item.getQuantity()
            );
        }

        orders.push_back(
            Order(nextOrderId, finalAmount)
        );

        cout << "\n============== BILL ==============\n";

        cout << "Customer Name : "
             << customer->getName() << endl;

        cout << "Order ID      : "
             << nextOrderId << endl;

        cout << "----------------------------------\n";

        cart.displayCart();

        cout << "\nSubtotal      : Rs. "
             << fixed << setprecision(2)
             << subtotal << endl;

        cout << "GST (18%)     : Rs. "
             << gst << endl;

        cout << "Delivery      : Rs. "
             << delivery << endl;

        cout << "----------------------------------\n";

        cout << "Final Amount  : Rs. "
             << finalAmount << endl;

        cout << "----------------------------------\n";

        cout << "Order Status  : Confirmed\n";

        cout << "\nThank you for shopping with us!\n";

        nextOrderId++;

        cart.clearCart();
    }

    // ---------- ORDER HISTORY ----------
    void displayOrders()
    {
        if (orders.empty())
        {
            cout << "\nNo orders placed yet.\n";
            return;
        }

        cout << "\n=============== ORDER HISTORY ===============\n";

        cout << left
             << setw(12) << "Order ID"
             << setw(15) << "Amount"
             << setw(15) << "Status" << endl;

        cout << "------------------------------------------\n";

        for (auto &order : orders)
        {
            order.displayOrder();
        }
    }

    // ---------- MAIN MENU ----------
    void run()
    {
        Customer* currentCustomer = nullptr;

        Cart cart;

        int choice;

        do
        {
            cout << "\n\n==============================================\n";
            cout << "       ONLINE SHOPPING MANAGEMENT SYSTEM\n";
            cout << "==============================================\n";

            cout << "1. Product Catalogue\n";
            cout << "2. Register Customer\n";
            cout << "3. Customer Records\n";
            cout << "4. Add Product to Cart\n";
            cout << "5. View Cart\n";
            cout << "6. Remove Product from Cart\n";
            cout << "7. Place Order & Generate Bill\n";
            cout << "8. Order History\n";
            cout << "9. Exit\n";

            cout << "----------------------------------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                displayProducts();
                break;

            case 2:
                currentCustomer = registerCustomer();
                break;

            case 3:
                displayCustomers();
                break;

            case 4:
            {
                if (currentCustomer == nullptr)
                {
                    cout << "\nPlease register as a customer first.\n";
                    break;
                }

                int id, quantity;

                displayProducts();

                cout << "\nEnter Product ID: ";
                cin >> id;

                Product* product = findProduct(id);

                if (product == nullptr)
                {
                    cout << "Product not found!\n";
                    break;
                }

                cout << "Enter Quantity: ";
                cin >> quantity;

                cart.addProduct(product, quantity);

                break;
            }

            case 5:
                cart.displayCart();
                break;

            case 6:
            {
                int id;

                cart.displayCart();

                if (!cart.isEmpty())
                {
                    cout << "\nEnter Product ID to remove: ";
                    cin >> id;

                    cart.removeProduct(id);
                }

                break;
            }

            case 7:

                if (currentCustomer == nullptr)
                {
                    cout << "\nPlease register as a customer first.\n";
                }
                else
                {
                    placeOrder(currentCustomer, cart);
                }

                break;

            case 8:
                displayOrders();
                break;

            case 9:
                cout << "\nThank you for using Online Shopping Management System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
            }

        } while (choice != 9);
    }
};

// ================= MAIN FUNCTION =================
int main()
{
    ShoppingSystem system;

    system.run();

    return 0;
}