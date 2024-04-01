class Inventario:
    def __init__(self):
        self.inventario = {}

    def registrar_producto(self,producto,precio,cantidad):
        self.inventario[producto] = {"precio": precio , "cantidad": cantidad}
        print("producto registrado")

    def mostrar_inventario(self):
        for producto, informacion in self.inventario.items():
            print(f"\n PRODUCTO: {producto}, Precio: {informacion['precio']}, Cantidad: {informacion['cantidad']}\n")



mi_inventario = Inventario()

while True:
    print("\n ****************\n 1.registrar producto \n 2.visualizar inventario \n 3.salir \n ****************")
    opc = int(input("ingrese una opcion: "))
    if opc == 1:
        producto = str(input("ingrese el nombre del producto: "))
        precio = int(input("ingrese el precio del producto: "))
        cantidad = int(input("ingrese la cantidad que se ingresara al inventario: "))
        mi_inventario.registrar_producto(producto,precio,cantidad)
    elif opc == 2:
        mi_inventario.mostrar_inventario()
    elif opc == 3:
        print("saliendo")
        break
    else:
        print("opcion invalida ingrese nuevamente")

    
    
    
    