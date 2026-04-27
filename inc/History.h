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
        }

        int index() const { return _index; };
        int count() const { return list.size(); };

        void preApply(Record<A> record) {
            // things to do before applying the record
        }

        void rewind() {
            if (_index-1 < 0) return;
            
            _index -= 1;
            list[_index+1].remove(list[_index+1].value);
            preApply(list[_index]);
            list[_index].apply(list[_index].value);
        };

        void forward() {
            if (_index+1 > _length() - 1) return;

            _index += 1;
            list[_index-1].remove(list[_index-1].value);
            preApply(list[_index]);
            list[_index].apply(list[_index].value);
            // preApply(list.back());
            // list.back()
        };

        void add(A arr) {
            const int lastIndex = _length() - 1;
            if (_index < lastIndex) {
                // Overwrite older records from the current index
                list.erase(list.begin()+_index, list.end());
            }

            _index += 1;            
            list.push_back(arr);
        };
        
        void erase() {
            _index = 0;
            list.clear();
        }
        void clear() { erase(); };
    };
};


#endif