/*
Author: Juan Pablo Echeagaray González (a00830646@itesm.mx)
main.cpp (c) 2021
Desc: Avances de la situación problema de POO2
Created:  2021-05-21T23:38:06.429Z
Modified: !date!
*/

#include <iostream>
#include "Peliculas.hpp"
#include "Series.hpp"

int menuPeliculas()
{
    int iOpcion;
/*     cout << "\n *******  Peliculas *******"
         << "\n1. Leer Peliculas  desde Archivo"
         << "\n2. Reporte de todas las peliculas"
         << "\n3. Reporte de peliculas que tienen cierta Calificacion"
         << "\n4. Reporte de peliculas de cierto genero"
         << "\n\n *******  Series *******"
         << "\n5. Leer Series  desde Archivo"
         << "\n6. Reporte de todas las Series"
         << "\n7. Reporte de Series que tienen cierta Calificacion"
         << "\n8. Reporte de Series de cierto genero"
         << "\n9. Calcular calificación de todas las Series"
         <<

        "\n\n0. SALIR\nTeclea la opcion:"; */
    cin >> iOpcion;
    return iOpcion;
}

int main()
{
    // se manda llamar al constructor - default
    Peliculas peliculas;
    Series series;

    int iOpcion;
    string sGenero, sId;
    double dCal;

    peliculas.leerArchivo();
    series.leerArchivo();
    iOpcion = menuPeliculas();

    while (iOpcion != 0)
    {
        switch (iOpcion)
        {
        case 1:
            peliculas.leerArchivo();
            break;
        case 2: 
            peliculas.reporteTodasLasPeliculas();
            break;
        case 3: 
            cin >> dCal;
            peliculas.reporteConCalificacion(dCal);
            break;
        case 4: 
            cin >> sGenero;
            peliculas.reporteGenero(sGenero);
            break;
        case 5:
            series.leerArchivo();
            break;
        case 6:
            series.reporteTodasLasSeries();
            break;
        case 7:
            cin >> dCal;
            series.reporteConCalificacion(dCal);
            break;
        case 8:
            cin >> sGenero;
            series.reporteGenero(sGenero);
            break;
        case 9:
            series.calcularCalificacionSeries();
            break;
        default:
            cout << "Opcion Incorrecta\n";
            break;
        }
        iOpcion = menuPeliculas();
    }
    return 0;
}