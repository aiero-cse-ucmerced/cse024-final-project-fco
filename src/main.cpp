#include <Application.h>

int main() {

    Application app;

    cout << "something" << endl;
    cout << "something i guess?" << endl;


    cout << "maybe something?? << endl;


    int i = 0;
    while (i < 5) {
        cout << to_string(i) << " is a number. something idk..." << endl;
        i++;
    };
    
    return app.run();
}
