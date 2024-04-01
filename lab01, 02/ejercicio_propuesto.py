# pylint: disable=E0401
import pandas as pd
class Inventario:
    def __init__(self):
        self.inventario = {}

    def registrar_producto(self,producto,precio,cantidad):
        self.inventario[producto] = {"precio": precio , "cantidad": cantidad}
        print("producto registrado")

    def mostrar_inventario(self):
        for producto, informacion in self.inventario.items():
            print(f"\n PRODUCTO: {producto}, Precio: {informacion['precio']}, Cantidad: {informacion['cantidad']}\n")
            
class Ventas(Inventario):
    def __init__(self):
        super().__init__()
        self.productos_vendidos =[]
        self.nventas=0
    def registrar_venta(self,producto,ctd):
        self.productos_vendidos.append(producto)
        self.nventas+=ctd
    def mostrar_vendidos(self):
        print(self.productos_vendidos)

class Pedidos(Inventario):
    def __init__(self,npedidos):
        super().__init__()
        self.npedidos=npedidos
    def registrar_venta(self,ctd):
        if producto in self.inventario and self.inventario[producto]['cantidad'] >= ctd:
            self.inventario[producto]['cantidad'] -= ctd
            self.npedidos += ctd
            print("Su pedido está listo...")
        else:
            print("Stock insuficiente...")

class Registros:
    def __init__(self):
        self.ventas = []
    def ver_venta(self, venta):
        self.ventas.append(venta)
    def reporte_de_ventas(self):
        datos_ventas = []
        for venta in self.ventas:
            datos_ventas.append({
                'CD': venta['cd'],
                'Producto': venta['producto'],
                'Calidad': venta['cantidad'],
                'Total': venta['total']
            })
        ventas_df = pd.DataFrame(datos_ventas)
        print("Reporte de Ventas:")
        print(ventas_df)
def registrar_venta(objeto):
    objeto.registrar_venta()
registros = Registros()
mi_inventario = Inventario()
ventas=Ventas()

while True:
    print("\n ****************\n 1.INVENTARIO \n 2.VENTAS \n 3.PEDIDOS \n 4.REPORTES \n 5.SALIR \n ****************")
    opc= int(input(": "))
    
    if opc ==1:
        while True:
            print("\n ****************\n INVENTARIO \n ****************")
            print("\n ****************\n 1.Registrar Producto \n 2.salir \n ****************")
            opcprod = int(input("ingrese una opcion: "))
            if opcprod == 1:
                producto = str(input("ingrese el nombre del producto: "))
                precio = int(input("ingrese el precio del producto: "))
                cantidad = int(input("ingrese la cantidad que se ingresara al inventario: "))
                mi_inventario.registrar_producto(producto,precio,cantidad)
            elif opcprod == 2:
                print("Saliendo...")
                break
            else:
                print("Opción no valida...")

    elif opc==2:
        while True:
            print("\n ****************\n VENTAS \n ****************")
            print("\n ****************\n 1.Productos Vendidos \n 2.salir \n ****************")
            opcvent = int(input("ingrese una opción: "))
            if opcvent == 1:
                ventas.mostrar_vendidos()
            elif opcvent == 2:
                print("Saliendo...")
                break
            else:
                print("Opción no valida...")    

    elif opc==3:
        while True:
            print("\n ****************\n PEDIDOS \n ****************")
            print("\n ****************\n 1.Registrar Pedido \n 2.salir \n ****************")
            opcped=int(input("Ingrese una opción: "))
            if opcped==1:
                ctdcompra=int(input("Ingrese el número de productos a comprar: "))
                ventas.registrar_venta(producto, ctdcompra)
            elif opcped==2:
                print("Saliendo...")
                break
            else:
                print("Opción no valida...")

    elif opc==4:
        while True:
            print("\n ****************\n REGISTROS \n ****************")
            print("\n ****************\n 1.Reporte de Ventas \n 2.Reporte de Inventario \n 3.salir \n ****************")
            print("2. Reporte de Ventas")
            print("3. Salir")
            opcreg=int(input("Ingrese una opción: "))
            if opcreg==1:
                registros.reporte_de_ventas()
            elif opcreg==2:
                mi_inventario.mostrar_inventario()
            elif opcreg==3:
                print("Saliendo...")
                break
            else:
                print("Opción no valida...")