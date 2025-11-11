
class Customer:
    def __init__(self, id: int, name: str, email: str, registered_at: datetime):


        self.id = id

        self.name = name

        self.email = email

        self.registered_at = registered_at





    def get_order_history(self):


        # Implies relationship: R1 'placed by' Customer(1) -> Order(M)

        return Orders.filter(customer_id=self.id)



    def update_email(self):


        self.email = new_email

        # TODO: raise event CustomerEmailUpdated







class Order:
    def __init__(self, id: int, customer_id: int, status: str, created_at: datetime, total_amount: float):


        self.id = id

        self.customer_id = customer_id

        self.status = status

        self.created_at = created_at

        self.total_amount = total_amount





    def confirm_order(self):


        self.status = 'confirmed'

        # TODO: raise event OrderConfirmed



    def calculate_total(self):


        # Implies relationship: R2 'contains' Order(1) -> OrderItem(M)

        total = 0

        items = OrderItems.filter(order_id=self.id)

        for item in items:

          total += item.get_subtotal()

        self.total_amount = total



    def ship_order(self):


        if self.status == 'confirmed':

          self.status = 'shipped'

          # TODO: raise event OrderShipped







class OrderItem:
    def __init__(self, id: int, order_id: int, product_id: int, quantity: int, price_per_unit: float):


        self.id = id

        self.order_id = order_id

        self.product_id = product_id

        self.quantity = quantity

        self.price_per_unit = price_per_unit





    def get_subtotal(self):


        return self.quantity * self.price_per_unit



    def get_product_name(self):


        # Implies relationship: R3 'references' OrderItem(M) -> Product(1)

        product = Products.get(id=self.product_id)

        return product.name







class Product:
    def __init__(self, id: int, sku: str, name: str, description: str, price: float):


        self.id = id

        self.sku = sku

        self.name = name

        self.description = description

        self.price = price





    def get_inventory_level(self):


        # Implies relationship: R4 'has' Product(1) -> Inventory(1)

        inventory = Inventory.get(product_id=self.id)

        return inventory.stock_level



    def update_price(self):


        self.price = new_price

        # TODO: raise event ProductPriceChanged







class Inventory:
    def __init__(self, id: int, product_id: int, stock_level: int, location: str):


        self.id = id

        self.product_id = product_id

        self.stock_level = stock_level

        self.location = location





    def decrement_stock(self):


        if self.stock_level >= amount:

          self.stock_level -= amount

          if self.stock_level < 10:

            # TODO: raise event LowStockWarning

        else:

          # TODO: raise event OutOfStockError



    def increment_stock(self):


        self.stock_level += amount






