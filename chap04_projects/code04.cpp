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

    string toString() {
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

    cout << yourComputer.getRamSize() << endl;
    cout << yourComputer.getDiskSize() << endl;
    cout << yourComputer.getScreenSize() << endl;

    cout << "My computer is:\n"
                + myComputer.toString() << endl;
    cout << "Your computer is:\n"
                + yourComputer.toString() << endl;          // Computer 클래스의 메소드이므로 screenSize와 weight를 출력할 수 없다. 
    
    return 0;
}
