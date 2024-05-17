#include <iostream>
#include <vector>

class Exercise {
public:
    virtual void do_exercise(double &body_part, double &body_fat) {}
};

class Person {
    double weight;
    double body_fat;
    double calves;
    double tights;
    double back;
    double chest;
    double biceps;
    double muscle_mass;
    std::vector<Exercise *> plan;

    void updateMuscleMass(){
        muscle_mass = weight - weight*(body_fat/100);
    }

public:
    Person(double _weight, double _body_fat, double _calves, double _tights, double _back, double _chest, double _biceps, const std::vector<Exercise *> &_plan): weight(_weight), body_fat(_body_fat), tights(_tights), back(_back), chest(_chest), biceps(_biceps), plan(_plan){
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

class Calf_raises: public Exercise {
    int sets;
    int reps;
public:
    Calf_raises(int _sets, int _reps): sets(_sets), reps(_reps) {}
    void do_exercise(double &calves, double &body_fat) override {
        double multiplier = (double)sets * reps / 100;
        calves = calves * multiplier;
    }
};

class Lunges: public Exercise {
    int sets;
    int reps;
public:
    Lunges(int _sets, int _reps): sets(_sets), reps(_reps) {}
    void do_exercise(double &thighs, double &body_fat) override {
        double multiplier = (double)sets * reps / 100;
        thighs = thighs * multiplier;
    }
};

class Deadlift: public Exercise {
    int sets;
    int reps;
    double weights;
public:
    Deadlift(int _sets, int _reps, double _weights): sets(_sets), reps(_reps), weights(_weights) {}
    void do_exercise(double &back, double &body_fat) override {
        double multiplier = (double)sets * reps * weights / 100;
        back = back * multiplier;
    }
};

class Pushups: public Exercise {
    int sets;
    int reps;
public:
    Pushups(int _sets, int _reps): sets(_sets), reps(_reps) {}
    void do_exercise(double &chest, double &body_fat) override {
        double multiplier = (double)sets * reps / 100;
        chest = chest * multiplier;
    }
};

class Dumbbell_curl: public Exercise {
    int sets;
    int reps;
    double weights;
public:
    Dumbbell_curl(int _sets, int _reps, double _weights): sets(_sets), reps(_reps), weights(_weights) {}
    void do_exercise(double &biceps, double &body_fat) override {
        double multiplier = (double)sets * reps * weights / 100;
        biceps = biceps * multiplier;
    }
};

int main() {
    return 0;
}
