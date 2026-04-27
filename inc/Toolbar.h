#include <bobcat_ui/group.h>
#include <bobcat_ui/window.h>


class Toolbar : public bobcat::Group {
    int _x, _y, _w, _h;
    bobcat::Window* _obj;
    
    void _init(int x, int y, int w, int h) {
        _x = 0;
        _y = 0;
        _w = 0;
        _h = 0;

        _obj = new bobcat::Window(_x, _y, _w, _h, "");
        _obj->parent(nullptr);
    }
    
    public:

        Toolbar() : Group(0, 0, 0, 0) {
            _init(0, 0, 0, 0);
        };
        
        Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
            _init(x, y, w, h);
        };

        void parent(bobcat::Window* newParent) {
            _obj->parent(newParent);
        }
        
        int x() const { return _obj->x(); };
        int y() const { return _obj->y(); };
        int w() const { return _obj->w(); };
        int h() const { return _obj->h(); };

        
};