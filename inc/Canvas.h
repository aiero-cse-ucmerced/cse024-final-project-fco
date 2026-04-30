// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/canvas.h>

namespace aiero {

    class Canvas : public bobcat::Canvas_ {
        
        
        public:
            bool checkMouseBounds(int x, int y) const {
                
                return true;
            };
    };
};

#endif