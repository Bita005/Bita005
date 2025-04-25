#include <iostream>
using namespace std;
class DinamicArray {
  private:
      int *DA;
      int Size;
  public:
      DinamicArray (int s){
          Size=s;
          DA=new int [Size];
          for(int i=0;i<Size;i++)
            DA[i]=-1;
      }
  void setValue(int index , int value){
      if (index >= 0 && index< Size)
        DA[index]= value;
      else
        cout<< "out of range";
  }
  int findMax()
{
    int Max = DA[0];
    for(int i=0 ; i<Size;i++){
        if (Max<DA[i])
            Max =DA[i];
        return Max;
    }

}
    void printArray() {
        cout << "Array elements: ";
        for (int i = 0; i < Size; i++)
            cout << DA[i] << " ";
        cout << endl;
    }

    int getSize() {
        return Size;
    }

    double calculateAverage() {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < Size; i++) {
            if (DA[i] != -1) {
                sum += DA[i];
                count++;
            }
        }
        if (count == 0) return 0;
        return (double)sum / count;
    }

    void removeAtIndex(int index) {
        if (index >= 0 && index < Size)
            DA[index] = -1;
        else
            cout << "Index out of range!" << endl;
    }

    ~DinamicArray() {
        delete[] DA;
    }

};

int main() {
    DinamicArray arr(5);
    arr.setValue(0, 10);
    arr.setValue(1, 25);
    arr.setValue(2, 17);
    arr.setValue(3, 32);
    arr.setValue(4, 5);
    arr.printArray();
    cout << "Max value: " << arr.findMax() << endl;
    cout << "Average value: " << arr.calculateAverage() << endl;
    arr.removeAtIndex(2);
    arr.printArray();
    cout << "New average after removal: " << arr.calculateAverage() << endl;
    return 0;
}
