# pylint: disable=E0401
import pandas as pd
class InventarioT:
    def __init__(self):
        self.productos = []
    def añadir_productos(self, producto):
        self.productos.append(producto)
    def reporte_de_inventario(self):
        listaInv = []
        for producto in self.productos:
            listaInv.append({
                'CD': producto['cd'],
                'Nombre': producto['nombre'],
                'Cantidad': producto['cantidad']
            })
        inventario_df = pd.DataFrame(listaInv)
        print("Inventory Report:")
        print(inventario_df)

class Ventas:
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

inventario = InventarioT()
ventas = Ventas()
inventario.añadir_productos({'cd': 1, 'Nombre': 'Leche', 'Cantidad': 100})
inventario.añadir_productos({'cd': 2, 'Nombre': 'Pan', 'Cantidad': 50})
ventas.ver_venta({'cd': 1, 'Producto': 'Leche', 'Cantidad': 5, 'Total': 12.5})
ventas.ver_venta({'cd': 2, 'Producto': 'Pan', 'Cantidad': 2, 'Total': 5.0})
inventario.reporte_de_inventario()
ventas.reporte_de_ventas()