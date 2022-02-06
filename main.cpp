#include <iostream>

class Toy {
    std::string name;
public:
    Toy(std::string inName) : name(inName) {}

    Toy() : Toy("SomeName") {}

    std::string getName() {
        return name;
    }
};

class shared_ptr_toy {
    Toy *obj;
    int *counter;

    void delPrt() {
        --*counter;
        if (*counter == 0) {
            std::cout << "delete name: " << obj->getName() << std::endl;
            delete obj;
            delete counter;
        }
    }

public:
    shared_ptr_toy(std::string inNameToy) {
        obj = new Toy(inNameToy);
        counter = new int(1);
    }

    shared_ptr_toy() {
        obj = new Toy();
        counter = new int(1);
    }

    shared_ptr_toy(Toy *inToy) : obj(inToy) {
        counter = new int(1);
    }

    shared_ptr_toy(const shared_ptr_toy &oth) : obj(oth.obj), counter(oth.counter) {
        ++*counter;
    }

    shared_ptr_toy &operator=(const shared_ptr_toy &oth) {
        if (this == &oth) {
            return *this;
        }
        if (obj != nullptr) {
            delPrt();
        }
        obj = oth.obj;
        counter = oth.counter;
        ++*counter;
        return *this;
    }

    ~shared_ptr_toy() {
        delPrt();
    }

};

shared_ptr_toy make_shared_toy(std::string inNameToy) {
    return shared_ptr_toy(inNameToy);
}

shared_ptr_toy make_shared_toy() {
    return shared_ptr_toy();
}

shared_ptr_toy make_shared_toy(shared_ptr_toy& toyPtr) {
    return shared_ptr_toy(toyPtr);
}

int main() {
    shared_ptr_toy bone = make_shared_toy("Bone");
    shared_ptr_toy ball = make_shared_toy("Ball");
    shared_ptr_toy ball2 = make_shared_toy(ball);
    shared_ptr_toy ball3 = ball;
    shared_ptr_toy ball4(ball);

    return 0;
}
