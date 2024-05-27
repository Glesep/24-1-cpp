#include <iostream>
    
using namespace std;

class Computer {
public:
    string manufacturer;
    string processor;
    int ramSize;
    int diskSize;
    double processorSpeed;

    double computePower() {
        return ramSize * processorSpeed;
    }
    double getRamSize() { return ramSize; }
    double getProcessorSpeed() { return processorSpeed; }
    int getDiskSize() { return diskSize; }
};

//IS-A Relationship: Notebook is a computer. -> 상속은 IS-A 관계에 있는 새로운 클래스를 쉽게 정의할 수 있게 한다.
class Notebook: public Computer {
public:
    double screenSize;
    double weight;

    double getScreenSize() {
        return screenSize;
    }
    
    double getWeight() {
        return weight;
    }
};


int main()
{
    Notebook yourNotebook;

    // Computer 클래스로부터 상속받은 멤버들을 사용할 수 있다.
    yourNotebook.manufacturer = "Dell";
    yourNotebook.processor = "AMD";
    yourNotebook.ramSize = 16;
    yourNotebook.diskSize = 512;
    yourNotebook.processorSpeed = 2.6;

    yourNotebook.screenSize = 15.0;
    yourNotebook.weight = 1.8;

    cout << yourNotebook.computePower() << endl;
    cout << yourNotebook.getScreenSize() << endl;
    
    return 0;
}
