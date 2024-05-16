#include <iostream>

class Person {
    double weight;
    double body_fat;
    double calves;
    double tights;
    double back;
    double chest;
    double biceps;
    double muscle_mass;

    void updateMuscleMass(){
        muscle_mass = weight - weight*(body_fat/100);
    }
};

int main() {
    return 0;
}
