#include <iostream>
#include <vector>

#include "../include/BTree_t.hpp"
#include "../include/dni.hpp"


void    insert_key(BSTree_t<int>& tree);

void    extract_key(BSTree_t<int>& tree);

void    check_balance(BSTree_t<int>& tree);

int main(int argc, char* argv[]) 
{   
    int mode;
    std::cout << "Indique el modo a ejecutar: \n";
    std::cout << "[1] Simulación\n[2] Estadístico\nOpción: ";
    std::cin >> mode;

    if (mode == 1)
    {

        std::cout << "\t\t\t\t\t\tPROGRAMA DE SIMULACIÓN DE ÁRBOLES BINARIOS DE BÚSQUEDA\n";
        int op;
        BSTree_t<int> tree;
        do
        {
            std::cout << "\n\nElija una opción: \n";
            std::cout << "[0] Salir\n";
            std::cout << "[1] insertar clave\n";
            std::cout << "[2] extraer  clave\n";
            std::cout << "[3] comprobar equilibrio\n";
            std::cout << "Opción: ";
            std::cin >> op;
            switch (op)
            {
            case 1:
                insert_key(tree);
                break;

            case 2:
                extract_key(tree);
                break;
            case 3:
                check_balance(tree);
                break;


            case 0:
                break;
            default:
                std::cout << "\nERROR: Esa opción no existe";
                break;
            }


        } while (op != 0);
    
    }
    else if (mode == 2)
    {
       srand(time(NULL));
            
        int n = 0, tests = 0;
        std::cout << "Introduzca el tamaño del arbol: ";
        std::cin >> n;

        std::cout << "Introduzca el número de pruebas: ";
        std::cin >> tests;

        std::vector<dni> testbench;

        BSTree_t<dni> tester;

        for (int i = 0; i < 2*n; i++)
        {
            dni aux;
            testbench.push_back(aux);
            if ( i < n)
            {
                tester.insert(aux);
            }
        
        }



        int min = 1000000000;
        int max = 0;
        int accum = 0;
        dni::reset_c();
        std::cout << "\n\n\n\t\t\tNumero de comparaciones\n";
        std::cout << "\t\t\tN\tPruebas\tMinimo\tMedio\tMáximo\n";
        
        for(int i  = 0; i < tests; i++)
        {

               tester.search(testbench[i]);
                if ( min > dni::nth_compare())
                    min = dni::nth_compare();

                if ( max <  dni::nth_compare())
                    max = dni::nth_compare();

                accum += dni::nth_compare();

            
        }

        std::cout << "\tBusqueda\t" << n << "\t" << tests 
                  << "\t" << min << "\t" << accum/tests  << "\t" << max 
                  << "\n"; 


         min = 10000000;
         max = 0;
         accum = 0;
        dni::reset_c();


        for(int i  = n; i < tests+n; i++)
        {

                tester.search(testbench[i]);
                if ( min > dni::nth_compare())
                    min = dni::nth_compare();

                if ( max <  dni::nth_compare())
                    max = dni::nth_compare();

                accum += dni::nth_compare();

        }

        std::cout << "\tInserción\t" << n << "\t" << tests 
                  << "\t" << min << "\t" << accum/tests  << "\t" << max 
                  << "\n"; 


        std::cout << "\n\n" <<"Arbol: \n" << tester << "\n";

    }
    else
    {
        std::cout << "\n\n ERROR: No existe el modo \n";
    }
    

    

    return 0;
}



void    insert_key(BSTree_t<int>& tree)
{
    int num;
    std::cout << "Introduzca el entero a insertar: ";
    std::cin >> num;
    tree.insert(num);
    std::cout << "Tree state: \n\n" << tree << "\n";

}

void    check_balance(BSTree_t<int>& tree)
{
    int num;
    std::cout << "\n\ncomprobando equilibrio: \n";
    if (tree.balanced())
    {
        std::cout << tree << std::endl;
        std::cout << "arbol en equilibrio: \n";
        
    }
    else
        std::cout << "arbol no equilibrado: \n";
    
}



void    extract_key(BSTree_t<int>& tree)
{

    int num;
    std::cout << "Introduzca el entero a extrarer: ";
    std::cin >> num;
    if (tree.search(num) != NULL)
    {
        tree.extract(num);
        std::cout << "Tree state: \n\n" << tree << "\n";
    }
    else
    {
        std::cout << "Elemento no presente en la lista\n";
    }
     
}