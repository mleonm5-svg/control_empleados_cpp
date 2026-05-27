#include <iostream>
#include "MySQLConexion.h"

using namespace std;

int main() {

    MySQLConexion conexion(
        "root",
        "Maynor1234",
        "control_empleados",
        "127.0.0.1",
        3306
    );

    if (conexion.open()) {

        cout << "Conexion exitosa a MySQL" << endl;

        MYSQL_RES* resultado;

        conexion.executeQuery("SELECT * FROM empleados");

        resultado = mysql_store_result(conexion.getConnection());

        MYSQL_ROW fila;

        cout << "\nLISTA DE EMPLEADOS\n";
        cout << "---------------------\n";

        while ((fila = mysql_fetch_row(resultado))) {

            cout << "ID: " << fila[0]
                 << " | Nombre: " << fila[1]
                 << " | Entrada: " << fila[2]
                 << " | Salida: " << fila[3]
                 << endl;
        }

        mysql_free_result(resultado);

    } else {

        cout << "Error al conectar a MySQL" << endl;
    }

    return 0;
}