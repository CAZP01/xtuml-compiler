// Auto-generated C struct for Customer
#include <stdio.h>
#include <string.h>

typedef struct {

    
    int id;
    

    
    char* name;
    

    
    char* email;
    

    
    char* registered_at;
    

} Customer;

void init_customer(Customer* self, int id, char* name, char* email, char* registered_at) {

    self->id = id;

    self->name = name;

    self->email = email;

    self->registered_at = registered_at;

}



void customer_get_order_history(Customer* self) {

    # Implies relationship: R1 'placed by' Customer(1) -> Order(M)
return Orders.filter(customer_id=self.id)

}

void customer_update_email(Customer* self) {

    self.email = new_email
# TODO: raise event CustomerEmailUpdated

}




// Auto-generated C struct for Order
#include <stdio.h>
#include <string.h>

typedef struct {

    
    int id;
    

    
    int customer_id;
    

    
    char* status;
    

    
    char* created_at;
    

    
    char* total_amount;
    

} Order;

void init_order(Order* self, int id, int customer_id, char* status, char* created_at, char* total_amount) {

    self->id = id;

    self->customer_id = customer_id;

    self->status = status;

    self->created_at = created_at;

    self->total_amount = total_amount;

}



void order_confirm_order(Order* self) {

    self.status = 'confirmed'
# TODO: raise event OrderConfirmed

}

void order_calculate_total(Order* self) {

    # Implies relationship: R2 'contains' Order(1) -> OrderItem(M)
total = 0
items = OrderItems.filter(order_id=self.id)
for item in items:
  total += item.get_subtotal()
self.total_amount = total

}

void order_ship_order(Order* self) {

    if self.status == 'confirmed':
  self.status = 'shipped'
  # TODO: raise event OrderShipped

}




// Auto-generated C struct for OrderItem
#include <stdio.h>
#include <string.h>

typedef struct {

    
    int id;
    

    
    int order_id;
    

    
    int product_id;
    

    
    int quantity;
    

    
    char* price_per_unit;
    

} OrderItem;

void init_orderitem(OrderItem* self, int id, int order_id, int product_id, int quantity, char* price_per_unit) {

    self->id = id;

    self->order_id = order_id;

    self->product_id = product_id;

    self->quantity = quantity;

    self->price_per_unit = price_per_unit;

}



void orderitem_get_subtotal(OrderItem* self) {

    return self.quantity * self.price_per_unit

}

void orderitem_get_product_name(OrderItem* self) {

    # Implies relationship: R3 'references' OrderItem(M) -> Product(1)
product = Products.get(id=self.product_id)
return product.name

}




// Auto-generated C struct for Product
#include <stdio.h>
#include <string.h>

typedef struct {

    
    int id;
    

    
    char* sku;
    

    
    char* name;
    

    
    char* description;
    

    
    char* price;
    

} Product;

void init_product(Product* self, int id, char* sku, char* name, char* description, char* price) {

    self->id = id;

    self->sku = sku;

    self->name = name;

    self->description = description;

    self->price = price;

}



void product_get_inventory_level(Product* self) {

    # Implies relationship: R4 'has' Product(1) -> Inventory(1)
inventory = Inventory.get(product_id=self.id)
return inventory.stock_level

}

void product_update_price(Product* self) {

    self.price = new_price
# TODO: raise event ProductPriceChanged

}




// Auto-generated C struct for Inventory
#include <stdio.h>
#include <string.h>

typedef struct {

    
    int id;
    

    
    int product_id;
    

    
    int stock_level;
    

    
    char* location;
    

} Inventory;

void init_inventory(Inventory* self, int id, int product_id, int stock_level, char* location) {

    self->id = id;

    self->product_id = product_id;

    self->stock_level = stock_level;

    self->location = location;

}



void inventory_decrement_stock(Inventory* self) {

    if self.stock_level >= amount:
  self.stock_level -= amount
  if self.stock_level < 10:
    # TODO: raise event LowStockWarning
else:
  # TODO: raise event OutOfStockError

}

void inventory_increment_stock(Inventory* self) {

    self.stock_level += amount

}




