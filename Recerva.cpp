#include <iostream>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>


 using namespace std;
 struct reserva
 {
     char categoria[100];
     char nombre[100];
     float extension;
     int dia;
     int mes;
     int anio;
     char localizacion[100];
     char clasificacion[100];
 };

void lectura(reserva lista[],int &numero_reserva);
void Agregar(reserva lista[],int &numero_reserva);
void Eliminar(reserva lista[],int &numero_reserva);
void Guardar(reserva lista[],int &numero_reserva);
void Busqueda_por_nombre(reserva lista[],int &numero_reserva);
void Busqueda_por_categoria(reserva lista[],int &numero_reserva);
void Busqueda_por_clasificacion(reserva lista[],int &numero_reserva);
void Enlistar(reserva lista[],int &numero_reserva);
void Bus_num(reserva lista[],int &numero_reserva);
int main()
{
 reserva lista[50];
 int numero_reserva=0;
 lectura(lista,numero_reserva);

 int opcion;

    do {
          system("cls");
          cout<<endl<<endl;
          cout<<"1.- Busquedas"<<endl;
          cout<<"2.- Agregar Registro"<<endl;
          cout<<"3.- Eliminar Registro"<<endl;
          cout<<"4.- Enlistar Todos Los Registros"<<endl;
          cout<<"5.- Salir"<<endl;

          cout<<"Escoge una opcion: ";

          cin>>opcion;

          switch (opcion){
                 case 1:
                      int opcion2;
                      do
                      {
                          system("cls");
                          cout<<endl<<endl;
                            cout<<"1.- Buscar por Nombre"<<endl;
                            cout<<"2.- Buscar por Categoria"<<endl;
                            cout<<"3.- Buscar por Clasificacion"<<endl;
                            cout<<"4.- Buscar por Numero de Reserva"<<endl;
                            cout<<"5.- Regresar al menu principal"<<endl;


                             cout<<"Escoge una opcion: ";
                            cin>>opcion2;
                            switch(opcion2)
                            {
                                case 1:
                                    Busqueda_por_nombre(lista,numero_reserva);
                                    break;
                                case 2:
                                    Busqueda_por_categoria(lista,numero_reserva);

                                    break;
                                case 3:
                                    Busqueda_por_clasificacion(lista,numero_reserva);

                                    break;
                                case 4:
                                    Bus_num(lista,numero_reserva);

                                    break;
                            }
                      }while (opcion2!=5);



                      break;



                 case 2:
                      system("cls");
                      Agregar(lista,numero_reserva);



                      break;



                 case 3:
                      system("cls");
                      Eliminar(lista,numero_reserva);

                      break;
                 case 4:
                     system("cls");
                      Enlistar(lista,numero_reserva);

                      break;


                 case 5:
                      system("cls");
                      Guardar(lista,numero_reserva);
                      cout<<"Has decidido salir, hasta luego";
                      getchar();
                      return 0;
                      break;

                 default:
                      cout<<"Opcion no encontrada, hubo un error, escriba unaopcion valida que se muestra en el menu";
                      getchar();
                      getchar();
                      break;



                 }

    } while (opcion != 5);


    return 0;
}

void lectura(reserva lista[],int &numero_reserva)
{
    FILE *a;
a= fopen("reserva.txt", "r");

if (a==NULL)
{
    cout<<"El archivo no se pudo abrir";
    exit (-1);
}

 reserva x;
 fscanf(a,"%i",&numero_reserva);
 //cout << "Numero: " << numero_reserva << endl;
 fgetc(a);
 for (int i=0; i<numero_reserva;i++)
 {

     fscanf(a,"%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,]",x.nombre);
     fgetc(a);
      fscanf(a,"%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,]",x.categoria);
      fgetc(a);
       fscanf(a,"%f",&x.extension);
       fgetc(a);
       fscanf(a,"%i",&x.dia);
       fgetc(a);
       fscanf(a,"%i",&x.mes);
       fgetc(a);
       fscanf(a,"%i",&x.anio);
       fgetc(a);
       fscanf(a,"%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 .,]",x.localizacion);
       fgetc(a);
       fscanf(a,"%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 .,]",x.clasificacion);
       fgetc(a);
       lista[i]=x;

    /*
     cout<<"   *************************************************************************"<<endl;
     cout<<"   -------------------------------------------------------------------------"<<endl<<endl<<endl;
     cout<<"\tCategoria: " << x.categoria<<endl;
     cout<<"\tNombre: " << x.nombre<<endl;
     cout<<"\tExtension: " << x.extension<<endl;
     cout<<"\tFecha: " <<x.dia<<"/"<<x.mes<<"/" << x.anio<<endl;
     cout<<"\tLocalizacion: " <<x.localizacion<<endl;
     cout<<"\tClasificacion: " <<x.clasificacion<<endl;
     cout << endl<<endl;
     cout<<"   *************************************************************************"<<endl;
     cout<<"   -------------------------------------------------------------------------"<<endl<<endl;
     getch();void Bus_num(reserva lista[],int &numero_reserva)
     system("cls");*/

}
//getch();
fclose(a);
}
void Agregar(reserva lista[],int &numero_reserva)
{
    reserva x;
    cout<<" Introduce los Datos"<<endl;

    cout<<" categoria:";cin.ignore();gets(x.categoria);
    cout<<" Nombre:";gets(x.nombre);
    cout<<" Extension:";cin>>x.extension;
    cout<<"       Fecha    "<<endl<<endl;
    cout<<" Dia:";cin>>x.dia;
    cout<<" Mes:";cin>>x.mes;
    cout<<" A"<<char(164)<<"o:";cin>>x.anio;
    cout<<endl;
    cout<<" Localizacion:";cin.ignore();gets(x.localizacion);
    cout<<endl;
    cout<<" Clasificacion:";cin.ignore();gets(x.clasificacion);
    cout<<endl;
    cout<<" Registro Agregado....";
    cout<<endl<<endl;
    lista[numero_reserva]=x;
    numero_reserva ++;
    system("pause");
}
void Eliminar(reserva lista[],int &numero_reserva)
{
    char nom[50];
    cout<<"introduce El nombre del area a eliminar:";cin.ignore();gets(nom);
    bool encontrado=false;
    for(int i=0;i<numero_reserva;i++)
    {
        if(strcmp(nom,lista[i].nombre)==0)//las cadenas son iguales
        {
            encontrado=true;
            cout<<"registro encontrado"<<endl;

             cout<<"categoria: " << lista[i].categoria<<endl;
             cout<<"Nombre: "<<lista[i].nombre<<endl;
             cout<<"Extension: "<<lista[i].extension<<endl;
             cout<<"Fecha: "<<lista[i].dia<<"/"<<lista[i].mes<<"/"<<lista[i].anio<<endl;
             cout<<"Localizacion: "<<lista[i].localizacion<<endl;
             cout<<"Clasificacion: "<<lista[i].clasificacion<<endl;

             for(int j=i;j<numero_reserva-1;j++)
             {
                 lista[j]= lista [j+1];
             }
             numero_reserva--;
             cout<<"registro eliminado"<<endl;
        }

    }
    if(encontrado== false)
        cout << "Esa reserva no se encuentra" << endl;
    getch();

}
void Guardar(reserva lista[],int &numero_reserva)
{
    FILE *a;
    a= fopen("reserva_copia1.txt", "w");

if (a==NULL)
{
    cout<<"El archivo no se pudo gurdar los cambios";
    exit (-1);
}

 fprintf(a,"%i\n",numero_reserva);

 for (int i=0; i<numero_reserva;i++)
 {

       fprintf(a,"%s",lista[i].categoria);
       fputc('-',a);
       fprintf(a,"%s",lista[i].nombre);
       fputc('-',a);
       fprintf(a,"%.2f",lista[i].extension);
       fputc('-',a);
       fprintf(a,"%i",lista[i].dia);
       fputc('/',a);
       fprintf(a,"%i",lista[i].mes);
       fputc('/',a);
       fprintf(a,"%i",lista[i].anio);
       fputc('-',a);
       fprintf(a,"%s",lista[i].localizacion);
       fputc('-',a);
       fprintf(a,"%s",lista[i].clasificacion);
       fputc('\n',a);





}

fclose(a);
}
void Busqueda_por_nombre(reserva lista[],int &numero_reserva)
{
    char nom[50];
    cout<<"introduce El nombre del area a buscar:";cin.ignore();gets(nom);
    cout<<endl;
    bool encontrado=false;
    for(int i=0;i<numero_reserva;i++)
    {
        if(strcmp(nom,lista[i].nombre)==0)//las cadenas son iguales
        {
            encontrado=true;
            cout<<"registro encontrado"<<endl;

             cout<<"Nombre: "<<lista[i].nombre<<endl;
             cout<<"categoria: " << lista[i].categoria<<endl;
             cout<<"Extension: "<<lista[i].extension<<endl;
             cout<<"Fecha: "<<lista[i].dia<<"/"<<lista[i].mes<<"/"<<lista[i].anio<<endl;
             cout<<"Localizacion: "<<lista[i].localizacion<<endl;
             cout<<"Clasificacion: "<<lista[i].clasificacion<<endl;
        }

    }
    if(encontrado== false)
        cout << "Esa reserva no se encuentra" << endl;

    cout << endl << endl;
     system("pause");

}
void Busqueda_por_categoria(reserva lista[],int &numero_reserva)
{
    char cat[50];
    cout<<"introduce El nombre del area a buscar:";cin.ignore();gets(cat);
    cout<<endl;
    bool encontrado=false;
    for(int i=0;i<numero_reserva;i++)
    {
        if(strcmp(cat,lista[i].categoria)==0)//las cadenas son iguales
        {
            encontrado=true;
            cout<<"registro encontrado"<<endl;

             cout<<"categoria: " << lista[i].categoria<<endl;
             cout<<"Nombre: "<<lista[i].nombre<<endl;
             cout<<"Extension: "<<lista[i].extension<<endl;
             cout<<"Fecha: "<<lista[i].dia<<"/"<<lista[i].mes<<"/"<<lista[i].anio<<endl;
             cout<<"Localizacion: "<<lista[i].localizacion<<endl;
             cout<<"Clasificacion: "<<lista[i].clasificacion<<endl;

        }

    }
    if(encontrado== false)
        cout << "Esa reserva no se encuentra" << endl;

    cout << endl << endl;
     system("pause");

}
void Busqueda_por_clasificacion(reserva lista[],int &numero_reserva)
{
    char cla[50];
    cout<<"introduce El nombre del area a buscar:";cin.ignore();gets(cla);
    cout<<endl;
    bool encontrado=false;
    for(int i=0;i<numero_reserva;i++)
    {
        if(strcmp(cla,lista[i].categoria)==0)//las cadenas son iguales
        {
            encontrado=true;
            cout<<"registro encontrado"<<endl;

             cout<<"categoria: " << lista[i].categoria<<endl;
             cout<<"Nombre: "<<lista[i].nombre<<endl;
             cout<<"Extension: "<<lista[i].extension<<endl;
             cout<<"Fecha: "<<lista[i].dia<<"/"<<lista[i].mes<<"/"<<lista[i].anio<<endl;
             cout<<"Localizacion: "<<lista[i].localizacion<<endl;
             cout<<"Clasificacion: "<<lista[i].clasificacion<<endl;
        }

    }
    if(encontrado== false)
        cout << "Esa reserva no se encuentra" << endl;

    cout << endl << endl;
     system("pause");

}

void Enlistar(reserva lista[],int &numero_reserva)
{
    for (int i=0; i<numero_reserva;i++)
    {
        reserva x = lista[i];
        system("cls");
     cout<<"   *************************************************************************"<<endl;
     cout<<"   -------------------------------------------------------------------------"<<endl<<endl<<endl;
     cout<<"\tCategoria: " << x.categoria<<endl;
     cout<<"\tNombre: " << x.nombre<<endl;
     cout<<"\tExtension: " << x.extension<<endl;
     cout<<"\tFecha: " <<x.dia<<"/"<<x.mes<<"/" << x.anio<<endl;
     cout<<"\tLocalizacion: " <<x.localizacion<<endl;
     cout<<"\tClasificacion: " <<x.clasificacion<<endl;
     cout << endl<<endl;
     cout<<"   *************************************************************************"<<endl;
     cout<<"   -------------------------------------------------------------------------"<<endl<<endl;
     cout << endl << endl;
     cout<<"                                     ";
     system("pause");
    }

}
void Bus_num(reserva lista[],int &numero_reserva)
{
    int bn;
    cout<<" Introduce el Numero de Reserva :";cin>>bn;

    while ( bn <= 0 || bn > numero_reserva)
    {
        cout << "Teclee un valor entre 1 y " << numero_reserva << ": ";
        cin>> bn;
    }

    reserva x = lista[bn-1];
        system("cls");
     cout<<"   *************************************************************************"<<endl;
     cout<<"   -------------------------------------------------------------------------"<<endl<<endl<<endl;
     cout<<"\tCategoria: " << x.categoria<<endl;
     cout<<"\tNombre: " << x.nombre<<endl;
     cout<<"\tExtension: " << x.extension<<endl;
     cout<<"\tFecha: " <<x.dia<<"/"<<x.mes<<"/" << x.anio<<endl;
     cout<<"\tLocalizacion: " <<x.localizacion<<endl;
     cout<<"\tClasificacion: " <<x.clasificacion<<endl;
     cout << endl<<endl;
     cout<<"   *************************************************************************"<<endl;
     cout<<"   -------------------------------------------------------------------------"<<endl<<endl;
     cout << endl << endl;
     cout<<"                                     ";
     system("pause");
}
