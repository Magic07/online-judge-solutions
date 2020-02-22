class Cashier {
 public:
  int n;
  int discount;
  unordered_map<int, int> price;
  int toDiscount;
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
      : n(n),
        discount(discount),
        toDiscount(n) {
          for(int i=0;i<products.size();i++){
            price[products[i]]=prices[i];
          }
        }

  double getBill(vector<int> product, vector<int> amount) {
    double factor(1);
    if(--toDiscount==0){
      toDiscount=n;
      factor=1-(double)discount/100;
    }
    double total(0);
    for(int i=0;i<product.size();i++){
      total+=price[product[i]]*amount[i];
    }
    return total*factor;
  }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */