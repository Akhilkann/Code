 #include <iostream>
#include "math.hpp"
    int main() {
	float Radius;
	std::cout<<"enter radius"<<std::endl;
	std::cin>>Radius;
	float Area = area(Radius);
	float Perim = perimeter(Radius);
        std::cout << "Area=" <<Area<<"\nperimeter="<<Perim<< std::endl;
        return 0;
    }

