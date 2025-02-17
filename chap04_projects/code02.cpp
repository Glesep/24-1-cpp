#include <iostream>
#include <string>
using namespace std;


class Computer {
private:
    string processor = "AMD";
    int ramSize = 16;
    int diskSize = 500;
    double processorSpeed = 7.76543;
protected:
    string manufacturer;
public:
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
    double getScreenSize() {
        return screenSize;
    }

    double getWeight() {
        return weight;
    }

    void faulty_method() {
        cout << manufacturer << endl;       // notebook 클래스에서 상속받은 Computer클래스 속 private 멤버를 접근할 수 없다.
                                            // 그러나 protected로 정의된 멤버들은 Notebook 클래스에서 접근할 수 있다. 클래스 외부에서는 private 멤버와 같이 사용할 수 없다.
    }
};


int main()
{
    Notebook mine;
    mine.faulty_method();
    cout << mine.toString() << endl;        // toString 함수가 Computer에서 정의되었기 때문에 private인 객체에 접근 가능
    
    return 0;
}
