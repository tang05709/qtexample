#include "widget.h"

#include <QApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <QDebug>
const int DataSize = 1000;
const int BufferSize = 80;
int buffer[BufferSize];
QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;
int numUsedBytes = 0;
int rIndex = 0;

class Producer : public QThread
{
public:
    Producer();
    void run() override;
};
Producer::Producer() {}
void Producer::run()
{
    for (int i = 0; i < DataSize; i++) {
        mutex.lock();
        if (numUsedBytes == BufferSize) {
            bufferEmpty.wait(&mutex);
        }
        buffer[i%BufferSize] = numUsedBytes;
        ++numUsedBytes;
        bufferFull.wakeAll();
        mutex.unlock();
    }
}

class Consumer : public QThread
{
public:
    Consumer();
    void run() override;
};
Consumer::Consumer() {}
void Consumer::run()
{
    forever {
        mutex.lock();
        if (numUsedBytes == 0) {
            bufferFull.wait(&mutex);
        }
        qDebug() << "Id: " << currentThread() << "; Index: " << rIndex << "; buffer: " << buffer[rIndex];
        rIndex = (++rIndex) % BufferSize;
        --numUsedBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Producer producer;
    Consumer consumerA;
    Consumer consumerB;

    producer.start();
    consumerA.start();
    consumerB.start();

    producer.wait();
    consumerA.wait();
    consumerB.wait();
    Widget w;
    w.show();
    return a.exec();
}
