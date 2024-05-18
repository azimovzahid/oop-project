#include <iostream>
#include <vector>

class Person;

class Exercise {
public:
    virtual void do_exercise(Person &person) {}
};

class Person {
    double weight;
    double body_fat;
    double calves;
    double thighs;
    double back;
    double chest;
    double biceps;
    double muscle_mass;
    std::vector<Exercise *> plan;

    void updateMuscleMass(){
        muscle_mass = weight - weight*(body_fat/100);
    }

public:
    Person(double _weight, double _body_fat, double _calves, double _thighs, double _back, double _chest, double _biceps, const std::vector<Exercise *> &_plan): weight(_weight), body_fat(_body_fat), calves(_calves), thighs(_thighs), back(_back), chest(_chest), biceps(_biceps), plan(_plan){
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
    double getThighs() const{
        return thighs;
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
    void setCalves(double new_calves) {
        calves = new_calves;
    }
    void setThighs(double new_thighs) {
        thighs = new_thighs;
    }
    void setBack(double new_back) {
        back = new_back;
    }
    void setChest(double new_chest) {
        chest = new_chest;
    }
    void setBiceps(double new_biceps) {
        biceps = new_biceps;
    }
};

class Calf_raises: public Exercise {
    int sets;
    int reps;
public:
    Calf_raises(int _sets, int _reps): sets(_sets), reps(_reps) {}
    void do_exercise(Person &person) override {
        double multiplier = (double)sets * reps / 100;
        double calves = person.getCalves() * (1+multiplier);
        person.setCalves(calves);
        double newBodyFat = person.getBodyFat() * (1-multiplier/10);
        person.setBodyFat(newBodyFat);
    }
};

class Lunges: public Exercise {
    int sets;
    int reps;
public:
    Lunges(int _sets, int _reps): sets(_sets), reps(_reps) {}
    void do_exercise(Person &person) override {
        double multiplier = (double)sets * reps / 100;
        double thighs = person.getThighs() * (1 + multiplier);
        person.setThighs(thighs);
        double newBodyFat = person.getBodyFat() * (1-multiplier/10);
        person.setBodyFat(newBodyFat);
    }
};

class Deadlift: public Exercise {
    int sets;
    int reps;
    double weights;
public:
    Deadlift(int _sets, int _reps, double _weights): sets(_sets), reps(_reps), weights(_weights) {}
    void do_exercise(Person &person) override {
        double multiplier = (double)sets * reps * (weights/10) / 100;
        double back = person.getBodyFat() * (1+multiplier);
        person.setBack(back);
        double newBodyFat = person.getBodyFat() * (1-multiplier/10);
        person.setBodyFat(newBodyFat);
    }
};

class Pushups: public Exercise {
    int sets;
    int reps;
public:
    Pushups(int _sets, int _reps): sets(_sets), reps(_reps) {}
    void do_exercise(Person &person) override {
        double multiplier = (double)sets * reps / 100;
        double chest = person.getChest() * (1+multiplier);
        person.setChest(chest);
        double newBodyFat = person.getBodyFat() * (1-multiplier/10);
        person.setBodyFat(newBodyFat);
    }
};

class Dumbbell_curl: public Exercise {
    int sets;
    int reps;
    double weights;
public:
    Dumbbell_curl(int _sets, int _reps, double _weights): sets(_sets), reps(_reps), weights(_weights) {}
    void do_exercise(Person &person) override {
        double multiplier = (double)sets * reps * weights / 100;
        double biceps = person.getBiceps() * (1+multiplier);
        person.setBiceps(biceps);
        double newBodyFat = person.getBodyFat() * (1-multiplier/10);
        person.setBodyFat(newBodyFat);
    }
};

int main() {
    return 0;
}
