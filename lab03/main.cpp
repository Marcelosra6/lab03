#include <iostream>
#include <vector>  
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

int getIntegerInput() {
    int input;
    cin >> input;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Se esperaba un número entero");
    }
    return input;
}
//SRP
//SRP
//SRP Y DIP
class Comentario{//SRP
    private:
        string texto;
        string nombre;
    public:
        Comentario() {}
        Comentario(string t, string n) : texto(t), nombre(n) {}
        string getTexto() const {
            return texto;
        }
        string getNombre() const {
            return nombre;
        }
        void Ingreso() {
            cout<<"Ingrese el comentario: ";
            getline(cin,texto);
            cout<<"Ingrese el nombre del autor del comentario: ";
            getline(cin,nombre);
        }
};

class Archivo {//SRP
    private:
        string nombre;
        string contenido;
    public:
        Archivo() {}
        Archivo(string n, string c) : nombre(n), contenido(c) {}
        string getNombre() const {
            return nombre;
        }
        string getContenido() const {
            return contenido;
        }
        void Ingreso() {
            cout<<"Ingrese el nombre del archivo: "<<endl;
            getline(cin,nombre);
            cout<<"Ingrese el contenido del archivo: "<<endl;
            getline(cin,contenido);
        }
};

class Proyecto {//SRP Y DIP
    private:
        string nombre;
        vector<Comentario> comentarios;
        vector<Archivo> archivos;
    public:
        Proyecto() {}
        Proyecto(string n) : nombre(n) {}
        string getNombre() const {
            return nombre;
        }
        void Añadir_comentario(Comentario comentario) {
            comentarios.push_back(comentario);
        }
        void Añadir_archivo(Archivo archivo) {
            archivos.push_back(archivo);
        }
        void Mostrar_comentario() const {
            cout<<"Comentarios sobre el proyecto '"<<nombre<<"':"<<endl;
            for (const auto& comentario : comentarios) {
                cout<<"----"<<comentario.getNombre()<<": "<<comentario.getTexto()<<endl;
            }
        }
        void Mostrar_archivo() const {
            cout<<"Archivos para el proyecto '"<<nombre<<"':"<<endl;
            for (const auto& archivo : archivos) {
                cout<<"----"<<archivo.getNombre()<<endl;
            }
        }
        void Ingreso() {
            cout<<"Ingresar un nombre para el proyecto: ";
            cin>>nombre;
        }
};

class Administrador {// SRP Y DIP
    private:
        vector<Proyecto> proyectos;
    public:
        void Crear_proyecto() {
            Proyecto proyecto;
            proyecto.Ingreso();
            proyectos.push_back(proyecto);
        }
        void Añadir_comentarioPro(int proyectoId) {
            if (proyectoId >= 0 && proyectoId < proyectos.size()) {
                Comentario comentario;
                comentario.Ingreso();
                proyectos[proyectoId].Añadir_comentario(comentario);
            } else {
                cout<<"La ID del proyecto es invalida"<<endl;
            }
        }
        void Añadir_archivoPro(int proyectoId) {
            if (proyectoId >= 0 && proyectoId < proyectos.size()) {
                Archivo archivo;
                archivo.Ingreso();
                proyectos[proyectoId].Añadir_archivo(archivo);
            } else {
                cout<<"La ID del proyecto es invalida"<<endl;
            }
        }
        void Mostrar_proyectos() const {
            cout<<"Proyectos:"<<endl;
            for (int i = 0; i < proyectos.size(); ++i) {
                cout<<"Id del Proyecto: "<<i<<" Nombre: "<<proyectos[i].getNombre()<<endl;
            }
        }
        void Mostrar_detallesPro(int proyectoId) const {
            if (proyectoId >= 0 && proyectoId < proyectos.size()) {
                proyectos[proyectoId].Mostrar_comentario();
                proyectos[proyectoId].Mostrar_archivo();
            } else {
                cout<<"La ID del proyecto es invalida "<<endl;
            }
        }
};
class Fechas_limite {
private:
    int dia;
    string mes;
    int hora;
public:
    Fechas_limite() {
        dia = 0;
        mes = "";
        hora = 0;
    }

    void ingresarDatos() {
        cout << "Ingrese el día: ";
        cin >> dia;

        cout << "Ingrese el mes: ";
        cin >> mes;

        cout << "Ingrese la hora: ";
        cin >> hora;
    }
   
    void imprimirTarea() {
        cout << "Vencimiento de su próxima tarea" << endl;
        cout << "Dia: " << dia << endl;
        cout << "Mes: " << mes << endl;
        cout << "Hora: " << hora << endl;
    }
};
class Task {//SRP
protected:
    string description; //Small description about the task
    int idEmployee; //who is going to do the task
    string taskName;
public:
    //Task name
    Task(string taskName, string description, int idEmployee){
        this -> taskName = taskName;
        this -> description = description;
        this -> idEmployee = idEmployee;
    }
    void showTaskInfotmation(){
        cout << "Task name: " << taskName << endl;
        cout << "Description: " << description << endl;

    }
    void getTaskName(){
    cout << taskName;}
    void getDescription(){
    cout << description;}  
    void getIDEmployee(){
    cout << idEmployee;}
};
class Progreso : public Task , public Fechas_limite{//SRP, LSP y DIP
private:
    int num_tareas;
    int num_tareas_entregadas;
    vector <string> lista_tareas;
    vector <string> lista_tareas_entregadas;
public:
    Progreso(int dia, string mes, int hora, string taskName, string description, int idEmployee, int num_tareas, int num_tareas_entregadas) : Task(taskName, description,idEmployee), Fechas_limite(){
        this->num_tareas=num_tareas;
    }
   
    void cargar_tarea(){
        this->num_tareas+=1;
        lista_tareas.push_back(this->taskName);
    }
    void mostrar_tareas_cargadas() {
        for (int i=0;i<this->num_tareas;i++){
            cout<<"Tarea "<<i+1<<": "<<this->lista_tareas[i]<<endl;
        }
    }
    void tarea_entregada(){
        this->num_tareas-=1;
        lista_tareas_entregadas.push_back(this->taskName);
    }
    void mostrar_tareas_entregadas() {
        for (int j=0;j<this->num_tareas;j++){
            cout<<"Tarea "<<j+1<<": "<<this->lista_tareas[j]<<endl;
        }
    }
};
int main()
{
    string nom_tarea, desc_tarea,month; int id, n_tareas, n_tareas_entregadas,day,hour;
    Administrador administrador;
    Progreso administrador_progreso(day,month,hour,nom_tarea,desc_tarea,id,n_tareas,n_tareas_entregadas);
    /*administrador_progreso.cargar_tarea();
    administrador_progreso.tarea_entregada();*/
   
    int opc1,opc2, opc_progreso;
    cout << "************ Bienvenido al menu ************" << endl;
    while(true){
        try {
            cout << "Seleccione: \n1.Tarea \n2.Proyecto \n3.Salir \n********************************************" << endl;
            opc1 = getIntegerInput();
           
            if(opc1 == 3) break;

            while(true){
                if (opc1 == 1){
                    cout << "Escoja una opcion\n1.Crear tarea \n2.asignar Tarea \n3.Establecer fecha limite\n4.Seguimiento del progreso \n5.Retroceder \n********************************************" << endl;
                    opc2 = getIntegerInput();
                   
                    if (opc2 == 5) break;

                    if (opc2 == 1){
                        cout << "Creando tarea..." << endl;
                        cout<<"Nombre de la tarea: ";cin>>nom_tarea;
                        cout<<"Descripción de la tarea: ";cin>>desc_tarea;
                        administrador_progreso.ingresarDatos();
                       
                        administrador_progreso.cargar_tarea();
                       
                        administrador_progreso.showTaskInfotmation();
                        administrador_progreso.imprimirTarea();
                    }
                    else if (opc2==2){
                        cout <<"Asignando tarea" << endl;//ISP
                    }
                    else if (opc2==3){
                    cout << "establecer fecha limite" << endl;//ISP
                    }
                    else if (opc2==4){
                        cout << "************ Progreso de la Tarea ************" << endl;//ISP
                        while (true){
                        cout<<"1. Mostrar tareas cargadas \n2.Mostrar tareas entregadas \n3. Retroceder\n********************************************"<<endl;
                        opc_progreso = getIntegerInput();
                            if (opc_progreso== 1){
                                administrador_progreso.mostrar_tareas_cargadas();
                            }
                            else if(opc_progreso== 2){
                                administrador_progreso.mostrar_tareas_entregadas();
                            }
                            else if(opc_progreso== 3){
                                cout << "\nRetrocediendo" << endl;
                                break;
                            }
                        }
                    }
                }
                else if (opc1 == 2){
                    cout<<"*****Creacion del proyecto*******"<<endl;
                    cout<<"1.Crear Proyecto  \n2.Añadir comentario \n3.Añadir archivos \n4.Mostrar Proyecto \n5.Detalles del proyecto \n6.Salir\n*********************"<<endl;
                    opc2 = getIntegerInput();
                    if (opc2==1){
                        administrador.Crear_proyecto();
                        cout <<"Creando proyecto..." << endl;
                    }
                    else if(opc2==2){
                        int proyectoId;
                        cout<<"Ingresar la ID del proyecto: ";
                        cin>>proyectoId;
                        cin.ignore();
                        administrador.Añadir_comentarioPro(proyectoId);
                        cout << "Comentario añadido" << endl;
                    }
                    else if(opc2==3){
                        int proyectoId;
                        cout<<"Ingresar la ID del proyecto: ";
                        cin>>proyectoId;
                        cin.ignore();
                        administrador.Añadir_archivoPro(proyectoId);
                    }
                    else if (opc2==4){
                        administrador.Mostrar_proyectos();
                    }
                    else if(opc2==5){
                        int proyectoId;
                        cout<<"Ingresar ID del proyecto: ";
                        cin>>proyectoId;
                        cin.ignore();
                        administrador.Mostrar_detallesPro(proyectoId);
                    }
                    else if(opc2==6){
                        cout << "\nSaliendo" << endl;
                        break;
                    }
                    else{
                        cout << "CARACTER INCORRECTO INGRESE NUEVAMENTE" << endl;
                        }
                    }
                }
            }

        catch(invalid_argument& e) {
            cout << e.what() << ". Intentelo de nuevo.\n";
        }
    }
   
    return 0;
}

