#ifndef NWIDGET_HPP
#define NWIDGET_HPP

#include <memory>

#include <boost/signals2/signal.hpp>


class NApplication;
class NPoint;
class NSize;

template <typename Slot>
using Signal = boost::signals2::signal<Slot>;

class NWidget {
public:
    explicit NWidget (NWidget * parent = 0);
    virtual ~NWidget ();

    NWidget * parent () const;
    const NPoint & pos () const;
    const NSize & size () const;
    void resize (int rows, int cols);
    void update ();

    Signal<void (int)> & keyPressed ();

protected:
    virtual void inputEvent (int keyCode);

private:
    NWidget (const NWidget &);
    NWidget & operator = (const NWidget &);
    friend class NApplication;
    class Private;
    std::shared_ptr<Private> p_;
};

#endif
