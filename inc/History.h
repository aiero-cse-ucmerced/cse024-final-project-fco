// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef HISTORY_H
#define HISTORY_H

#include <functional>
#include <vector>
#include <iostream>


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
        int maxRecord;
        
        std::vector<Record<A>> list;

        std::size_t _length() { return list.size(); };
        
    public:
        History() {
            _index = -1;
            maxRecord = 10;
        };
        
        ~History() {
            for (const auto& r : list) {
                if (r.remove)
                    r.remove(r.value);
            }

            list.clear();
        }

        int index() const { return _index; };
        int count() const { return list.size(); };

        virtual void preApply(const Record<A>& record) {
            // things to do before applying the record
        }

        void rewind() {
            if (_index-1 < 0) return;
            if (list.empty()) return;
            
            // std::cout << "current index:" << _index << std::endl;
            // std::cout << "last index: " << (int)_length() - 1 << std::endl;
            // std::cout << "attempting to rewind to index" << _index-1 << std::endl;
            
            _index -= 1;
            // std::cout << "calling history record " << _index+1 << " to remove itself" << std::endl;
            if (list[_index+1].remove) 
                list[_index+1].remove(list[_index+1].value);
            preApply(list[_index]);
            if (list[_index].apply)
                list[_index].apply(list[_index].value);
            // std::cout << "rewinded to index " << _index << " from previous index " << _index-1 << std::endl;
        };

        void forward() {
            if (_index+1 > (int) _length() - 1) return;
            if (list.empty()) return;

            _index += 1;
            // if (list[_index-1].remove)
            //     list[_index-1].remove(list[_index-1].value);
            preApply(list[_index]);
            if (list[_index].apply)
                list[_index].apply(list[_index].value);
            // std::cout << "forwarded to index " << _index << " from previous index " << _index-1 << std::endl;
            // preApply(list.back());
            // list.back()
        };

        void add(A arr) {
            const int latestIndex = _length() - 1;
            if (_index < latestIndex) {
                // Overwrite older records from the current index
                list.erase(list.begin()+_index+1, list.end());
            }

            if (_length()+1 > (std::size_t) maxRecord) {
                list.erase(list.begin());
            }

            // std::cout << "history " << _index+1 << " was created" << std::endl;

            _index += 1;            
            list.push_back({arr});
        };
        
        void add(A arr, std::function<void(A)> applyCb) {
            const int latestIndex = _length() - 1;
            if (_index < latestIndex) {
                // Overwrite older records from the current index
                list.erase(list.begin()+_index+1, list.end());
            }

            if (_length()+1 > (std::size_t) maxRecord) {
                list.erase(list.begin());
            }

            // std::cout << "history " << _index+1 << " was created" << std::endl;
            _index += 1;            
            list.push_back({arr, applyCb});
        };
        
        // with apply and remove callback
        void add(A arr, std::function<void(A)> applyCb, std::function<void(A)> removeCb) {
            const int latestIndex = _length() - 1;
            if (_index < latestIndex) {
                // Overwrite older records from the current index
                list.erase(list.begin()+_index+1, list.end());
            }

            if (_length()+1 > (std::size_t) maxRecord) {
                list.erase(list.begin());
            }

            _index += 1;            
            list.push_back({arr, applyCb, removeCb});
        };
        
        void erase() {
            if (list.empty()) return;

            for (const auto& r : list) {
                if (r.remove)
                    r.remove(r.value);
            }
            
            _index = -1;
            list.clear();
        }
        void clear() { erase(); };
    };
};


#endif