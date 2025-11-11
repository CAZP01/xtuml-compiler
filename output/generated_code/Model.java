// Auto-generated from xtUML model
public class Customer {
    
    private int id;
    
    private str name;
    
    private str email;
    
    private datetime registered_at;
    

    public Customer(int id, str name, str email, datetime registered_at) {
        
        this.id = id;
        
        this.name = name;
        
        this.email = email;
        
        this.registered_at = registered_at;
        
    }

    
    public void get_order_history() {
        
        # Implies relationship: R1 'placed by' Customer(1) -> Order(M)
return Orders.filter(customer_id=self.id)
        
    }
    
    public void update_email() {
        
        self.email = new_email
# TODO: raise event CustomerEmailUpdated
        
    }
    
}


// Auto-generated from xtUML model
public class Order {
    
    private int id;
    
    private int customer_id;
    
    private str status;
    
    private datetime created_at;
    
    private float total_amount;
    

    public Order(int id, int customer_id, str status, datetime created_at, float total_amount) {
        
        this.id = id;
        
        this.customer_id = customer_id;
        
        this.status = status;
        
        this.created_at = created_at;
        
        this.total_amount = total_amount;
        
    }

    
    public void confirm_order() {
        
        self.status = 'confirmed'
# TODO: raise event OrderConfirmed
        
    }
    
    public void calculate_total() {
        
        # Implies relationship: R2 'contains' Order(1) -> OrderItem(M)
total = 0
items = OrderItems.filter(order_id=self.id)
for item in items:
  total += item.get_subtotal()
self.total_amount = total
        
    }
    
    public void ship_order() {
        
        if self.status == 'confirmed':
  self.status = 'shipped'
  # TODO: raise event OrderShipped
        
    }
    
}


// Auto-generated from xtUML model
public class OrderItem {
    
    private int id;
    
    private int order_id;
    
    private int product_id;
    
    private int quantity;
    
    private float price_per_unit;
    

    public OrderItem(int id, int order_id, int product_id, int quantity, float price_per_unit) {
        
        this.id = id;
        
        this.order_id = order_id;
        
        this.product_id = product_id;
        
        this.quantity = quantity;
        
        this.price_per_unit = price_per_unit;
        
    }

    
    public void get_subtotal() {
        
        return self.quantity * self.price_per_unit
        
    }
    
    public void get_product_name() {
        
        # Implies relationship: R3 'references' OrderItem(M) -> Product(1)
product = Products.get(id=self.product_id)
return product.name
        
    }
    
}


// Auto-generated from xtUML model
public class Product {
    
    private int id;
    
    private str sku;
    
    private str name;
    
    private str description;
    
    private float price;
    

    public Product(int id, str sku, str name, str description, float price) {
        
        this.id = id;
        
        this.sku = sku;
        
        this.name = name;
        
        this.description = description;
        
        this.price = price;
        
    }

    
    public void get_inventory_level() {
        
        # Implies relationship: R4 'has' Product(1) -> Inventory(1)
inventory = Inventory.get(product_id=self.id)
return inventory.stock_level
        
    }
    
    public void update_price() {
        
        self.price = new_price
# TODO: raise event ProductPriceChanged
        
    }
    
}


// Auto-generated from xtUML model
public class Inventory {
    
    private int id;
    
    private int product_id;
    
    private int stock_level;
    
    private str location;
    

    public Inventory(int id, int product_id, int stock_level, str location) {
        
        this.id = id;
        
        this.product_id = product_id;
        
        this.stock_level = stock_level;
        
        this.location = location;
        
    }

    
    public void decrement_stock() {
        
        if self.stock_level >= amount:
  self.stock_level -= amount
  if self.stock_level < 10:
    # TODO: raise event LowStockWarning
else:
  # TODO: raise event OutOfStockError
        
    }
    
    public void increment_stock() {
        
        self.stock_level += amount
        
    }
    
}


