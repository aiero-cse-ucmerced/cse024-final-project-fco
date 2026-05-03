// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

// Lead team note: Due to file recursion issue, only core tools will have access to Canvas

#ifndef BASE_TOOL_CLASS_H
#define BASE_TOOL_CLASS_H

#include "../Tool.h"
#include "../Canvas.h"

namespace aiero {
    class CoreTool : public aiero::Tool {
        protected:
            aiero::Canvas* Canvas;
        public:
            CoreTool() {
                Canvas = nullptr;
            };

            bool isCore() { return true; };
            
            // one-time internal setter for security
            void internalCanvas(aiero::Canvas* c) {
                if (Canvas != nullptr || c == nullptr) return;
                Canvas = c;
            };
    };
};

#endif