#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Product{
    private:
        string Productname;
        int Price;
        int Stock;
    
    public:
    
    virtual ~Product() = default;

    Product(string aProductname, int aPrice, int aStock){
        SetProductname(aProductname);
        SetPrice(aPrice);
        SetStock(aStock);
    }

    string GetProductname(){ return Productname;}
    int GetPrice(){ return Price;}
    int GetStock(){ return Stock;}

    void SetProductname(string aProductname){
        Productname = aProductname;
    }

    void SetPrice(int aPrice){
        Price = aPrice;
    }

    void SetStock(int aStock){
        Stock = aStock;
    }
};

vector <Product*> products;

void viewProduct(){
    cout << "\n===================== VIEW PRODUCT =====================" << endl;
    if(products.empty()){
        cout << "\n[-] NO PRODUCT FOUND!" << endl;
        return;
    }

    for(int i = 0; i < products.size(); i++){
        cout << "PRODUCT NAME  " << i + 1 <<  "#: " << products[i]->GetProductname() << endl;
        cout << "PRODUCT PRICE " << i + 1 << "#: " << products[i]->GetPrice() << endl;
        cout << "PRODUCT STOCK " << i + 1 << "#: " << products[i]->GetStock() << endl;
        cout << endl;
    }
}

void deleteProduct(){
    int select;
    cout << "======================= DELETE PRODUCT =========================" << endl;

    if(products.empty()){
        cout << "[-] NO PRODUCTS FOUND!" << endl;
        return;
    }

    for(int i = 0; i < products.size(); i++){
        cout << "[" << i + 1 << "]" << products[i]->GetProductname() << endl;
    }

    while (true)
    {
        cout << "SELECT: ";
        cin >> select;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID CHOICES!" << endl;
        } else if(select < 1 || select > products.size()){
            cout << "INVALID VALUE!" << endl;
        } else {
            break;
        }
    }

    int index = select -1;
    delete products[index];

    products.erase(products.begin() + index);
    cout << "DELETING PLEASE WAIT...." << endl;
    Sleep(2000);
    cout << "[-] PRODUCTS DELETED SUCCESSFULLY!" << endl;
    Sleep(1000);
    viewProduct();


}
void updateProduct(){
    string productname;
    int select, price, stock;

    if(products.empty()){
        cout << "[-] NO PRODUCTS FOUND!" << endl;
        return;
    }
    cout << "======================== UPDATE PRODUCT =======================" << endl;
    
    while(true){
        for(int i = 0; i < products.size(); i++){
            cout << "[" << i + 1 << "]" << products[i]->GetProductname() << endl;
        }

        cout << "SELECT: ";
        cin >> select;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID INPUT" << endl;
        } else if(select < 1 || select > products.size()){
            cout << "INVALID VALUE" << endl;
        } else {
            break;
        }
    }

    cout << "NEW PRODUCT NAME: ";
    cin.ignore();
    getline(cin, productname);

    while(true){
        cout << "NEW PRICE: ";
        cin >> price;

        if(cin.fail() || price < 0){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID INPUT!" << endl;
        } else {
            break;
        }
    }

    while (true)
    {
        cout << "NEW STOCK: ";
        cin >> stock;

        if(cin.fail() || stock < 0){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID INPUT!" << endl;
        } else {
            break;
        }
    }

    int index = select -1;

    products[index]->SetProductname(productname);
    products[index]->SetPrice(price);
    products[index]->SetStock(stock);

    cout << "PRODUCT SUCCESSFULLY UPDATED!" << endl;

    Sleep(2000);
    cout << "PLEASE WAIT...." << endl;
    Sleep(3000);
    viewProduct();    
}

void addProduct(){
    string productName;
    int price, stock;

    cout << "\n===================== ADD PRODUCT =====================" << endl;
    cout << "PRODUCT NAME: ";
    cin.ignore();
    getline(cin, productName);

    while(true){
        cout << "PRICE: ";
        cin >> price;

        if(cin.fail() || price < 0){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID INPUT!" << endl;
        } else {
            break;
        }
    }

    while (true)
    {
        cout << "STOCK: ";
        cin >> stock;

        if(cin.fail() || stock < 0){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID INPUT!" << endl;
        } else {
            break;
        }
    }

    Product* ptrProduct = new Product(productName, price, stock);
    products.push_back(ptrProduct);
    Sleep(2000);
    viewProduct();
    cout << "[+] PRODUCT ADDED SUCCESSFULLY" << endl;
}

int main()
{
    int choose;
    while(true){
        cout << "\n========================== WELCOME TO MY E COMMERCE ==========================" << endl;
        cout << "[1] ADD PRODUCT\n[2] VIEW PRODUCT\n[3] UPDATE PRODUCT\n[4] DELETE PRODUCT\n[5] EXIT" << endl;
        cout << "CHOOSE: ";
        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if(choose == 1){
            addProduct();
            Sleep(2000);
            cout << "LOADING PLEASE WAIT..." << endl; 
            Sleep(5000);
        } else if(choose == 2){
            viewProduct();
        } else if(choose == 3){
            updateProduct();
        } else if(choose == 4){
            deleteProduct();
        } else if(choose == 5) {
            for(int i = 0; i < products.size(); i++){
                delete products[i];
            }

            cout << "THANK YOU!" << endl;
            products.clear();
            break;
        }
        else {
            cout << "INVALID INPUT!" << endl;
        }
    }
    return 0;
}