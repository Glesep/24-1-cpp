#include <iostream>
#include <string>
using namespace std;

class Computer {
private:
    string manufacturer;
    string processor;
    int ramSize;
    int diskSize;
    double processorSpeed;

public:
    Computer() = default;
    Computer(string man, string proc, int ram, int disk, double procSpeed): manufacturer(man), processor(proc), ramSize(ram), 
                    diskSize(disk), processorSpeed(procSpeed) {}

    double computePower() {
        return ramSize * processorSpeed;
    }

    double getRamSize() { return ramSize; }
    double getProcessorSpeed() { return processorSpeed; }
    int getDiskSize() { return diskSize; }

    // 오버라이딩할 메소드를 virtual 메소드로 선언: 오버라이딩을 할 수 있게 만듦(무조건 오버라이딩되어야 한다는 것은 아님)
    virtual string toString() {
        string result = "Manufacturer: " + manufacturer + 
                        "\nCPU: " + processor +
                        "\nRAM " + to_string(ramSize) + " megabytes" +
                        "\nDisk: " + to_string(diskSize) + " gigabytes"+
                        "\nProcessor speed: " + to_string(processorSpeed) + "gigahertz"; 
        return result;
    }
};

class Notebook: public Computer {
private: 
    double screenSize;
    double weight;
public:
    Notebook() = default;
    // 파셍 클래스의 멤버들 중 베이스 클래스에 속한 멤버들은 베이스클래스의 생성자를 이용해 초기화한다.
    // 파생 클래스의 생성자를 호출할 때는 베이스클래스의 생성자를 명시적으로 호출해준다. 그렇지 않으면 베이스클래스의 디폴트 생성자를 자동 호출한다.
    Notebook(string man, string proc, int ram, int disk, double procSpeed, double screen, double weight):
                    Computer(man, proc, ram, disk, procSpeed), screenSize(screen), weight(weight) {}

    // Method Overriding (파생클래스에서 virtual로 선언 안하더라도 base class에서 선언을 하였기 때문에 virtual 메소드로 간주된다.)
    string toString() override {
        string result = Computer::toString() +      // Computer의 toString() 메소드를 호출 -> Computer의 private 멤버 접근 가능
                        "\nScreen size: " + to_string(screenSize) + " inches" +
                        "\nWeight: " + to_string(weight) + " pounds";
        return result;
    }

    double getScreenSize() {
        return screenSize;
    }

    double getWeight() {
        return weight;
    }
};

int main()
{
    Computer myComputer("Acme", "Intel", 2, 160, 2.4);
    Notebook yourComputer("DellGate", "AMD", 4, 240, 1.8, 15.0, 7.5);

    // cout << yourComputer.getRamSize() << endl;
    // cout << yourComputer.getDiskSize() << endl;
    // cout << yourComputer.getScreenSize() << endl;

    cout << "My computer is:\n" + myComputer.toString() << endl << endl;
    cout << "Your computer is:\n" + yourComputer.toString() << endl << endl;            // Notebook 클래스의 toString 메소드 사용
    cout << "Your computer is:\n" + yourComputer.Computer::toString() << endl;          // Computer 클래스의 toString 메소드 사용
    
    return 0;
}
