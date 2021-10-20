#include "widget.h"

#include <QApplication>
#include <QThread>
#include <QSemaphore>
#include <stdio.h>

const int DataSize = 1000;
const int BufferSize = 80;
int buffer[BufferSize];
QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes(0);

class Producer : public QThread
{
public:
    Producer();
    void run() override;
};
Producer::Producer(){}
void Producer::run()
{
    for (int i = 0; i < DataSize; i++) {
        freeBytes.acquire();
        buffer[i%BufferSize] = (i%BufferSize);
        usedBytes.release();
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
    for (int i = 0; i < DataSize; i++) {
        usedBytes.acquire();
        fprintf(stderr, "%d", buffer[i%BufferSize]);
        if (i % 16 == 0 && i != 0) {
            fprintf(stderr, "\n");
        }
        freeBytes.release();
    }
    fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    // 等待生产者和消费者各自执行完毕后退出
    producer.wait();
    consumer.wait();
    //Widget w;
    //w.show();
    return a.exec();
}
