#include <iostream>
#include <string>


// task 1
class Liquid
{
protected:
    std::string name;
    double density;

public:
    Liquid(std::string name, double density)
    {
		this->name = name;
		this->density = density;
    }
    ~Liquid() {};

    void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Density: " << density << std::endl;
	}
};

class Alcohol : public Liquid
{
private:
    double alcohol_strength;
public:
	Alcohol(std::string name, double density, double alcohol_strength) : Liquid(name, density) 
    {
		this->alcohol_strength = alcohol_strength;
    };
	~Alcohol() {};

    void new_data(std::string name, double density)
    {
		this->name = name;
		this->density = density;
    }

	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Density: " << density << std::endl;
		std::cout << "Alcohol strength: " << alcohol_strength << std::endl;
	}
};

// task 2
class Wheels
{
protected:
	double radius;
	int count;
	std::string name;
public:
	Wheels(std::string name, double radius, int count)
	{
		this->name = name;
		this->radius = radius;
		this->count = count;
	};
	~Wheels() {};
	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Radius: " << radius << std::endl;
		std::cout << "Count: " << count << std::endl;
	}
};

class Car : public Wheels
{
private:
	double speed;
public:
	Car(std::string name, double radius, int count, double speed) : Wheels(name, radius, count)
	{
		this->speed = speed;
	};
	~Car() {};
	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Radius: " << radius << std::endl;
		std::cout << "Count: " << count << std::endl;
		std::cout << "Speed: " << speed << std::endl;
	}
};

class Bicycle : public Wheels
{
private:
	double speed;
public:
	Bicycle(std::string name, double radius, int count, double speed) : Wheels(name, radius, count)
	{
		this->speed = speed;
	};
	~Bicycle() {};
	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Radius: " << radius << std::endl;
		std::cout << "Count: " << count << std::endl;
		std::cout << "Speed: " << speed << std::endl;
	}
};

// task 3

class Person
{
protected:
    std::string name;
    int age;

public:
    Person(std::string name = "", int age = 0)
        : name(name), age(age) {}

    Person(const Person& other)
    {
        name = other.name;
        age = other.age;
    }

    Person& operator=(const Person& other)
    {
        if (this != &other)
        {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& p)
    {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Person& p)
    {
        std::cout << "Enter name: ";
        std::getline(is, p.name);
        std::cout << "Enter age: ";
        is >> p.age;
        is.ignore();
        return is;
    }

    virtual ~Person() {}
};

class Teacher : public Person
{
private:
    std::string subject;

public:
    Teacher(std::string name = "", int age = 0, std::string subject = "")
        : Person(name, age), subject(subject) {}

    Teacher(const Teacher& other)
        : Person(other)
    {
        subject = other.subject;
    }

    Teacher& operator=(const Teacher& other)
    {
        if (this != &other)
        {
            Person::operator=(other);
            subject = other.subject;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Teacher& t)
    {
        os << static_cast<const Person&>(t) << ", Subject: " << t.subject;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Teacher& t)
    {
        is >> static_cast<Person&>(t);
        std::cout << "Enter subject: ";
        std::getline(is, t.subject);
        return is;
    }

    ~Teacher() {}
};

int main()
{
	//      task 1
	Liquid water("Water", 1000);
	Alcohol whiskey("whiskey", 800, 40);
	whiskey.print();
	whiskey.new_data("whiskey", 900);
	water.print();
	whiskey.print();

	std::cout << "----------------------------------" << std::endl;
	
	//      task 2
	Wheels wheels("winter tire", 20, 4);
	Car car("Honda Civic", 20, 4, 100);
	Bicycle bicycle("Ukrayina", 20, 2, 10);

	car.print();
	bicycle.print();
	wheels.print();

	std::cout << "----------------------------------" << std::endl;

	//      task 3
    Teacher t1;
    std::cout << "Fill in teacher information:\n";
    std::cin >> t1;

    std::cout << "\nTeacher details:\n";
    std::cout << t1 << std::endl;

    std::cout << "\nTesting copy constructor:\n";
    Teacher t2 = t1;
    std::cout << t2 << std::endl;

    std::cout << "\nTesting assignment operator:\n";
    Teacher t3;
    t3 = t1;
    std::cout << t3 << std::endl;

}