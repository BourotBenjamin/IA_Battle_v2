#include "Army.hpp"
#include "Terrain.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "training.hpp"
#include "fstream"

#include "OpenGLRenderer.h"

int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		Terrain::setMaxX(atoi(argv[1]));
		Terrain::setMaxY(atoi(argv[2]));
	}
	else
	{
		int x = 0;
		std::cout << "Largeur du terrain : ";
		std::cin >> x;
		int y = 0;
		std::cout << "Longueur du terrain : ";
		std::cin >> y;
		Terrain::setMaxX(x);
		Terrain::setMaxY(y);
	}
    std::srand(time(NULL));
    std::vector<std::unique_ptr<Army> > champions;
    try {
        std::ifstream in("Army_10_100.save");
        Army army = Army::load(in);
        std::cout<<army<<std::endl;
        champions.push_back(std::unique_ptr<Army>(new Army(army)));
    } catch(...) {

    }
    std::unique_ptr<Army> army = train(10,100, 20, 10, 100, champions);
    std::cout<<*army<<std::endl;
    std::ofstream out("Army_10_100.save");
    army->save(out);
    out.flush();
    out.close();
	system("pause");
    return 0;
}