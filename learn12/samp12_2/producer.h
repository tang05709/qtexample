#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
class Producer : public QThread
{
public:
    Producer();
    void run() override;
};

#endif // PRODUCER_H
