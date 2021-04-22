#include <iterator>

template<typename RandomIt>  //In fact, a forward iterator is sufficient if change some code.
class Sample{
    template<typename Compare>
    void selectionSort(RandomIt first, RandomIt last, Compare comp){
        for(auto i = first; i < last - 1; ++i){  //Use < for the case that first == last.
            auto min = i;
            for(auto j = i + 1; j != last; ++j){
                if(comp(*j, *min))
                    min = j;
            }
            std::iter_swap(i, min);  //or std::swap(*i, *min);
        }
    }

    template<typename Compare>
    void insertionSort(RandomIt first, RandomIt last, Compare comp){
        for(RandomIt i = first, j; i != last; ++i){
            auto t = *i;
            for(j = i; j != first; --j){
                if(comp(*(j-1), t))
                    break;
                *j = *(j-1);
            }
            *j = t;
        }
    }

    template<typename Compare>
    void bubbleSort(RandomIt first, RandomIt last, Compare comp){
        for(auto i = last - 1; i >= first; --i){  //Use >= for the case that first == last.
            for(auto j = first; j != i; ++j){
                if(comp(*(j+1), *j))
                    std::iter_swap(j, j+1);  //or std::swap(*j, *(j+1));
            }
        }
    }
public:
    enum SortAlgo{selection, insertion, bubble};

    template<SortAlgo algo, typename Compare>
    void sort(RandomIt first, RandomIt last, Compare comp){
        if constexpr(algo == selection)
            selectionSort(first, last, comp);
        else if constexpr(algo == insertion)
            insertionSort(first, last, comp);
        else if constexpr(algo == bubble)
            bubbleSort(first, last, comp);
    }
};