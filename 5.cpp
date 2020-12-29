#include <iostream>

using namespace std;

class Cinematograph
{
protected:
    string producer, scenarist, name;

    Cinematograph(string producer, string scenarist, string name) : producer(producer), scenarist(scenarist), name(name)
    {

    }

    void showBasicInfo()
    {
        cout << "Producer - " << producer << endl;
        cout << "Scenarist - " << scenarist << endl;
        cout << "Name - " << name << endl;
    }

public:
    virtual void showInfo() = 0;
};

class Cinema : public Cinematograph
{
private:
    unsigned int duration;
    unsigned short part;

public:
    Cinema(string producer, string scenarist, string name, unsigned int duration, unsigned short part) : Cinematograph(producer, scenarist, name), duration(duration), part(part)
    {

    }

    void showInfo()
    {
        cout << "Cinema" << endl;
        showBasicInfo();
        cout << "Duration - " << duration << endl;
        cout << "Part - " << part << endl;
    }
};

class Ser : public Cinematograph
{
private:
    unsigned int parts, part;
    unsigned short season;

public:
    Ser(string producer, string scenarist, string name, unsigned int parts, unsigned int part, unsigned short season) : Cinematograph(producer, scenarist, name), parts(parts), part(part), season(season)
    {

    }

    void showInfo()
    {
        cout << "Ser" << endl;
        showBasicInfo();
        cout << "Parts - " << parts << endl;
        cout << "Part - " << part << endl;
        cout << "Season - " << season << endl;
    }
};

class Documentary : public Cinematograph
{
private:
    string theme, historicalMoment;

public:
    Documentary(string producer, string scenarist, string name, string theme, string historicalMoment) : Cinematograph(producer, scenarist, name), theme(theme), historicalMoment(historicalMoment)
    {

    }

    void showInfo()
    {
        cout << "Documantary" << endl;
        showBasicInfo();
        cout << "Theme - " << theme << endl;
        cout << "Historical moment - " << historicalMoment << endl;
    }
};

int main()
{
    Cinematograph* cinematograph = nullptr;

    int choose;
    cout << "1.Cinema 2.Ser 3.Documentary" << endl;
    cin >> choose;

    string producer, scenarist, name;
    cout << "Producer: ";
    cin >> producer;

    cout << "Scenarist: ";
    cin >> scenarist;

    cout << "Name: ";
    cin >> name;

    switch (choose)
    {
    case 1: 
    {
        unsigned int duration;
        unsigned short part;

        cout << "Duration: ";
        cin >> duration;

        cout << "Part: ";
        cin >> part;

        cinematograph = new Cinema{ producer, scenarist, name, duration, part };
        break;
    }
    case 2:
    {
        unsigned int parts, part;
        unsigned short season;

        cout << "Parts: ";
        cin >> parts;

        cout << "Part: ";
        cin >> part;

        cout << "Season: ";
        cin >> season;

        cinematograph = new Ser{ producer, scenarist, name, parts, part, season };
        break;
    }
    case 3:
    {
        string theme, historicalMoment;

        cout << "theme: ";
        cin >> theme;

        cout << "Historical moment: ";
        cin >> historicalMoment;

        cinematograph = new Documentary{ producer, scenarist, name, theme, historicalMoment };
        break;
    }
    default:
        return 0;
    }

    cinematograph->showInfo();
    delete cinematograph;

    return 0;
}
