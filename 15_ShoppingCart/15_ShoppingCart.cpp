#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Product
{
    std::string name;
    double price;

public:
    Product(const std::string& productName, double productPrice)
        : name{ productName }, price{ productPrice }
    {
        if (productPrice < 0.0)
        {
            price = 0.0;
        }
    }

    std::string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }
};


class ShoppingCart
{
    std::vector<Product> products;

public:
    void addProduct(const Product& product)
    {
        products.push_back(product);
    }

    double calculateTotal() const
    {
        double total{};

        for (const Product& product : products)
        {
            total += product.getPrice();
        }

        return total;
    }

    void displayCart() const
    {
        std::cout << "\nSHOPPING CART\n";
        std::cout << "--------------------------------\n";

        for (const Product& product : products)
        {
            std::cout << std::left
                << std::setw(15)
                << product.getName()
                << " : "
                << std::fixed
                << std::setprecision(2)
                << product.getPrice()
                << '\n';
        }

        std::cout << "--------------------------------\n";
        std::cout << "Total: "
            << calculateTotal()
            << '\n';
    }
};


int main()
{
    int productCount{};

    std::cout << "SHOPPING CART APPLICATION\n";
    std::cout << "--------------------------------\n";

    std::cout << "Enter number of products: ";
    std::cin >> productCount;

    ShoppingCart cart;

    for (int index{}; index < productCount; index++)
    {
        std::string name;
        double price{};

        std::cout << "\nEnter product " << index + 1 << " name: ";
        std::cin >> name;

        std::cout << "Enter product " << index + 1 << " price: ";
        std::cin >> price;

        Product product{ name, price };

        cart.addProduct(product);
    }

    cart.displayCart();

    return 0;
}