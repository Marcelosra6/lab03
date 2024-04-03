#include <iostream>
#include <vector>   
#include <string>
using namespace std;
class Comentario{//SRP
    private:
        string texto;
        string nombre;
    public:
        Comentario(string t, string n) : texto(t), nombre(n) {}
        string getTexto() const {
            return texto;
        }
        string getNombre() const {
            return nombre;
        }
};

class Archivo {//SRP
    private:
        string nombre;
        string contenido;
    public:
        Archivo(string n, string c) : nombre(n), contenido(c) {}
        string getNombre() const {
            return nombre;
        }
        string getContenido() const {
            return contenido;
        }
};
//otras clases
class Proyecto {//SRP Y DIP
    private:
        string nombre;
        vector<Comentario> comentarios;
        vector<Archivo> archivos;
    public:
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
};

class Administrador {//SRP Y DIP
    private:
        vector<Proyecto> proyectos;
    public:
        void Crear_proyecto(string nombre) {
            proyectos.emplace_back(nombre);
        }
        void Añardir_comentarioPro(int proyectoId, Comentario comentario) {
            if (proyectoId >= 0 && proyectoId < proyectos.size()) {
                proyectos[proyectoId].Añadir_comentario(comentario);
            } else {
                cout<<"La ID del proyecto es invalida" << endl;
            }
        }
        void Añadir_archivoPro(int proyectoId, Archivo archivo) {
            if (proyectoId >= 0 && proyectoId < proyectos.size()) {
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
        cout << "ID Employee: " << idEmployee << endl;
    }
    void getTaskName(){
    cout << taskName;}
    void getDescription(){
    cout << description;}   
    void getIDEmployee(){
    cout << idEmployee;}
};
class Progreso : public Task{//SRP, LSP y DIP
private:
    int num_tareas;
    int num_tareas_entregadas;
    vector <string> lista_tareas;
    vector <string> lista_tareas_entregadas;
public:
    Progreso( string taskName, string description, int idEmployee, int num_tareas, int num_tareas_entregadas) : Task(taskName, description,idEmployee){
        this->num_tareas=num_tareas;
    }
    //atributo heredado 
    void getTaskName(){
        cout<<taskName;
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
    string nom_tarea, desc_tarea; int id, n_tareas, n_tareas_entregadas;
    Administrador admin_proyectos();
    Progreso administrador_progreso(nom_tarea,desc_tarea,id,n_tareas,n_tareas_entregadas); 
    /*administrador_progreso.cargar_tarea();
    administrador_progreso.tarea_entregada();*/
    char opc; //char para que acepte el ingreso de cualquier opcion
    cout << "************ Bienvenido al menu ************" << endl;
    //OCP
    while (true){
        cout << "Escoja una opcion\n1.Crear tarea \n2.Crear Proyecto \n3.Añadir Comentario\n4.Seguimiento del progreso de las Tareas \n5.Salir \n********************************************" << endl;
        cin >> opc;
        if (opc == '1'){//ISP
            cout << "Creando tarea..." << endl;
            cout<<"Nombre de la tarea: ";cin>>nom_tarea;
            administrador_progreso.getTaskName();
            administrador_progreso.cargar_tarea();
            administrador_progreso.cargar_tarea();
        }
        else if (opc=='2'){
            cout <<"Creando proyecto..." << endl;//ISP
        }
         else if (opc=='3'){
            cout << "Comentario añadido" << endl;//ISP
        }
        else if (opc=='4'){
            char opc_progreso;
            cout << "************ Progreso de la Tarea ************" << endl;//ISP
            while (true){
                cout<<"1. Mostrar tareas cargadas \n2.Mostrar tareas entregadas \n3. Salir\n********************************************"<<endl;
                cin>>opc_progreso;
                if (opc_progreso=='1'){
                    administrador_progreso.mostrar_tareas_cargadas();
                }
                else if(opc_progreso=='2'){
                    administrador_progreso.mostrar_tareas_entregadas();
                }
                 else if(opc_progreso=='3'){
                    cout << "\nSaliendo" << endl;
                    break;
                }
                else{
                    cout << "CARACTER INCORRECTO INGRESE NUEVAMENTE" << endl;
                }
            }
        }
         else if (opc=='5'){
            cout << "\nSaliendo" << endl;
            break;
        }
        else{
            cout << "\nCARACTER INCORRECTO INGRESE NUEVAMENTE" << endl;
        }
    }
    
    return 0;
}