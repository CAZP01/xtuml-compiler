// Auto-generated from xtUML model
export class Customer {
    constructor(id, name, email, registered_at) {
        
        
        this.id = id;
        
        this.name = name;
        
        this.email = email;
        
        this.registered_at = registered_at;
        
        
    }

    
    
    get_order_history() {
        
        # Implies relationship: R1 'placed by' Customer(1) -> Order(M)
return Orders.filter(customer_id=self.id)
        
    }
    
    update_email() {
        
        self.email = new_email
# TODO: raise event CustomerEmailUpdated
        
    }
    
    
}


// Auto-generated from xtUML model
export class Order {
    constructor(id, customer_id, status, created_at, total_amount) {
        
        
        this.id = id;
        
        this.customer_id = customer_id;
        
        this.status = status;
        
        this.created_at = created_at;
        
        this.total_amount = total_amount;
        
        
    }

    
    
    confirm_order() {
        
        self.status = 'confirmed'
# TODO: raise event OrderConfirmed
        
    }
    
    calculate_total() {
        
        # Implies relationship: R2 'contains' Order(1) -> OrderItem(M)
total = 0
items = OrderItems.filter(order_id=self.id)
for item in items:
  total += item.get_subtotal()
self.total_amount = total
        
    }
    
    ship_order() {
        
        if self.status == 'confirmed':
  self.status = 'shipped'
  # TODO: raise event OrderShipped
        
    }
    
    
}


// Auto-generated from xtUML model
export class OrderItem {
    constructor(id, order_id, product_id, quantity, price_per_unit) {
        
        
        this.id = id;
        
        this.order_id = order_id;
        
        this.product_id = product_id;
        
        this.quantity = quantity;
        
        this.price_per_unit = price_per_unit;
        
        
    }

    
    
    get_subtotal() {
        
        return self.quantity * self.price_per_unit
        
    }
    
    get_product_name() {
        
        # Implies relationship: R3 'references' OrderItem(M) -> Product(1)
product = Products.get(id=self.product_id)
return product.name
        
    }
    
    
}


// Auto-generated from xtUML model
export class Product {
    constructor(id, sku, name, description, price) {
        
        
        this.id = id;
        
        this.sku = sku;
        
        this.name = name;
        
        this.description = description;
        
        this.price = price;
        
        
    }

    
    
    get_inventory_level() {
        
        # Implies relationship: R4 'has' Product(1) -> Inventory(1)
inventory = Inventory.get(product_id=self.id)
return inventory.stock_level
        
    }
    
    update_price() {
        
        self.price = new_price
# TODO: raise event ProductPriceChanged
        
    }
    
    
}


// Auto-generated from xtUML model
export class Inventory {
    constructor(id, product_id, stock_level, location) {
        
        
        this.id = id;
        
        this.product_id = product_id;
        
        this.stock_level = stock_level;
        
        this.location = location;
        
        
    }

    
    
    decrement_stock() {
        
        if self.stock_level >= amount:
  self.stock_level -= amount
  if self.stock_level < 10:
    # TODO: raise event LowStockWarning
else:
  # TODO: raise event OutOfStockError
        
    }
    
    increment_stock() {
        
        self.stock_level += amount
        
    }
    
    
}


