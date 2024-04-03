#include <iostream>
#include <vector>   
using namespace std;

class Comentario{
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

class Archivo {
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

class Proyecto {
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

class Administrador {
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

class Task {
private:
    string description; //Small description about the task
    int idEmployee; //who is going to do the task
public:
    string taskName; //Task name
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

class Progreso : public Task{
private:
    //atributo heredado 
    string nombre;
    string comentario;
    int num_tareas;
    int num_tareas_entregadas;
    vector <string> lista_tareas;
    vector <string> lista_tareas_entregadas;
public:
    Progreso( string taskName, string comentario, int num_tareas, int num_tareas_entregadas){
        this->nombre=nombre;
        this->num_tareas=num_tareas;
        this->comentario;
    }
    //atributo heredado 
    void getTaskName_p(){
        cout<<taskName;
    }
    void cargar_tarea(){
        this->num_tareas+=1;
        lista_tareas.push_back(this->nombre);
    }
    void mostrar_tareas_cargadas() {
        for (int i=0;i<this->num_tareas;i++){
            cout<<"Tarea "<<i+1<<": "<<this->lista_tareas[i]<<endl;
        }
    }
    void tarea_entregada(){
        this->num_tareas-=1;
        lista_tareas_entregadas.push_back(this->nombre);
    }
    void mostrar_tareas_entregadas() {
        for (int j=0;j<this->num_tareas;j++){
            cout<<"Tarea "<<j+1<<": "<<this->lista_tareas[j]<<endl;
        }
    }
    
};

int main()
{
    string com=" ";
    Progreso administrador("trabajo LP2",com,1,0); 
    administrador.cargar_tarea();
    administrador.tarea_entregada();
    int opc;
    cout << "************ Bienvenido al menu ************" << endl;
    while (true){
        cout << "Escoja una opcion\n1.Crear tarea \n2.asignar Tarea \n3.Establecer fecha limite\n4.Seguimiento del progreso \n5.Salir \n********************************************" << endl;
        cin >> opc;
        if (opc == 1){
            cout << "creando tarea" << endl;
        }
        else if (opc==2){
            cout <<"asignando una tarea" << endl;
        }
        else if (opc==3){
            cout << "estableciendo fecha limite" << endl;
        }
        else if (opc==4){
            int opc_progreso;
            cout << "************ Progreso de la Tarea ************" << endl;
            while (true){
                cout<<"1. Mostrar tareas cargadas \n2.Mostrar tareas entregadas \n3. Agregar comentario \n4. Salir\n********************************************"<<endl;
                if (opc==1){
                    administrador.mostrar_tareas_cargadas();
                }
                else if(opc==2){
                    administrador.mostrar_tareas_entregadas();
                }
                else if(opc==3){
                    cout<<"Comentario: ";cin>>com;
                    administrador.agregar_comentario();
                }
                else if(opc==4){
                    cout << "\nSaliendo" << endl;
                    break;
                }
                else{
                    cout << "CARACTER INCORRECTO INGRESE NUEVAMENTE" << endl;
                }
            }
        }
        else if (opc==5){
            cout << "\nSaliendo" << endl;
            break;
        }
        else{
            cout << "\nCARACTER INCORRECTO INGRESE NUEVAMENTE" << endl;
        }
    }
    
    return 0;
}
