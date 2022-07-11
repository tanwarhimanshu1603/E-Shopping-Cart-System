// Here the model of Shopping Cart will be coded.
// Classes to be used - Product, Item, Carts
#include<string>
#include<unordered_map>
using namespace std;

class Cart;
class Item;

class Product{

    int id;
    string name;
    int price;

    public:

    Product(){}
    Product(int u_id,string name,int price){
        id = u_id;
        this->name = name;
        this->price = price;
    }

    string getDisplayName(){
        return "(" + name.substr(0,1) + ")" + name.substr(1,name.size()) + " : Rs " + to_string(price) + "\n";
    }

    string getShortName(){
        return name.substr(0,1);
    }

    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int quantity;

    public:
    Item(){}
    // Constructor initialization using initialization List 
    Item(Product p,int q):product(p),quantity(q){}

    int getItemPrice(){
        return quantity*product.price;
    }

    string getItemInfo(){
        return to_string(quantity) + " * " + product.name + " Rs. " + to_string(quantity*product.price) + "\n";
    }


    friend class Cart;
};

class Cart{
    unordered_map<int,Item> items;

    public:

    void addProducts(Product product){
        if(items.count(product.id)==0){
            
            Item newItem(product,1); 
            items[product.id] = newItem;
        }else{
            items[product.id].quantity += 1;
        }
    }

    int getTotal(){
        int total = 0;
        for(auto itemPair:items){
            auto itemList = itemPair.second;
            total += itemList.getItemPrice();
        }
        return total;
    }

    string viewCart(){

        if(items.empty()){
            cout<<"Cart is Empty"<<endl;
        }
        string itemizedList;
        int cart_total = getTotal();
        for(auto itemPair:items){
            auto items = itemPair.second;
            itemizedList.append(items.getItemInfo());
        }
        return itemizedList + "\n Total Amount : Rs. " + to_string(cart_total) + "\n";
    }

    bool isEmpty(){
        return items.empty();
    }
};