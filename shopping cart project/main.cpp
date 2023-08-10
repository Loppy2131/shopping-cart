#include<iostream>
#include "datamodel.h"
using namespace std;
#include <vector>
vector <Product> allProducts = {
    Product(1,"apple",26),
    Product(2,"mango",29),
    Product(3,"guava",56),
    Product(4,"banana",96),
    Product(5,"strawberry",206),
    Product(6,"pineapple",90),

};
Product* chooseProduct(){
    string productList;
    cout<<"Availabel Products"<<endl;

    for(auto product: allProducts){
        productList.append(product.getDisplayName());
    }
    cout << productList <<endl;

    cout<<"______________________"<<endl;
    string choice;
    cin>>choice;

    for(int i=0;i<allProducts.size(); i++){
        if(allProducts[i].getShorName()==choice){
            return &allProducts[i];
        }
    }
    cout <<"Product not found"<<endl;
    return NULL;

}
bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout <<"Pay in Cash";
    int paid;
    cin >> paid;
    if(paid>=total){
        cout<<"change: " << paid-total<<endl;
        cout<<"thank u for shopping!\n";
        return true;

    }
    else{
        cout <<"NOt enough cash";
        return false;
    }
}

int main(){
    Cart cart;
    char action;
    while(true){
        cout<<"Select an action (a)-additem, (v) view cart, (c) checkout"<<endl;
        cin >> action;

        if(action =='a'){
            //Add to cart
            //veiw All Products+ add to the cart
            Product *product = chooseProduct();
            if(product!=NULL){
                cout <<"added to the cart"<<product->getDisplayName() <<endl;
                cart.addProduct(*product);
            }

        }
        else if(action =='v'){
            cout<<"________________"<<endl;
            cout << cart.viewCart();
            cout << "________________"<<endl;
        }
        else{
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }


    return 0;
}