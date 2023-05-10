#include <iostream>
#include <fstream>
#include <stdio.h>
#include <climits>
#include <cmath>

#include <iterator>

#include <vector>
#include <string>

#include <float.h>

#define binary 2

using namespace std;
// or else ill have to do stuff like //std::cout

class Person {
    private:
        string disease;
    public:
        string name;
        int age;
        float height;
        bool isMale;
        bool isFemale;

        Person(){
            cout << "Behold a child is born on Earth." << endl;
        };

        void darnell(){
            name = "Darnell Baird";
            age = 24;
            height = 183;
            isMale = true;
            isFemale = false;
        };

        bool handsome(){
            bool handsome = false;
            if(height > 180 && isMale && disease.length() == 0){
                handsome = true;
            }
            return handsome;
        }
        void shout(){cout << "Hey!" << endl;};
};

class Student : public Person{
    public:
        float gpa;
        int year = 1;

        Student(){
            cout << "A student is enrolled." << endl;
        };
        void shout(){cout << "Yahooooo!" << endl;};
};

char letter = 'd';
string phrase = "Goat mouth";

int count = 5;
float trinidad = 1.3e6;
double merica = 3.4E8;
const int fixed_interger = 4; 
int someNum;

int field[2][3] = {
    {0,0,0},
    {1,1,1},
};

bool isMale = true;

string sayHi(string nm, int age);

template <typename arrae>
int len(arrae arri[]);

int first(){
    cout << "Hello world from Microsoft Visual Studio Code." << endl;

    cout << trinidad << endl;
    cout << fmax(2,3) << endl;  //stupid function. only allows 2 arguments.

    cout << "Enter some string." << endl;

    //cin >> phrase;
    getline(cin, phrase);

    cout << "Here is the string. " << phrase << endl;

    // pointers return the memory address of the variable/container.
    int *pCount = &count;
    float *pTrinidad = &trinidad;
    // the * returns the variable of the pointer. dereference
    cout << &"String. " << " This is the memory location of a string. " << endl;
    cout << *pCount << " This is the variable of pCount. or just count. " << endl;

    return 0;
}

void second(){
    int lottery[] = {1,5,8,21,14,30};
    int container[5] = {};

    cout << lottery << container << endl;
    cout << sayHi("Darnell Baird", 23) << endl;
}

void ilfs(bool ifs[10]){
    //bool ifs[10] = {true, false, false};

    if(ifs[0]){
        cout << "Went through index 0" << endl;
    }
    else if(ifs[1] && ifs[2]){
        cout << "Went through index 1 and 2" << endl;
    }
    else if(ifs[3] || ifs[4]){
        cout << "Went through index 3 or 4." << endl;
    }

    int length = len(ifs);
    for (int i = 0; i < length; i++){
        cout << "Bool for index " << i << " is " << ifs[i] << endl;
    }
}

string swtch(char letter){
    //SWITCH ONLY ALLOWS INTEGRAL TYPES
    string word;
    switch(letter){
    case 'a':
        word = "apple";
        break;
    case 'b':
        word = "bat";
        break;
    case 'c':
        word = "cat";
        break;
    case 'd':
        word = "dog";
        break;
    case 'e':
        word = "elephant";
        break;
    default:
        word = "Not in the alphabet.";
    }
    return word;
}

void wildLopp(){
    int i = 1;
    int limit = 100;
    if(limit > i){
        while(i < limit){
            i++;
            cout << "Index " << i << endl;
        }
    }
}

void classPlay(){
    Person pl[4];

    Person conrad;
    conrad.name = "Conrad Baird";

    //Person darnell = Person.darnell()
    Person darnell;
    darnell.darnell();
    cout << darnell.name << ". Darnell's name." << endl;
};

template <typename arrae>
int len(arrae arri[]){
    int n = (sizeof(arri)/sizeof(*arri));
    //int n = size(arri);
    cout << "length of array " << arri << " is " << n << endl;
    return n;
};

template <typename arrayType>
void pythonPrint(arrayType ayy[], bool endIt)
{
    int length = len(ayy);
    for (int i=0; i<length; i++){
        cout << " " << ayy[i];
    };
    cout << endl;
};
//template <typename arrayType>
//void pythonPrint(arrayType ayy[]){ pythonPrint(ayy,true); }

int randInt(int low, int high){
    int range = high - low;
    int ans = rand() % range + low;
    return ans;
}

string sayHi(string nm, int age){
    cout << "Hi " << nm << ". you are " << age << " years old." << endl;
    string final = nm + " " + to_string(age);
    return final;
}

int allIntegralTypes(){
    // 1 byte or 8 bits
    char z = 'A';
    int zInt = (int) z;
    // 2 bytes or 16 bits
    short a;
    unsigned short aa;
    // 4 bytes or 32 bits
    int b;
    unsigned int bb;
    // 8 bytes or 64 bits
    long c;
    unsigned long cc;
    // 8 bytes or 64 bits
    long long d;
    unsigned long long dd;

    // this is how many bytes available for each variable.
    cout << "This is the size of the memory of the variable in bytes. " << sizeof(int) << endl;
    cout << "The maximum value of the datatype." << USHRT_MAX << "Another one." << LLONG_MIN << endl;

    return 0;
}

int interactiveWriteToFile(){
    return 0;
};

bool stringInString(string str1, string patt);
void writeToFile(string fileName, string text){
    if(!stringInString(fileName, ".txt")){
        fileName.append(".txt");
    }
    if(!stringInString(text,"\n")){
        text.append("\n");
    }

    ofstream myfile;
    myfile.open(fileName, ios::app);
    myfile << text;
    myfile.close();
}

void clearTextFile(string fileName){
};

bool stringInString(string str1, string patt){
    bool ans = str1.find(patt) != string::npos;
    return ans;
};

int cylinderPlots(){
    string fileName = "cylinderCoordinates.txt";
    //remove(fileName);

    string text;
    float x,y,rad;
    float r = 1;
    float dAlpha=5, dZ=1;
    float zLimit = 10;

    for (int z=0; z<=zLimit; z+=dZ){
        for (int a=0; a<=360; a+=dAlpha){
            rad = a*M_PI/180;
            x = r * sin(rad);
            y = r * cos(rad);
            text = to_string(x) + ',' + to_string(y) + ',' + to_string(z) + "\n";

            writeToFile(fileName, text);
        }
    }
};

string escapeCharacters(){  //escape sequences
    // for more info: https://www.ibm.com/support/knowledgecenter/SSAE4W_9.6.0/com.ibm.etools.iseries.langref.doc/as400clr33.htm
    //could be string or char
    char backSpace = '\b';
    char verticalTab = '\v';
    char beep = '\a';   //bell or alarm
    char tab = '\t';
    char nextLine = '\n';
    string lotsOfBeeps = "\a\a\a\a\a\a";
    char cLanguageEndString = '\0';
    char allChars[10] = {backSpace, verticalTab, beep, tab, nextLine, cLanguageEndString};

    //cout << beep * 10 << '\n';
    cout << beep << '\n';
};

float floats(){
    //floating point types
    float speed_of_light = 3E8;
    float mother_load = 10.0/3;
    float imaginary = NAN;
    float infinity_and_beyond = INFINITY;
    float infinity_and_beyond_backwards = -INFINITY;
    cout << "Speed of light is:" << std::fixed << speed_of_light << "km/s" << '\n';
    //cout << "Amount of trusted digits in float standard form: " << FLT_DIG << '\n';
    //cout << "Amount of trusted digits in double standard form: " << DBT_DIG << '\n';
    cout << "When you want to see memory suffer. " << fixed << mother_load << '\n'; //fixed is from std library.
    cout << "When you want to see memory suffer. " <<  mother_load << '\n';

    return 0;
}

string printMultipleSpacedString(){
    //NB. string is a variable type from std. i.e. std::string
    string inpot;
    string hint = "You could type whatever string you want and you will return all the string, even if it has whitespace characters.";

    cout << hint << endl;
    getline(cin, inpot);
    cout << inpot << '\n';
}

void myHeroEnum(){
    enum directions{north, south, east, west};
    directions hero = east;
    string ans;
    
    switch(hero){
        case north:
        ans = "The hero is going to the north pole.";
        break;
        case east:
        ans = "The hero is going to the middle east.";
        break;
        case south:
        ans = "The hero is going to antartica.";
        case west:
        ans = "The hero is going to England";
        default:
        ans = "I don't know where the hero is going.";
        break;  //no need for this
    }

    enum class Instruments{piano, guitar, flute, violin};
    Instruments iPlay = Instruments::guitar;
    string ans2;

    switch(iPlay){
        case Instruments::guitar:
        ans2 = "I play the guitar.";
        break;
        default:
        ans2 = "I don't care about anything else I play.";
        break; //not needed

        cout << ans2 << endl;
    }

    cout << ans << '\n';
}

int stoiTest(){
    string ans;
    int num;
    cout << "Enter a string. (Will be converted to number)" << endl;
    cin >> ans;
    //num = stoi(ans);
    //istringstream(ans) >> num;
    num = atoi(ans.c_str());
    cout << "The answer is:\n" << num;
    return num;
}


int main(){
    //first();

    //second();

    bool tries[] = {true, true, 5>2, false, true};
    //ilfs( tries );

    //classPlay();

    //pythonPrint(tries, true);

    //int allIntergralTypes();

    //cylinderPlots();

    //escapeCharacters();
    //printMultipleSpacedString();

    //floats();

    stoiTest();


    return 0;
}
