#ifndef CIRCULAR_ITERATOR_H
#define CIRCULAR_ITERATOR_H

#include <assert.h>
#include <boost/iterator_adaptors.hpp>
#include <boost/iterator.hpp>

template<class Iterator>
class circular_iterator
        : public boost::iterator_adaptor<
        circular_iterator<Iterator>,     // the derived class overriding iterator behavior
        Iterator,       // the base class providing default behavior
        boost::use_default, // iterator value type, will be IteratorBase::value_type
        std::bidirectional_iterator_tag, // iterator category
        boost::use_default  // iterator reference type
        >
{
private:
    using typename boost::iterator_adaptor<circular_iterator<Iterator>, Iterator, boost::use_default, std::forward_iterator_tag, boost::use_default>::iterator_adaptor_;
    using iterator_adaptor_::base_reference;

    Iterator m_itBegin;
    Iterator m_itEnd;

public:
    circular_iterator( Iterator itBegin, Iterator itEnd )
        : iterator_adaptor_(itBegin),
          m_itBegin(itBegin),
          m_itEnd(itEnd)
    {
	assert (m_itBegin != m_itEnd); //this can be disable using NDEBUG
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
