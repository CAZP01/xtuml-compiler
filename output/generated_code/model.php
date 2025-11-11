<?php

<?php
// Auto-generated from xtUML model
class Customer {
    
    public $id;
    
    public $name;
    
    public $email;
    
    public $registered_at;
    

    public function __construct($id, $name, $email, $registered_at) {
        
        $this->id = $id;
        
        $this->name = $name;
        
        $this->email = $email;
        
        $this->registered_at = $registered_at;
        
    }

    
    public function get_order_history() {
        
        # Implies relationship: R1 'placed by' Customer(1) -> Order(M)
return Orders.filter(customer_id=self.id)
        
    }
    
    public function update_email() {
        
        self.email = new_email
# TODO: raise event CustomerEmailUpdated
        
    }
    
}
?>


<?php
// Auto-generated from xtUML model
class Order {
    
    public $id;
    
    public $customer_id;
    
    public $status;
    
    public $created_at;
    
    public $total_amount;
    

    public function __construct($id, $customer_id, $status, $created_at, $total_amount) {
        
        $this->id = $id;
        
        $this->customer_id = $customer_id;
        
        $this->status = $status;
        
        $this->created_at = $created_at;
        
        $this->total_amount = $total_amount;
        
    }

    
    public function confirm_order() {
        
        self.status = 'confirmed'
# TODO: raise event OrderConfirmed
        
    }
    
    public function calculate_total() {
        
        # Implies relationship: R2 'contains' Order(1) -> OrderItem(M)
total = 0
items = OrderItems.filter(order_id=self.id)
for item in items:
  total += item.get_subtotal()
self.total_amount = total
        
    }
    
    public function ship_order() {
        
        if self.status == 'confirmed':
  self.status = 'shipped'
  # TODO: raise event OrderShipped
        
    }
    
}
?>


<?php
// Auto-generated from xtUML model
class OrderItem {
    
    public $id;
    
    public $order_id;
    
    public $product_id;
    
    public $quantity;
    
    public $price_per_unit;
    

    public function __construct($id, $order_id, $product_id, $quantity, $price_per_unit) {
        
        $this->id = $id;
        
        $this->order_id = $order_id;
        
        $this->product_id = $product_id;
        
        $this->quantity = $quantity;
        
        $this->price_per_unit = $price_per_unit;
        
    }

    
    public function get_subtotal() {
        
        return self.quantity * self.price_per_unit
        
    }
    
    public function get_product_name() {
        
        # Implies relationship: R3 'references' OrderItem(M) -> Product(1)
product = Products.get(id=self.product_id)
return product.name
        
    }
    
}
?>


<?php
// Auto-generated from xtUML model
class Product {
    
    public $id;
    
    public $sku;
    
    public $name;
    
    public $description;
    
    public $price;
    

    public function __construct($id, $sku, $name, $description, $price) {
        
        $this->id = $id;
        
        $this->sku = $sku;
        
        $this->name = $name;
        
        $this->description = $description;
        
        $this->price = $price;
        
    }

    
    public function get_inventory_level() {
        
        # Implies relationship: R4 'has' Product(1) -> Inventory(1)
inventory = Inventory.get(product_id=self.id)
return inventory.stock_level
        
    }
    
    public function update_price() {
        
        self.price = new_price
# TODO: raise event ProductPriceChanged
        
    }
    
}
?>


<?php
// Auto-generated from xtUML model
class Inventory {
    
    public $id;
    
    public $product_id;
    
    public $stock_level;
    
    public $location;
    

    public function __construct($id, $product_id, $stock_level, $location) {
        
        $this->id = $id;
        
        $this->product_id = $product_id;
        
        $this->stock_level = $stock_level;
        
        $this->location = $location;
        
    }

    
    public function decrement_stock() {
        
        if self.stock_level >= amount:
  self.stock_level -= amount
  if self.stock_level < 10:
    # TODO: raise event LowStockWarning
else:
  # TODO: raise event OutOfStockError
        
    }
    
    public function increment_stock() {
        
        self.stock_level += amount
        
    }
    
}
?>


?>