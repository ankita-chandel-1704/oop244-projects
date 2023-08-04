#include <iostream>
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include "Collection.h"


namespace sdds {
    using namespace std;
        class Search {
        public:
            template<typename T>
            bool search(const T array[], int arrlength, const char* key, Collection<T>& collection);
        };

       
        template<typename T>
        bool Search::search(const T array[], int arrlength, const char* key, Collection<T>& collection)
        {
            bool keyFound = false;
            for (int i = 0; i < arrlength; i++) {
               if (array[i] == key) {
                   collection.add(array[i]);
                   keyFound = true;
               }
            }
            return keyFound;
        }

}
#endif // !SDDS_SEARCH_H_