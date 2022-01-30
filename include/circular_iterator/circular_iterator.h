#ifndef CIRCULAR_ITERATOR_H
#define CIRCULAR_ITERATOR_H

#include <stdexcept>
#include <boost/iterator_adaptors.hpp>

template<class iterator>
class circular_iterator
        : public boost::iterator_adaptor<
        circular_iterator<iterator>,     // the derived class overriding iterator behavior
        iterator,       // the base class providing default behavior
        boost::use_default, // iterator value type, will be IteratorBase::value_type
        std::bidirectional_iterator_tag, // iterator category
        boost::use_default  // iterator reference type
        >
{
private:
    using typename boost::iterator_adaptor<circular_iterator<iterator>, iterator, boost::use_default, std::bidirectional_iterator_tag, boost::use_default>::iterator_adaptor_;
    using iterator_adaptor_::base_reference;

    iterator m_itBegin;
    iterator m_itEnd;

public:
    circular_iterator( iterator itBegin, iterator itEnd )
        : iterator_adaptor_(itBegin),
          m_itBegin(itBegin),
          m_itEnd(itEnd)
    {
        if(m_itBegin == m_itEnd)    throw std::invalid_argument("circular_iterator<Iterator>::circular_iterator(Iterator, Iterator): Assertion `m_itBegin != m_itEnd` failed.");
    }

    auto increment()
    {
        /* Increment the base reference pointer. */
        ++base_reference();

        /* Check if past-the-end element is reached and bring back the base reference to the beginning. */
        if(base_reference() == m_itEnd)
            base_reference() = m_itBegin;
    }

    auto decrement()
    {
        /* Check if past-the-begining element is reached and bring back the base reference to the end. */
        if(base_reference() == m_itBegin)
            base_reference() = m_itEnd;

        /* Decrement the base reference pointer. */
        --base_reference();
    }
};

#endif //CIRCULAR_ITERATOR_H
