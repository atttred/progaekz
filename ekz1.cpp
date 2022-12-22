#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class student {
private:
    string fullname;
public:
    student() {
        fullname = "null";
    }

    friend istream& operator>>(istream& is, student& x) {
        is >> x.fullname;
        return is;
    }

    friend ostream& operator<<(ostream& os, student& x) {
        os << x.fullname << endl;
        return os;
    }
    string getfullname() { return fullname; };
    string setfullname(student& x) { fullname = x.fullname; };

};

class group {
private:
    int size;
    string name;
    int year;
    student* students;
public:
    group() {
        size = 0;
        name = "null";
        year = 0;
        students = new student[size];
    }
    group(int x, string a, int b) {
        size = x;
        name = a;
        year = b;
        students = new student[size];
    }
    group(const group& x) {
        size = x.size;
        name = x.name;
        year = x.year;
        students = new student[size];
        for (size_t i = 0; i < size; i++)
        {
            students[i] = x.students[i];
        }
    }

    //group& operator=(const group& x) {
    //    if (this != &x) {
    //        size = x.size;
    //        name = x.name;
    //        year = x.year;
    //        delete[] students;
    //        for (size_t i = 0; i < size; i++)
    //        {
    //            students[i] = x.students[i];
    //        }
    //    }
    //    return *this;
    //}

    student& operator[](const int n) {
        return students[n];
    }
    friend istream& operator>>(istream& is, group& x) {
        is >> x.size >> x.name >> x.year;
        delete[] x.students;
        x.students = new student[x.size];
        for (int i = 0; i < x.size; i++)
        {
            is >> x.students[i];
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, group& x) {
        os << "The size of the group: " << x.size << endl
            << "The name of the group: " << x.name << endl
            << "The starting year of the group: " << x.year << endl << endl;
        for (size_t i = 0; i < x.size; i++)
        {
            os << "The " << i + 1<< " student: " << x.students[i] << endl;
        }
        return os;
    }

    int getsize() { return size; };
    string getname() { return name; };
    int getyear() { return year; };
    student* getstudents() { return students; };

    void setsize(const int n) { size = n; };
    void setname(const string n) { name = n; };
    void setyear(const int m) { year = m; };

    friend void sort(group* arr, int n);
    friend void print(group* arr, int n);
    friend void printst(group arr);
    friend void checkyear(group* arr, int n);
    friend group checkst(group* arr, int n);

    ~group() {
        delete[] students;
    }
};

void sort(group* arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].getname() > arr[j + 1].getname())
                swap(arr[j], arr[j + 1]);
}
void print(group* arr, int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}

void checkyear(group* arr, int n) {
    int temp = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (temp < arr[i].getyear()) {
            temp = arr[i].getyear();
        }
    }
    
    for (size_t i = 0; i < n; i++)
    {
        if (temp == arr[i].getyear()) {
            printst(arr[i]);
        }
    }
}

group checkst(group* arr, int n) {
    int ind = 0;
    int temp = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (temp > arr[i].getsize()) {
            ind = i;
            temp = arr[i].getsize();
        }
    }

    group neew(arr[ind]);
    return neew;
}

void printst(group arr) {
    for (size_t i = 0; i < arr.getsize(); i++)
    {
        cout << "The info about student of the youngest group: " << arr[i].getfullname() << endl<<endl;
    }
}

int main()
{
    int num;
    cout << "Enter the num of the groups: " << endl;
    cin >> num;
    group* hrupy = new group[num];
    for (size_t i = 0; i < num; i++)
    {
        cout << "Enter the info about the " << i + 1 << " group: \n";
        cin >> hrupy[i];
    }
    cout << "<------------------------>\n";

    group* sorted = new group[num];
    sorted = hrupy;
    //sort(sorted, num);
    print(sorted, num);
    cout << "<------------------------>\n";

    checkyear(hrupy, num);
    
    group x = checkst(hrupy, num);

}

