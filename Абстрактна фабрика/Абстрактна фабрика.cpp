#include <iostream>

class AbstractProductA {
public:
    virtual void display() = 0;
};


class AbstractProductB {
public:
    virtual void show() = 0;
};


class ConcreteProductA1 : public AbstractProductA {
public:
    void display() override {
        std::cout << "Concrete Product A1" << std::endl;
    }
};


class ConcreteProductA2 : public AbstractProductA {
public:
    void display() override {
        std::cout << "Concrete Product A2" << std::endl;
    }
};


class ConcreteProductB1 : public AbstractProductB {
public:
    void show() override {
        std::cout << "Concrete Product B1" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void show() override {
        std::cout << "Concrete Product B2" << std::endl;
    }
};


class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};


class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {

    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();

    productA1->display();
    productB1->show();


    delete productA1;
    delete productB1;
    delete factory1;

    return 0;
}
