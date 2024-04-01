class Producto():
    def __init__(self, nombre, precio, stock):
        self.nombre = nombre
        self.precio = precio
        self.stock = stock
    def venta(self,num):   
        if self.stock >= num:
            self.stock -= num
            print(f"Se han vendido {num} productos {self.nombre}.")
        else:
            print("No hay suficientes productos en stock.")
class Inventario(Producto):
    productos={}
    def __init__(self, nombre, stock, precio, nproductos, productos =None):
        super().__init__(nombre, precio,stock)
        self.nproductos=nproductos
        self.productos=productos
        super().__init__(nombre, precio,stock)
        
class Ventas(Inventario, Producto):
    listpabarrotados =[]
    listpvendidos=[]
    def __init__(self, nombre, stock, precio, nproductos, pabarrotados,pvendidos , ingresos, productos=None,listpabarrotados=None, listpvendidos=None):
        super().__init__(nombre, stock, precio, nproductos, productos)
        self.pvendidos = pvendidos
        self.ingresos = ingresos
        self.pabarrotados=pabarrotados
        self.listpabarrotados=listpabarrotados
        self.listpvendidos=listpvendidos
    def venta(self,num):   
        self.ingresos += self.precio
        return self.ingresos
        
    def abarrotado(self):
        if self.pabarrotados==0:
            print("No hay productos abarrotados.")
        else:
            self.nproductos-=1 
            self.pabarrotados+=1
            self.listpabarrotados.append(self.nombre)
            print(f"Hay {self.pabarrotados} productos abarrotados.")
            print(self.listpabarrotados)

    def productos_vendidos(self):
        if self.pvendidos== 0:
            print("No hay productos vendidos...")
        else:
            self.listpvendidos.append(self.nombre)
            self.pvendidos+=1
            print(f"Hay {self.pvendidos} productos vendidos.")
            print(self.listpvendidos)

def venta(objProd):
    objProd.venta()
def abarrotado(objProd):
    objProd.abarrotado()

objproductov = Ventas(nombre="leche", stock=5, precio=20, nproductos=40, pabarrotados=0,pvendidos=0 , ingresos=0, productos={"lacteos":"leche"},listpabarrotados=[], listpvendidos=[] ) 

while True:
    print("Registro de Ventas")
    print("1. Productos vendidos")
    print("2. Productos abarrotados")
    print("3. Ingresos")
    print("4. Salir")
    opcventas=int(input("Ingrese una opción: "))
    if opcventas==1:
        objproductov.productos_vendidos()
    elif opcventas==2:
        objproductov.abarrotado()
    elif opcventas==3:
        print(f"Los ingresos son de: {objproductov.ingresos}.")
    elif opcventas==4:
        break
    else:
        print("Opción no valida...")
    