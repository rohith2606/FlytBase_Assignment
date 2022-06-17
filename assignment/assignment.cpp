#include <cpp_api/navigation_bridge.h>
#include <iostream>
#include <ros/package.h>
Navigation nav;

int main(int argc, char *argv[]){
float alt = std::stof(argv[1]);

if(!nav.arm()){std::cout<<"Waiting for arm \n";}

nav.take_off(alt);

if(*argv[2] == 's' ){
std::cout<<"Square Pattern \n";
nav.position_set(6.5,0,-alt);
nav.position_set(6.5,6.5,-alt);
nav.position_set(0,6.5,-alt);
nav.position_set(0,0,-alt);
nav.land(false);
}

if(*argv[2] == 't' ){
std::cout<<"Triangle Pattern \n";
nav.position_set(5,5,-alt);
nav.position_set(0,10,-alt);
nav.position_set(0,0,-alt);
nav.land(false);
}

}
