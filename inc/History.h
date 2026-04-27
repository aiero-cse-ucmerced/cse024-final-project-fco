#ifndef HISTORY_H
#define HISTORY_H

#include <functional>
#include <vector>


namespace aiero {
    template <typename U>
    struct Record {
        U value;
        std::function<void(U)> apply;
        std::function<void(U)> remove;
    };

    template <typename A>
    class History {
        int _index;
        
        std::vector<Record<A>> list;

        std::size_t _length() { return list.size(); };
        
    public:
        History() {
            _index = 0;
        };
        
        ~History() {
            for (Record r : list) {
                r.remove();
            }

            list.clear();
            delete this;
        }

        int index() const { return _index; };
        int count() const { return list.size(); };

        void preApply(Record<A> record) {
            // things to do before applying the record
        }

        void rewind() {
            if (_index-1 < 0) return;
            
            _index -= 1;
            preApply(list[_index]);
            list[_index].apply(list[_index].value);
        };

        void forward() {
            if (_index+1 > _length() - 1) return;

            _index += 1;
            preApply(list[_index]);
            list[_index].apply(list[_index].value);
            // preApply(list.back());
            // list.back()
        };


        void add(A arr) {
            if (_index == _length() - 1)
                _index += 1;
            
            list.push_back(arr);
        };
        
    };
};


#endif