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

public:
    Person(double _weight, double _body_fat, double _calves, double _tights, double _back, double _chest, double _biceps): weight(_weight), body_fat(_body_fat), tights(_tights), back(_back), chest(_chest), biceps(_biceps){
        updateMuscleMass();
    }
    double getWeight() const{
        return weight;
    }
    void setWeight(double _weight) {
        weight = _weight;
        updateMuscleMass();
    }
    double getBodyFat() const{
        return body_fat;
    }
    void setBodyFat(double _body_fat) {
        body_fat = _body_fat;
        updateMuscleMass();
    }
    double getCalves() const{
        return calves;
    }
    double getTights() const{
        return tights;
    }
    double getBack() const{
        return back;
    }
    double getChest() const{
        return chest;
    }
    double getBiceps() const{
        return biceps;
    }
    double getMuscleMass() const{
        return muscle_mass;
    }
};

class Exercise {
public:
    virtual void do_exercise(double &body_part, double &body_fat) {}
};

int main() {
    return 0;
}
