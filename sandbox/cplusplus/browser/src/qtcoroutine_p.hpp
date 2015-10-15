#ifndef QTCOROUTINE_HPP_
#define QTCOROUTINE_HPP_

#include "qtcoroutine.hpp"

#include <boost/coroutine/stack_allocator.hpp>
#include <boost/coroutine/coroutine.hpp>

class QtCoroutine::Private: public QObject {
    Q_OBJECT
public:
    typedef boost::coroutines::coroutine<void> Coroutine;

    Private (QtCoroutine::Callback task, QObject * parent);

    void tail ();

signals:
    void finished ();

public slots:
    void postAction ();

public:
    QtCoroutine::Callback task;
    Coroutine::pull_type fork;
};

class QtCoroutine::YieldPrivate {
public:
    typedef QtCoroutine::Private::Coroutine Coroutine;

    YieldPrivate (QtCoroutine & task, Coroutine::push_type & yield);

    QtCoroutine & task;
    Coroutine::push_type & yield;
};

class SignalIsolator : public QObject {
    Q_OBJECT
signals:
    void proxy();
};

#endif
