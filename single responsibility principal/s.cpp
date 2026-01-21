#include <bits/stdc++.h>
using namespace std;

class product
{
public:
    string name;
    double price;
    product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

class cart
{
private:
    vector<product *> products;

public:
    void addProduct(product *p)
    {
        products.push_back(p);
    }

    const vector<product *> &getProduct()
    {
        return products;
    }
    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};

class shoppingCartprinter
{
private:
    cart *c;

public:
    shoppingCartprinter(cart *c)
    {
        this->c = c;
    }

    void printInvoice()
    {
        cout << "shopping cart invoice \n";
        for (auto p : c->getProduct()) {
                 cout << p->name << " - " << p->price << endl;
        }
        cout << "Total $ - " << c->calculateTotal() << endl;
    }
};

class savetoDB
{
private:
    cart *c;

public:
    savetoDB(cart *c)
    {
        this->c = c;
    }

    void saveDB()
    {
        cout << "Saving the process to data base.... " << endl;
    }
};

int main()
{
    cart *c = new cart();
    c->addProduct(new product("Laptop", 1500.00));
    c->addProduct(new product("apple", 15));

    shoppingCartprinter *printer = new shoppingCartprinter(c);
    printer->printInvoice();

    savetoDB *savetodb = new savetoDB(c);
    savetodb->saveDB();

    return 0;
}
