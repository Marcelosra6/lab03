class Producto:
    def __init__ (self, nombre, precio, stock, descripcion):
        self.nombre =nombre
        self.precio = precio
        self.stock = stock
        self.descripcion = descripcion
    def mostrar_producto(self):
        print(f"| {self.nombre} | {self.precio} | {self.stock} | {self.descripcion} |")

class Inventario(Producto):

    def __init__ (self, nombre, precio, stock, descripcion, nproductos):
        super().__init__(nombre, precio, stock, descripcion)
        self.nproductos=nproductos
        self.productos=[]
    def registrar_producto(self):
        self.productos.append(self.nombre)
        print("Producto Registrado...")
    def eliminar_producto(self):
        self.productos.remove(self.nombre)
        print("Producto Eliminado...")

class Pedido(Producto, Inventario): 
    def __init__ (self, nombre, precio, stock,ctdprodacomprar):
        super().__init__(nombre, precio, stock)
        self.prodacomprar=[]
        self.ctdprodacomprar=ctdprodacomprar
    def registar_pedido(self):
        

class Reportes(Inventario, Pedido):

    def __init__ (self, nombre, precio, stock, descripcion, nproductos,ingresos,nproductosv,productos):
        super().__init__(nombre, precio, stock, descripcion,nproductos, productos)
        self.ingresos=ingresos
        self.nproductosv=nproductosv
        self.listagotados=[]
        self.listavendidos=[]
    def mostrar_ingresos(self):
        