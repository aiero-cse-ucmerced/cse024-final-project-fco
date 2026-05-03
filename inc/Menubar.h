// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef MENUBAR_H
#define MENUBAR_H

#include <FL/Fl_Group.H>
#include <bobcat_ui/group.h>
#include <bobcat_ui/menu.h>
#include <bobcat_ui/window.h>

namespace aiero {
    class Menubar : public bobcat::Group {
        bobcat::Menu* _obj;
        std::vector<bobcat::MenuItem*> _items;

        virtual void onSelection(bobcat::Widget* sender) {};
        
        public:
            Menubar(int w, int h) : Group(0, 0, w, h) {
                _obj = new bobcat::Menu();
            };

            ~Menubar() {
                for (bobcat::MenuItem* mitem : _items)
                    delete mitem;

                _items.clear();

                delete _obj;
            };

            bobcat::MenuItem* operator[](int index) {
                if ((int) _items.size()-1 < index) throw "Non existent index";
                return _items[index];
            };

            bobcat::MenuItem* operator[](const std::string& menuName) {
                for (bobcat::MenuItem* mitem : _items) {
                    if (mitem->label() == menuName)
                        return mitem;
                }
                
                throw menuName + " does not exist as a menu item";
            };

            bobcat::MenuItem* addItem(std::string itemName) {
                bobcat::MenuItem* mitem = new bobcat::MenuItem(itemName);
                _obj->addItem(mitem);
                _items.push_back(mitem);
                
                Fl_Group::add(mitem); // important for tracking children of Menu

                ON_CLICK(mitem, Menubar::onSelection);
                
                return mitem;
            };
            
            void parent(bobcat::Window* par) { _obj->parent(par); };
            
    };

}

#endif
