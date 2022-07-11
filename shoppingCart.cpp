#include <iostream>
#include "dataModel.h"
#include<vector>
using namespace std;

vector<Product> allProduct = {
    Product(1,"apple",26),
    Product(3,"mango",16),
    Product(2,"guava",36),
    Product(5,"banana",56),
    Product(4,"strawberry",29),
    Product(6,"pineapple",20)
};

Product* chooseProduct(){
    string productList;

    cout<<"Availabe Products"<<endl;
    for(auto x:allProduct){
        productList.append(x.getDisplayName());
    }

    cout<<productList<<endl;

    cout<<"----------------------"<<endl;
    string choice;
    cin>>choice;

    for(int i=0;i<allProduct.size();i++){
        if(allProduct[i].getShortName()==choice){
            return &allProduct[i];
        }
    }
    cout<<"Product Not Found!!!"<<endl;
    return NULL;
}

bool checkout(Cart &c){

    if(c.isEmpty()){return false;}

    int total_to_be_paid = c.getTotal();
    int paid;
    cout<<"Pay in Cash \nEnter Amount:";
    cin>>paid;

    if(paid>=total_to_be_paid){
        cout<<"Change "<<paid-total_to_be_paid<<endl;
        cout<<"Successfully Checked Out"<<endl;
        return true;
    }else{
        cout<<"Not Enough Cash"<<endl;
        return false;
    }
}

int main()
{
    char action;
    Cart cart;
    while(true){
        cout<<"Select an action - (a)dd Item, (v)iew Cart, (c)heckout"<<endl;
        cin>>action;

        if(action == 'a'){
            // Display Items 
            Product *p = chooseProduct();
            if(p!=NULL){
                cout<<"Added to the Cart "<<p->getDisplayName()<<endl;
            }
            // Add to Cart the selected item
            cart.addProducts(*p);
        }else if(action == 'v'){
            // View Cart or Display the items addded
            cout<<"----------------------"<<endl;
            cout<<cart.viewCart();
            cout<<"----------------------"<<endl;  
        }else{
            // Checkout
            cout<<cart.viewCart();
            if(checkout(cart)){break;}
            // break from the loop
        }
    }

    return 0;
}