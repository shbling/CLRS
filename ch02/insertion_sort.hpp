/***************************************************************************
 *  @file       insertion_sort.hpp
 *  @author     Alan.W
 *  @date       22  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! ex2.1-2
//! Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of non-
//! decreasing order.
//!
//!
//! ex2.3-4
//! We can express insertion sort as a recursive procedure as follows. In order to sort
//! A[1..n], we recursively sort A[1..n-1] and then insert A[n] into the sorted array
//! A[1..n-1]. Write a recurrence for the running time of this recursive version of
//! insertion sort.
//!

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <iterator.hpp>
#include <assert.h>
#include <functional>

namespace clrs { namespace ch2 {

/**
 * @brief insertion_sort
 * @param first
 * @param last
 *
 * @typename        Iter    iterator
 * @typename        Comp    callable
 *
 * @pseudocode      INSERTION-SORT, Page 18, CLRS
 * @exercise        ex2.1-2, Page 22, CLRS
 * @complx          O(n^2)
 */
template<typename Iter, typename Comp = std::greater<clrs::IterValue<Iter> > >
void insertion_sort(Iter first, Iter last, Comp compare = Comp())
{
    //! trivial case
    if(last - first < 2)    return;

    //! when more than two elements
    for(auto curr = first + 1; curr != last; ++curr)
    {
        auto key = *curr;

        //! insert into the sorted sequence
        auto prev = curr - 1;
        while(prev != first - 1  &&  compare(*prev, key))
        {
            *(prev + 1) =   *prev;
            --prev;
        }
        *(prev + 1) =   key;
    }
}

/**
 * @brief insertion_sort_recur
 * @param first
 * @param last
 *
 * @typename        Iter    iterator
 * @typename        Comp    callable
 *
 * @exercise        ex2.3-4, Page 39, CLRS
 * @complx          O(n^2)
 */
template<typename Iter, typename Comp = std::greater<clrs::IterValue<Iter> > >
void insertion_sort_recur(Iter first, Iter last, Comp compare = Comp())
{
    if(last - first > 1)
    {
        auto curr   =   last - 1;
        insertion_sort_recur(first, curr);  //recur

        //! find the right place
        auto prev   =   curr - 1;
        auto key    =   *curr;
        while(prev != first - 1     &&  compare(*prev, key))
        {
            *(prev + 1) =   *prev;
            --prev;
        }
        //! insert
        *(prev + 1) =   key;
    }
}

}}//namespace
#endif // INSERTION_SORT_HPP


//! @test   insertion_sort
//!         insertion_sort with predicate,   for ex2.1-2
//!
//! @output
//!
//! the sorted sequence:
//! 0 1 2 3 6 99
//! exit normally
//!
//#include <iostream>
//#include <vector>
//#include "insertion_sort.hpp"
//#include "alan.hpp"

//int main()
//{
//    std::vector<int> v = {3,2,1,6,99,0};
//    clrs::ch2::insertion_sort(v.begin(), v.end(), std::greater<int>());

//    alan::prompt("the sorted sequence:");
//    alan::print_container(v);
//    alan::end();
//    return 0;
//}

//! @test   insertion_sort_recur for ex2.3-4
//!
//! @output
//! 0 33 a22 s11
//! exit normally
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "insertion_sort.hpp"

//int main()
//{
//    std::vector<std::string> v{"a22","s11","33","0"};

//    clrs::ch2::insertion_sort_recur(v.begin(), v.end());
//    alan::print_container(v);

//    alan::end();
//    return 0;
//}

